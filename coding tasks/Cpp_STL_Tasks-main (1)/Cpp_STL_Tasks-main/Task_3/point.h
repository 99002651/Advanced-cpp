#ifndef __POINT_H_
#define __POINT_H_


class point
{

  int m_x;
  int m_y;

  public:
      point();
      point(int x, int y);
      point(const point &p);
      point(point &&p);
      point& operator=(point &&p);

      double distance() const;
      point flip_horizontal();
      point flip_vertical();
      point displace(int dx, int dy);
      int getX() const;
      int getY() const;
      void setX(int);
      void setY(int);
      void display() const;
};

#endif // __POINT_H_
