#include "MeasurementState.h"
#include "Measurement.h"
#include "MeasurementTopUI.h"
#include "MeasurementBottomUI.h"
#include "Settings.h"
#include "Program.h"
#include "Menu.h"
#include "GraphWidget.h"
#include "LabelWidget.h"
#include "ValueWidget.h"
#include "Button.h"
#include "DeltaBitmap.h"


extern DeltaBitmap s_canvas;
extern Button s_button;
extern int16_t s_windowY;
extern AiEsp32RotaryEncoder s_knob;
extern Measurement s_measurement;
extern ValueWidget s_temperatureWidget;

extern LabelWidget s_modeWidget;

static Menu s_menu;
enum class MenuSection
{
	Disabled,
	Main,
	SetTarget,
	SetFan,
	ProgramSelection
};
static MenuSection s_menuSection = MenuSection::Disabled;

enum class MenuEntry
{
	Back = 0,
	Target, 
	_4Wire,
	Mode,
	Fan,
	Reset,
	StartProgram,
	StopProgram,
	Settings		
};

//static size_t s_menuSelection = 0;

static int32_t s_targetCurrent_mA = 0;
static int32_t s_targetPower_mW = 0;
static int32_t s_targetResistance_mO = 0;
static float s_fan = 0;

static void refreshSubMenu()
{
	char buf[32];

	Measurement::TrackingMode mode = s_measurement.getTrackingMode();

	if (s_menuSection == MenuSection::Main)
	{
		sprintf(buf, "Target: %.3f %s", 
			(mode == Measurement::TrackingMode::CC ? s_targetCurrent_mA : mode == Measurement::TrackingMode::CP ? s_targetPower_mW : s_targetResistance_mO) / 1000.f,
			(mode == Measurement::TrackingMode::CC ? "A" : mode == Measurement::TrackingMode::CP ? "W" : "{"));
		s_menu.getSubMenuEntry((size_t)MenuEntry::Target).text = buf;
	}
	else if (s_menuSection == MenuSection::SetTarget)
	{
		sprintf(buf, "Target:>%.3f %s", 
			(mode == Measurement::TrackingMode::CC ? s_targetCurrent_mA : mode == Measurement::TrackingMode::CP ? s_targetPower_mW : s_targetResistance_mO) / 1000.f,
			(mode == Measurement::TrackingMode::CC ? "A" : mode == Measurement::TrackingMode::CP ? "W" : "{"));
		s_menu.getSubMenuEntry((size_t)MenuEntry::Target).text = buf;
	}
	if (s_menuSection == MenuSection::Main)
	{
		sprintf(buf, "Fan: %d%%", (int)(s_fan * 100.f));
		s_menu.getSubMenuEntry((size_t)MenuEntry::Fan).text = buf;
	}
	else if (s_menuSection == MenuSection::SetFan)
	{
		sprintf(buf, "Fan:>%d%%", (int)(s_fan * 100.f));
		s_menu.getSubMenuEntry((size_t)MenuEntry::Fan).text = buf;
	}
	sprintf(buf, "4 Wire: %s", s_measurement.is4WireEnabled() ? "On" : "Off");
	s_menu.getSubMenuEntry((size_t)MenuEntry::_4Wire) = buf;

	if (mode == Measurement::TrackingMode::None)
	{
		sprintf(buf, "Mode: None");
	}
	else
	{
		sprintf(buf, "Mode: %s", mode == Measurement::TrackingMode::CC ? "CC" : mode == Measurement::TrackingMode::CP ? "CP" : "CR");
	}
	s_menu.getSubMenuEntry((size_t)MenuEntry::Mode) = buf;
}

void processMeasurementState()
{
	Measurement::TrackingMode mode = s_measurement.getTrackingMode();

	if (s_button.state() == Button::State::RELEASED)
	{
		s_measurement.setLoadEnabled(!s_measurement.isLoadEnabled());
	}

	if (s_menuSection == MenuSection::Main)
	{
		refreshSubMenu();
		MenuEntry selection = (MenuEntry)s_menu.process(s_knob);
		if (selection == MenuEntry::Back)
		{
			s_menuSection = MenuSection::Disabled;
		}
		else if (selection == MenuEntry::Target)
		{
			s_targetCurrent_mA = s_measurement.getTargetCurrent() * 1000.f;
			s_targetPower_mW = s_measurement.getTargetPower() * 1000.f;
			s_targetResistance_mO = s_measurement.getTargetResistance() * 1000.f;

			s_menuSection = MenuSection::SetTarget;
		}
		else if (selection == MenuEntry::Fan)
		{
			s_menuSection = MenuSection::SetFan;
		}
		else if (selection == MenuEntry::_4Wire)
		{
			s_measurement.set4WireEnabled(!s_measurement.is4WireEnabled());
		}
		else if (selection == MenuEntry::Mode)
		{
			mode = mode == Measurement::TrackingMode::CC ? 
								Measurement::TrackingMode::CP : 
								mode == Measurement::TrackingMode::CP ? 
									Measurement::TrackingMode::CR : 
									Measurement::TrackingMode::CC;
			s_measurement.setTrackingMode(mode);
		}
		else if (selection == MenuEntry::Reset)
		{
			s_measurement.resetEnergy();
			s_graphWidget.clear();
		}
		else if (selection == MenuEntry::StopProgram)
		{
			stopProgram();
		}
	}
	else if (s_menuSection == MenuSection::SetTarget)
	{
		int knobDelta = s_knob.encoderChangedAcc();
		if (mode == Measurement::TrackingMode::CC)
		{
			s_targetCurrent_mA += knobDelta;
			s_targetCurrent_mA = std::max(std::min(s_targetCurrent_mA, int32_t(Measurement::k_maxCurrent * 1000.f)), 0);
		}
		else if (mode == Measurement::TrackingMode::CP)
		{
			s_targetPower_mW += knobDelta;
			s_targetPower_mW = std::max(std::min(s_targetPower_mW, int32_t(Measurement::k_maxPower * 1000.f)), 0);
		}
		else if (mode == Measurement::TrackingMode::CR)
		{
			s_targetResistance_mO += knobDelta;
			s_targetResistance_mO = std::max(std::min(s_targetResistance_mO, int32_t(Measurement::k_maxResistance * 1000.f)), int32_t(Measurement::k_minResistance * 1000.f));
		}
		refreshSubMenu();

		if (s_knob.currentButtonState() == BUT_RELEASED)
		{
			if (mode == Measurement::TrackingMode::CC)
			{
				s_measurement.setTargetCurrent(s_targetCurrent_mA / 1000.f);
			}
			else if (mode == Measurement::TrackingMode::CP)
			{
				s_measurement.setTargetPower(s_targetPower_mW / 1000.f);
			}
			else if (mode == Measurement::TrackingMode::CR)
			{
				s_measurement.setTargetResistance(s_targetResistance_mO / 1000.f);
			}
			s_menuSection = MenuSection::Main;
		}
	}
	else if (s_menuSection == MenuSection::SetFan)
	{
		int knobDelta = s_knob.encoderChangedAcc();
		s_fan += knobDelta / 100.f;
		s_fan = std::max(std::min(s_fan, 1.f), 0.f);
		s_measurement.setFan(s_fan);
		refreshSubMenu();
		if (s_knob.currentButtonState() == BUT_RELEASED)
		{
			s_menuSection = MenuSection::Main;
		}
	}
	else if (s_menuSection == MenuSection::Disabled)
	{
		if (s_knob.currentButtonState() == BUT_RELEASED)
		{
			s_menuSection = MenuSection::Main;
		}
		int knobDelta = s_knob.encoderChanged();
		//setBottomUI()
	}

	processMeasurementTopUI();
	processMeasurementBottomUI();

	if (s_menuSection != MenuSection::Disabled)
	{
		s_menu.render(s_canvas, 0);
	}

	updateProgram();

	if (s_measurement.isLoadEnabled() || isRunningProgram())
	{
		//printOutput();
	}
}

void initMeasurementState()
{
	initMeasurementTopUI();
	initMeasurementBottomUI();
}

void beginMeasurementState()
{
	s_measurement.setLoadEnabled(false);
	s_measurement.setCurrentAutoRanging(true);
	s_measurement.setVoltageAutoRanging(true);

	s_menu.pushSubMenu({
	                 /* 0 */"Back",
					 /* 1 */"Target",
	                 /* 2 */"4 Wire: On",
					 /* 3 */"Mode: CC",
					 /* 4 */"Fan: 0%",
					 /* 5 */"Reset Energy",
					 /* 6 */"Start Program",
	                 /* 7 */"Stop Program",
					 /* 8 */"Settings",
	                }, 0, 120);
}
void endMeasurementState()
{

}
