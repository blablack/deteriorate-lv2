#ifndef DOWNSAMPLER_MONO_H
#define DOWNSAMPLER_MONOH

#include <lvtk-1/lvtk/plugin.hpp>

#include "downsampler_mono_ttl.hpp"

using namespace lvtk;

class DownsamplerMono: public Plugin<DownsamplerMono>
{
	private:
		float ratio;
		float p_lastInput;
		float p_loop;
	public:
		DownsamplerMono(double rate);
		void run(uint32_t nframes);
};

#endif
