#include "panel.h"
#include "gameView.h"
#include "grid.h"

using namespace std;
using namespace sf;

GameView::GameView(int m, RenderWindow &window)
{
    window.setFramerateLimit(30);
    userText.resize(m * m * m * m);
    int k = 0;
    int le = m * m;
    for (int i = 0; i < le; i++)
    {
        for (int j = 0; j < le; j++)
        {
            int curInd = i * le + j;

            userText[curInd].texture.loadFromFile("Pic/cell0.png");
            userText[curInd].sprite.setTexture(userText[curInd].texture);
            userText[curInd].font.loadFromFile("./fonts/digital-7.ttf");
            userText[curInd].text.setFont(userText[curInd].font);
            userText[curInd].text.setFillColor(Color::Black);

            double firstPosX = 400.0 - (m * m) / 2.0 * 50.0;
            double firstPosY = 300.0 - (m * m) / 2.0 * 50.0;

            userText[curInd].sprite.setPosition(Vector2f(firstPosX + curInd % (m * m) * 50, firstPosY + curInd / (m * m) * 50));
            userText[curInd].text.setPosition(Vector2f(17 + firstPosX + curInd % (m * m) * 50, 7 + firstPosY + curInd / (m * m) * 50));
        }
        window.display();
    }

    //win
    textureWin.loadFromFile("Pic/win2.png"); //Load Texture from image
    // spriteWin = Sprite();
    spriteWin.setTexture(textureWin);
    //lose
    textureLose.loadFromFile("Pic/lose2.png"); //Load Texture from image
    // spriteLose = Sprite();
    spriteLose.setTexture(textureLose);

    // title = Text();

    font.loadFromFile("./fonts/Vertigo.ttf");
    title.setFont(font);
    title.setString("sudoku");
    title.setCharacterSize(80);
    title.setPosition(Vector2f(340, -10));
    title.setFillColor(Color::Red);
    //TEXT

    //R
    textureRecom.loadFromFile("Pic/recom.png");
    //Sprite spriteRecom;
    spriteRecom.setTexture(textureRecom);
}

void GameView::draw(int mistakes, Grid &grid, RenderWindow &window, int typeGame, Panel& panel)
{
    window.clear(Color(230, 239, 166));
    window.draw(title);
    window.draw(spriteRecom);
    for (int i = 0; i < userText.size(); i++)
    {
        window.draw(userText[i].sprite);
    }

    for (int i = 0; i < userText.size(); i++)
    {
        userText[i].text.setString(userText[i].s);
        window.draw(userText[i].text);
    }

    if (typeGame == 1)
    {
        if (grid.isSudocuCompleted1())
        {
            window.draw(spriteWin);
            cout << "you WIN :)";
            //return 0;
        }

        if (mistakes >= 5)
        {
            window.draw(spriteLose);
            cout << "you LOSE :((((";
            //return 0;
        }
    } else {
        if (grid.isSudocuCompleted2())
        {
            window.draw(spriteWin);
            cout << "you WIN :)";
            //return 0;
        }
    }

    if (panel.drawable)
    {
        panel.draw(window);
    }

    window.display();
}

GameView::~GameView()
{
}