#include "GraphWidget.h"

GraphWidget::GraphWidget(Adafruit_GFX& gfx, size_t capacity)
	: WidgetBase(gfx)
	, m_capacity(capacity)
{
}
uint8_t GraphWidget::addPlot(const char* name, uint16_t color, float minRange)
{
	Plot plot;
	plot.name = name;
	plot.color = color;
	plot.minRange = minRange;
	plot.points.reserve(m_capacity);
	m_plots.push_back(std::move(plot));
	return m_plots.size() - 1;
}
void GraphWidget::resample(Plot& plot)
{
	plot.timePerUnit *= 2;
	printf("\nResampling to %d", (int)plot.timePerUnit);
	size_t step = 0;
	for (auto it = plot.points.begin(); it != plot.points.end();)
	{
		if ((step & 1) == 1)
		{
			it = plot.points.erase(it);
		}
		else
		{
			++it;
		}
		step++;
	}
}
void GraphWidget::addValue(uint8_t plotIndex, uint64_t timestamp, float value, bool continued)
{
	if (plotIndex >= m_plots.size())
	{
		assert(false && "Plot out of bounds");
		return;
	}
	Plot& plot = m_plots[plotIndex];
	if (plot.points.empty())
	{
		plot.firstTimestamp = timestamp;
		plot.lastTimestamp = timestamp;
		plot.minValue = value;
		plot.maxValue = value;
		plot.points.push_back(Point(value, continued));
		return;
	}

	if (timestamp <= plot.lastTimestamp)
	{
		return;
	}

	float lastValue = plot.points.back().value;
	float dv = value - lastValue;
	uint64_t lastTimestamp = plot.lastTimestamp;
	uint64_t dt = timestamp - lastTimestamp;

	//sample
	//printf("\nS: ");
	uint64_t t = plot.timePerUnit;
	while (t < dt)
	{
		if (plot.points.size() >= m_capacity)
		{
			resample(plot);
		}
		assert(plot.points.size() < m_capacity);

		float sampledValue = lastValue + (float(t) / float(dt)) * dv;
		//printf("T:%d/%f, ", (int)(lastTimestamp + t), sampledValue);

		plot.minValue = std::min(plot.minValue, sampledValue);
		plot.maxValue = std::max(plot.maxValue, sampledValue);
		plot.points.push_back(Point(sampledValue, continued));
		plot.lastTimestamp = lastTimestamp + t;

		t += plot.timePerUnit;
	}
}

void GraphWidget::setSize(int16_t width, int16_t height)
{
	m_w = std::max<int16_t>(width, 1);
	m_h = std::max<int16_t>(height, 1);
}
int16_t GraphWidget::getWidth() const
{
	return m_w;
}
int16_t GraphWidget::getHeight() const
{
	return m_h;
}
void GraphWidget::render()
{
	Position position = getPosition(Anchor::TopLeft);
	m_gfx.fillRect(position.x, position.y, m_w, m_h, 0x0861);

	//printf("\nV: ");
	for (const Plot& plot: m_plots)
	{
		float range = std::max(plot.maxValue - plot.minValue, std::max(plot.minRange, 0.00000001f));
		int16_t index = 0;
		int16_t lastX, lastY;
		for (const Point& point: plot.points)
		{
			//printf("%f, ", point.value);
			int16_t x = position.x + index * m_w / plot.points.size();
			int16_t y = position.y + m_h - int16_t(((point.value - plot.minValue) / range) * m_h);
			if (index > 0)
			{
				m_gfx.drawLine(lastX, lastY, x, y, plot.color);
			}
			lastX = x;
			lastY = y;
			index++;
		}
	}
}
