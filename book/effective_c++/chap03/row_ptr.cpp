#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

class Investment
{
  public:
    std::string str;
    Investment(std::string _str)
      :str(_str)
    {}
  private:
};

Investment* createInvestment(std::string _str="default")
{
  Investment* pInv = new Investment(_str);
  return pInv;
}

Investment* return_NULL()
{
  return NULL;
}

Investment* return_row_pointer()
{
  Investment* pInv = createInvestment();
  return pInv;
}

Investment* return_deleted_pointer()
{
  Investment* pInv = createInvestment();
  delete pInv;
  return pInv;
}

BOOST_AUTO_TEST_CASE( test_createInvestment )
{
  BOOST_CHECK_EQUAL(createInvestment()->str, "default");
}

BOOST_AUTO_TEST_CASE( test_return_NULL )
{
  BOOST_CHECK(return_NULL()==NULL);
}

BOOST_AUTO_TEST_CASE( test_return_row_pointer )
{
  BOOST_CHECK_EQUAL(return_row_pointer()->str, "default");
}

BOOST_AUTO_TEST_CASE( test_return_deleted_pointer )
{
  std::cout << "This test is always fail." << std::endl;
  std::cout << "Because returned pointer is deleted." << std::endl;
  std::cout << "And this test does not reach the last." << std::endl;
  BOOST_CHECK(return_deleted_pointer()==NULL);
  BOOST_CHECK_EQUAL(return_deleted_pointer()->str, "default");
  std::cout << "This test is not end." << std::endl;
}

