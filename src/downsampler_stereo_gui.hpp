#ifndef DOWNSAMPLER_STEREO_GUI_H
#define DOWNSAMPLER_STEREO_GUI_H

#include <lvtk-1/lvtk/plugin.hpp>
#include <lvtk-1/lvtk/gtkui.hpp>

#include "labeleddial.hpp"

using namespace lvtk;
using namespace sigc;
using namespace Gtk;

class DownsamplerStereoGUI: public UI<DownsamplerStereoGUI, GtkUI<true>>
{
	public:
		DownsamplerStereoGUI(const std::string& URI);
		void port_event(uint32_t port, uint32_t buffer_size, uint32_t format, const void* buffer);

	protected:
		LabeledDial* m_dialRatio;

		float get_ratio();
};

#endif
