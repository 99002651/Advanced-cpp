#ifndef ADDRESS_H_INCLUDED
#define ADDRESS_H_INCLUDED

#include "Contact.h"

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

class Address
{
	private:
		list <Contact> contacts;

	public:
		void add_contact(string,string,string,string);
		void remove_contact(string);
		Contact* find_contact_by_primary_number(string);
		Contact* find_contact_by_name(string);
		Contact* update_contact(string,string,string,string);
   		Contact* display();
   		int count_all();
};

#endif // ADDRESS_H_INCLUDED
