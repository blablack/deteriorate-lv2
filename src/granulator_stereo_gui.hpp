#ifndef GRANULATOR_STEREO_GUI_H
#define GRANULATOR_STEREO_GUI_H

#include <lvtk-1/lvtk/plugin.hpp>
#include <lvtk-1/lvtk/gtkui.hpp>

#include "labeleddial.hpp"

using namespace lvtk;
using namespace sigc;
using namespace Gtk;

class GranulatorStereoGUI: public UI<GranulatorStereoGUI, GtkUI<true>>
{
	public:
		GranulatorStereoGUI(const std::string& URI);
		void port_event(uint32_t port, uint32_t buffer_size, uint32_t format, const void* buffer);

	protected:
        Gtk::CheckButton* m_checkBypass;
		LabeledDial* m_dialInputGain;
		LabeledDial* m_dialGrainSize;
		LabeledDial* m_dialAttack;
		LabeledDial* m_dialRelease;
		LabeledDial* m_dialGrainDensity;
		LabeledDial* m_dialGrainSpread;
		LabeledDial* m_dialOutputGain;
};

#endif
