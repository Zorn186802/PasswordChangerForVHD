/* --- INCLUDES ------------------------------------------------------------- */
#include "PasswordChangerForVHD.h"

/* --- PRIVATE VARIABLES ---------------------------------------------------- */
static PCFVHD_OPTIONS gs_sOptions = { 0 };

/* --- PUBLIC VARIABLES ----------------------------------------------------- */

/* --- PRIVATE FUNCTIONS ---------------------------------------------------- */
__declspec(noreturn) static void PCFVHDUsage(
    _In_ const PTCHAR ptProgName,
    _In_opt_ const PTCHAR ptMsg
    )
{
    if (ptMsg != NULL)
    {
        _tprintf_s(_T("Error: "));
        _tprintf_s(_T("%s"), ptMsg);
    }

    _tprintf_s(_T("Usage: "));
    _tprintf_s(_T("%s -d <drive letter> -u <username> -p <password>\r\n"), ptProgName);

    ExitProcess(EXIT_FAILURE);
}

static void PCFVHDParseOptions(
    _In_ const PPCFVHD_OPTIONS pOpt,
    _In_ const INT argc,
    _In_ const PTCHAR argv[]
) {
    INT curropt = 0;

    while ((curropt = getopt(argc, argv, _T("d:u:p:"))) != -1)
    {
        switch (curropt)
        {
            case _T('d'):
                pOpt->ptDriveLetter = optarg;
                break;
            case _T('u'):
                pOpt->ptLogin = optarg;
                break;
            case _T('p'):
                pOpt->ptPassword = optarg;
                break;

            default:
                ExitProcess(EXIT_FAILURE);
        }
    }

    if (pOpt->ptDriveLetter == NULL)
    {
        PCFVHDUsage(argv[0], const_cast<PTCHAR> (_T(" drive letter is mandatory.\r\n")));
    }

    if (pOpt->ptLogin == NULL)
    {
        PCFVHDUsage(argv[0], const_cast<PTCHAR> (_T(" login is mandatory.\r\n")));
    }

    if (pOpt->ptPassword == NULL)
    {
        PCFVHDUsage(argv[0], const_cast<PTCHAR> (_T(" password is mandatory.\r\n")));
    }
}

INT _tmain(
    _In_ const INT argc,
    _In_ const PTCHAR argv[]
    )
 {

    // Option
    if (argc == 1) {
        PCFVHDUsage(argv[0], NULL);
    }

    PCFVHDParseOptions(&gs_sOptions, argc, argv);

    return EXIT_SUCCESS;
}