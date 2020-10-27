#include "Contact.h"
#include "Address.h"

#include <gtest/gtest.h>

namespace {

class AddressTest : public ::testing::Test {

protected:
  void SetUp()
  {
    samples.add_contact("Rahul", "Rathod", "9845012340", "9845012341");
    samples.add_contact("Gunturu", "Sowmya", "9845012342", "9845012343");
    samples.add_contact("Sandhya", "Devi", "9845012344", "9845012345");
    samples.add_contact("Unmesh", "Sameer", "9845012346", "9845012347");
    samples.add_contact("Syed", "Thameem", "9845012348", "9845012349");
    samples.add_contact("Sampreeth", "Rayadurga", "9845012350", "9845012351");
  }
  void TearDown() {}
  Address samples;
};

TEST_F(AddressTest, AddContactTest) {
  EXPECT_EQ(6, samples.count_all());
  samples.add_contact("Om", "Prakash", "9845012352", "9845012353");
  EXPECT_EQ(7, samples.count_all());
}

TEST_F(AddressTest, CountTest) {             //Just After Setup
  EXPECT_EQ(6, samples.count_all());
}

TEST_F(AddressTest, FindContactByPrimaryNumber) {
  Contact *ptr = samples.find_contact_by_primary_number("9845012348");
  //EXPECT_NE(NULL, ptr);
  EXPECT_STREQ("Syed", ptr->getfirst_name().c_str());
  EXPECT_STREQ("Thameem", ptr->getlast_name().c_str());
  EXPECT_STREQ("9845012349", ptr->getalternate_number().c_str());
}

TEST_F(AddressTest, FindContactByFirstName) {
  Contact *ptr = samples.find_contact_by_name("Sampreeth");
  //EXPECT_NE(NULL, ptr);
  EXPECT_STREQ("Rayadurga", ptr->getlast_name().c_str());
  EXPECT_STREQ("9845012350", ptr->getprimary_number().c_str());
  EXPECT_STREQ("9845012351", ptr->getalternate_number().c_str());
}

TEST_F(AddressTest, FindContactByLastName) {
  Contact *ptr = samples.find_contact_by_name("Rathod");
  //EXPECT_NE(NULL, ptr);
  EXPECT_STREQ("Rahul", ptr->getfirst_name().c_str());
  EXPECT_STREQ("9845012340", ptr->getprimary_number().c_str());
  EXPECT_STREQ("9845012341", ptr->getalternate_number().c_str());
}

TEST_F(AddressTest, UpdateContactByPrimaryNumber) {
  Contact *ptr = samples.update_contact("9845012340","Om", "Prakash","9845012353");
  //EXPECT_NE(NULL, ptr);
  EXPECT_STREQ("Om", ptr->getfirst_name().c_str());
  EXPECT_STREQ("Prakash", ptr->getlast_name().c_str());
  EXPECT_STREQ("9845012353", ptr->getalternate_number().c_str());
}

} // namespace
