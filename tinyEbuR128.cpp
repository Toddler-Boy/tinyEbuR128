#include "tinyEbuR128.h"

#include <cstdlib>

//-----------------------------------------------------------------------------

tinyEbuR128::~tinyEbuR128 ()
{
	if ( sts == nullptr )
		return;

	ebur128_destroy ( &sts );
}
//-----------------------------------------------------------------------------

void tinyEbuR128::init ( const int numChannels, const int sampleRate )
{
    sts = ebur128_init ( numChannels, sampleRate, EBUR128_MODE_I );

    if ( numChannels == 2 )
    {
        ebur128_set_channel ( sts, 0, EBUR128_LEFT );
        ebur128_set_channel ( sts, 1, EBUR128_RIGHT );
    }
    else
    {
        ebur128_set_channel ( sts, 0, EBUR128_CENTER );
    }
}
//-----------------------------------------------------------------------------

void tinyEbuR128::process ( const float* input, const int numFrames )
{
	ebur128_add_frames_float ( sts, input, numFrames );
}
//-----------------------------------------------------------------------------

double tinyEbuR128::getLoudnessIntegrated () const
{
	double  loudness = 0.0;
	ebur128_loudness_global ( sts, &loudness );

    return loudness;
}
//-----------------------------------------------------------------------------

double tinyEbuR128::getLoudnessShortTerm () const
{
    double  loudness = 0.0;
    ebur128_loudness_shortterm ( sts, &loudness );

    return loudness;
}
//-----------------------------------------------------------------------------

double tinyEbuR128::getLoudnessMomentary () const
{
    double  loudness = 0.0;
    ebur128_loudness_momentary ( sts, &loudness );

    return loudness;
}
//-----------------------------------------------------------------------------
