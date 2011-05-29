#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/tr1/memory.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Investment
{
  public:
    Investment()
      :_tax(true),
      _day(10)
  {}
    bool isTaxFree() const;
    int getHeld() const;
  private:
    bool _tax;
    int _day;
};
inline bool Investment::isTaxFree() const
{
  return _tax;
}
inline int Investment::getHeld() const
{
  return _day;
}

Investment* createInvestment()
{
  Investment* pInv = new Investment();
  return pInv;
}

int daysHeld(const Investment* pi)
{
  return pi->getHeld();
}

BOOST_AUTO_TEST_CASE( test_daysHeld )
{
  std::tr1::shared_ptr<Investment> pInv(createInvestment());
  int days = daysHeld(pInv.get());
  BOOST_CHECK_EQUAL(days, 10);
}

BOOST_AUTO_TEST_CASE( test_isTaxFree_arrow )
{
  std::tr1::shared_ptr<Investment> pInv(createInvestment());
  bool taxable = !(pInv->isTaxFree());
  BOOST_CHECK_EQUAL(taxable, false);
}

BOOST_AUTO_TEST_CASE( test_isTaxFree_cast )
{
  std::tr1::shared_ptr<Investment> pInv(createInvestment());
  bool taxable = !((*pInv).isTaxFree());
  BOOST_CHECK_EQUAL(taxable, false);
}
