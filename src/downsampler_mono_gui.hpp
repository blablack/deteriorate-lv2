#ifndef DOWNSAMPLER_MONO_GUI_H
#define DOWNSAMPLER_MONO_GUI_H

#include <lvtk-2/lvtk/plugin.hpp>
#include <lvtk-2/lvtk/gtkui.hpp>

#include "labeleddial.hpp"

using namespace lvtk;
using namespace sigc;
using namespace Gtk;

class DownsamplerMonoGUI: public UI<DownsamplerMonoGUI, GtkUI<true>>
{
	public:
		DownsamplerMonoGUI(const std::string& URI);
		void port_event(uint32_t port, uint32_t buffer_size, uint32_t format, const void* buffer);

	protected:
        Gtk::CheckButton* m_checkBypass;
		LabeledDial* m_dialRatio;
};

#endif
