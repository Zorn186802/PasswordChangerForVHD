#ifndef __PCFVHD_H__
#define __PCFVHD_H__

/* --- INCLUDES ------------------------------------------------------------- */
#include <tchar.h>
#include <windows.h>
#include "../Utils/getopt.h"
#include "../Utils/LibRegistry/LibRegistry.h"

/* --- DEFINES -------------------------------------------------------------- */

/* --- TYPES ---------------------------------------------------------------- */

typedef struct _PCFVHD_OPTIONS {
    PTCHAR ptDriveLetter;
    PTCHAR ptLogin;
    PTCHAR ptPassword;
} PCFVHD_OPTIONS, *PPCFVHD_OPTIONS;

#endif