#include "collection.h"
#include <iostream>
#include <functional>

void collection::addPoint(int x, int y)
{
    //point p1(x,y);
    //points.push_back(std::move(p1));
    points.push_back(point(x,y));
}

   // * display all points
void collection::displayAll()
{

    std::for_each(points.begin(),points.end(),[](const point &p){
                             std::cout<<"("<<p.getX()<<","<<p.getY()<<")"<<std::endl;});   
}

    //* count all points in a particular quadrant
int collection::count_in_quadrant(int Q)
{
    
    std::list <point> :: iterator iter;
    if(Q==1)
    {
      auto count = std::count_if(points.begin(),points.end(),[](const point &p)
                                                  {return p.getX()>0 && p.getY()>0;});
      return count;                                            
    }
    else if(Q==2)
    {
      auto count = std::count_if(points.begin(),points.end(),[](const point &p)
                                                  {return p.getX()<0 && p.getY()>0;});
      return count;                                            
    }
    else if(Q==3)
    {
      auto count = std::count_if(points.begin(),points.end(),[](const point &p)
                                                  {return p.getX()<0 && p.getY()<0;});
       return count;                                           
        
    }
    else if(Q==4)
    {
      auto count = std::count_if(points.begin(),points.end(),[](const point &p)
                                                  {return p.getX()>0 && p.getY()<0;});
       return count;                                           
    }

    return NULL;
}

//* count all points lies on a circle boundary with given radius


bool count_point_on_circle(const point &p, int r)
{
    int x = p.getX();
    int y = p.getY();
    return (x*x+y*y) == r*r; 
}

int collection::count_circle(int r)
{ 
/* auto count = std::count_if(points.begin(),points.end(), [&](const point &p){
                                                                dummy d;
                                                                return d(p) == r*r; });

*/
 auto count = std::count_if(points.begin(),points.end(), std::bind(count_point_on_circle,std::placeholders::_1,r));
    
 return count;
}

    //* find all points in a particular quadrant
std::list<point> collection::points_in_quadrant(int Q)
{
    std::list<point> quadrant;
    if(Q==1)
    {
     std::for_each(points.begin(),points.end(),[&](const point &p){
              if(p.getX()>0 && p.getY()>0)
         {
             quadrant.push_back(point(p.getX(),p.getY()));
         }    });

    }
    else if(Q==2)
    {
        std::for_each(points.begin(),points.end(),[&](const point &p){
              if(p.getX()<0 && p.getY()>0)
         {
             quadrant.push_back(point(p.getX(),p.getY()));
         }    });
       
    }
    else if(Q==3)
    {
       std::for_each(points.begin(),points.end(),[&](const point &p){
              if(p.getX()<0 && p.getY()<0)
         {
             quadrant.push_back(point(p.getX(),p.getY()));
         }    });
    }
    else if(Q==4)
    {
       std::for_each(points.begin(),points.end(),[&](const point &p){
              if(p.getX()>0 && p.getY()<0)
         {
             quadrant.push_back(point(p.getX(),p.getY()));
         }    });
    }

    return quadrant;

}

    //* find all points lies on a circle boundary with given radius
std::list<point> collection::points_circle(int r)
{
    int x,y;
    // centre as origin
    std::list<point> cir;
    std::for_each(points.begin(),points.end(),[&](const point &p)
      {  
         x = p.getX();
         y = p.getY();
         if((x*x+y*y)==r*r)
            cir.push_back(point(x,y));  });
    
    return cir;
}



    //* count all points which are within a circle boundary of given radius
std::list<point> collection::points_within_circle(int r)
{
    int x,y;
    // centre as origin
    std::list<point> cir;
    std::for_each(points.begin(),points.end(),[&](const point &p)
      {  
         x = p.getX();
         y = p.getY();
         if((x*x+y*y)<r*r)
            cir.push_back(point(x,y));  });

    return cir;
}

