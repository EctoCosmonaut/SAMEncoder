#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "same.h"

int main( int argc, char *argv[] )
{
	sameMsg_t msg;
	SNDFILE *wav;
	SF_INFO info;

	//TODO: Write proper command line processing
	info.channels = 1;
	info.format = SF_FORMAT_WAV | SF_FORMAT_PCM_16;
	info.samplerate = S_RATE;

	wav = sf_open( "same.wav", SFM_WRITE, &info );
	puts( sf_strerror( wav ) );

	strcpy_s( msg.callsign, sizeof( msg.callsign ), "KMBC/TV" );
	msg.event = EV_NUW;
	msg.iTime.d = 360;
	msg.iTime.h = 12;
	msg.iTime.m = 0;
	msg.pTime.h = 1;
	msg.pTime.m = 0;
	msg.loc[0].all = false;
	msg.loc[0].county = 95;
	msg.loc[0].state = 29;
	msg.loc_num = 1;
	msg.org = ORG_PEP;

	generateMsg( &msg, wav );

	sf_close( wav );
}
