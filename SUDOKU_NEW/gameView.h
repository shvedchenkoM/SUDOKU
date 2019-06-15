#pragma once
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "panel.h"
#include "grid.h"

using namespace std;
using namespace sf;

struct uT
{
    bool isActive = false;
    bool readOnly = false;
    string s = "";
    Font font;
    Text text;
    Texture texture;
    Color color;
    Sprite sprite;
};

class GameView
{
  public:
    GameView(int m, RenderWindow &window);

    Texture textureWin;
    Sprite spriteWin;

    Texture textureLose;
    Sprite spriteLose;

    Texture textureRecom;
    Sprite spriteRecom;

    Font font;
    Text title;
    vector<uT> userText;
    void draw(int mistakes, Grid &grid, RenderWindow &window, int typeGame, Panel& panel);

    ~GameView();
};