#ifndef DOWNSAMPLER_STEREO_GUI_H
#define DOWNSAMPLER_STEREO_GUI_H

#include <lvtk-2/lvtk/plugin.hpp>
#include <lvtk-2/lvtk/gtkui.hpp>

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
    Gtk::CheckButton* m_checkBypass;
    LabeledDial* m_dialRatio;
};

#endif
