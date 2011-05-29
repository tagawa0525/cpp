#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/tr1/memory.hpp>
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

std::tr1::shared_ptr<Investment> return_auto_ptr()
{
  std::tr1::shared_ptr<Investment> pInv(createInvestment());
  return pInv;
}

Investment* return_row_ptr()
{
  std::tr1::shared_ptr<Investment> pInv(createInvestment());
  return pInv.get();
}

BOOST_AUTO_TEST_CASE( test_createInvestment )
{
  std::tr1::shared_ptr<Investment> pInv(createInvestment());
  BOOST_CHECK_EQUAL(pInv->str, "default");
  BOOST_CHECK_EQUAL(pInv.get()->str, "default");
}

BOOST_AUTO_TEST_CASE( test_NULL )
{
  std::tr1::shared_ptr<Investment> pInv1(createInvestment("pInv1"));
  std::tr1::shared_ptr<Investment> pInv2(pInv1);
  BOOST_CHECK_EQUAL(pInv1->str, "pInv1");
  BOOST_CHECK_EQUAL(pInv2->str, "pInv1");
  pInv1 = pInv2;
  BOOST_CHECK_EQUAL(pInv1->str, "pInv1");
  BOOST_CHECK_EQUAL(pInv2->str, "pInv1");
}

BOOST_AUTO_TEST_CASE( test_return_auto_ptr )
{
  std::tr1::shared_ptr<Investment> pInv = return_auto_ptr();
  BOOST_CHECK(pInv.get()!=NULL);
  BOOST_CHECK_EQUAL(pInv->str, "default");
}

BOOST_AUTO_TEST_CASE( test_return_row_ptr )
{
  std::cout << "This test is always fail." << std::endl;
  std::cout << "Because returned pointer is deleted." << std::endl;
  std::cout << "And this test does not reach the last." << std::endl;
  Investment* pInv = return_row_ptr();
  BOOST_CHECK(pInv==NULL);
  BOOST_CHECK_EQUAL(pInv->str, "default");
  std::cout << "This test is not end." << std::endl;
}
