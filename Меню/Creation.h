#pragma once
#include "General.h"

void CreateMainMenu(const std::string menuName, void (*function)() = nullptr);

void CreateSubMenu(const int indexOfMain, const std::string menuName, void (*function)());