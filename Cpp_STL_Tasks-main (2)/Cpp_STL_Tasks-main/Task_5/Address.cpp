#include "Address.h"
#include "Contact.h"

#include <list>
#include <iterator>

using namespace std;

void Address::add_contact(string first_name,string last_name,string primary_number,string alternate_number)
{
    contacts.push_back(Contact(first_name,last_name,primary_number,alternate_number));
}

void Address::remove_contact(string primary_number)
{
    //list<Contact> :: iterator iter;
    for(auto iter=contacts.begin();iter!=contacts.end();iter++)
    {
        if(iter->getprimary_number()==primary_number)
        {
           contacts.erase(iter);
           break;
        }
    }
}

Contact* Address::find_contact_by_primary_number(string primary_number)
{
    //list<Contact> :: iterator iter;
    for(auto iter=contacts.begin();iter!=contacts.end();iter++)
    {
        if(primary_number==iter->getprimary_number())
        {
            return &(*iter);
        }
    }
    return NULL;
}

Contact* Address::find_contact_by_name(string any_name)
{
    //list<Contact> :: iterator iter;
    for(auto iter=contacts.begin();iter!=contacts.end();iter++)
    {
        if(any_name==iter->getfirst_name())
        {
            return &(*iter);
        }
        if(any_name==iter->getlast_name())
        {
            return &(*iter);
        }
    }
    return NULL;
}

Contact* Address::display()
{
	//list<Contact> :: iterator iter;
	for(auto iter=contacts.begin();iter!=contacts.end();iter++)
	{
		return &(*iter);
	}
	return NULL;
}

int Address:: count_all()
{
   return contacts.size();
}

Contact* Address::update_contact(string primary_number,string first_name,string last_name,string alternate_number)
{
	//list<Contact> :: iterator iter;
	for(auto iter=contacts.begin();iter!=contacts.end();iter++)
	{
		if(primary_number==iter->getprimary_number())
		{
			iter->set_contact_values(primary_number,first_name,last_name,alternate_number);
			//*iter.first_name=first_name;
			//*iter.last_name=last_name;
			//*iter.alternate_number=alternate_number;
			return &(*iter);
		}
	}
	return NULL;
}
