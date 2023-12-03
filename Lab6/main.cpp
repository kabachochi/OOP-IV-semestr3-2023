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

    tShape** shapes = new tShape*[7];

    int i = 0;
    while (i != 7)
    {
        double pos_x, pos_y, pos_x2, pos_y2;
        switch (i)
        {
        case 0:
            shapes[i] = new tPoint(rand() % 1000, rand() % 700, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            break;
        case 1:
            shapes[i] = new tLine(rand() % 1000, rand() % 700, rand() % 1000, rand() % 700, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            break;
        case 2:
            shapes[i] = new tCircle(rand() % 100, rand() % 1000, rand() % 700, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            break;
        case 3:
            pos_x = rand() % 1000;
            pos_y = rand() % 700;
            pos_x2 = pos_x > 500 ? pos_x - rand() % 500 : pos_x + rand() % 500;
            pos_y2 = pos_y > 350 ? pos_y - rand() % 350 : pos_y + rand() % 350;
            shapes[i] = new tRectangle(pos_x, pos_y, pos_x2, pos_y2, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            break;
        case 4:
            shapes[i] = new tTriangle(rand() % 1000, rand() % 700, rand() % 1000, rand() % 700, rand() % 1000, rand() % 700, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            break;
        case 5:
            shapes[i] = new tEllipse(rand() % 800, rand() % 600, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par, rand() % 150, rand() % 150);
            break;
        case 6:
            pos_x = rand() % 1000;
            pos_y = rand() % 700;
            shapes[i] = new tRhomb(pos_x, pos_y, rand() % 255, rand() % 255, rand() % 255, 255, -(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par, rand() % 300, rand() % 300);
            break;
        default:
            break;
        }
        i++;
    }

    CircleShape sfml_points;
    Vertex sfml_lines[2];
    CircleShape sfml_circles;
    Vertex sfml_rectangles[4];
    Vertex sfml_triangles[3];
    EllipseShape sfml_ellipses;
    Vertex sfml_rhombs[4];

    Color color[7]; 

    color[0].r = shapes[0]->get_R();
    color[0].g = shapes[0]->get_G();
    color[0].b = shapes[0]->get_B();
    color[0].a = shapes[0]->get_A();
    sfml_points.setRadius(4);
    sfml_points.setOutlineThickness(1);
    sfml_points.setPosition(Vector2f(shapes[0]->get_x(), shapes[0]->get_y()));
    sfml_points.setOutlineColor(color[0]);
    sfml_points.setFillColor(color[0]);

    color[1].r = shapes[1]->get_R();
    color[1].g = shapes[1]->get_G();
    color[1].b = shapes[1]->get_B();
    color[1].a = shapes[1]->get_A();
    sfml_lines[0].position.x = shapes[1]->get_x();
    sfml_lines[0].position.y = shapes[1]->get_y();
    sfml_lines[1].position.x = shapes[1]->get_x2();
    sfml_lines[1].position.y = shapes[1]->get_y2();
    sfml_lines[0].color = color[1];
    sfml_lines[1].color = color[1];

    color[2].r = shapes[2]->get_R();
    color[2].g = shapes[2]->get_G();
    color[2].b = shapes[2]->get_B();
    color[2].a = shapes[2]->get_A();
    sfml_circles.setRadius(shapes[2]->get_radius());
    sfml_circles.setOutlineThickness(5);
    sfml_circles.setPosition(Vector2f(shapes[2]->get_x(), shapes[2]->get_y()));
    sfml_circles.setOutlineColor(color[2]);
    sfml_circles.setFillColor(Color(255, 255, 255, 0));

    color[3].r = shapes[3]->get_R();
    color[3].g = shapes[3]->get_G();
    color[3].b = shapes[3]->get_B();
    color[3].a = shapes[3]->get_A();
    sfml_rectangles[0].position.x = shapes[3]->get_x();
    sfml_rectangles[0].position.y = shapes[3]->get_y();
    sfml_rectangles[1].position.x = shapes[3]->get_x2();
    sfml_rectangles[1].position.y = shapes[3]->get_y2();
    sfml_rectangles[2].position.x = shapes[3]->get_x3();
    sfml_rectangles[2].position.y = shapes[3]->get_y3();
    sfml_rectangles[3].position.x = shapes[3]->get_x4();
    sfml_rectangles[3].position.y = shapes[3]->get_y4();
    sfml_rectangles[0].color = color[3];
    sfml_rectangles[1].color = color[3];
    sfml_rectangles[2].color = color[3];
    sfml_rectangles[3].color = color[3];

    color[4].r = shapes[4]->get_R();
    color[4].g = shapes[4]->get_G();
    color[4].b = shapes[4]->get_B();
    color[4].a = shapes[4]->get_A();
    sfml_triangles[0].position.x = shapes[4]->get_x();
    sfml_triangles[0].position.y = shapes[4]->get_y();
    sfml_triangles[1].position.x = shapes[4]->get_x2();
    sfml_triangles[1].position.y = shapes[4]->get_y2();
    sfml_triangles[2].position.x = shapes[4]->get_x2();
    sfml_triangles[2].position.y = shapes[4]->get_y2();
    sfml_triangles[0].color = color[4];
    sfml_triangles[1].color = color[4];
    sfml_triangles[2].color = color[4];

    color[5].r = shapes[5]->get_R();
    color[5].g = shapes[5]->get_G();
    color[5].b = shapes[5]->get_B();
    color[5].a = shapes[5]->get_A();
    sfml_ellipses.setRadius(Vector2f(shapes[5]->get_radius_x(),shapes[5]->get_radius_y()));
    sfml_ellipses.setOutlineThickness(3);
    sfml_ellipses.setPosition(Vector2f(shapes[5]->get_x(), shapes[5]->get_y()));
    sfml_ellipses.setOutlineColor(color[5]);
    sfml_ellipses.setFillColor(Color(255, 255, 255, 0));

    color[6].r = shapes[6]->get_R();
    color[6].g = shapes[6]->get_G();
    color[6].b = shapes[6]->get_B();
    color[6].a = shapes[6]->get_A();
    sfml_rhombs[0].position.x = shapes[6]->get_x();
    sfml_rhombs[0].position.y = shapes[6]->get_y();
    sfml_rhombs[1].position.x = shapes[6]->get_x2();
    sfml_rhombs[1].position.y = shapes[6]->get_y2();
    sfml_rhombs[2].position.x = shapes[6]->get_x3();
    sfml_rhombs[2].position.y = shapes[6]->get_y3();
    sfml_rhombs[3].position.x = shapes[6]->get_x4();
    sfml_rhombs[3].position.y = shapes[6]->get_y4();
    sfml_rhombs[0].color = color[6];
    sfml_rhombs[1].color = color[6];
    sfml_rhombs[2].color = color[6];
    sfml_rhombs[3].color = color[6];

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
            shapes[0]->set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            shapes[1]->set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            shapes[2]->set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            shapes[3]->set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            shapes[4]->set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            shapes[5]->set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
            shapes[6]->set_speed(-(rand() % speed_par) + rand() % speed_par, -(rand() % speed_par) + rand() % speed_par);
        }

        pos = shapes[0]->move();
        pos_circles = shapes[2]->move();
        if (type == 1)
        {
            pos_lines = shapes[1]->move();
            pos_rectangles = shapes[3]->move();
            pos_triangles = shapes[4]->move();
            pos_ellipses = shapes[5]->move();
            sfml_ellipses.setPosition(Vector2f(pos_ellipses[0], pos_ellipses[1]));
            pos_rhombs = shapes[6]->move();
        }
        else
        {
            angle = angle + 0.02;
            pos_lines = shapes[1]->rotate(angle);
            pos_rectangles = shapes[3]->rotate(angle);
            pos_triangles = shapes[4]->rotate(angle);
            pos_ellipses = shapes[5]->rotate(angle);
            sfml_ellipses.setRadius(Vector2f(pos_ellipses[0], pos_ellipses[1]));
            // sfml_ellipses[i].rotate(angle);
            pos_rhombs = shapes[6]->rotate(angle);
        }
        

        sfml_points.setPosition(Vector2f(pos[0], pos[1]));
        sfml_lines[0].position.x = pos_lines[0];
        sfml_lines[0].position.y = pos_lines[1];
        sfml_lines[1].position.x = pos_lines[2];
        sfml_lines[1].position.y = pos_lines[3];
        sfml_circles.setPosition(Vector2f(pos_circles[0], pos_circles[1]));
        sfml_rectangles[0].position.x = pos_rectangles[0];
        sfml_rectangles[0].position.y = pos_rectangles[1];
        sfml_rectangles[1].position.x = pos_rectangles[2];
        sfml_rectangles[1].position.y = pos_rectangles[3];
        sfml_rectangles[2].position.x = pos_rectangles[4];
        sfml_rectangles[2].position.y = pos_rectangles[5];
        sfml_rectangles[3].position.x = pos_rectangles[6];
        sfml_rectangles[3].position.y = pos_rectangles[7];
        sfml_triangles[0].position.x = pos_triangles[0];
        sfml_triangles[0].position.y = pos_triangles[1];
        sfml_triangles[1].position.x = pos_triangles[2];
        sfml_triangles[1].position.y = pos_triangles[3];
        sfml_triangles[2].position.x = pos_triangles[4];
        sfml_triangles[2].position.y = pos_triangles[5];
        sfml_rhombs[0].position.x = pos_rhombs[0];
        sfml_rhombs[0].position.y = pos_rhombs[1];
        sfml_rhombs[1].position.x = pos_rhombs[2];
        sfml_rhombs[1].position.y = pos_rhombs[3];
        sfml_rhombs[2].position.x = pos_rhombs[4];
        sfml_rhombs[2].position.y = pos_rhombs[5];
        sfml_rhombs[3].position.x = pos_rhombs[6];
        sfml_rhombs[3].position.y = pos_rhombs[7];

        window.draw(sfml_points);
        window.draw(sfml_lines, 2, Lines);
        window.draw(sfml_circles);
        window.draw(sfml_rectangles, 4, Quads);
        window.draw(sfml_triangles, 3, Triangles);
        window.draw(sfml_ellipses);
        window.draw(sfml_rhombs, 4, Quads);
        
        delete pos;
        delete pos_lines;
        delete pos_circles;
        delete pos_rectangles;
        delete pos_triangles;
        delete pos_ellipses;
        delete pos_rhombs;

        window.display();
    }

    for (int i = 0; i < 7; i++)
    {
        delete shapes[i];
    }
    delete shapes;
    return 0;
}