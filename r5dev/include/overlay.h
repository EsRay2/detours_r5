#pragma once
#include "imgui.h"

/////////////////////////////////////////////////////////////////////////////
// Initialization
void PrintDXAddress();
void InstallDXHooks();
void RemoveDXHooks();
void ShowGameConsole(bool* p_open);

/////////////////////////////////////////////////////////////////////////////
// Internals
int Stricmp(const char* s1, const char* s2);
int Strnicmp(const char* s1, const char* s2, int n);
char* Strdup(const char* s);
void  Strtrim(char* s);

/////////////////////////////////////////////////////////////////////////////
// Globals
inline ImVector<char*>       Items;

/////////////////////////////////////////////////////////////////////////////