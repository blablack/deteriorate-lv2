#ifndef GRANULATOR_MONO_GUI_H
#define GRANULATOR_MONO_GUI_H

#include <lvtk-2/lvtk/plugin.hpp>
#include <lvtk-2/lvtk/gtkui.hpp>

#include "labeleddial.hpp"

using namespace lvtk;
using namespace sigc;
using namespace Gtk;

class GranulatorMonoGUI: public UI<GranulatorMonoGUI, GtkUI<true>>
{
	public:
		GranulatorMonoGUI(const std::string& URI);
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
