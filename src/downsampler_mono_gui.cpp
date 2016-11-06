#include <gtkmm-2.4/gtkmm.h>

#include <lvtk-1/lvtk/plugin.hpp>
#include <lvtk-1/lvtk/gtkui.hpp>

#include "downsampler_mono_gui.hpp"
#include "downsampler_mono.hpp"

DownsamplerMonoGUI::DownsamplerMonoGUI(const std::string& URI)
{
    EventBox *p_background = manage (new EventBox());
    Gdk::Color* color = new  Gdk::Color();
    color->set_rgb(7710, 8738, 9252);
    p_background->modify_bg(Gtk::STATE_NORMAL, *color);

    VBox *p_mainWidget = manage(new VBox(false));

    Alignment* p_align1 = new Alignment(0.5, 0.5, 0, 0);
    m_dialRatio = new LabeledDial("Ratio", p_ratio, 1, 10, NORMAL, 1, 1);
    m_dialRatio->signal_value_changed().connect(compose(bind<0>(mem_fun(*this, &DownsamplerMonoGUI::write_control), p_ratio), mem_fun(*m_dialRatio,  &LabeledDial::get_value)));
    p_align1->add(*m_dialRatio);
    p_mainWidget->pack_start(*p_align1);

    Alignment* p_align2 = new Alignment(0.5, 0.5, 0, 0);
    m_checkBypass = manage(new CheckButton("Bypass"));
    m_checkBypass->signal_toggled().connect(compose(bind<0>(mem_fun(*this, &DownsamplerMonoGUI::write_control), p_bypass), mem_fun(*m_checkBypass, &CheckButton::get_active)));
    p_align2->add(*m_checkBypass);
    p_mainWidget->pack_start(*p_align2);

    p_background->add(*p_mainWidget);
    add(*p_background);

    Gtk::manage(p_background);
}

void DownsamplerMonoGUI::port_event(uint32_t port, uint32_t buffer_size, uint32_t format, const void* buffer)
{
    switch(port)
    {
    case p_ratio:
        m_dialRatio->set_value(*static_cast<const float*> (buffer));
        break;
    case p_bypass:
        m_checkBypass->set_active(*static_cast<const float*> (buffer) == 1);
        break;
    }
}

static int _ = DownsamplerMonoGUI::register_class("http://github.com/blablack/deteriorate-lv2/downsampler_mono/gui");
