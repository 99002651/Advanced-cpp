#include "banking.h"
#include <gtest/gtest.h>
namespace{
    TEST(account,debit_test){
        account a("Unmesh","3715",9000);
        a.debit(100);
        EXPECT_EQ(8900,a.getBalance());
    }
    TEST(account,credit_test){
        account a("Unmesh","3715",9000);
        a.credit(100);
        EXPECT_EQ(9100,a.getBalance());
    }

   TEST(banking,Finding_account_by_id){
        banking obj;
        obj.addAccount("OP","3715",9000);
        obj.addAccount("Thameem","3716",18000);
        obj.addAccount("Sowmya","4569",50000);
        EXPECT_EQ("Thameem",obj.FindAccountById("3716"));
    }
   TEST(banking,Finding_account_with_customer_name){
        banking obj;
        obj.addAccount("OP","3715",9000);
        obj.addAccount("Thameem","3716",18000);
        obj.addAccount("Sowmya","4569",50000);
        EXPECT_EQ("4569",obj.FindAccountsWithCustomerName("Sowmya"));
    }

    TEST(banking,Average_balance){
        banking obj;
        obj.addAccount("Rahul","3715",16000);
        obj.addAccount("Sandhya","3716",14000);
        EXPECT_EQ(15000,obj.AvgBalance());
    }
    TEST(banking,count_Within_Range){
        banking obj;
        obj.addAccount("Sandhya","3715",9000);
        obj.addAccount("Thameem","3716",18000);
        obj.addAccount("OP","4569",50000);
        EXPECT_EQ(3,obj.CountAccountsWithInRange(1000,200000));
    }
    TEST(banking,count_Lessthan_limit){
        banking obj;
        obj.addAccount("Sandhya","3715",9000);
        obj.addAccount("Thameem","3716",18000);
        obj.addAccount("OP","4569",50000);
        EXPECT_EQ(3,obj.CountAccountsLessThanLimit(60000));
    }
     TEST(banking,maxbal_test){
        banking obj;
        obj.addAccount("Rahul","3715",9000);
        obj.addAccount("Sowmya","3716",18000);
        EXPECT_EQ("3716",obj.AccountWithMaxBal());
    }

}
int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
