#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "Rectangles.hpp"

using namespace sf;

class EllipseShape : public sf::Shape
{
public :

    explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0, 0)) :
    m_radius(radius)
    {
        update();
    }

    void setRadius(const sf::Vector2f& radius)
    {
        m_radius = radius;
        update();
    }

    const sf::Vector2f& getRadius() const
    {
        return m_radius;
    }

    virtual size_t getPointCount() const
    {
        return 30; // fixed, but could be an attribute of the class if needed
    }

    virtual sf::Vector2f getPoint(size_t index) const
    {
        static const float pi = 3.141592654f;

        float angle = index * 2 * pi / getPointCount() - pi / 2;
        float x = std::cos(angle) * m_radius.x;
        float y = std::sin(angle) * m_radius.y;

        return sf::Vector2f(m_radius.x + x, m_radius.y + y);
    }

private :

    sf::Vector2f m_radius;
};

int speed_par = 5;

int main()
{
    srand(time(NULL));

    tPoint points[10];
    tLine lines[10];
    tCircle circles[10];
    tRectangle rectangles[10];
    tTriangle triangles[10];
    tEllipse ellipses[10];
    tRhomb rhombs[10];

    CircleShape sfml_points[10];
    Vertex sfml_lines[10][2];
    CircleShape sfml_circles[10];
    Vertex sfml_rectangles[10][4];
    Vertex sfml_triangles[10][3];
    EllipseShape sfml_ellipses[10];
    Vertex sfml_rhombs[10][4];

    for (int i = 0; i < 10; i++)
    {
        Color color[10], color2[10], color3[10], color4[10], color5[10], color6[10], color7[10]; 

        points[i] = tPoint(rand() % 1000, rand() % 700, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
        color[i].r = points[i].get_R();
        color[i].g = points[i].get_G();
        color[i].b = points[i].get_B();
        color[i].a = points[i].get_A();
        sfml_points[i].setRadius(4);
        sfml_points[i].setOutlineThickness(1);
        sfml_points[i].setPosition(Vector2f(points[i].get_x(), points[i].get_y()));
        sfml_points[i].setOutlineColor(color[i]);
        sfml_points[i].setFillColor(color[i]);

        lines[i] = tLine(rand() % 1000, rand() % 700, rand() % 1000, rand() % 700, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
        color2[i].r = lines[i].get_R();
        color2[i].g = lines[i].get_G();
        color2[i].b = lines[i].get_B();
        color2[i].a = lines[i].get_A();
        sfml_lines[i][0].position.x = lines[i].get_x();
        sfml_lines[i][0].position.y = lines[i].get_y();
        sfml_lines[i][1].position.x = lines[i].get_x2();
        sfml_lines[i][1].position.y = lines[i].get_y2();
        sfml_lines[i][0].color = color2[i];
        sfml_lines[i][1].color = color2[i];

        circles[i] = tCircle(rand() % 100, rand() % 1000, rand() % 700, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
        color3[i].r = circles[i].get_R();
        color3[i].g = circles[i].get_G();
        color3[i].b = circles[i].get_B();
        color3[i].a = circles[i].get_A();
        sfml_circles[i].setRadius(circles[i].get_radius());
        sfml_circles[i].setOutlineThickness(5);
        sfml_circles[i].setPosition(Vector2f(circles[i].get_x(), circles[i].get_y()));
        sfml_circles[i].setOutlineColor(color3[i]);
        sfml_circles[i].setFillColor(Color(255, 255, 255, 0));

        double pos_x, pos_y, pos_x2, pos_y2;
        pos_x = rand() % 1000;
        pos_y = rand() % 700;
        pos_x2 = pos_x > 500 ? pos_x - rand() % 500 : pos_x + rand() % 500;
        pos_y2 = pos_y > 350 ? pos_y - rand() % 350 : pos_y + rand() % 350;
        rectangles[i] = tRectangle(pos_x, pos_y, pos_x2, pos_y2, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
        color4[i].r = rectangles[i].get_R();
        color4[i].g = rectangles[i].get_G();
        color4[i].b = rectangles[i].get_B();
        color4[i].a = rectangles[i].get_A();
        sfml_rectangles[i][0].position.x = rectangles[i].get_x();
        sfml_rectangles[i][0].position.y = rectangles[i].get_y();
        sfml_rectangles[i][1].position.x = rectangles[i].get_x2();
        sfml_rectangles[i][1].position.y = rectangles[i].get_y2();
        sfml_rectangles[i][2].position.x = rectangles[i].get_x3();
        sfml_rectangles[i][2].position.y = rectangles[i].get_y3();
        sfml_rectangles[i][3].position.x = rectangles[i].get_x4();
        sfml_rectangles[i][3].position.y = rectangles[i].get_y4();
        sfml_rectangles[i][0].color = color4[i];
        sfml_rectangles[i][1].color = color4[i];
        sfml_rectangles[i][2].color = color4[i];
        sfml_rectangles[i][3].color = color4[i];

        triangles[i] = tTriangle(rand() % 1000, rand() % 700, rand() % 1000, rand() % 700, rand() % 1000, rand() % 700, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
        color5[i].r = triangles[i].get_R();
        color5[i].g = triangles[i].get_G();
        color5[i].b = triangles[i].get_B();
        color5[i].a = triangles[i].get_A();
        sfml_triangles[i][0].position.x = rectangles[i].get_x();
        sfml_triangles[i][0].position.y = rectangles[i].get_y();
        sfml_triangles[i][1].position.x = rectangles[i].get_x2();
        sfml_triangles[i][1].position.y = rectangles[i].get_y2();
        sfml_triangles[i][2].position.x = rectangles[i].get_x3();
        sfml_triangles[i][2].position.y = rectangles[i].get_y3();
        sfml_triangles[i][0].color = color5[i];
        sfml_triangles[i][1].color = color5[i];
        sfml_triangles[i][2].color = color5[i];

        ellipses[i] = tEllipse(rand() % 800, rand() % 600, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par, rand() % 150, rand() % 150, rand() % 50);
        color6[i].r = circles[i].get_R();
        color6[i].g = circles[i].get_G();
        color6[i].b = circles[i].get_B();
        color6[i].a = circles[i].get_A();
        sfml_ellipses[i].setRadius(Vector2f(ellipses[i].get_radius1(), ellipses[i].get_radius2()));
        sfml_ellipses[i].setOutlineThickness(3);
        sfml_ellipses[i].setPosition(Vector2f(ellipses[i].get_x(), ellipses[i].get_y()));
        sfml_ellipses[i].setOutlineColor(color3[i]);
        sfml_ellipses[i].setFillColor(Color(255, 255, 255, 0));

        pos_x = rand() % 1000;
        pos_y = rand() % 700;
        rhombs[i] = tRhomb(pos_x, pos_y, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par, rand() % 300, rand() % 300);
        color7[i].r = rhombs[i].get_R();
        color7[i].g = rhombs[i].get_G();
        color7[i].b = rhombs[i].get_B();
        color7[i].a = rhombs[i].get_A();
        sfml_rhombs[i][0].position.x = rhombs[i].get_x();
        sfml_rhombs[i][0].position.y = rhombs[i].get_y();
        sfml_rhombs[i][1].position.x = rhombs[i].get_x2();
        sfml_rhombs[i][1].position.y = rhombs[i].get_y2();
        sfml_rhombs[i][2].position.x = rhombs[i].get_x3();
        sfml_rhombs[i][2].position.y = rhombs[i].get_y3();
        sfml_rhombs[i][3].position.x = rhombs[i].get_x4();
        sfml_rhombs[i][3].position.y = rhombs[i].get_y4();
        sfml_rhombs[i][0].color = color7[i];
        sfml_rhombs[i][1].color = color7[i];
        sfml_rhombs[i][2].color = color7[i];
        sfml_rhombs[i][3].color = color7[i];
    }

    int type = 0;
    printf("Введите тип движения: \n1. Прямолинейное \n2. Вокруг своей оси\n");
    scanf("%d", &type);

    RenderWindow window(sf::VideoMode(1080, 720), "Shapes Chaos!");
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
        for (int i = 0; i < 10; i++)
        {
            int random = rand() % 100;
            double angle = 0.25;
            double *pos = new double[2];
            double *pos_lines = new double[4];
            double *pos_circles = new double[2];
            double *pos_rectangles = new double[8];
            double *pos_triangles = new double[6];
            double *pos_ellipses = new double[2];
            double *pos_rhombs = new double[8];

            if (random == 55)
            {
                points[i].set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
                lines[i].set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
                circles[i].set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
                rectangles[i].set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
                triangles[i].set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
                ellipses[i].set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            }

            pos = points[i].move();
            if (type == 1)
            {
                pos_lines = lines[i].move();
                pos_circles = circles[i].move();
                pos_rectangles = rectangles[i].move();
                pos_triangles = triangles[i].move();
                pos_ellipses = ellipses[i].move();
                sfml_ellipses[i].setPosition(Vector2f(pos_ellipses[0], pos_ellipses[1]));
                pos_rhombs = rhombs[i].move();
            }
            else
            {
                angle = angle + 0.02;
                pos_lines = lines[i].rotate(angle);
                pos_rectangles = rectangles[i].rotate(angle);
                pos_triangles = triangles[i].rotate(angle);
                pos_ellipses = ellipses[i].rotate(angle);
                sfml_ellipses[i].setRadius(Vector2f(pos_ellipses[0], pos_ellipses[1]));
                // sfml_ellipses[i].rotate(angle);
                pos_rhombs = rhombs[i].rotate(angle);
            }
            pos_circles = circles[i].move();

            sfml_points[i].setPosition(Vector2f(pos[0], pos[1]));
            sfml_lines[i][0].position.x = pos_lines[0];
            sfml_lines[i][0].position.y = pos_lines[1];
            sfml_lines[i][1].position.x = pos_lines[2];
            sfml_lines[i][1].position.y = pos_lines[3];
            sfml_circles[i].setPosition(Vector2f(pos_circles[0], pos_circles[1]));
            sfml_rectangles[i][0].position.x = pos_rectangles[0];
            sfml_rectangles[i][0].position.y = pos_rectangles[1];
            sfml_rectangles[i][1].position.x = pos_rectangles[2];
            sfml_rectangles[i][1].position.y = pos_rectangles[3];
            sfml_rectangles[i][2].position.x = pos_rectangles[4];
            sfml_rectangles[i][2].position.y = pos_rectangles[5];
            sfml_rectangles[i][3].position.x = pos_rectangles[6];
            sfml_rectangles[i][3].position.y = pos_rectangles[7];
            sfml_triangles[i][0].position.x = pos_triangles[0];
            sfml_triangles[i][0].position.y = pos_triangles[1];
            sfml_triangles[i][1].position.x = pos_triangles[2];
            sfml_triangles[i][1].position.y = pos_triangles[3];
            sfml_triangles[i][2].position.x = pos_triangles[4];
            sfml_triangles[i][2].position.y = pos_triangles[5];
            sfml_rhombs[i][0].position.x = pos_rhombs[0];
            sfml_rhombs[i][0].position.y = pos_rhombs[1];
            sfml_rhombs[i][1].position.x = pos_rhombs[2];
            sfml_rhombs[i][1].position.y = pos_rhombs[3];
            sfml_rhombs[i][2].position.x = pos_rhombs[4];
            sfml_rhombs[i][2].position.y = pos_rhombs[5];
            sfml_rhombs[i][3].position.x = pos_rhombs[6];
            sfml_rhombs[i][3].position.y = pos_rhombs[7];

            window.draw(sfml_points[i]);
            window.draw(sfml_lines[i], 2, Lines);
            window.draw(sfml_circles[i]);
            window.draw(sfml_rectangles[i], 4, Quads);
            window.draw(sfml_triangles[i], 3, Triangles);
            window.draw(sfml_ellipses[i]);
            window.draw(sfml_rhombs[i], 4, Quads);
            
            delete pos;
            delete pos_lines;
            delete pos_circles;
            delete pos_rectangles;
            delete pos_triangles;
            delete pos_ellipses;
            delete pos_rhombs;
        }
        window.display();
    }

    return 0;
}