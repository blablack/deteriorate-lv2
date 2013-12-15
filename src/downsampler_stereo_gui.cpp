#include <gtkmm-2.4/gtkmm.h>


#include <lvtk-1/lvtk/plugin.hpp>
#include <lvtk-1/lvtk/gtkui.hpp>

#include "downsampler_stereo_gui.hpp"
#include "downsampler_stereo.hpp"
#include "dial.hpp"

DownsamplerStereoGUI::DownsamplerStereoGUI(const std::string& URI)
{
	EventBox *p_background = manage (new EventBox());
	Gdk::Color* color = new  Gdk::Color();
	color->set_rgb(7710, 8738, 9252);
	p_background->modify_bg(Gtk::STATE_NORMAL, *color);

	slot<void> p_slotRatio = compose(bind<0>(mem_fun(*this, &DownsamplerStereoGUI::write_control), p_ratio), mem_fun(*this,  &DownsamplerStereoGUI::get_ratio));
	m_dialRatio = new LabeledDial("Ratio", p_slotRatio, p_ratio, 1, 10, NORMAL, 1, 1);
	p_background->add(*m_dialRatio);

	p_background->set_size_request(100, 80);

	add(*p_background);

	Gtk::manage(p_background);
}

float DownsamplerStereoGUI::get_ratio() { return m_dialRatio->get_value(); }

void DownsamplerStereoGUI::port_event(uint32_t port, uint32_t buffer_size, uint32_t format, const void* buffer)
{
	if (port == p_ratio)
	{
		m_dialRatio->set_value(*static_cast<const float*> (buffer));
	}
}

static int _ = DownsamplerStereoGUI::register_class("http://github.com/blablack/deteriorate.lv2/downsampler_stereo/gui");
