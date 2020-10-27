#ifndef CONTACT_H_INCLUDED
#define CONTACT_H_INCLUDED

#include <string>
#include <cstdint>

using namespace std;

class Contact
{
	protected:
		string first_name;
		string last_name;
		string primary_number;
		string alternate_number;
		static int unique_id;

	public:
   		Contact();
   		Contact(string,string,string,string);
   		//Contact(const Contact&);
   		string getfirst_name();
   		string getlast_name();
   		string getprimary_number();
   		string getalternate_number();
   		void set_contact_values(string,string,string,string);
};

#endif // CONTACT_H_INCLUDED
