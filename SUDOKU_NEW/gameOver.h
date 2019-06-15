#pragma once
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#include "grid.h"

using namespace std;
using namespace sf;

class GameOver {
	public:
		GameOver(RenderWindow &window, Grid &grid, int typeGame);
        Texture tGameOver;
        Sprite sGameOver;
		~GameOver();	
};
