#include "banking.h"
#include <iostream>
#include <list>
#include <iterator>

void banking :: addAccount(std::string name,std::string num,double bal){
    a.push_back(account(name,num,bal));
}
void banking :: removeAccountByid(std::string num){
    std::list <account> :: iterator iter;
    for(iter = a.begin();iter != a.end();++iter){
        if(num == iter->getId()){
            a.erase(iter);
            break;
        }
    }
}

std::string banking :: AccountWithMaxBal(){
    std::list <account> :: iterator iter = a.begin();
    double maxbal = iter -> getBalance();
    std::string id = iter->getId();
    for(;iter != a.end();++iter){
        if(maxbal < iter->getBalance()){
            maxbal = iter->getBalance();
            id = iter->getId();
        }
    }
    return id;
}
