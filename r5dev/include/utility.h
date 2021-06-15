#pragma once
#include <Windows.h>
#include <Psapi.h>

BOOL FileExists(LPCTSTR szPath);
MODULEINFO GetModuleInfo(const char* szModule);
DWORD64 FindPattern(const char* szModule, const unsigned char* szPattern, const char* szMask);

void DbgPrint(LPCSTR sFormat, ...);
void HexDump(const char* szHeader, const char* szFile, const char* szMode, int nFunc, const void* pData, int nSize);