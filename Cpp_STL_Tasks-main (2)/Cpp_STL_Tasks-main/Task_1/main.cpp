#include "library.h"
#include "book.h"
#include<iostream>
#include<algorithm>
#include<list>
#include<iterator>
using namespace std;
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

ostream & operator << (std::ostream& rout,  const Book& obj) 
{ 
    rout << obj.m_id<<std::endl; 
	rout << obj.m_title<<std::endl;
	rout << obj.m_author<<std::endl;
	rout << obj.m_publisher<<std::endl;
	rout << obj.m_price<<std::endl;
	rout << obj.m_pages<<std::endl;
    return rout; 


} 



void Library::addBook(int id, std::string title, std::string title_author, std::string publisher,double price,int pages)
{
	//books.push_back(Book(id,title,title_author,publisher, price,pages));
	Book b(id,title,title_author,publisher, price,pages);
	books.push_back(std::move(b));
}
Book& Library::findBookWithMaxPages()
{
	auto iter=std::max_element(books.begin(),books.end(),
	[](Book& r1,Book& r2) {
                    return (r1.getPages() < r2.getPages());
	});
	//std::cout<<*iter;
	return *iter;

}
 Book& Library::findBookWithMinPriceByPublisher()
 {
    auto iter=std::min_element(books.begin(),books.end(),
	[](Book& r1,Book& r2) {
                    return (r1.getPages() < r2.getPages());
	});
	//cout<<*iter;
	return *iter;
 }
 int Library::countByPricebyMin(int min1)
 {
//namespace ranges = std::ranges;
//int num_items3 = ranges::count_if(v.begin(), v.end(), [](int i){return i % 3 == 0;});
	int count = count_if(books.begin(),books.end(),[min1](Book &r1) {return (r1.getPrice()>min1);});

//std::cout<<count<<endl;
            return count;
}

int Library::countBypriceRange(int min1,int max1)
{
	int count1=0; 
	for_each(begin(books),end(books),[min1,max1,&count1](Book &r1)
					 { if(r1.getPrice()>min1 && r1.getPrice()<max1)count1++;});
int i=0;
//std::cout<<"count"<<count<<std::endl;

return count1/2;
}
Book* Library::findBookById(int id)
{
	
	auto iter=std::find_if(begin(books),end(books),[id](Book &r1)
	{
		return(r1.getId()==id);
	}
	);
//cout<<*iter;
	return &(*iter);
}
double Library::findAveragePrice()
{	
	double sum=0;
	//double avg=0.0;
	std::for_each(begin(books),end(books),[&](Book &r1)
	{
		sum =sum+r1.getPrice();
	}
	);
	//std::cout<<std::endl;
	//std::cout<<"avg:"<<sum/books.size();
	return sum/books.size();
}
/* int Library::countAllBooksByAuthor(std::string author)
 {
	 int count1=0;
	 //std::list<Book> b1;
	 auto iter=std::find_if(begin(books),end(books),[&](Book &r1)
	{	
		if(r1.getAuthor()==author) count1++;
		if((r1.getAuthor()==author)&&(books.end()))
		      return(r1.getAuthor()==author);
	}
	);
	cout<<*iter;
	return (count1);
 }*/


/*int main()
{
	Library l;
//Library l1;
l.addBook(12,"abc","thameem","tum",150.5,0);
l.addBook(13,"kya","hai","ye",110,200);
l.addBook(14,"bus","hoo","gya",130,250);
l.addBook(15,"bus","hoo","gya",120,250);
l.findBookWithMaxPages();
l.findBookWithMinPriceByPublisher();
l.countByPricebyMin(150);
l.countBypriceRange(0,131);
l.findBookById(13);
l.findAveragePrice();
}*/

