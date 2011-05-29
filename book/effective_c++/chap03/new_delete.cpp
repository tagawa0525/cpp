#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

static const int Buf = 100;

BOOST_AUTO_TEST_CASE( test_delete )
{
  string* strings = new string[Buf];
  delete[] strings;
}

BOOST_AUTO_TEST_CASE( test_delte_fail )
{
  cout << "This test is fail." << endl;
  string* strings = new string[Buf];
  delete strings;
}

