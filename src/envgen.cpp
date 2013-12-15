#include <stdio.h>

#include "envgen.hpp"

float* gen_full_envelope(int Size, int Attack, int Release)
{
	float p_fade = 0.0f;
	float* p_envelope = new float[Size];

	p_envelope[0] = 0.0f;
	p_envelope[1] = 0.0f;

	float p_fadeStep = 1.0f / (Attack - 2);
	p_fade = 0.0f;
	for (int i = 2 ; i < Attack ; i++)
	{
		if(p_fade < 1)
		{
			p_envelope[i] = p_fade;
		}
		else
		{
			p_envelope[i] = 1.0f;
		}
		p_fade += p_fadeStep;
	}

	for (int i = Attack ; i < Size - Release ; i++)
	{
		p_envelope[i] = 1.0f;
	}

	p_fadeStep = 1.0f / (Release - 2);
	p_fade = 1.0f;
	for (int i = Size - Release ; i < Size - 2; i++)
	{
		p_fade -= p_fadeStep;
		if(p_fade > 0)
		{
			p_envelope[i] = p_fade;
		}
		else
		{
			p_envelope[i] = 0.0f;
		}
	}

	p_envelope[Size - 2] = 0.0f;
	p_envelope[Size - 1] = 0.0f;

	return p_envelope;
}


float* gen_attack(int Attack)
{
	float* m_envelope = new float[Attack];

	m_envelope[0] = 0.0f;
	m_envelope[1] = 0.0f;

	float m_fadeInStep = 1.0f / (Attack - 4);
	float m_fadeIn = 0.0f;
	for (int i = 2 ; i < Attack - 2 ; i++)
	{
		if(m_fadeIn < 1)
		{
			m_envelope[i] = m_fadeIn;
		}
		else
		{
			m_envelope[i] = 1.0f;
		}
		m_fadeIn += m_fadeInStep;
	}

	m_envelope[Attack - 2] = 1.0f;
	m_envelope[Attack - 1] = 1.0f;

	return m_envelope;
}

float* gen_long_release(int Size, int Release)
{
	float* m_envelope = new float[Size];

	for(int i = 0 ; i < Size - Release ; i++)
	{
		m_envelope[i] = 1;
	}

	float* m_release = gen_release(Release);

	for(int i = 0 ; i < Release ; i++)
	{
		m_envelope[Size - Release + i] = m_release[i];
	}

	return m_envelope;
}

float* gen_release(int Release)
{
	return gen_release(1.0f, Release);
}

float* gen_release(float StartingAmp, int Release)
{
	float* m_envelope = new float[Release];

	m_envelope[0] = StartingAmp;
	m_envelope[1] = StartingAmp;

	float m_fadeOutStep = StartingAmp / (Release - 4);
	float m_fadeOut = StartingAmp;
	for (int i = 2 ; i < Release - 2; i++)
	{
		m_fadeOut -= m_fadeOutStep;
		if(m_fadeOut > 0)
		{
			m_envelope[i] = m_fadeOut;
		}
		else
		{
			m_envelope[i] = 0.0f;
		}
	}

	m_envelope[Release - 2] = 0.0f;
	m_envelope[Release - 1] = 0.0f;

	return m_envelope;
}
