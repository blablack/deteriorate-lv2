#ifndef DOWNSAMPLER_STEREO_H
#define DOWNSAMPLER_STEREO_H

#include <lvtk-1/lvtk/plugin.hpp>

#include "downsampler_stereo_ttl.hpp"

using namespace lvtk;

class DownsamplerStereo: public Plugin<DownsamplerStereo>
{
	private:
		float ratio;
		float p_lastInputL, p_lastInputR;
		float p_loop;
	public:
		DownsamplerStereo(double rate);
		void run(uint32_t nframes);
};

#endif
