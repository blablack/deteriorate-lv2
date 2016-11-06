#include <gtkmm-2.4/gtkmm.h>

#include <lvtk-1/lvtk/plugin.hpp>
#include <lvtk-1/lvtk/gtkui.hpp>

#include "granulator_mono_gui.hpp"
#include "granulator_mono.hpp"
#include "dial.hpp"
#include "my_box.hpp"

GranulatorMonoGUI::GranulatorMonoGUI(const std::string& URI)
{
    EventBox *p_background = manage (new EventBox());
    Gdk::Color* color = new  Gdk::Color();
    color->set_rgb(7710, 8738, 9252);
    p_background->modify_bg(Gtk::STATE_NORMAL, *color);


    VBox *p_mainWidget = manage(new VBox(false));


    Alignment* p_align = new Alignment(0.5, 0.5, 0, 0);
    m_checkBypass = manage(new CheckButton("Bypass"));
    m_checkBypass->signal_toggled().connect(compose(bind<0>(mem_fun(*this, &GranulatorMonoGUI::write_control), p_bypass), mem_fun(*m_checkBypass, &CheckButton::get_active)));
    p_align->add(*m_checkBypass);
    p_mainWidget->pack_start(*p_align);


    MyBox *p_gainFrame = manage (new MyBox("Gain", Gtk::Orientation::ORIENTATION_HORIZONTAL));

    m_dialInputGain = new LabeledDial("Input", p_inputGain, 0, 10, NORMAL, 0.01, 2);
    m_dialInputGain->signal_value_changed().connect(compose(bind<0>(mem_fun(*this, &GranulatorMonoGUI::write_control), p_inputGain), mem_fun(*m_dialInputGain, &LabeledDial::get_value)));
    p_gainFrame->pack_start(*m_dialInputGain);

    m_dialOutputGain = new LabeledDial("Output", p_outputGain, 0, 10, NORMAL, 0.01, 2);
    m_dialOutputGain->signal_value_changed().connect(compose(bind<0>(mem_fun(*this, &GranulatorMonoGUI::write_control), p_outputGain), mem_fun(*m_dialOutputGain, &LabeledDial::get_value)));
    p_gainFrame->pack_start(*m_dialOutputGain);

    p_mainWidget->pack_start(*p_gainFrame);


    MyBox *p_grainFrame = manage(new MyBox("Grain", Gtk::Orientation::ORIENTATION_HORIZONTAL));

    m_dialGrainSize = new LabeledDial("Grain Size (ms)", p_grainSize, 6, 10000, LOG, 1, 0);
    m_dialGrainSize->signal_value_changed().connect(compose(bind<0>(mem_fun(*this, &GranulatorMonoGUI::write_control), p_grainSize), mem_fun(*m_dialGrainSize, &LabeledDial::get_value)));
    p_grainFrame->pack_start(*m_dialGrainSize);

    m_dialAttack = new LabeledDial("Attack (ms)", p_attack, 3, 100, NORMAL, 1, 0);
    m_dialAttack->signal_value_changed().connect(compose(bind<0>(mem_fun(*this, &GranulatorMonoGUI::write_control), p_attack), mem_fun(*m_dialAttack, &LabeledDial::get_value)));
    p_grainFrame->pack_start(*m_dialAttack);

    m_dialRelease = new LabeledDial("Release (ms)", p_release, 3, 100, NORMAL, 1, 0);
    m_dialRelease->signal_value_changed().connect(compose(bind<0>(mem_fun(*this, &GranulatorMonoGUI::write_control), p_release), mem_fun(*m_dialRelease, &LabeledDial::get_value)));
    p_grainFrame->pack_start(*m_dialRelease);

    p_mainWidget->pack_start(*p_grainFrame);


    MyBox *p_textureFrame = manage(new MyBox("Texture", Gtk::Orientation::ORIENTATION_HORIZONTAL));

    m_dialGrainDensity = new LabeledDial("Grain Spacing (ms)", p_grainDensity, 1, 10000, LOG, 1, 0);
    m_dialGrainDensity->signal_value_changed().connect(compose(bind<0>(mem_fun(*this, &GranulatorMonoGUI::write_control), p_grainDensity), mem_fun(*m_dialGrainDensity, &LabeledDial::get_value)));
    p_textureFrame->pack_start(*m_dialGrainDensity);

    m_dialGrainSpread = new LabeledDial("Grain Spread", p_grainSpread, 2, 10000, LOG, 1, 0);
    m_dialGrainSpread->signal_value_changed().connect(compose(bind<0>(mem_fun(*this, &GranulatorMonoGUI::write_control), p_grainSpread), mem_fun(*m_dialGrainSpread,  &LabeledDial::get_value)));
    p_textureFrame->pack_start(*m_dialGrainSpread);

    p_mainWidget->pack_start(*p_textureFrame);


    p_background->add(*p_mainWidget);
    add(*p_background);

    Gtk::manage(p_background);
}

void GranulatorMonoGUI::port_event(uint32_t port, uint32_t buffer_size, uint32_t format, const void* buffer)
{
    switch(port)
    {
    case p_inputGain:
        m_dialInputGain->set_value(*static_cast<const float*> (buffer));
        break;
    case p_grainSize:
        m_dialGrainSize->set_value(*static_cast<const float*> (buffer));
        break;
    case p_attack:
        m_dialAttack->set_value(*static_cast<const float*> (buffer));
        break;
    case p_release:
        m_dialRelease->set_value(*static_cast<const float*> (buffer));
        break;
    case p_grainDensity:
        m_dialGrainDensity->set_value(*static_cast<const float*> (buffer));
        break;
    case p_grainSpread:
        m_dialGrainSpread->set_value(*static_cast<const float*> (buffer));
        break;
    case p_outputGain:
        m_dialOutputGain->set_value(*static_cast<const float*> (buffer));
        break;
    case p_bypass:
        m_checkBypass->set_active(*static_cast<const float*> (buffer) == 1);
        break;
    }
}

static int _ = GranulatorMonoGUI::register_class("http://github.com/blablack/deteriorate-lv2/granulator_mono/gui");
