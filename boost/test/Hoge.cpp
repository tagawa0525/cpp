#include <iostream>

using namespace std;

class Hoge
{
  public:
    string puts();
};


string Hoge::puts()
{
  return "hoge";
}

#ifndef BOOST_TEST_MAIN
int main(int argc, char* argv[])
{

  Hoge hoge;
  cout << hoge.puts() << endl;

  return 0;
}
#endif
