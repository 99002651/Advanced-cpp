#include<iostream>
#include "gtest/gtest.h"
#include "collection.h"
#include "point.h"

namespace
{
  
TEST(pointTest , DefaultConstructor)
 {
  point p1;
  EXPECT_EQ(0, p1.getX());
  EXPECT_EQ(0, p1.getY()); 
}
TEST(pointTest , parameterConstructor)
 {
  point p1(2,3);
  EXPECT_EQ(2, p1.getX());
  EXPECT_EQ(3, p1.getY()); 
 }
TEST(pointTest , moveConstructor)
 {
  point p1(2,3);
  point p2(std::move(p1));
  EXPECT_EQ(2, p2.getX());
  EXPECT_EQ(3, p2.getY()); 
 }

}

/*

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc,argv);
  return RUN_ALL_TESTS();
}

*/

