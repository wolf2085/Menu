#include "ParagraphFunctionality.h"

void OpenSiteVK()
{
    ShellExecute(NULL, L"open", L"http://www.vk.com", NULL, NULL, SW_SHOW);
}

void OpenSiteYT()
{
    ShellExecute(NULL, L"open", L"http://www.youtube.com", NULL, NULL, SW_SHOW);
}

void OpenSiteCF()
{
    ShellExecute(NULL, L"open", L"http://www.cyberforum.ru", NULL, NULL, SW_SHOW);
}

void OpenCalc()
{
    system("calc");
}

void OpenExplorer()
{
    ShellExecute(NULL, L"open", L"C://windows//explorer.exe", NULL, NULL, SW_SHOW);
}

void OpenPaint()
{
    ShellExecute(NULL, L"open", L"mspaint.exe", NULL, NULL, SW_SHOW);
}

void PrintSystemTime()
{
    char buffer[32];
    time_t raw;
    struct tm timeinfo;

    errno_t possible_error;
    time(&raw);
    raw = localtime_s(&timeinfo, &raw);
    possible_error = asctime_s(buffer, 32, &timeinfo);

    SetConsoleCursorPosition(con, { posXStart * 2, posYStart * 2 });
    std::cout << buffer;
    SetConsoleCursorPosition(con, { posXStart * 2, posYStart * 2 + 1 });
    std::cout << "Âנולÿ נאבמעû ןנמדנאללû: " << clock() / 1000.0;
}