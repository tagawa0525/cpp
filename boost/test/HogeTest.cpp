#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "Hoge.cpp"

BOOST_AUTO_TEST_CASE( test_test )
{
  BOOST_CHECK_EQUAL(1, 1);
  BOOST_CHECK_EQUAL(1, 0);
}

BOOST_AUTO_TEST_CASE( hoge_test )
{
  Hoge hoge;
  BOOST_CHECK_EQUAL(hoge.puts(), "hoge");
}

//BOOST_AUTO_TEST_CASE( abort_test )
//{
//  abort();
//}
