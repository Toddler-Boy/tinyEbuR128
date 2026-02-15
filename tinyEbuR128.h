#pragma once

#include <vector>

#include "libebur128/ebur128.h"

//-----------------------------------------------------------------------------

class tinyEbuR128
{
public:
	tinyEbuR128 () = default;
	virtual ~tinyEbuR128 ();

	void init ( const int numChannels, const int sampleRate );
	void process ( const float* input, const int numSamples );
	void process ( const float* inputL, const float* inputR, const int numFrames );
	[[ nodiscard ]] double getLoudnessIntegrated () const;
	[[ nodiscard ]] double getLoudnessShortTerm () const;
	[[ nodiscard ]] double getLoudnessMomentary () const;

private:
	ebur128_state*		sts = nullptr;
	std::vector<float>	interleaveBuffer;
};
//-----------------------------------------------------------------------------
