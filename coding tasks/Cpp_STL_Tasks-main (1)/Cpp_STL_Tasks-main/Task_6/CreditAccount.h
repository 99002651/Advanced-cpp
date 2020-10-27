#ifndef __BANKING_H
#define __BANKING_H

#include<string>
#include"Account.h"

class CreditAccount : public Account {
public:
  CreditAccount();
  CreditAccount(std::string,std::string,double);
  CreditAccount(std::string,std::string);
  double debit(double);
  double credit(double);
  void display();
  std::string GetID();
  std::string GetName();
  double getBalance();
};

#endif
