#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Points.hpp"

using namespace sf;

int speed_par = 5;

void tPoint::init()
{
    x = 0; y = 0; red = 0; blue = 0; green = 0; alpha = 0; speed_x = 0; speed_y = 0;
}

void tPoint::set_x(int ex)
{
    x = ex;
}

void tPoint::set_y(int ex) 
{ 
    y = ex;
}
        
int tPoint::get_x()
{ 
    return x;
}
        
int tPoint::get_y() 
{ 
    return y;
}
        
void tPoint::set_RGBA(int r, int g, int b, int a) 
{ 
    red = r; green = g; blue = b; alpha = a;
}
        
int tPoint::get_R() 
{
    return red;
}
        
int tPoint::get_G() 
{
    return green;
}
        
int tPoint::get_B() 
{
    return blue;
}
        
int tPoint::get_A() 
{
    return alpha;
}
        
void tPoint::set_speed_x(int ex) 
{ 
    speed_x = ex;
}
        
void tPoint::set_speed_y(int ex) 
{ 
    speed_y = ex;
}
        
int tPoint::get_speed_x() 
{ 
    return speed_x;
}
        
int tPoint::get_speed_y() 
{ 
    return speed_y;
}
        
int tPoint::move_x() 
{ 
    x = x + speed_x; return x;
}
        
int tPoint::move_y() 
{ 
    y = y + speed_y; return y;
}
        
void tPoint::reflexion_x() 
{ 
    if (x >= 1080 - abs(get_speed_x()) || x <= 0 + abs(get_speed_x())) { speed_x = speed_x * -1;}
}
        
void tPoint::reflexion_y() 
{ 
    if (y >= 720 - abs(get_speed_y()) || y <= 0 + abs(get_speed_y())) { speed_y = speed_y * -1;}
}

int main()
{
    srand(time(NULL));
    tPoint points[100];
    CircleShape sfml_points[100];
    for (int i = 0; i < 100; i++)
    {
        Color color[100];
        points[i].init();
        points[i].set_x(rand() % 1000);
        points[i].set_y(rand() % 700);
        points[i].set_speed_x(-(rand() % speed_par) + rand() % speed_par);
        points[i].set_speed_y(-(rand() % speed_par) + rand() % speed_par);
        points[i].set_RGBA(rand() % 255, rand() % 255, rand() % 255, 255);
        color[i].r = points[i].get_R();
        color[i].g = points[i].get_G();
        color[i].b = points[i].get_B();
        color[i].a = points[i].get_A();
        sfml_points[i].setRadius(4);
        sfml_points[i].setOutlineThickness(1);
        sfml_points[i].setPosition(Vector2f(points[i].get_x(), points[i].get_y()));
        sfml_points[i].setOutlineColor(color[i]);
        sfml_points[i].setFillColor(color[i]);
    }

    RenderWindow window(sf::VideoMode(1080, 720), "Points!");
    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        
        window.clear();
        for (int i = 0; i < 100; i++)
        {
            int random = rand() % 100;
            if (random == 55)
            {
                points[i].set_speed_x(-(rand() % speed_par) + rand() % speed_par);
                points[i].set_speed_y(-(rand() % speed_par) + rand() % speed_par);
            }
            points[i].reflexion_x();
            points[i].reflexion_y();
            sfml_points[i].setPosition(Vector2f(points[i].move_x(), points[i].move_y()));
            window.draw(sfml_points[i]);
        }
        window.display();
    }

    return 0;
}