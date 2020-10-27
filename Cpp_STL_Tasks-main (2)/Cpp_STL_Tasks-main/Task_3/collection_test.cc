#include<iostream>
#include "gtest/gtest.h"
#include "collection.h"
#include "point.h"
#include<algorithm>

namespace
{

class pointtest : public ::testing::Test
{
  public:
  void SetUp()
  {
  data.addPoint(1,-2);
  data.addPoint(2,3);
  data.addPoint(-4,3);
  data.addPoint(3,-4);
  data.addPoint(4,-5);
  data.addPoint(5,6);
  data.addPoint(-3,4);

  }
  void TearDown() {}
  collection data;
};

TEST_F(pointtest,count_in_quad )
 {
  EXPECT_EQ(2, data.count_in_quadrant(1));
 }

TEST_F(pointtest,points_in_quadrant)
 {
    int count=0;
    std::list<point> p = data. points_in_quadrant(4);
    std::for_each(p.begin(),p.end(), [&](const point& p1)
    { count++;}
    );
  EXPECT_EQ(3,count);
 }

TEST_F(pointtest,points_within_circle)
 {
    int count=0;
    std::list<point> p = data.points_within_circle(3);
    std::for_each(p.begin(),p.end(), [&](const point& p1)
    { count++;}
    );
  EXPECT_EQ(1,count);
 }

TEST_F(pointtest,points_circle)
 {
    int count=0;
    std::list<point> p = data.points_circle(5);
    std::for_each(p.begin(),p.end(), [&](const point& p1)
    { count++;}
    );
  EXPECT_EQ(3,count);
 }


}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}
