// Delete this line if you don't use precompiled header in your project
#include "stdafx.h"

#include <CrashRpt.h>

/*
   +-------------------------------------------------+
   | @ {AppName}                                   X |
   +-------------------------------------------------+
   |                                                 |
   | {AppName} has stopped working                   |
   |                                                 |
   | Sending collected information to the {Company}. |
   | This might take several minutes...   +--------+ |
   |                                      | Cancel | |
   |                                      +--------+ |
   +-------------------------------------------------+
*/

// global crash handler
crash_rpt::CrashRpt g_crashRpt(
	"1235D7D1-DD7D-4FDC-9C28-32FF7E7BBC66", // GUID assigned to this application.
	L"test", // Application name that will be used in a message box.
	L"test" // Company name that will be used in a message box.
	);