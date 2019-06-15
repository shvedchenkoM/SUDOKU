#include "gameOver.h"
#include "gameView.h"
#include "grid.h"

using namespace std;

GameOver::GameOver(RenderWindow &window, Grid &grid, int typeGame)
{
    if (typeGame == 1)
    {
        if (grid.isSudocuCompleted1())
        {
            tGameOver.loadFromFile("Pic/game_over_win.png"); //Load Texture from image
            sGameOver.setTexture(tGameOver);
        }
        else
        {
            tGameOver.loadFromFile("Pic/game_over_lose.png"); //Load Texture from image
            sGameOver.setTexture(tGameOver);
        }
    }
    if(typeGame == 2)
    {
        if(grid.isSudocuCompleted2())
        {
            tGameOver.loadFromFile("Pic/game_over_win.png"); //Load Texture from image
            sGameOver.setTexture(tGameOver);
        }
    }
}




GameOver::~GameOver()
{
}