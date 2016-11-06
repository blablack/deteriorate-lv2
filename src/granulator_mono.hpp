#ifndef GRANULATOR_MONO_H
#define GRANULATOR_MONO_H

#include <lvtk-1/lvtk/plugin.hpp>

#include "granulator_mono_ttl.hpp"

using namespace lvtk;

class GranulatorMono: public Plugin<GranulatorMono>
{
	public:
		GranulatorMono(double rate);
		void run(uint32_t nframes);

	private:
		double m_rate;

		int m_lastGrainSize;

		int m_lastAttack, m_lastRelease;
		float* m_envelope;

		int m_recordingGrainPosition;
		float *m_recordingGrain;

		bool m_playingGrainMode;

		int m_grainIndex, m_grainPosition;
		float *m_playingGrain;

		int m_silencePosition;

		std::vector<float*> m_grains;
		std::vector<int> m_sizeGrains;
};

#endif
