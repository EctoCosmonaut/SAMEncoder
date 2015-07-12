#ifndef SAME_H
#define SAME_H

#include <sndfile.h>
#include <stdbool.h>
#include <stdint.h>

/*** MACROS ***/
#define CALL_LEN    8
#define MAX_LOC     31
#define S_RATE      44100

/*** TYPES ***/
typedef enum {
	EV_ADR, /* administrative message                   */
	EV_ADA, /* avalanche watch                          */
	EV_AVW, /* avalanche warning                        */
	EV_BZW, /* blizzard warning                         */
	EV_CAE, /* child abduction emergency                */
	EV_CDW, /* civil danger warning                     */
	EV_CEM, /* civil emergency message                  */
	EV_CFA, /* coastal flood watch                      */
	EV_CFW, /* costal flood warning                     */
	EV_DMO, /* demonstration message                    */
	EV_DSW, /* dust storm warning                       */
	EV_EAN, /* emergency action notification            */
	EV_EAT, /* emergency action termination             */
	EV_EQW, /* earthquake warning                       */
	EV_FFA, /* flash flood watch                        */
	EV_FFS, /* flash flood statement                    */
	EV_FFW, /* flash flood warning                      */
	EV_FLA, /* flood watch                              */
	EV_FLS, /* flood statement                          */
	EV_FLW, /* flood warning                            */
	EV_FRW, /* fire warning                             */
	EV_FSW, /* flash freeze warning                     */
	EV_FZW, /* freeze warning                           */
	EV_HLS, /* hurricane local statement                */
	EV_HMW, /* hazardous materials warning              */
	EV_HUA, /* hurricane watch                          */
	EV_HUW, /* hurricane warning                        */
	EV_HWA, /* high wind watch                          */
	EV_HWW, /* high wind warning                        */
	EV_LAE, /* local area emergency                     */
	EV_LEW, /* law enforcement warning                  */
	EV_NAT, /* national audible test                    */
	EV_NIC, /* national information center statement    */
	EV_NMN, /* network message notification             */
	EV_NPT, /* national periodic test                   */
	EV_NST, /* national silent test                     */
	EV_NUW, /* nuclear power plant warning              */
	EV_RHW, /* radiological hazard warning              */
	EV_RMT, /* required monthly test                    */
	EV_RWT, /* required weekly test                     */
	EV_SMW, /* special marine warning                   */
	EV_SPS, /* special weather statement                */
	EV_SPW, /* shelter in-place warning                 */
	EV_SVA, /* severe thunderstorm watch                */
	EV_SVR, /* severe thunderstorm warning              */
	EV_SVS, /* severe weather statement                 */
	EV_TOA, /* tornado watch                            */
	EV_TOR, /* tornado warning                          */
	EV_TRA, /* tropical storm watch                     */
	EV_TRW, /* tropical storm warning                   */
	EV_TSA, /* tsunami watch                            */
	EV_TSW, /* tsunami warning                          */
	EV_VOW, /* volcano warning                          */
	EV_WSA, /* winter storm watch                       */
	EV_WSW  /* winter storm warning                     */
} event_t;

typedef enum {
	ORG_PEP, /* primary entry point station             */
	ORG_CIV, /* civil authority                         */
	ORG_WXR, /* national weather service                */
	ORG_EAS, /* emergency alert system participant      */
	ORG_EAN  /* emergency action notification network   */
} org_t;

typedef enum {
	ST_AK = 2,  /* Alaska               */
	ST_AL = 1,  /* Alabama              */
	ST_AR = 5,  /* Arkansas             */
	ST_AS = 60, /* American Samoa       */
	ST_AZ = 4,  /* Arizona              */
	ST_CA = 6,  /* California           */
	ST_CO = 8,  /* Colorado             */
	ST_CT = 9,  /* Connecticut          */
	ST_DC = 11, /* District of Columbia */
	ST_DE = 10, /* Delaware             */
	ST_FL = 12, /* Florida              */
	ST_GA = 13, /* Georgia              */
	ST_GU = 66, /* Guam                 */
	ST_HI = 15, /* Hawaii               */
	ST_IA = 19, /* Iowa                 */
	ST_ID = 16, /* Idaho                */
	ST_IL = 17, /* Illinois             */
	ST_IN = 18, /* Indiana              */
	ST_KS = 20, /* Kansas               */
	ST_KY = 21, /* Kentucky             */
	ST_LA = 22, /* Louisiana            */
	ST_MA = 25, /* Massachusetts        */
	ST_MD = 24, /* Maryland             */
	ST_ME = 23, /* Maine                */
	ST_MI = 26, /* Michigan             */
	ST_MN = 27, /* Minnesota            */
	ST_MO = 29, /* Missouri             */
	ST_MS = 28, /* Mississippi          */
	ST_MT = 30, /* Montana              */
	ST_NC = 37, /* North Carolina       */
	ST_ND = 38, /* North Dakota         */
	ST_NE = 31, /* Nebraska             */
	ST_NH = 33, /* New Hampshire        */
	ST_NJ = 34, /* New Jersey           */
	ST_NM = 35, /* New Mexico           */
	ST_NV = 32, /* Nevada               */
	ST_NY = 36, /* New York             */
	ST_OH = 39, /* Ohio                 */
	ST_OK = 40, /* Oklahoma             */
	ST_OR = 41, /* Oregon               */
	ST_PA = 42, /* Pennsylvania         */
	ST_PR = 72, /* Puerto Rico          */
	ST_RI = 44, /* Rhode Island         */
	ST_SC = 45, /* South Carolina       */
	ST_SD = 46, /* South Dakota         */
	ST_TN = 47, /* Tennessee            */
	ST_TX = 48, /* Texas                */
	ST_UT = 49, /* Utah                 */
	ST_VA = 51, /* Virginia             */
	ST_VI = 78, /* Virgin Islands       */
	ST_VT = 50, /* Vermont              */
	ST_WA = 53, /* Washington           */
	ST_WI = 55, /* Wisconsin            */
	ST_WV = 54, /* West Virginia        */
	ST_WY = 56, /* Wyoming              */
} state_t;

typedef struct {
	bool        all;                    /* entire county?       */
	state_t     state;                  /* state code           */
	uint16_t    county;                 /* county code          */
} loc_t;

typedef struct {
	uint8_t     h;                      /* hours                */
	uint8_t     m;                      /* minutes              */
} purgeTime_t;

typedef struct {
	uint16_t    d;                      /* day (ordinal)        */
	uint8_t     h;                      /* hours                */
	uint8_t     m;                      /* minutes              */
} issueTime_t;

typedef struct {
	org_t       org;                    /* originator code      */
	event_t     event;                  /* event code           */
	uint8_t     loc_num;                /* number of locations  */
	loc_t       loc[MAX_LOC];           /* location codes       */
	purgeTime_t pTime;                  /* purge time (HHMM)    */
	issueTime_t iTime;                  /* issue time (DDDHHMM) */
	char        callsign[CALL_LEN + 1]; /* TX station callsign  */
} sameMsg_t;

/*** PROTOTYPES ***/
void generateMsg( const sameMsg_t *msg, SNDFILE *wav );

bool processArgs( int argc, char *argv[], sameMsg_t *msg );

#endif
