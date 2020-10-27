#include "library.h"
#include "book.h"
#include <gtest/gtest.h>
namespace {

class TripTest : public ::testing::Test {

protected:
  void SetUp() { // override {
  //  l.addBook(12,"abc","thameem","tum",150.5,0);
l.addBook(13,"kya","hai","ye",110,200);
l.addBook(14,"bus","hoo","gya",130,250);
l.addBook(15,"bus","hoo","gya",120,250);
l.addBook(15,"bus","hoo","gya",125,250);
  }
  void TearDown() {}
  Library l;
    
};
TEST_F(TripTest,countByPricebyMin)
{
	EXPECT_EQ(0,l.countByPricebyMin(150));
}
TEST_F(TripTest,countBypriceRange)
{
	EXPECT_EQ(4,l.countBypriceRange(0,131));
}
TEST_F(TripTest,findAveragePrice)
{
	EXPECT_EQ(121.25,l.findAveragePrice());	
}
/*TEST_F(TripTest,findbook)
{
	
 Library *lib= dynamic_cast<Library*>(ptr);
 EXPECT_STREQ("", lib->getOrigin().c_str());*/
 	
/*TEST_F(TripTest, DefaultConstructor) {
  FlightTrip ft;
  EXPECT_EQ(0, ft.getFlightNumber().length());
  EXPECT_EQ(0, ft.getOrigin().length());
  EXPECT_EQ(0, ft.getDestination().length());
  EXPECT_EQ(0, ft.getOperator().length());
  EXPECT_EQ(0, ft.getDistance());
}

TEST_F(TripTest, ParameterizedConstructor) {
  FlightTrip *fptr = dynamic_cast<FlightTrip*>(ptr);
  EXPECT_STREQ("Mumbai", fptr->getOrigin().c_str());
  EXPECT_STREQ("Delhi", fptr->getDestination().c_str());
  EXPECT_STREQ("6E123", fptr->getFlightNumber().c_str());
  EXPECT_STREQ("Indigo", fptr->getOperator().c_str());
  EXPECT_EQ(800, fptr->getDistance());
}
TEST_F(TripTest, ComputationTest) {
  EXPECT_EQ(8000, ptr->computeFare());      //800 * 10, INR 10 for each mile
  EXPECT_EQ(96, ptr->computeTravelTime());  //96 mins, if speed in 500 miles per hr
}
TEST_F(TripTest, AnotherTest) {
  FlightTrip ft("Bengaluru", "Chennai", "SG401", "SpiceJet", 200);
  Trip *pt = &ft;
  EXPECT_STREQ("Bengaluru", ft.getOrigin().c_str());
  EXPECT_STREQ("Chennai", ft.getDestination().c_str());
  EXPECT_STREQ("SG401", ft.getFlightNumber().c_str());
  EXPECT_STREQ("SpiceJet", ft.getOperator().c_str());
  EXPECT_EQ(200, ft.getDistance());
  EXPECT_EQ(2000, pt->computeFare());        //200 * 10 = 2000
  EXPECT_EQ(24, pt->computeTravelTime());    //24 mins, if speed is 500 miles per hr
}*/
} // namespace
