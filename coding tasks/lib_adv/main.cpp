#include "library.h"
#include "book.h"
#include<iostream>
#include<algorithm>
#include<list>
#include<iterator>
std::list<Book> books;
   int Book::getId()
  {
	 return m_id;
  }


  double Book::getPrice()
  {
  	return m_price;
  }

  std::string Book::getAuthor()
  {
  	return m_author;
  }
  int Book::getPages()
  {
  	return m_pages;
  }
   std::string Book::getPublisher()
   {
   	return  m_publisher;
   }
   std::string Book::getTitle()
   {
   	return  m_title;
   }

  Book::Book(){}
Book::Book(int id,std::string tit,std::string au_tit,std::string pub,double pri,int pages): m_id(id),m_title(tit),m_author(au_tit),m_publisher(pub),m_price(pri),m_pages(pages){}

void Library::addBook(int id, std::string title, std::string title_author, std::string publisher,double price,int pages)
{
	books.push_back(Book(id,title,title_author,publisher, price,pages));
}
Book& Library::findBookWithMaxPages()
{
	auto iter=std::max_element(books.begin(),books.end(),
	[](Book& r1,Book& r2) {
                    return (r1.getPages() < r2.getPages());
	});
	std::cout<<iter->getId()<<std::endl;
	std::cout<<iter->getPrice()<<std::endl;
	std::cout<<iter->getAuthor()<<std::endl;
	std::cout<<iter->getPages()<<std::endl;
	std::cout<<iter->getPublisher()<<std::endl;
	std::cout<<iter->getTitle()<<std::endl;
	return *iter;

}
 Book& Library::findBookWithMinPriceByPublisher()
 {
    auto iter=std::min_element(books.begin(),books.end(),
	[](Book& r1,Book& r2) {
                    return (r1.getPages() < r2.getPages());
	});

	std::cout<<iter->getId()<<std::endl;
	std::cout<<iter->getPrice()<<std::endl;
	std::cout<<iter->getAuthor()<<std::endl;
	std::cout<<iter->getPages()<<std::endl;
	std::cout<<iter->getPublisher()<<std::endl;
	std::cout<<iter->getTitle()<<std::endl;
	return *iter;
 }
/* int Library::countByPriceRange(int min1,int max1)
 {

	 count = std::count_if(books.begin(),books.end(),[min1,max1](Book) {

            if(min1)

	 return(x>min);});
 }*/




int main()
{
	Library l;
//Library l1;
l.addBook(12,"abc","thameem","tum",150.5,0);
l.addBook(13,"kya","hai","ye",150.5,200);
l.addBook(14,"bus","hoo","gya",150.5,250);
l.findBookWithMaxPages();
l.findBookWithMinPriceByPublisher();


}

