#ifndef STRINGS_H
#define STRINGS_H

#include "same.h"

/*** TYPES ***/
typedef struct {
	state_t state;
	char   *abbr;
} state_tbl_row;


/*** STRINGS ***/
char *event_strs[] = {
	"ADR", /* administrative message                */
	"ADA", /* avalanche watch                       */
	"AVW", /* avalanche warning                     */
	"BZW", /* blizzard warning                      */
	"CAE", /* child abduction emergency             */
	"CDW", /* civil danger warning                  */
	"CEM", /* civil emergency message               */
	"CFA", /* coastal flood watch                   */
	"CFW", /* costal flood warning                  */
	"DMO", /* demonstration message                 */
	"DSW", /* dust storm warning                    */
	"EAN", /* emergency action notification         */
	"EAT", /* emergency action termination          */
	"EQW", /* earthquake warning                    */
	"FFA", /* flash flood watch                     */
	"FFS", /* flash flood statement                 */
	"FFW", /* flash flood warning                   */
	"FLA", /* flood watch                           */
	"FLS", /* flood statement                       */
	"FLW", /* flood warning                         */
	"FRW", /* fire warning                          */
	"FSW", /* flash freeze warning                  */
	"FZW", /* freeze warning                        */
	"HLS", /* hurricane local statement             */
	"HMW", /* hazardous materials warning           */
	"HUA", /* hurricane watch                       */
	"HUW", /* hurricane warning                     */
	"HWA", /* high wind watch                       */
	"HWW", /* high wind warning                     */
	"LAE", /* local area emergency                  */
	"LEW", /* law enforcement warning               */
	"NAT", /* national audible test                 */
	"NIC", /* national information center statement */
	"NMN", /* network message notification          */
	"NPT", /* national periodic test                */
	"NST", /* national silent test                  */
	"NUW", /* nuclear power plant warning           */
	"RHW", /* radiological hazard warning           */
	"RMT", /* required monthly test                 */
	"RWT", /* required weekly test                  */
	"SMW", /* special marine warning                */
	"SPS", /* special weather statement             */
	"SPW", /* shelter in-place warning              */
	"SVA", /* severe thunderstorm watch             */
	"SVR", /* severe thunderstorm warning           */
	"SVS", /* severe weather statement              */
	"TOA", /* tornado watch                         */
	"TOR", /* tornado warning                       */
	"TRA", /* tropical storm watch                  */
	"TRW", /* tropical storm warning                */
	"TSA", /* tsunami watch                         */
	"TSW", /* tsunami warning                       */
	"VOW", /* volcano warning                       */
	"WSA", /* winter storm watch                    */
	"WSW"  /* winter storm warning                  */
};

char *org_strs[] = {
	"PEP", /* primary entry point station           */
	"CIV", /* civil authority                       */
	"WXR", /* national weather service              */
	"EAS", /* emergency alert system participant    */
	"EAN"  /* emergency action notification network */
};

state_tbl_row state_tbl[] = {
	{ ST_AK, "AK" },
	{ ST_AL, "AL" },
	{ ST_AR, "AR" },
	{ ST_AS, "AS" },
	{ ST_AZ, "AZ" },
	{ ST_CA, "CA" },
	{ ST_CO, "CO" },
	{ ST_CT, "CT" },
	{ ST_DC, "DC" },
	{ ST_DE, "DE" },
	{ ST_FL, "FL" },
	{ ST_GA, "GA" },
	{ ST_GU, "GU" },
	{ ST_HI, "HI" },
	{ ST_IA, "IA" },
	{ ST_ID, "ID" },
	{ ST_IL, "IL" },
	{ ST_IN, "IN" },
	{ ST_KS, "KS" },
	{ ST_KY, "KY" },
	{ ST_LA, "LA" },
	{ ST_MA, "MA" },
	{ ST_MD, "MD" },
	{ ST_ME, "ME" },
	{ ST_MI, "MI" },
	{ ST_MN, "MN" },
	{ ST_MO, "MO" },
	{ ST_MS, "MS" },
	{ ST_MT, "MT" },
	{ ST_NC, "NC" },
	{ ST_ND, "ND" },
	{ ST_NE, "NE" },
	{ ST_NH, "NH" },
	{ ST_NJ, "NJ" },
	{ ST_NM, "NM" },
	{ ST_NV, "NV" },
	{ ST_NY, "NY" },
	{ ST_OH, "OH" },
	{ ST_OK, "OK" },
	{ ST_OR, "OR" },
	{ ST_PA, "PA" },
	{ ST_PR, "PR" },
	{ ST_RI, "RI" },
	{ ST_SC, "SC" },
	{ ST_SD, "SD" },
	{ ST_TN, "TN" },
	{ ST_TX, "TX" },
	{ ST_UT, "UT" },
	{ ST_VA, "VA" },
	{ ST_VI, "VI" },
	{ ST_VT, "VT" },
	{ ST_WA, "WA" },
	{ ST_WI, "WI" },
	{ ST_WV, "WV" },
	{ ST_WY, "WY" }
};

#endif
