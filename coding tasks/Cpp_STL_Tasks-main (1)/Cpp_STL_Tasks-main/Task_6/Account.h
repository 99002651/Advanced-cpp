#ifndef __ACCOUNT_H
#define __ACCOUNT_H

#include<string>

class Account {
protected:
  std::string m_accNumber;
  std::string m_accName;
  double m_balance;
public:
  Account();
  Account(std::string,std::string,double);
  Account(std::string,std::string);
  Account(const Account&);
  virtual double debit(double)=0;
  virtual double credit(double)=0;
  virtual void display()=0;
  double getBalance();
};

#endif
