#include "Creation.h"

std::vector<paragraph> paragraphMain;

void CreateMainMenu(const std::string menuName, void (*function)())
{
    short posY;

    if (paragraphMain.size() < 1)
        posY = posYStart;
    else
        posY = paragraphMain[paragraphMain.size() - 1].posY + 1;

    paragraphMain.push_back(paragraph{ posY, menuName, function });
}

void CreateSubMenu(const int indexOfMain, const std::string menuName, void (*function)())
{
    short posY;
    if (paragraphMain[indexOfMain].sub.size() < 1)
        posY = posYStart;
    else
    {
        posY = paragraphMain[indexOfMain].sub[paragraphMain[indexOfMain].sub.size() - 1].posY + 1;
    }

    paragraphMain[indexOfMain].sub.push_back(paragraph{ posY, menuName, function });
}