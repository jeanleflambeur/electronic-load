#include "MeasurementState.h"
#include "Measurement.h"
#include "Settings.h"
#include "Program.h"
#include "Menu.h"
#include "GraphWidget.h"
#include "LabelWidget.h"
#include "ValueWidget.h"
#include "ImageWidget.h"
#include "DurationEditWidget.h"
#include "ValueEditWidget.h"
#include "Button.h"
#include "DeltaBitmap.h"
#include "AiEsp32RotaryEncoder.h"
#include "Fonts/SansSerif_plain_10.h"
#include "Fonts/SansSerif_bold_10.h"
#include "Fonts/SansSerif_plain_13.h"
#include "Fonts/SansSerif_bold_13.h"
#include "Fonts/SansSerif_plain_18.h"
#include "Fonts/SansSerif_bold_18.h"
#include "Fonts/SansSerif_plain_28.h"
#include "Fonts/SansSerif_bold_28.h"
#include "Fonts/SansSerif_plain_32.h"
#include "Fonts/SansSerif_bold_32.h"
#include "icons.h"

extern DeltaBitmap s_canvas;
extern Button s_button;
extern int16_t s_windowY;
extern AiEsp32RotaryEncoder s_knob;
extern Measurement s_measurement;
extern ValueWidget s_temperatureWidget;
extern LabelWidget s_modeWidget;

static const uint16_t k_voltageColor = 0x05D2;
static const uint16_t k_currentColor = 0x0C3C;
static const uint16_t k_resistanceColor = 0xFE4D;
static const uint16_t k_powerColor = 0xFBAE;
static const uint16_t k_timerColor = 0xFFFF;
static const uint16_t k_chargeColor = 0x6AFC;
static const uint16_t k_energyColor = 0xD186;

//static LabelWidget s_rangeWidget(s_canvas, "");
static ValueWidget s_voltageWidget(s_canvas, 0.f, "V");
static ValueWidget s_currentWidget(s_canvas, 0.f, "A");
static ValueWidget s_resistanceWidget(s_canvas, 0.f, "{"); //Create the ohm symbol with this: https://tchapi.github.io/Adafruit-GFX-Font-Customiser/
static ValueWidget s_powerWidget(s_canvas, 0.f, "W");
static ValueWidget s_energyWidget(s_canvas, 0.f, "Wh");
static ValueWidget s_chargeWidget(s_canvas, 0.f, "Ah");
static LabelWidget s_timerWidget(s_canvas, "00:00:00");
static DurationEditWidget s_durationLimitWidget(s_canvas, nullptr);
static ValueEditWidget s_valueLimitWidget(s_canvas, nullptr);
static ValueWidget s_targetWidget(s_canvas, 0.f, "Ah");
static ImageWidget s_targetIconWidget(s_canvas, &k_imgTarget, &k_imgTargetH, nullptr);

static ImageWidget s_graphIconWidget(s_canvas, &k_imgGraph, &k_imgGraphH, nullptr);
static ImageWidget s_limitsIconWidget(s_canvas, &k_imgLimits, &k_imgLimitsH, nullptr);
static ImageWidget s_settingsIconWidget(s_canvas, &k_imgSettings, &k_imgSettingsH, nullptr);

//static LabelWidget s_rangeWidget(s_canvas, "");
static GraphWidget s_graphWidget(s_canvas, 512);

static uint8_t s_voltagePlot = 0;
static uint8_t s_currentPlot = 0;
static uint8_t s_powerPlot = 0;
static uint8_t s_resistancePlot = 0;

static std::vector<Widget*> s_selectableWidgets = 
{ 
	&s_targetIconWidget, 
	&s_graphIconWidget,
	&s_limitsIconWidget,
	&s_settingsIconWidget
};
static size_t s_highlightedWidgetIndex = 0;
static bool s_isWidgetSelected = false;

enum class LowSection
{
	Graph,
	Details
};
static LowSection s_lowSection = LowSection::Graph;


enum class UIState
{
	Main,
	SettingsMenu,
	GraphMenu,
	SetTarget,
	SetTimerLimit,
	SetVoltageLimit,
	SetEnergyLimit,
	SetChargeLimit	
};
static UIState s_uiState = UIState::Main;

static Menu s_menu;

enum class SettingsMenuEntry
{
	Back = 0,
	_4Wire,
	Mode,
	Reset,
	StartProgram,
	StopProgram,
	Settings		
};
enum class SettingsMenuState
{
	Main,
	ProgramSelection
};
static SettingsMenuState s_settingsMenuState = SettingsMenuState::Main;


//static size_t s_menuSelection = 0;

static int32_t s_targetCurrent_mA = 0;
static int32_t s_targetPower_mW = 0;
static int32_t s_targetResistance_mO = 0;
static float s_fan = 0;

void setUnitValue(ValueWidget& widget, float value, uint8_t decimalsMacro, float maxMacro, uint8_t decimalsMicro, float maxMicro, const char* unitSI)
{
	char buf[8];
	if (value >= 1000000.f)
	{
		widget.setValue(value / 1000000.f);
		widget.setDecimals(decimalsMacro);
		widget.setRange(0, maxMacro);
		sprintf(buf, "M%s", unitSI);
		widget.setSuffix(buf);
	}
	else if (value >= 1000.f)
	{
		widget.setValue(value / 1000.f);
		widget.setDecimals(decimalsMacro);
		widget.setRange(0, maxMacro);
		sprintf(buf, "k%s", unitSI);
		widget.setSuffix(buf);
	}
	else if (value >= 1.f)
	{
		widget.setValue(value);
		widget.setDecimals(decimalsMacro);
		widget.setRange(0, maxMacro);
		widget.setSuffix(unitSI);
	}	
	else
	{
		widget.setValue(value * 1000.f);
		widget.setDecimals(decimalsMicro);
		widget.setRange(0, maxMicro);
		sprintf(buf, "m%s", unitSI);
		widget.setSuffix(buf);
	}	
}

static void refreshSubMenu()
{
	char buf[64];

	uint16_t modeColors[] = {0xFFFF, k_currentColor, k_powerColor, k_resistanceColor};
	const char* modeNames[] = {"None", "CC", "CP", "CR"};
	const char* modeUnits[] = {"-", "A", "W", "}"};
	int32_t* modeTargetValues[] = {&s_targetCurrent_mA, &s_targetCurrent_mA, &s_targetPower_mW, &s_targetResistance_mO};

	Measurement::TrackingMode mode = s_measurement.getTrackingMode();

	// if (s_settingsMenuState == SettingsMenuState::Main)
	// {
	// 	sprintf(buf, "#f7CF7Target: #f%04X%.3f %s", 
	// 		modeColors[(int)mode],
	// 		*modeTargetValues[(int)mode] / 1000.f,
	// 		modeUnits[(int)mode]);
	// 	s_menu.getSubMenuEntry((size_t)SettingsMenuEntry::Target).text = buf;
	// }
	// else if (s_settingsMenuState == SettingsMenuState::SetTarget)
	// {
	// 	sprintf(buf, "#fBBCETarget: #f%04X%.3f %s", 
	// 		modeColors[(int)mode],
	// 		*modeTargetValues[(int)mode] / 1000.f,
	// 		modeUnits[(int)mode]);
	// 	s_menu.getSubMenuEntry((size_t)SettingsMenuEntry::Target).text = buf;
	// }
	// if (s_settingsMenuState == SettingsMenuState::Main)
	// {
	// 	sprintf(buf, "#f7CF7Fan: %d%%", (int)(s_fan * 100.f));
	// 	s_menu.getSubMenuEntry((size_t)SettingsMenuEntry::Fan).text = buf;
	// }
	// else if (s_settingsMenuState == SettingsMenuState::SetFan)
	// {
	// 	sprintf(buf, "#fBBCEFan: %d%%", (int)(s_fan * 100.f));
	// 	s_menu.getSubMenuEntry((size_t)SettingsMenuEntry::Fan).text = buf;
	// }
	sprintf(buf, "#f7CF74 Wire: %s", s_measurement.is4WireEnabled() ? "On" : "Off");
	s_menu.getSubMenuEntry((size_t)SettingsMenuEntry::_4Wire) = buf;

	if (mode == Measurement::TrackingMode::None)
	{
		sprintf(buf, "#f7CF7Mode: None");
	}
	else
	{
		sprintf(buf, "#f7CF7Mode: #f%04X%s", 
					modeColors[(int)mode],
					modeNames[(int)mode]);
	}
	s_menu.getSubMenuEntry((size_t)SettingsMenuEntry::Mode) = buf;
}

void processUIState_Main()
{
	Widget* sw = s_selectableWidgets[s_highlightedWidgetIndex];
	sw->setHighlighted(false);
	s_highlightedWidgetIndex += s_knob.encoderDelta();
	s_highlightedWidgetIndex %= s_selectableWidgets.size();
	sw = s_selectableWidgets[s_highlightedWidgetIndex];
	sw->setHighlighted(true);

	if (s_knob.buttonState() == RotaryEncoder::ButtonState::Released)
	{
		if (sw == &s_settingsIconWidget)
		{
			s_uiState = UIState::SettingsMenu;
			s_menu.pushSubMenu({
							"#f7CF7Back",
							"#f7CF74 Wire: On",
							"#f7CF7Mode: CC",
							"#f7CF7Reset Energy",
							"#f7CF7Start Program",
							"#f7CF7Stop Program",
							"#f7CF7Settings",
							}, 0, 120);
		}
	}
}

void processUIState_SettingsMenu()
{
	Measurement::TrackingMode mode = s_measurement.getTrackingMode();

	if (s_settingsMenuState == SettingsMenuState::Main)
	{
		refreshSubMenu();
		SettingsMenuEntry selection = (SettingsMenuEntry)s_menu.process(s_knob);
		if (selection == SettingsMenuEntry::Back)
		{
			s_uiState = UIState::Main;
			s_menu.popSubMenu();
		}
		// else if (selection == SettingsMenuEntry::Target)
		// {
			// s_targetCurrent_mA = s_measurement.getTargetCurrent() * 1000.f;
			// s_targetPower_mW = s_measurement.getTargetPower() * 1000.f;
			// s_targetResistance_mO = s_measurement.getTargetResistance() * 1000.f;

			// s_settingsMenuState = SettingsMenuState::SetTarget;
		// }
		else if (selection == SettingsMenuEntry::_4Wire)
		{
			s_measurement.set4WireEnabled(!s_measurement.is4WireEnabled());
		}
		else if (selection == SettingsMenuEntry::Mode)
		{
			mode = mode == Measurement::TrackingMode::CC ? 
								Measurement::TrackingMode::CP : 
								mode == Measurement::TrackingMode::CP ? 
									Measurement::TrackingMode::CR : 
									Measurement::TrackingMode::CC;
			s_measurement.setTrackingMode(mode);
		}
		else if (selection == SettingsMenuEntry::Reset)
		{
			s_measurement.resetEnergy();
			s_graphWidget.clear();
		}
		else if (selection == SettingsMenuEntry::StopProgram)
		{
			stopProgram();
		}
	}
	// else if (s_settingsMenuState == SettingsMenuState::SetTarget)
	// {
	// 	int knobDelta = s_knob.encoderDeltaAcc();
	// 	if (mode == Measurement::TrackingMode::CC)
	// 	{
	// 		s_targetCurrent_mA += knobDelta;
	// 		s_targetCurrent_mA = std::max(std::min(s_targetCurrent_mA, int32_t(Measurement::k_maxCurrent * 1000.f)), 0);
	// 	}
	// 	else if (mode == Measurement::TrackingMode::CP)
	// 	{
	// 		s_targetPower_mW += knobDelta;
	// 		s_targetPower_mW = std::max(std::min(s_targetPower_mW, int32_t(Measurement::k_maxPower * 1000.f)), 0);
	// 	}
	// 	else if (mode == Measurement::TrackingMode::CR)
	// 	{
	// 		s_targetResistance_mO += knobDelta;
	// 		s_targetResistance_mO = std::max(std::min(s_targetResistance_mO, int32_t(Measurement::k_maxResistance * 1000.f)), int32_t(Measurement::k_minResistance * 1000.f));
	// 	}
	// 	refreshSubMenu();

	// 	if (s_knob.buttonState() == RotaryEncoder::ButtonState::Released)
	// 	{
	// 		if (mode == Measurement::TrackingMode::CC)
	// 		{
	// 			s_measurement.setTargetCurrent(s_targetCurrent_mA / 1000.f);
	// 		}
	// 		else if (mode == Measurement::TrackingMode::CP)
	// 		{
	// 			s_measurement.setTargetPower(s_targetPower_mW / 1000.f);
	// 		}
	// 		else if (mode == Measurement::TrackingMode::CR)
	// 		{
	// 			s_measurement.setTargetResistance(s_targetResistance_mO / 1000.f);
	// 		}
	// 		s_settingsMenuState = SettingsMenuState::Main;
	// 	}
	// }
	// else if (s_settingsMenuState == SettingsMenuState::SetFan)
	// {
	// 	int knobDelta = s_knob.encoderDeltaAcc();
	// 	s_fan += knobDelta / 100.f;
	// 	s_fan = std::max(std::min(s_fan, 1.f), 0.f);
	// 	s_measurement.setFan(s_fan);
	// 	refreshSubMenu();
	// 	if (s_knob.buttonState() == RotaryEncoder::ButtonState::Released)
	// 	{
	// 		s_settingsMenuState = SettingsMenuState::Main;
	// 	}
	// }
}

void processMeasurementState()
{
	Measurement::TrackingMode mode = s_measurement.getTrackingMode();

	if (s_button.state() == Button::State::RELEASED)
	{
		s_measurement.setLoadEnabled(!s_measurement.isLoadEnabled());
	}

	if (s_uiState == UIState::Main)
	{
		processUIState_Main();
	}
	else if (s_uiState == UIState::SettingsMenu)
	{
		processUIState_SettingsMenu();
	}

	//Mode
	s_modeWidget.setValue(isRunningProgram() ? "Program Mode" : mode == Measurement::TrackingMode::CC ? "CC Mode" : mode == Measurement::TrackingMode::CP ? "CP Mode" : "CR Mode");
	s_modeWidget.render();

	//char buf[32];
	//sprintf(buf, "(V%d/A%d)", getVoltageRange(), getCurrentRange());
	//s_rangeWidget.setValue(buf);
  	//s_rangeWidget.setPosition(Widget::Position{s_canvas.width() - s_rangeWidget.getWidth() - 2, s_windowY + s_rangeWidget.getHeight()});
	//s_rangeWidget.render();

	//s_voltageWidget.setValueColor(isVoltageValid() ? 0xFFFF : 0xF000);
	//s_voltageWidget.setDecimals(s_voltage < 10.f ? 3 : 2);
	float voltage = s_measurement.getVoltage();
	setUnitValue(s_voltageWidget, voltage, 3, 99.f, 1, 999.999f, "V");
	s_voltageWidget.render();

	uint16_t trackedColor = 0;
	int16_t trackedBorderY = 0;

	if (mode == Measurement::TrackingMode::CC)
	{
		int16_t border = 3;
		Widget::Position p = s_currentWidget.getPosition(Widget::Anchor::TopLeft);
		s_canvas.fillRoundRect(p.x - border, p.y - border, 1000, s_currentWidget.getHeight() + border*2, border, k_currentColor);
		s_currentWidget.setTextColor(0x0);
		setUnitValue(s_targetWidget, s_measurement.getTargetCurrent(), 3, 99.f, 0, 999.999f, "A");
		trackedColor = k_currentColor;
		trackedBorderY = p.y;
	}
	else
	{
		s_currentWidget.setTextColor(k_currentColor);
	} 	
	float current = s_measurement.getCurrent();
	setUnitValue(s_currentWidget, current, 3, 99.f, 1, 999.999f, "A");
	s_currentWidget.render();

	if (mode == Measurement::TrackingMode::CP)
	{
		int16_t border = 3;
		Widget::Position p = s_powerWidget.getPosition(Widget::Anchor::TopLeft);
		s_canvas.fillRoundRect(p.x - border, p.y - border, 1000, s_powerWidget.getHeight() + border*2, border, k_powerColor);
		s_powerWidget.setTextColor(0x0);
		setUnitValue(s_targetWidget, s_measurement.getTargetPower(), 3, 999.999f, 0, 999.999f, "W");
		trackedColor = k_powerColor;
		trackedBorderY = p.y;
	}
	else
	{
		s_powerWidget.setTextColor(k_powerColor);
	}
	float power = s_measurement.getPower();
	setUnitValue(s_powerWidget, power, 3, 999.999f, 1, 999.999f, "W");
	s_powerWidget.render();

	if (mode == Measurement::TrackingMode::CR)
	{
		int16_t border = 3;
		Widget::Position p = s_resistanceWidget.getPosition(Widget::Anchor::TopLeft);
		s_canvas.fillRoundRect(p.x - border, p.y - border, 1000, s_resistanceWidget.getHeight() + border*2, border, k_resistanceColor);
		s_resistanceWidget.setTextColor(0x0);
		setUnitValue(s_targetWidget, s_measurement.getTargetResistance(), 3, 999.999f, 0, 999.999f, "{");
		trackedColor = k_resistanceColor;
		trackedBorderY = p.y;
	}
	else
	{
		s_resistanceWidget.setTextColor(k_resistanceColor);
	}
	float resistance = s_measurement.getResistance();
	setUnitValue(s_resistanceWidget, resistance, 3, 999.999f, 1, 999.999f, "{");
	s_resistanceWidget.render();

	float energy = s_measurement.getEnergy();
	setUnitValue(s_energyWidget, energy, 3, 999.999f, 3, 999.999f, "Wh");
	s_energyWidget.render();

	float charge = s_measurement.getCharge();
	setUnitValue(s_chargeWidget, charge, 3, 999.999f, 3, 999.999f, "Ah");
	s_chargeWidget.render();

	Clock::duration loadTimer = s_measurement.getLoadTimer();

	if (s_measurement.isLoadEnabled())
	{
		int16_t border = 3;
		Widget::Position p = s_timerWidget.getPosition(Widget::Anchor::TopLeft);
		s_canvas.fillRoundRect(p.x - border, p.y - border, s_timerWidget.getWidth() + border*2, s_timerWidget.getHeight() + border*2, border, k_timerColor);
		s_timerWidget.setTextColor(0x0);
	}
	else
	{
		s_timerWidget.setTextColor(k_timerColor);
	}
	{
		int32_t seconds = std::chrono::duration_cast<std::chrono::seconds>(loadTimer).count() % 60;
		int32_t minutes = std::chrono::duration_cast<std::chrono::minutes>(loadTimer).count() % 60;
		int32_t hours = std::chrono::duration_cast<std::chrono::hours>(loadTimer).count();
		char buf[128];
		sprintf(buf, "%d:%02d:%02d", hours, minutes, seconds);
		s_timerWidget.setValue(buf);
	}
	s_timerWidget.render();

	{
		int16_t border = 3;
		Widget::Position tlp = s_targetIconWidget.getPosition(Widget::Anchor::TopLeft);
		Widget::Position blp = s_targetWidget.getPosition(Widget::Anchor::BottomLeft);
		s_canvas.fillRoundRect(tlp.x - border, tlp.y - border, 1000, blp.y - tlp.y + border*2, border, trackedColor);
		s_canvas.fillRect(s_canvas.width() - 10, trackedBorderY, 1000, blp.y - trackedBorderY, trackedColor);
	}
	s_targetWidget.render();
	s_targetIconWidget.setPosition(s_targetWidget.getPosition(Widget::Anchor::CenterLeft).move(-2, 0), Widget::Anchor::CenterRight);
	s_targetIconWidget.render();

	const Image* img = s_measurement.is4WireEnabled() ? &k_img4Wire : &k_img2Wire;
	s_canvas.drawRGBA8888Bitmap(s_temperatureWidget.getPosition(Widget::Anchor::TopLeft).x - 36, 0, 
							(const uint32_t*)img->pixel_data, img->width, img->height);

	static char program[1024] = { 0 };
	static size_t programSize = 0;
	if (Serial.available() > 0) 
	{
		char ch = Serial.peek();
		if (ch == 'r')
		{
			ESP.restart();
		}
		else while (Serial.available() > 0)
		{
			ch = Serial.read();
			if (ch == '\n' || ch == '\r' || programSize >= 1023)
			{
				program[programSize] = 0;
				compileProgram(program);
				programSize = 0;
				break;
			}
			else
			{
				program[programSize++] = ch;
			}
		}
	}
/*
	{	
		s_timerWidget2.setEditing(true);
		s_timerWidget2.setRange(0, 50);
		s_timerWidget2.setSuffix("A");
		s_timerWidget2.process(s_knob);
	}
*/

	s_graphIconWidget.render();
	s_limitsIconWidget.render();
	s_settingsIconWidget.render();

	if (s_measurement.isLoadEnabled() && s_measurement.isLoadSettled()) //skip a few samples
	{
		s_graphWidget.addValue(s_voltagePlot, loadTimer, voltage, true);
		s_graphWidget.addValue(s_currentPlot, loadTimer, current, true);
		s_graphWidget.addValue(s_powerPlot, loadTimer, power, true);
		s_graphWidget.addValue(s_resistancePlot, loadTimer, resistance, true);
	}
	if (s_lowSection == LowSection::Graph)
	{
		s_graphWidget.render();
	}

	s_menu.render(s_canvas, 0);
	if (s_uiState == UIState::SetTimerLimit)
	{
		s_durationLimitWidget.process(s_knob);
		s_durationLimitWidget.render();
	}
	if (s_uiState == UIState::SetVoltageLimit ||
		s_uiState == UIState::SetEnergyLimit ||
		s_uiState == UIState::SetChargeLimit)
	{
		s_durationLimitWidget.process(s_knob);
		s_durationLimitWidget.render();
	}

	updateProgram();

	if (s_measurement.isLoadEnabled() || isRunningProgram())
	{
		//printOutput();
	}
}

void initUI()
{
	int16_t xSpacing = 12;
	int16_t ySpacing = 6;

	int16_t column1X = s_canvas.width() / 4;
	int16_t column2X = s_canvas.width() * 3 / 4;

	//1st ROW
	s_voltageWidget.setUseContentHeight(true);
	s_voltageWidget.setRange(0, 99);
	s_voltageWidget.setTextColor(k_voltageColor);
	s_voltageWidget.setValueFont(&SansSerif_bold_32);
	s_voltageWidget.setSuffixFont(&SansSerif_bold_10);
  	s_voltageWidget.setDecimals(3);
  	s_voltageWidget.setPosition(Widget::Position{column1X, s_windowY + 8}, Widget::Anchor::TopCenter);

	s_currentWidget.setUseContentHeight(true);
	s_currentWidget.setRange(0, 99);
	s_currentWidget.setTextColor(k_currentColor);
	s_currentWidget.setValueFont(&SansSerif_bold_32);
	s_currentWidget.setSuffixFont(&SansSerif_bold_10);
  	s_currentWidget.setDecimals(3);
  	s_currentWidget.setPosition(Widget::Position{column2X, s_windowY + 8}, Widget::Anchor::TopCenter);

	//2nd ROW
	s_energyWidget.setUseContentHeight(true);
	s_energyWidget.setRange(0, 999.9999f);
	s_energyWidget.setTextColor(k_energyColor);
	s_energyWidget.setValueFont(&SansSerif_bold_18);
	s_energyWidget.setSuffixFont(&SansSerif_bold_10);
  	s_energyWidget.setDecimals(3);
  	s_energyWidget.setPosition(s_voltageWidget.getPosition(Widget::Anchor::BottomCenter).move(0, ySpacing), Widget::Anchor::TopCenter);

	s_powerWidget.setUseContentHeight(true);
	s_powerWidget.setRange(0, 999.9999f);
	s_powerWidget.setTextColor(k_powerColor);
	s_powerWidget.setValueFont(&SansSerif_bold_18);
	s_powerWidget.setSuffixFont(&SansSerif_bold_10);
  	s_powerWidget.setDecimals(3);
  	s_powerWidget.setPosition(s_currentWidget.getPosition(Widget::Anchor::BottomCenter).move(0, ySpacing), Widget::Anchor::TopCenter);

	//3rd ROW
	s_chargeWidget.setUseContentHeight(true);
	s_chargeWidget.setRange(0, 999.9999f);
	s_chargeWidget.setTextColor(k_chargeColor);
	s_chargeWidget.setValueFont(&SansSerif_bold_18);
	s_chargeWidget.setSuffixFont(&SansSerif_bold_10);
  	s_chargeWidget.setDecimals(3);
  	s_chargeWidget.setPosition(s_energyWidget.getPosition(Widget::Anchor::BottomCenter).move(0, ySpacing), Widget::Anchor::TopCenter);

	s_resistanceWidget.setUseContentHeight(true);
	s_resistanceWidget.setRange(0, 999.9999f);
	s_resistanceWidget.setTextColor(k_resistanceColor);
	s_resistanceWidget.setValueFont(&SansSerif_bold_18);
	s_resistanceWidget.setSuffixFont(&SansSerif_bold_10);
  	s_resistanceWidget.setDecimals(3);
  	s_resistanceWidget.setPosition(s_powerWidget.getPosition(Widget::Anchor::BottomCenter).move(0, ySpacing), Widget::Anchor::TopCenter);

  	//4th ROW
	s_timerWidget.setUseContentHeight(true);
	s_timerWidget.setTextColor(k_timerColor);
	s_timerWidget.setFont(&SansSerif_bold_18);
  	s_timerWidget.setPosition(s_chargeWidget.getPosition(Widget::Anchor::BottomCenter).move(0, ySpacing * 2), Widget::Anchor::TopCenter);

/*
	s_timerWidget2.setUseContentHeight(true);
	s_timerWidget2.setTextColor(k_timerColor);
	s_timerWidget2.setMainFont(&SansSerif_bold_18);
	s_timerWidget2.setSuffixFont(&SansSerif_bold_10);
  	s_timerWidget2.setPosition(Widget::Position{xSpacing, s_timerWidget.getPosition(Widget::Anchor::BottomLeft).y}.move(0, ySpacing * 2), Widget::Anchor::TopLeft);
*/
	s_targetWidget.setUseContentHeight(true);
	s_targetWidget.setRange(0, 999.9999f);
	s_targetWidget.setTextColor(0);
	s_targetWidget.setValueFont(&SansSerif_bold_18);
	s_targetWidget.setSuffixFont(&SansSerif_bold_10);
  	s_targetWidget.setDecimals(3);
  	s_targetWidget.setPosition(s_resistanceWidget.getPosition(Widget::Anchor::BottomCenter).move((s_targetIconWidget.getWidth() + xSpacing) / 2, ySpacing * 2), Widget::Anchor::TopCenter);

	s_modeWidget.setFont(&SansSerif_bold_13);
	s_modeWidget.setPosition(Widget::Position{0, s_windowY - 3});

	{
		int16_t y = s_canvas.height() - s_graphIconWidget.getHeight() - s_limitsIconWidget.getHeight() - s_settingsIconWidget.getHeight();
		s_graphIconWidget.setPosition(Widget::Position(s_canvas.width(), y), Widget::Anchor::TopRight);
		y += s_graphIconWidget.getHeight();
		s_limitsIconWidget.setPosition(Widget::Position(s_canvas.width(), y), Widget::Anchor::TopRight);
		y += s_limitsIconWidget.getHeight();
		s_settingsIconWidget.setPosition(Widget::Position(s_canvas.width(), y), Widget::Anchor::TopRight);
	}

	s_graphWidget.setPosition(Widget::Position{0, s_timerWidget.getPosition(Widget::Anchor::BottomLeft).y}.move(0, ySpacing * 3), Widget::Anchor::TopLeft);
	s_graphWidget.setSize(s_graphIconWidget.getPosition(Widget::Anchor::TopLeft).x - xSpacing, s_canvas.height() - s_graphWidget.getPosition().y - 1);
	s_voltagePlot = s_graphWidget.addPlot("V", k_voltageColor, 0.1f);
	s_currentPlot = s_graphWidget.addPlot("A", k_currentColor, 0.1f);
	s_powerPlot = s_graphWidget.addPlot("W", k_powerColor, 0.1f);
	s_resistancePlot = s_graphWidget.addPlot("{", k_resistanceColor, 0.1f);
}

void initMeasurementState()
{
	initUI();
}

void beginMeasurementState()
{
	s_measurement.setLoadEnabled(false);
	s_measurement.setCurrentAutoRanging(true);
	s_measurement.setVoltageAutoRanging(true);
}
void endMeasurementState()
{

}
