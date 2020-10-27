#include<gtest/gtest.h>
#include "Banking.cpp"
#include "Account.cpp"

TEST(Banking,Tests1){
  SavingsAccount S1("13253","Unmesh",10000);
  CreditAccount C1("13235","Unmesh",4577);
  CreditAccount C2("131325","Thameem",1577);
  SavingsAccount S2("13213","Thameem",30000);
  Banking B1;
  B1.AddSavings(S1);
  B1.AddCurrent(C1);
  B1.AddSavings(S2);
  B1.AddCurrent(C2);
  ASSERT_EQ(4577,B1.CreditMaxBalance());
  ASSERT_EQ(1,B1.CreditBalanceThreshold(2000));
  ASSERT_EQ(1,B1.SavingsBalanceRange(1000,21000));
  ASSERT_EQ(20000,B1.SavingsAverageBalance());
  ASSERT_EQ(10000,B1.CustomerSearch("Unmesh")->getBalance());
}
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
