#include "SavingsAccount.h"
#include "CreditAccount.h"
#include "Account.h"
#include<list>
#include<iterator>

using namespace std;

class Banking {
  std::list<SavingsAccount>SavingsDB;
  std::list<CreditAccount>CreditDB;
public:
  Banking();
  void AddSavings(SavingsAccount);
  void AddCurrent(CreditAccount);
  void RemoveAccount(std::string);
  SavingsAccount* CustomerSearch(std::string);
  double SavingsAverageBalance();
  double CreditMaxBalance();
  int SavingsBalanceRange(double,double);
  int CreditBalanceThreshold(double);
  void DisplayAllSavings();
  void DisplayAllCredit();
};
