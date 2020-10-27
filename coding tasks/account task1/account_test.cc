#include "banking.h"
#include <gtest/gtest.h>
namespace{
    TEST(account,debit_test){
        account a("sandhya","3715",9000);
        a.debit(100);
        EXPECT_EQ(8900,a.getBalance());
    }
    TEST(account,credit_test){
        account a("sandhya","3715",9000);
        a.credit(100);
        EXPECT_EQ(9100,a.getBalance());
    }
    TEST(banking,maxbal_test){
        banking a;
        a.addAccount("annu","3716",18000);
        EXPECT_EQ("3716",a.AccountWithMaxBal());
    }
}

