#pragma once

#include "libebur128/ebur128.h"

//-----------------------------------------------------------------------------

class tinyEbuR128
{
public:
	tinyEbuR128 () = default;
	virtual ~tinyEbuR128 ();

	void init ( const int numChannels, const int sampleRate );
	void process ( const float* input, const int numFrames );
	[[ nodiscard ]] double getLoudnessIntegrated () const;
	[[ nodiscard ]] double getLoudnessShortTerm () const;
	[[ nodiscard ]] double getLoudnessMomentary () const;

private:
	ebur128_state*	sts = nullptr;
};
//-----------------------------------------------------------------------------
