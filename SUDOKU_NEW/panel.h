#pragma once
#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

struct uTT
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


class Panel {
	public:
		Panel(RenderWindow &window);

        int coordX,coordY;
        vector<uTT> panelka;

        int click(double posx, double posy);

        bool drawable = false;        
        bool draw(RenderWindow &window);
        //bool isSelected(Grid &grid, RenderWindow &window, int x, int y, int n);
		~Panel();	
};
