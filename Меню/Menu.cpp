#include "Association.h"

int main()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(con, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(con, &cursorInfo);
    
    setlocale(LC_ALL, "Rus");
    
    CreateMainMenu("Открыть сайт");
    
    CreateSubMenu(0, "VK", OpenSiteVK);
    CreateSubMenu(0, "YT", OpenSiteYT);
    CreateSubMenu(0, "CyberForum", OpenSiteCF);

    CreateMainMenu("Открыть приложение");
    CreateSubMenu(1, "Кальуклятор", OpenCalc);
    CreateSubMenu(1, "Проводник", OpenExplorer);
    CreateSubMenu(1, "Paint", OpenPaint);

    CreateMainMenu("Время", PrintSystemTime);


    
    Navigate(paragraphMain);
}

