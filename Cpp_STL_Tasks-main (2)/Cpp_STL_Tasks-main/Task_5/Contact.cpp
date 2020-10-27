#include"Contact.h"
#include <iostream>

using namespace std;

int Contact::unique_id=0;

Contact::Contact():first_name(""),last_name(""),primary_number(""),alternate_number(""){}

Contact::Contact(string first_name,string last_name,string primary_number,string alternate_number):
	first_name(first_name),last_name(last_name),primary_number(primary_number),alternate_number(alternate_number){unique_id++;}

/*
Contact::Contact(const Contact& obj):
	first_name(obj.first_name),last_name(obj.last_name),primary_number(obj.primary_name),alternate_number(obj.alternate_number){}
*/

void Contact::set_contact_values(string primary_number_reset,string first_name_reset,string last_name_reset,string alternate_number_reset)
{
	primary_number=primary_number_reset;
	first_name=first_name_reset;
	last_name=last_name_reset;
	alternate_number=alternate_number_reset;
}

string Contact::getfirst_name()
{
    return first_name;
}

string Contact::getlast_name()
{
    return last_name;
}

string Contact::getprimary_number()
{
    return primary_number;
}

string Contact::getalternate_number()
{
    return alternate_number;
}
