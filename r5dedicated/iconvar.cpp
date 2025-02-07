#include "pch.h"
#include "hooks.h"

//-----------------------------------------------------------------------------
// Purpose: test each ConVar query before setting the cvar
// Input  : **cvar - flag
// Output : true if change is not permitted, false if permitted
//-----------------------------------------------------------------------------

bool Hooks::ConVar_IsFlagSet(int** cvar, int flag)
{
	int real_flags = *(*(cvar + (72 / (sizeof(void*)))) + (56 / sizeof(int)));
	if (g_bDebugConsole)
	{
		printf("--------------------------------------------------\n");
		printf(" Flaged: %08X\n", real_flags);
	}
	// Mask off FCVAR_CHEATS and FCVAR_DEVELOPMENTONLY
	real_flags &= 0xFFFFBFFD;
	if (g_bDebugConsole)
	{
		printf(" Masked: %08X\n", real_flags);
		printf(" Verify: %08X\n", flag);
		printf("--------------------------------------------------\n");
	}
	if (flag & 0x80000) { return true; }

	if (!g_bReturnAllFalse)
	{
		return (real_flags & flag) != 0;
	}
	else
	{
		return false;
	}
}

//-----------------------------------------------------------------------------
// Purpose: test each ConCommand query before execution
// Input  : *cmd - flag
// Output : true if execution is not permitted, false if permitted
//-----------------------------------------------------------------------------

bool Hooks::ConCommand_IsFlagSet(int* cmd, int flag)
{
	int real_flags = *((cmd + (56 / sizeof(int))));
	if (g_bDebugConsole)
	{
		printf("--------------------------------------------------\n");
		printf(" Flaged: %08X\n", real_flags);
	}
	// Mask off FCVAR_CHEATS and FCVAR_DEVELOPMENTONLY
	real_flags &= 0xFFFFBFFD;
	if (g_bDebugConsole)
	{
		printf(" Masked: %08X\n", real_flags);
		printf(" Verify: %08X\n", flag);
		printf("--------------------------------------------------\n");
	}
	if (flag & 0x80000) { return true; }

	if (!g_bReturnAllFalse)
	{
		return(real_flags & flag) != 0;
	}
	else
	{
		return false;
	}
}