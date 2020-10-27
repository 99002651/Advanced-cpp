#include<iostream>
#include "Banking.h"
//#include "Account.cpp"
#include <string>
#include <iterator>
#include <list>
#include "CreditAccount.h"
#include "SavingsAccount.h"
#include "Account.h"
#include <bits/stdc++.h>
using namespace std;

Banking::Banking(){};

void Banking::AddSavings(SavingsAccount SA){
  SavingsDB.push_back(SA);
}
void Banking::AddCurrent(CreditAccount CA){
  CreditDB.push_back(CA);
}
void Banking::RemoveAccount(std::string ID){
  std::list<SavingsAccount>::iterator iter;

  for(iter = SavingsDB.begin();iter != SavingsDB.end();iter++){
    if(iter->GetID() == ID){
      SavingsDB.erase(iter);
    }
  }
  std::list<CreditAccount>::iterator iter1;

  for(iter1 = CreditDB.begin();iter1 != CreditDB.end();iter1++){
    if(iter1->GetID() == ID){
      CreditDB.erase(iter1);
    }
  }

}
void DisplayData(SavingsAccount SA){
  cout<<SA.GetName()<<"'s Balance is:"<<SA.getBalance()<<endl;
  cout<<SA.GetName()<<"'s Account Number is "<<SA.GetID()<<endl;
}
void Banking::DisplayAllSavings(){
  std::list<SavingsAccount>::iterator iter;
  void DisplayData(SavingsAccount SA);
  std::for_each(begin(SavingsDB),end(SavingsDB),DisplayData);
}
void DisplayDataC(CreditAccount CA){
  cout<<CA.GetName()<<"'s Balance is:"<<CA.getBalance()<<endl;
  cout<<CA.GetName()<<"'s Account Number is "<<CA.GetID()<<endl;
}
void Banking::DisplayAllCredit(){
  std::list<CreditAccount>::iterator iter;
  void DisplayDataC(CreditAccount CA);
  std::for_each(begin(CreditDB),end(CreditDB),DisplayDataC);
}
SavingsAccount* Banking::CustomerSearch(std::string cname){
  /*std::list<SavingsAccount>::iterator iter;
  for(iter = SavingsDB.begin();iter != SavingsDB.end();iter++){
    if(cname == iter->GetName()){
      return &(*iter);
    }
  }*/
auto iter=std::find_if(begin(SavingsDB),end(SavingsDB),[cname](SavingsAccount &r1)
 {
 return(r1.GetName()==cname);
 }
 );
return &(*iter);
}
double Banking :: SavingsAverageBalance(){
std::list<SavingsAccount>::iterator iter;
  double sum = 0;
  for(iter = SavingsDB.begin();iter!=SavingsDB.end();iter++){
    sum = sum + iter -> getBalance();
  }
  return sum/SavingsDB.size();
}
double Banking :: CreditMaxBalance(){
std::list<CreditAccount>::iterator iter;
double maxBal;
for(iter = CreditDB.begin();iter != CreditDB.end();iter++){
  if(maxBal < iter ->getBalance()){
    maxBal = iter->getBalance();

  }
}
return maxBal;
}
int Banking :: SavingsBalanceRange(double min,double max){
int count = 0;
std::list<SavingsAccount>::iterator iter;
for(iter = SavingsDB.begin();iter != SavingsDB.end();iter++){
  if(max > iter->getBalance() > min){
  count++;
  }
}
return count;

}
int Banking :: CreditBalanceThreshold(double threshold){
int count = 0;
std::list<CreditAccount>::iterator iter;
for(iter = CreditDB.begin();iter != CreditDB.end();iter++){
  if(iter->getBalance()>=threshold){
  count++;
  }
}
return count;
}

/*
int main(){
  SavingsAccount S1("13253","Unmesh",10000);
  CreditAccount C1("13235","Unmesh",4577);
  CreditAccount C2("131325","Thameem",1577);
  SavingsAccount S2("13213","Thameem",30000);
  Banking B1;
  B1.AddSavings(S1);
  B1.AddCurrent(C1);
  B1.AddSavings(S2);
  B1.AddCurrent(C2);

  cout<<B1.CreditMaxBalance()<<endl;
  cout<<B1.CreditBalanceThreshold(2000)<<endl;
  cout<<B1.SavingsBalanceRange(1000,21000)<<endl;
  cout<<B1.SavingsAverageBalance()<<endl;
  //DisplayData("Unmesh");
  //DisplayData("Thameem");
  B1.DisplayAllSavings();
  B1.DisplayAllCredit();
  return 0;
}
*/
