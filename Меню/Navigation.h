#pragma once
#include "General.h"

extern std::string empty_str;

void SetVisualCursor(std::string& toMoveOn, std::string& toMoveFrom);

void DrawMenu(const std::vector<paragraph>& screen);

void Navigate(std::vector<paragraph>& screen);