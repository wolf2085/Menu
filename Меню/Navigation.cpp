#include "Navigation.h"

extern const short posXStart = 25; //
extern const short posYStart = 10; //10
extern HANDLE con = GetStdHandle(STD_OUTPUT_HANDLE); // 
extern std::string empty_str = "";

void SetVisualCursor(std::string& toMoveOn, std::string& toMoveFrom = empty_str)
{
    toMoveOn.insert(toMoveOn.begin(), '*');
    toMoveOn.insert(toMoveOn.end(), '*');

    if (toMoveFrom != "")
    {
        toMoveFrom.erase(toMoveFrom.begin());
        toMoveFrom.erase(toMoveFrom.end() - 1);
    }
}

void DrawMenu(const std::vector<paragraph>& screen)
{
    system("cls");
    for (paragraph p : screen)
    {
        SetConsoleCursorPosition(con, { posXStart, p.posY });
        std::cout << p.name;
    }
}

void Navigate(std::vector<paragraph>& screen)
{
    std::vector<paragraph> currentScreen = screen;

    SetVisualCursor(currentScreen[0].name);
    DrawMenu(currentScreen);

    Sleep(500u);

    short currentParagraph = 0;
    while (true)
    {
        if (GetAsyncKeyState(VK_DOWN))
        {
            if (currentParagraph == currentScreen.size() - 1)
            {
                SetVisualCursor(currentScreen[0].name, currentScreen[currentParagraph].name);
                currentParagraph = 0;
            }
            else
            {
                SetVisualCursor(currentScreen[currentParagraph + 1].name, currentScreen[currentParagraph].name);
                currentParagraph++;
            }

            DrawMenu(currentScreen);

            Sleep(500u);
        }
        else if (GetAsyncKeyState(VK_UP))
        {
            if (currentParagraph == 0)
            {
                SetVisualCursor(currentScreen[currentScreen.size() - 1].name, currentScreen[currentParagraph].name);
                currentParagraph = currentScreen.size() - 1;
            }
            else
            {
                SetVisualCursor(currentScreen[currentParagraph - 1].name, currentScreen[currentParagraph].name);
                currentParagraph--;
            }

            DrawMenu(currentScreen);

            Sleep(500u);
        }
        else if (GetAsyncKeyState(VK_RETURN))
        {
            if (currentScreen[currentParagraph].function != nullptr)
            {
                currentScreen[currentParagraph].function();
            }
            else
            {

                currentScreen[currentParagraph].name.erase(currentScreen[currentParagraph].name.begin()); // удалаяем *
                currentScreen[currentParagraph].name.erase(currentScreen[currentParagraph].name.end() - 1);

                if (currentScreen[currentParagraph].name == "Вернуться назад")
                {
                    auto goBack = currentScreen[currentParagraph].sub;
                    currentScreen.pop_back();
                    currentScreen = std::vector<paragraph>(goBack);
                }
                else
                {
                    auto goBack = paragraph{ posYStart + (short)currentScreen[currentParagraph].sub.size(), "Вернуться назад" };
                    goBack.sub = std::vector<paragraph>(currentScreen);

                    currentScreen = std::vector<paragraph>(currentScreen[currentParagraph].sub);
                    currentScreen.push_back(goBack);
                }

                SetVisualCursor(currentScreen[0].name);
                DrawMenu(currentScreen);

                currentParagraph = 0;
            }

            Sleep(500u);
        }
    }

}