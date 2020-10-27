#ifndef __SAVINGS_ACCOUNT_H
#define __SAVINGS_ACCOUNT_H

#include<string>
#include"Account.h"

class SavingsAccount : public Account {
public:
  SavingsAccount();
  SavingsAccount(std::string,std::string,double);
  SavingsAccount(std::string,std::string);
  double debit(double);
  double credit(double);
  void display();
  std::string GetID();
  std::string GetName();
  double getBalance();
};

#endif
