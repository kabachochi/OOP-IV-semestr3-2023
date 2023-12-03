#include "Rectangles.hpp"

double tShape::get_x()
{
    return x;
}

double tShape::get_y()
{
    return y;
}
        
double tShape::get_x2()
{
    return x2;
}
        
double tShape::get_y2()
{
    return y2;
}

double tShape::get_x3()
{
    return x3;
}

double tShape::get_y3()
{
    return y3;
}

double tShape::get_x4()
{
    return x4;
}

double tShape::get_y4()
{
    return y4;
}

void tShape::set_RGBA(int r, int g, int b, int a)
{
    red = r; green = g; blue = b; alpha = a;
}
        
int tShape::get_R()
{
    return red;
}
        
int tShape::get_G()
{
    return green;
}

int tShape::get_B()
{
    return blue;
}
        
int tShape::get_A()
{
    return alpha;
}

void tShape::set_speed(double ex, double ey)
{
    speed_x = ex; speed_y = ey;
}
        
double tShape::get_speed_x()
{
    return speed_x;
}

double tShape::get_speed_y()
{
    return speed_y;
}

double tShape::get_radius()
{
    return radius;
}
        
double tShape::get_radius_x()
{
    return radius_x;
}
        
double tShape::get_radius_y()
{
    return radius_y;
}

double tShape::get_diag1()
{
    return diag1;
}
        
double tShape::get_diag2()
{
    return diag2;
}

/* double *tShape::move()
{
    return NULL;
}

double *tShape::rotate(double angle)
{
    return NULL;
} */
    
double *tPoint::move() 
{
    double *param = new double[2]; 
    if (x >= 1080 - abs(get_speed_x()) || x <= 0 + abs(get_speed_x())) { speed_x = speed_x * -1;}
    if (y >= 720 - abs(get_speed_y()) || y <= 0 + abs(get_speed_y())) { speed_y = speed_y * -1;}
    x = x + speed_x;
    y = y + speed_y;
    param[0] = x;
    param[1] = y;
    return param;
}

double *tPoint::rotate(double angle)
{
    return NULL;
}
        
double *tLine::move()
{
    double *param = new double[4]; 
    if (x >= 1080 - abs(get_speed_x()) || x <= 0 + abs(get_speed_x()) || x2 >= 1080 - abs(get_speed_x()) || x2 <= 0 + abs(get_speed_x())) { speed_x = speed_x * -1;}
    if (y >= 720 - abs(get_speed_y()) || y <= 0 + abs(get_speed_y()) || y2 >= 720 - abs(get_speed_y()) || y2 <= 0 + abs(get_speed_y())) { speed_y = speed_y * -1;}
    x = x + speed_x;
    y = y + speed_y;
    x2 = x2 + speed_x;
    y2 = y2 + speed_y;
    param[0] = x;
    param[1] = y;
    param[2] = x2;
    param[3] = y2;
    return param;
}

double *tLine::rotate(double angle)
{
    double *param = new double[4]; 
    if (angle > 360) { angle = 0;}
    double dx, dy, dx2, dy2;
    dx = x2;
    dy = y2;
    dx2 = x;
    dy2 = y;
    x2 = x + (dx - x) * cos(angle * 3.14 / 180) - (dy - y) * sin(angle * 3.14 / 180);
    y2 = y + (dx - x) * sin(angle * 3.14 / 180) + (dy - y) * cos(angle * 3.14 / 180);
    x = x2 + (dx2 - x2) * cos(angle * 3.14 / 180) - (dy2 - y2) * sin(angle * 3.14 / 180);
    y = y2 + (dx2 - x2) * sin(angle * 3.14 / 180) + (dy2 - y2) * cos(angle * 3.14 / 180);
    param[0] = x;
    param[1] = y;
    param[2] = x2;
    param[3] = y2;
    return param;
}

double *tCircle::move()
{
    double *param = new double[2]; 
    if (x >= 1080 - abs(get_speed_x()) - 2 * radius || x <= 0 + abs(get_speed_x())) { speed_x = speed_x * -1;}
    if (y >= 720 - abs(get_speed_y()) -  2 * radius || y <= 0 + abs(get_speed_y())) { speed_y = speed_y * -1;}
    x = x + speed_x;
    y = y + speed_y;
    param[0] = x;
    param[1] = y;
    return param;
}

double *tCircle::rotate(double angle)
{
    return NULL;
}

double *tRectangle::move()
{
    double *param = new double[8]; 
    if (x >= 1080 - abs(get_speed_x()) || x <= 0 + abs(get_speed_x()) || x2 >= 1080 - abs(get_speed_x()) || x2 <= 0 + abs(get_speed_x()) || x3 >= 1080 - abs(get_speed_x()) || x3 <= 0 + abs(get_speed_x()) || x4 >= 1080 - abs(get_speed_x()) || x4 <= 0 + abs(get_speed_x())) { speed_x = speed_x * -1;}
    if (y >= 720 - abs(get_speed_y()) || y <= 0 + abs(get_speed_y()) || y2 >= 720 - abs(get_speed_y()) || y2 <= 0 + abs(get_speed_y()) || y3 >= 720 - abs(get_speed_y()) || y3 <= 0 + abs(get_speed_y()) || y4 >= 720 - abs(get_speed_y()) || y4 <= 0 + abs(get_speed_y())) { speed_y = speed_y * -1;}
    x = x + speed_x;
    y = y + speed_y;
    x2 = x2 + speed_x;
    y2 = y2 + speed_y;
    x3 = x3 + speed_x;
    y3 = y3 + speed_y;
    x4 = x4 + speed_x;
    y4 = y4 + speed_y;
    param[0] = x;
    param[1] = y;
    param[2] = x2;
    param[3] = y2;
    param[4] = x3;
    param[5] = y3;
    param[6] = x4;
    param[7] = y4;
    return param;
}

double *tRectangle::rotate(double angle)
{
    double *param = new double[8]; 
    if (angle > 360) { angle = 0;}
    double x_center, y_center, xo, yo, xo2, yo2, xo3, yo3, xo4, yo4;
    x_center = (x + x3) / 2;
    y_center = (y + y3) / 2;
    xo = x;
    yo = y;
    xo2 = x2;
    yo2 = y2;
    xo3 = x3;
    yo3 = y3;
    xo4 = x4;
    yo4 = y4;
    x = cos(angle * 3.14 / 180) * (xo - x_center) - sin(angle * 3.14 / 180) * (yo - y_center) + x_center;
    y = sin(angle * 3.14 / 180) * (xo - x_center) + cos(angle * 3.14 / 180) * (yo - y_center) + y_center;
    x2 = cos(angle * 3.14 / 180) * (xo2 - x_center) - sin(angle * 3.14 / 180) * (yo2 - y_center) + x_center;
    y2 = sin(angle * 3.14 / 180) * (xo2 - x_center) + cos(angle * 3.14 / 180) * (yo2 - y_center) + y_center;
    x3 = cos(angle * 3.14 / 180) * (xo3 - x_center) - sin(angle * 3.14 / 180) * (yo3 - y_center) + x_center;
    y3 = sin(angle * 3.14 / 180) * (xo3 - x_center) + cos(angle * 3.14 / 180) * (yo3 - y_center) + y_center;
    x4 = cos(angle * 3.14 / 180) * (xo4 - x_center) - sin(angle * 3.14 / 180) * (yo4 - y_center) + x_center;
    y4 = sin(angle * 3.14 / 180) * (xo4 - x_center) + cos(angle * 3.14 / 180) * (yo4 - y_center) + y_center;
    param[0] = x;
    param[1] = y;
    param[2] = x2;
    param[3] = y2;
    param[4] = x3;
    param[5] = y3;
    param[6] = x4;
    param[7] = y4;
    return param;
}

double *tTriangle::move()
{
    double *param = new double[6]; 
    if (x >= 1080 - abs(get_speed_x()) || x <= 0 + abs(get_speed_x()) || x2 >= 1080 - abs(get_speed_x()) || x2 <= 0 + abs(get_speed_x()) || x3 >= 1080 - abs(get_speed_x()) || x3 <= 0 + abs(get_speed_x())) { speed_x = speed_x * -1;}
    if (y >= 720 - abs(get_speed_y()) || y <= 0 + abs(get_speed_y()) || y2 >= 720 - abs(get_speed_y()) || y2 <= 0 + abs(get_speed_y()) || y3 >= 720 - abs(get_speed_y()) || y3 <= 0 + abs(get_speed_y())) { speed_y = speed_y * -1;}
    x = x + speed_x;
    y = y + speed_y;
    x2 = x2 + speed_x;
    y2 = y2 + speed_y;
    x3 = x3 + speed_x;
    y3 = y3 + speed_y;
    param[0] = x;
    param[1] = y;
    param[2] = x2;
    param[3] = y2;
    param[4] = x3;
    param[5] = y3;
    return param;
}

double *tTriangle::rotate(double angle)
{
    double *param = new double[6]; 
    if (angle > 360) { angle = 0;}
    double x_center, y_center, xo, yo, xo2, yo2, xo3, yo3;
    x_center = (x + x2 + x3) / 3;
    y_center = (y + y2 + y3) / 3;
    xo = x;
    yo = y;
    xo2 = x2;
    yo2 = y2;
    xo3 = x3;
    yo3 = y3;
    x = cos(angle * 3.14 / 180) * (xo - x_center) - sin(angle * 3.14 / 180) * (yo - y_center) + x_center;
    y = sin(angle * 3.14 / 180) * (xo - x_center) + cos(angle * 3.14 / 180) * (yo - y_center) + y_center;
    x2 = cos(angle * 3.14 / 180) * (xo2 - x_center) - sin(angle * 3.14 / 180) * (yo2 - y_center) + x_center;
    y2 = sin(angle * 3.14 / 180) * (xo2 - x_center) + cos(angle * 3.14 / 180) * (yo2 - y_center) + y_center;
    x3 = cos(angle * 3.14 / 180) * (xo3 - x_center) - sin(angle * 3.14 / 180) * (yo3 - y_center) + x_center;
    y3 = sin(angle * 3.14 / 180) * (xo3 - x_center) + cos(angle * 3.14 / 180) * (yo3 - y_center) + y_center;
    param[0] = x;
    param[1] = y;
    param[2] = x2;
    param[3] = y2;
    param[4] = x3;
    param[5] = y3;
    return param;
}

double *tEllipse::move()
{
    double *param = new double[2]; 
    if (x >= 1080 - abs(get_speed_x()) - 2 * radius_x || x <= 0 + abs(get_speed_x())) { speed_x = speed_x * -1;}
    if (y >= 720 - abs(get_speed_y()) - 2 * radius_y || y <= 0 + abs(get_speed_y())) { speed_y = speed_y * -1;}
    x = x + speed_x;
    y = y + speed_y;
    param[0] = x;
    param[1] = y;
    return param;
}

double *tEllipse::rotate(double angle)
{
    double *param = new double[2]; 
    if (angle > 360) { angle = 0;}
    double x_center, y_center, xo, yo;
    x_center = x;
    y_center = y;
    xo = radius_x;
    yo = radius_y;
    radius_x = cos(angle * 3.14 / 180) * (xo - x_center) - sin(angle * 3.14 / 180) * (yo - y_center) + x_center;
    radius_y = sin(angle * 3.14 / 180) * (xo - x_center) + cos(angle * 3.14 / 180) * (yo - y_center) + y_center;
    param[0] = radius_x;
    param[1] = radius_y;
    return param;
}