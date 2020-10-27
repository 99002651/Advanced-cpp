#include<iostream>
#include "collection.h"
#include "point.h"

int main()
{
  /*point p1;
  std::cout << "p1 -\n";

  point p2(2,3);
  std::cout << "p2 -\n";

  point p3(std::move(p2));
  std::cout << "p3 -\n";
  
  point p4;
  p4 = std::move(p2);
  std::cout << "p4 -\n";
 */

  collection data;
  data.addPoint(1,-2);
  data.addPoint(2,3);
  data.addPoint(-4,3);
  data.addPoint(3,-4);
  data.addPoint(4,-5);
  data.addPoint(5,6);
  data.addPoint(-3,4);

  // data.displayAll();
 // std::cout << data.count_in_quadrant(1) << std::endl;

  /*  std::list<point> p = data. points_in_quadrant(4);
    std::for_each(p.begin(),p.end(),[](const point& p1)
    { p1.display();}
    );
*/

 /*   std::list<point> p = data.points_within_circle(3);
    std::for_each(p.begin(),p.end(),[](const point& p1)
    { p1.display();}
    );
*/
  std::list<point> p = data.points_circle(5);
    std::for_each(p.begin(),p.end(),[](const point& p1)
    { p1.display();}
    );
}