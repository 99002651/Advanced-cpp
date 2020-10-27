#include "point.h"
#include <iostream>
#include <cmath>

point::point():m_x(0),m_y(0)
{ //std::cout << "Default Constructor\n";
}

point::point(int x, int y):m_x(x),m_y(y)
{ //std::cout << "Paramterised Constructor\n";
}


point::point(const point &p):m_x(p.m_x), m_y(p.m_y)
{ //std::cout << "Copy Constructor\n";
}


//move constructor
point::point(point &&p):m_x(p.m_x), m_y(p.m_y)
{
   //std::cout << "Move Constructor\n";
}

//move operator=
 point& point::operator=(point &&p)
 {
     //std::cout << "Move = operator\n";
     m_x = p.m_x;
     m_y = p.m_y;

     return *this;
 } 
 
double point::distance() const
{
    return sqrt(m_x*m_x+m_y*m_y);
}


void point::display() const
{
    std::cout<<"("<<m_x<<","<<m_y<<")"<<std::endl;
}

point  point:: flip_horizontal()
{
    m_y= -m_y;
    return point(m_x,m_y);

}
point point::flip_vertical()
{
    m_x= -m_x;
    return point(m_x,m_y);
}

point point::displace(int dx, int dy)
{
    m_x += dx;
    m_y += dy;
    return point(m_x,m_y);

}
int point:: getX() const
{
    return m_x;
}
int point::getY() const
{
    return m_y;
}
void point::setX(int x)
{
    m_x=x;
}
void point::setY(int y)
{
    m_y=y;
}
