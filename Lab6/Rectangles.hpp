#include <iostream>
#include <math.h>

class tShape
{
    protected:
        double x, y, x2, y2, x3, y3, x4, y4, speed_x, speed_y, radius, radius_x, radius_y, diag1, diag2;
        int red, blue, green, alpha;
    public:
        tShape()
        {
            x = 0; y = 0; x2 = 0; y2 = 0; x3 = 0; y3 = 0; x4 = 0; y4 = 0; red = 0; blue = 0; green = 0; alpha = 0; speed_x = 0; speed_y = 0; radius = 0; radius_x = 0; radius_y = 0; diag1 = 0; diag2 = 0;
        }
        tShape(double ex, double ey, double ex2, double ey2, double ex3, double ey3, double ex4, double ey4, int ered, int eblue, int egreen, int ealpha, double espeed_x, double espeed_y, double eradius, double eradius_x, double eradius_y, double ediag1, double ediag2)
        {
            x = ex; y = ey; x2 = ex2; y2 = ey2; x3 = ex3; y3 = ey3; x4 = ex4; y4 = ey4; red = ered; blue = eblue; green = egreen; alpha = ealpha; speed_x = espeed_x; speed_y = espeed_y; radius = eradius; radius_x = eradius_x; radius_y = eradius_y; diag1 = ediag1; diag2 = ediag2;
        }
        double get_x();
        double get_y();
        double get_x2();
        double get_y2();
        double get_x3();
        double get_y3();
        double get_x4();
        double get_y4();
        void set_RGBA(int r, int g, int b, int a);
        int get_R();
        int get_G();
        int get_B();
        int get_A();
        void set_speed(double ex, double ey);
        double get_speed_x();
        double get_speed_y();
        double get_radius();
        double get_radius_x();
        double get_radius_y();
        double get_diag1();
        double get_diag2();
        virtual double *move() = 0;
        virtual double *rotate(double angle) = 0;
};

class tPoint: public tShape
{
    public:
        tPoint()
        {
            x = 0; y = 0; red = 0; blue = 0; green = 0; alpha = 0; speed_x = 0; speed_y = 0;
        };
        tPoint(double ex, double ey, int ered, int eblue, int egreen, int ealpha, double espeed_x, double espeed_y)
        {
            x = ex; y = ey; red = ered; blue = eblue; green = egreen; alpha = ealpha; speed_x = espeed_x; speed_y = espeed_y;
        };
        virtual double *move();
        virtual double *rotate(double angle);
};

class tLine: public tPoint
{
    public:
        tLine(): tPoint()
        {
            x2 = 0; y2 = 0;
        };
        tLine(double ex, double ey, double ex2, double ey2, int ered, int eblue, int egreen, int ealpha, double espeed_x, double espeed_y)
        {
            x = ex; y = ey; red = ered; blue = eblue; green = egreen; alpha = ealpha; speed_x = espeed_x; speed_y = espeed_y; x2 = ex2; y2 = ey2;
        };
        virtual double *move();
        virtual double *rotate(double angle);
};

class tCircle: public tPoint
{
    public:
        tCircle(): tPoint()
        {
            radius = 0;
        };
        tCircle(double erad, double ex, double ey, int ered, int eblue, int egreen, int ealpha, double espeed_x, double espeed_y)
        {
            radius = erad; x = ex; y = ey; red = ered; blue = eblue; green = egreen; alpha = ealpha; speed_x = espeed_x; speed_y = espeed_y;
        };
        virtual double *move();
        virtual double *rotate(double angle);
};

class tRectangle: public tLine
{
    public:
        tRectangle(): tLine()
        {
            x3 = 0; x4 = 0; y3 = 0; y4 = 0;
        };
        tRectangle(double ex, double ey, double ex2, double ey2, int ered, int eblue, int egreen, int ealpha, double espeed_x, double espeed_y)
        {
            x = ex; y = ey; x2 = ex; y2 = ey2; x3 = ex2; y3 = ey2; x4 = ex2; y4 = ey; red = ered; blue = eblue; green = egreen; alpha = ealpha; speed_x = espeed_x; speed_y = espeed_y;
        };
        virtual double *move();
        virtual double *rotate(double angle);
};

class tTriangle: public tLine
{
    public:
        tTriangle(): tLine()
        {
            x3 = 0; y3 = 0;
        };
        tTriangle(double ex, double ey, double ex2, double ey2, double ex3, double ey3, int ered, int eblue, int egreen, int ealpha, double espeed_x, double espeed_y)
        {
            red = ered; blue = eblue; green = egreen; alpha = ealpha; speed_x = espeed_x; speed_y = espeed_y;
            double d1, d2, d3;
            d1 = sqrt(pow((ex - ex2), 2) - pow((ey - ey2), 2));
            d2 = sqrt(pow((ex2 - ex3), 2) - pow((ey2 - ey3), 2));
            d3 = sqrt(pow((ex3 - ex), 2) - pow((ey3 - ey), 2));
            if (d1 < d2 + d3 && d2 < d1 + d3 && d3 < d1 + d2);
            {
                x = ex; y = ey; x2 = ex2; y2 = ey2; x3 = ex3; y3 = ey3;
            }
        };
        virtual double *move();
        virtual double *rotate(double angle);
};

class tEllipse: public tPoint
{
    public:
        tEllipse(): tPoint()
        {
            radius_x = 0; radius_y = 0;
        }
        tEllipse(double ex, double ey, int ered, int eblue, int egreen, int ealpha, double espeed_x, double espeed_y, double eradius_x, double eradius_y)
        {
            x = ex; y = ey; red = ered; blue = eblue; green = egreen; alpha = ealpha; speed_x = espeed_x; speed_y = espeed_y; radius_x = eradius_x; radius_y = eradius_y;
        }
        virtual double *move();
        virtual double *rotate(double angle);
};

class tRhomb: public tRectangle
{
    public:
        tRhomb(): tRectangle()
        {
            diag1 = 0; diag2 = 0;
        };
        tRhomb(double ex, double ey, int ered, int eblue, int egreen, int ealpha, double espeed_x, double espeed_y, double diag1, double diag2)
        {
            x = ex - diag1 / 2; y = ey; x2 = ex; y2 = ey + diag2 / 2; x3 = ex + diag1 / 2; y3 = ey; x4 = ex; y4 = ey - diag2 / 2; red = ered; blue = eblue; green = egreen; alpha = ealpha; speed_x = espeed_x; speed_y = espeed_y;
        };
};