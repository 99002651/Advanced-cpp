#ifndef __LIBRARY_H
#define __LIBRARY_H
#include<list>
#include"book.h"
//#include<bits/stdc+.h>
#include<string>
#include<iostream>
#include<iterator>
using namespace std;
class Library {

  public:
  void addBook(int id, std::string title, std::string title_author,
                std::string publisher,double price,int pages);
  void addBook(const Book& ref);
  Book* findBookById(int id);
  void displayAll();
  void removeBookById(int id);
  double findAveragePrice();
  Book& findBookWithMaxPages();  //Book*
  Book& findBookWithMinPriceByPublisher(); //Book*
  double findAveragePriceByPublisher(std::string);
  int countByPricebyMin(int);
  int countBypriceRange(int,int);
  int countByPriceLimitAndAuthor(std::string, int price);
 Book* findAllBooksByAuthor(std::string);
 int countAllBooksByAuthor(std::string);
  void sortByTitle();
  void display();
};
#endif // __LIBRARY_H














