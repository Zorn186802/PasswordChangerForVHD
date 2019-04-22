/* --- INCLUDES ------------------------------------------------------------- */
#include "LibRegistry.h"

/* --- PRIVATE VARIABLES ---------------------------------------------------- */
/* --- PUBLIC VARIABLES ----------------------------------------------------- */
/* --- PRIVATE FUNCTIONS ---------------------------------------------------- */

/* --- PUBLIC FUNCTIONS ----------------------------------------------------- */

INT OpenHive(
    void
)
{
    return 42;
}

BOOL WINAPI DllMain(
    _In_  HINSTANCE hinstDLL,
    _In_  DWORD fdwReason,
    _In_  LPVOID lpvReserved
    )
{
    BOOL bResult = FALSE;

    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
        default:
            bResult = TRUE;
            break;
    }
    return TRUE;
}