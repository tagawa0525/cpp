#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/tr1/memory.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Foo
{
  public:
    string name()
    {
      return "Foo";
    }
};
void deleter(Foo* pf)
{
  cout << "Call deleter" << endl;
  delete pf;
}

BOOST_AUTO_TEST_CASE( test_shared_pointer )
{
  Foo* pRow = new Foo;
  tr1::shared_ptr<Foo> pi(pRow);
}

BOOST_AUTO_TEST_CASE( test_shared_pointer2 )
{
  Foo* pRow = new Foo;
  tr1::shared_ptr<Foo> pi1(pRow);
  tr1::shared_ptr<Foo> pi2 = pi1;
  BOOST_CHECK_EQUAL(pRow->name(), "Foo");
  BOOST_CHECK_EQUAL(pi1->name(), "Foo");
  BOOST_CHECK_EQUAL(pi2->name(), "Foo");
  BOOST_CHECK_EQUAL(pi1.get()->name(), "Foo");
  BOOST_CHECK_EQUAL(pi2.get()->name(), "Foo");
}

BOOST_AUTO_TEST_CASE( test_deleter )
{
  Foo* pRow = new Foo;
  BOOST_CHECK( pRow );
  tr1::shared_ptr<Foo> pi(pRow, deleter);
}
