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

} // namespace
