#include <stdbool.h>
#include <stdint.h>
#include <string.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "same.h"
#include "strings.h"

/*** MACROS ***/
#define BIT_MS      1.92
#define FRAME_MS    ( 1000.0 / S_RATE )
#define VOLUME      0.75
#define W_PEAK      ( INT16_MAX * VOLUME )
#define ONE_FREQ    ( ( 2.0 * M_PI * 4.0 ) / BIT_MS )
#define ZERO_FREQ   ( ( 2.0 * M_PI * 3.0 ) / BIT_MS )

/*** PROTOTYPES ***/
void genBit( SNDFILE *wav, bool b );
void genByte( SNDFILE *wav, uint8_t b );
void genPreamble( SNDFILE *wav );
void genQuiet( SNDFILE *wav, double ms );
void genTail( SNDFILE *wav );

/*** FUNCTIONS ***/
void generateMsg( const sameMsg_t *msg, SNDFILE *wav )
{
	char    msgTxt[250];
	char    temp[30];
	int8_t  i;
	int8_t  j;

	sprintf_s( msgTxt, sizeof( msgTxt ), "ZCZC-%s-%s", org_strs[msg->org], event_strs[msg->event] );

	/* append locations */
	for( i = 0; i < msg->loc_num; ++i ) {
		sprintf_s( temp, sizeof( temp ), "-%01u%02u%03u", msg->loc[i].all, msg->loc[i].state, msg->loc[i].county );
		strcat_s( msgTxt, sizeof( msgTxt ), temp );
	}

	sprintf_s( temp, sizeof( temp ), "+%02u%02u-%03u%02u%02u-%s-", msg->pTime.h, msg->pTime.m, msg->iTime.d, msg->iTime.h, msg->pTime.m, msg->callsign );
	strcat_s( msgTxt, sizeof( msgTxt ), temp );

	genQuiet( wav, 1000.0 );

	for( i = 0; i < 3; ++i ) {
		genPreamble( wav );
		for( j = 0; j < sizeof( msgTxt ); ++j ) {
			if( msgTxt[j] == '\0' ) {
				break;
			}

			genByte( wav, msgTxt[j] );
		}

		genQuiet( wav, 1000.0 );
	}

	//TODO: Make EOM signal optional
	for( i = 0; i < 3; ++i ) {
		genTail( wav );
		genQuiet( wav, 1000.0 );
	}
}

void genBit( SNDFILE *wav, bool b )
{
	int16_t frame;
	double  freq;
	double  t;

	freq = b ? ONE_FREQ : ZERO_FREQ;
	for( t = 0.0; t < BIT_MS; t += FRAME_MS ) {
		frame = (int16_t)( W_PEAK * sin( freq * t ) );
		sf_writef_short( wav, &frame, 1 );
	}
}

void genByte( SNDFILE *wav, uint8_t b )
{
	uint8_t i;

	for( i = 0; i < sizeof( b ) * 8; ++i ) {
		genBit( wav, ( b & 1 ) );
		b >>= 1;
	}
}

void genPreamble( SNDFILE *wav )
{
	const uint8_t preamble = 0xAB;
	uint8_t i;

	for( i = 0; i < 16; ++i ) {
		genByte( wav, preamble );
	}
}

void genQuiet( SNDFILE *wav, double ms )
{
    double  t;
    int16_t frame;

    frame = 0;
    for( t = 0.0; t < ms; t += FRAME_MS ) {
		sf_writef_short( wav, &frame, 1 );
    }
}

void genTail( SNDFILE *wav )
{
    uint8_t i;

    genPreamble( wav );
    for( i = 0; i < 4; ++i ) {
        genByte( wav, 'N' );
    }
}
