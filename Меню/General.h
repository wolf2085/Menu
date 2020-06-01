#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <ctime>

struct paragraph
{
    short posY;
    std::string name;
    void(*function)() = nullptr;
    std::vector<paragraph> sub;
};

extern const short posXStart; //
extern const short posYStart; //10
extern std::vector<paragraph> paragraphMain;
extern HANDLE con; // = GetStdHandle(STD_OUTPUT_HANDLE)