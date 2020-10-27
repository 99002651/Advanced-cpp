#include<iostream>
#include"Account.h"
#include"CreditAccount.h"
#include"SavingsAccount.h"
using namespace std;

Account::Account(){}
Account::Account(string number,string name,double balance):
    m_accNumber(number),m_accName(name),m_balance(balance){}

Account::Account(string number,string name):
   m_accNumber(number),m_accName(name),m_balance(0){
}
Account::Account(const Account &ref):
    m_accNumber(ref.m_accNumber),m_accName(ref.m_accName),m_balance(ref.m_balance){
}
CreditAccount::CreditAccount(){}
CreditAccount::CreditAccount(string number,string name,double balance):
   Account(number, name, balance){
}
CreditAccount::CreditAccount(string number,string name):
   Account(number,name){
}

SavingsAccount::SavingsAccount(){}
SavingsAccount::SavingsAccount(string number,string name,double balance):
    Account(number,name,balance){
}
SavingsAccount::SavingsAccount(string number,string name):
    Account(number,name){
}

std::string CreditAccount::GetID(){
  return m_accNumber;
}
std::string CreditAccount::GetName(){
  return m_accName;
}
double CreditAccount::getBalance(){
  return m_balance;
}
std::string SavingsAccount::GetID(){
  return m_accNumber;
}
std::string SavingsAccount::GetName(){
  return m_accName;
}
double SavingsAccount::getBalance(){
  return m_balance;
}

double CreditAccount::debit(double dr)
{
    m_balance -= dr;
    return m_balance;
}
double SavingsAccount::debit(double dr)
{
    m_balance -= dr;
    return m_balance;
}
double CreditAccount::credit(double cr)
{
    m_balance += cr;
    return m_balance;
}
double SavingsAccount::credit(double cr)
{
    m_balance += cr;
    return m_balance;
}
void CreditAccount::display(){
    cout<<"Current:"<<m_accName<<","<<m_accNumber<<","<<m_balance<<endl;
}
void SavingsAccount::display(){
    cout<<"Savings:"<<m_accName<<","<<m_accNumber<<","<<m_balance<<endl;
}
