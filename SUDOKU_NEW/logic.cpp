#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "panel.h"
#include "grid.h"
#include "gameView.h"
#include "gameOver.h"

using namespace std;
using namespace sf;

long long mistakes = 0;

/*bool isPanelActive(Grid &grid, RenderWindow &window, Panel &panel, int x, int y, int n)
{
    Vector2i localPosition = Mouse::getPosition(window);
    Vector2f pos = window.mapPixelToCoords(localPosition);

}*/

void setActive(RenderWindow &window, vector<uT> &userText, Panel &panel)
{
    Vector2i localPosition = Mouse::getPosition(window);
    Vector2f pos = window.mapPixelToCoords(localPosition);

    int t = -1;

    bool isClickOnField = false;

    for (int i = 0; i < userText.size(); i++)
    {
        if (userText[i].sprite.getGlobalBounds().contains(pos.x, pos.y))
        {
            isClickOnField = true;

            userText[i].isActive = true;
            userText[i].texture.loadFromFile("Pic/cellCnr.png");
            t = i;

            panel.drawable = true;

            if (panel.coordX != i / 9 || panel.coordY != i % 9)
            {
                if (userText[i].readOnly)
                {
                    panel.drawable = false;
                }
            }

            if (panel.drawable)
            {
                panel.coordX = i / 9;
                panel.coordY = i % 9;
            }

            break;
        }
    }

    if (!isClickOnField)
    {
        panel.drawable = false;
    }

    for (int i = 0; i < userText.size(); i++)
    {
        if (i != t)
        {
            userText[i].isActive = false;
            userText[i].texture.loadFromFile("Pic/cell0.png");
        }
    }
}

void cleanText(RenderWindow &window, vector<uT> &userText, Grid &grid)
{
    for (int i = 0; i < userText.size(); i++)
    {
        if (userText[i].isActive)
        {
            if (userText[i].s.empty() == false && grid.isCellReadonly(i) == true)
            {
                userText[i].s.pop_back();
                grid.table[i] = 0;
            }
        }
    }
}

void writeText(RenderWindow &window, vector<uT> &userText, int code, Grid &grid, int typeGame)
{
    //Vector2i localPosition = Mouse::getPosition(window);
    //Vector2f pos = window.mapPixelToCoords(localPosition);

    for (int i = 0; i < userText.size(); i++)
    {
        if (grid.table[i] == 0)
        {
            if (userText[i].isActive)
            {
                if (code >= 26 && code <= 35)
                {   
                    if (userText[i].s.empty())
                    {
                        userText[i].s += char(code + 22);
                        grid.table[i] = code - 26;
                    }
                }
            }
        }
        else
        {
            userText[i].s = to_string(grid.table[i]);
            if (!grid.isCellReadonly(i))
            {
                userText[i].text.setFillColor(Color(48, 63, 159));
                userText[i].readOnly = true;
            }
        }
    }
}

int panelClick(RenderWindow &window, Panel &panel, vector<uT> &userText, Grid &grid, int keyCode, int m, int typeGame)
{
    Vector2i localPosition = Mouse::getPosition(window);
    Vector2f pos = window.mapPixelToCoords(localPosition);

    int point = panel.click(pos.x, pos.y);

    if (point != 0)
    {
        cleanText(window, userText, grid);
        writeText(window, userText, point + 26, grid, typeGame);
    }

    return point;
}

bool askContinuePlay(int keyCode)
{
    //cout << keyCode << endl;
    if (keyCode == 24)
        return false;
    if (keyCode == 2)
        return true;
}

void keyPressedHandler(RenderWindow &window, vector<uT> &userText, Grid &grid, int keyCode, int m, int typeGame)
{
    //cout << keyCode << endl;
    if (keyCode == 59) //backspace
    {
        cleanText(window, userText, grid);
        return;
    }

    writeText(window, userText, keyCode, grid, typeGame);
}

Grid createNewGame(int size, int level, int typeGame)
{
    Grid grid(size);
    grid.mix();
    grid.show();
    grid.del(level);
    grid.show();
    return grid;
}

bool isGameFinished(Grid &grid, int mistakes, int typegame)
{
    return (grid.isGameWon(typegame) || mistakes >= 5);
}

int main()
{
    RenderWindow window(VideoMode(800, 600), "SUDOKU", 4);

    int diffic = 40;

    int m = 3;
    bool continuePlay = true;

    /*double a,b;
    //cout <<"MAX "<< a<<" "<<b << endl;*/

    while (continuePlay)
    {
        bool t;
        mistakes = 0;
        int typegame = 2;
        //type 1 - проверка каждого хода
        //tyoe 2 - проверка только конечного поля

        Grid grid = createNewGame(m, diffic, typegame);
        Panel panel(window);
        GameView gameView(m, window);
        int fl = 0;
        while (window.isOpen() && fl != 2)
        {
            Event event;
            while (window.pollEvent(event))
            {

                if (event.type == Event::Closed)
                {
                    window.close();
                    continuePlay = false;
                }

                if (event.type == Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        int isOnPanel = 0;
                        if (panel.drawable)
                        {
                            isOnPanel = panelClick(window, panel, gameView.userText, grid, event.key.code, m, typegame);
                        }

                        //cout << "PP " << isOnPanel << endl;
                        if (!isOnPanel)
                        {
                            setActive(window, gameView.userText, panel);
                        }
                    }
                }

                if (event.type == Event::KeyPressed)
                {
                    keyPressedHandler(window, gameView.userText, grid, event.key.code, m, typegame);
                }

                if (fl == 1 && event.type == Event::KeyPressed)
                {
                    continuePlay = askContinuePlay(event.key.code);
                    if (event.key.code == 2 || event.key.code == 24)
                    {
                        fl = 2;
                    }
                }
            }

            if (isGameFinished(grid, mistakes, typegame) && fl == 0)
            {
                fl = 1;
                // GameOver game(window, grid, typegame);
            }

            gameView.draw(mistakes, grid, window, typegame, panel);
        }
    }

    return 0;
}
