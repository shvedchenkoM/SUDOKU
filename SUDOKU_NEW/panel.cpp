#include "panel.h"

using namespace std;
using namespace sf;

Panel::Panel(RenderWindow &window)
{
      panelka.resize(11);
      //cout <<coordX<<" "<<coordY<<endl;
      //int x = coordX;
      //int y = coordY;

      panelka[0].texture.loadFromFile("Pic/PanPic1.png"); 
      panelka[0].sprite.setTexture(panelka[0].texture);

      panelka[1].texture.loadFromFile("Pic/PanPic2.png"); 
      panelka[1].sprite.setTexture(panelka[1].texture);

      panelka[2].texture.loadFromFile("Pic/PanPic3.png"); 
      panelka[2].sprite.setTexture(panelka[2].texture);

      panelka[3].texture.loadFromFile("Pic/PanPic4.png"); 
      panelka[3].sprite.setTexture(panelka[3].texture);

      panelka[4].texture.loadFromFile("Pic/PanPic5.png"); 
      panelka[4].sprite.setTexture(panelka[4].texture);

      panelka[5].texture.loadFromFile("Pic/PanPic6.png"); 
      panelka[5].sprite.setTexture(panelka[5].texture);

      panelka[6].texture.loadFromFile("Pic/PanPic7.png"); 
      panelka[6].sprite.setTexture(panelka[6].texture);

      panelka[7].texture.loadFromFile("Pic/PanPic8.png");
      panelka[7].sprite.setTexture(panelka[7].texture);

      panelka[8].texture.loadFromFile("Pic/PanPic9.png"); 
      panelka[8].sprite.setTexture(panelka[8].texture);

      panelka[9].texture.loadFromFile("Pic/PanelRemember.png");
      panelka[9].sprite.setTexture(panelka[9].texture);

      panelka[10].texture.loadFromFile("Pic/Panelclean.png");
      panelka[10].sprite.setTexture(panelka[10].texture);
    
}

int Panel::click(double posx, double posy)
{
    for (int i = 0; i < panelka.size(); i++)
    {
        if (panelka[i].sprite.getGlobalBounds().contains(posx, posy))
        {
            return i + 1;
        }
    }

    return 0;
}

bool Panel::draw(RenderWindow &window)
{
        double x, y;
      if(coordY < 5 && coordX < 5)
      {
          x = (400.0 - 9 / 2.0 * 50.0) + 50 * coordY;
          y = (300.0 - 9 / 2.0 * 50.0) + 50 + 50 * coordX;
      }

      if(coordY < 5 && coordX >= 5)
      {
          x = (400.0 - 9 / 2.0 * 50.0) + 50 * coordY;
          y = (300.0 - 9 / 2.0 * 50.0) - 100 + 50 * coordX;
      }

      if(coordY >= 5 && coordX < 5)
      {
          x = (400.0 - 9 / 2.0 * 50.0) - 50 + 50 * coordY;
          y = (300.0 - 9 / 2.0 * 50.0) + 50 + 50 * coordX;
      }

      if(coordY >= 5 && coordX >= 5)
      {
          x = (400.0 - 9 / 2.0 * 50.0) - 50 + 50 * coordY;
          y = (300.0 - 9 / 2.0 * 50.0) - 100 + 50 * coordX;
      }
      
      panelka[0].sprite.setPosition(Vector2f(x, y));
      panelka[1].sprite.setPosition(Vector2f(x + 32, y));
      panelka[2].sprite.setPosition(Vector2f(x + 64, y));
      panelka[3].sprite.setPosition(Vector2f(x, y + 32));
      panelka[4].sprite.setPosition(Vector2f(x + 32, y + 32));
      panelka[5].sprite.setPosition(Vector2f(x + 64, y + 32));
      panelka[6].sprite.setPosition(Vector2f(x, y + 64));
      panelka[7].sprite.setPosition(Vector2f(x + 32, y + 64));
      panelka[8].sprite.setPosition(Vector2f(x + 64, y + 64));
      panelka[9].sprite.setPosition(Vector2f(x, y + 96));
      panelka[10].sprite.setPosition(Vector2f(x + 47, y + 96));

    for (int i = 0; i < 11; i++)
    {
        window.draw(panelka[i].sprite);
        //cout <<endl<<"panelka "<<coordX<<" "<<coordY<<" "<<endl;
    }
    return -1;
}

/*bool Panel::isActive(Grid &grid, RenderWindow &window, int x, int y, int n)
{
    if (grid.isCellReadonly(x * n * n + y))
    {
        return false;
    }
    else
    {
        coordX = x;
        coordY = y;
        return true;
    }
}*/

Panel::~Panel()
{
}