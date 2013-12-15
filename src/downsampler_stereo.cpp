#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#include <lvtk-1/lvtk/plugin.hpp>

#include "downsampler_stereo.hpp"

using namespace lvtk;

DownsamplerStereo::DownsamplerStereo(double rate)
:Plugin<DownsamplerStereo>(p_n_ports)
 {
	ratio = 1;
	p_loop = 0;
	p_lastInputL = 0;
	p_lastInputR = 0;
 }

void DownsamplerStereo::run(uint32_t nframes)
{
	ratio = *p(p_ratio);
	unsigned int l2;
	for (l2 = 0; l2 < nframes; l2++)
	{
		p_loop++;
		if(p_loop >= ratio)
		{
			p_loop = 0;
			p_lastInputL = p(p_inputL)[l2];
			p_lastInputR = p(p_inputR)[l2];
		}
		p(p_outputL)[l2] = p_lastInputL;
		p(p_outputR)[l2] = p_lastInputR;
	}
}

static int _ = DownsamplerStereo::register_class("http://github.com/blablack/deteriorate.lv2/downsampler_stereo");

