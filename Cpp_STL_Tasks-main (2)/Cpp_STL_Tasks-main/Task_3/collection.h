#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED

#include "point.h"
#include <list>
#include <iterator>
#include <algorithm>

class collection
{

    std::list <point> points;
    public:
    //* addPoint
    void addPoint(int x, int y);

   // * display all points
    void displayAll();

    //* count all points in a particular quadrant
    int count_in_quadrant(int Q);

    //* count all points lies on a circle boundary with given radius
    int count_circle(int r);

    //* find all points in a particular quadrant
    std::list<point> points_in_quadrant(int Q);

    //* find all points lies on a circle boundary with given radius
    std::list<point> points_circle(int r);

    //* count all points which are within a circle boundary of given radius
    std::list<point> points_within_circle(int r);

};

bool count_point_on_circle(const point &p, int r);
class dummy
{
    public:
   int operator()(const point &p)
   {
    int x = p.getX();
    int y = p.getY();
    return (x*x+y*y);
   }
};








#endif // COLLECTION_H_INCLUDED
