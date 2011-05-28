#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
/*
 * Ref)
 * http://ameblo.jp/woooh-p/entry-10037362664.html
*/

using namespace std;

class BadObj
{
  public:
    BadObj()  { cout << __FUNCTION__ << endl; }
    ~BadObj()
    {
      cout << __FUNCTION__ << endl;
      throw runtime_error("~BadObj throw exception");
    }
};

class SomeObj
{
  public:
    SomeObj()  { cout << __FUNCTION__ << endl; }
    ~SomeObj() { cout << __FUNCTION__ << endl; }
};

class CompositeObj
{
  public:
    CompositeObj() :
      badObj(new BadObj),
      someObj(new SomeObj)
  { cout << __FUNCTION__ << endl;}
    ~CompositeObj()

    {
      cout << __FUNCTION__ << endl;
      delete badObj;
      delete someObj;
    }
  private:
    BadObj*  badObj;
    SomeObj* someObj;
};

void someobj_destractor_is_not_called()
{
  cout << endl << __FUNCTION__ << endl;
  try {
  CompositeObj compObj;
  }
  catch(exception& e) {
    cerr << e.what() << endl;
  }
}

void badobj_destractor_is_called_only_once()
{
  cout << endl << __FUNCTION__ << endl;
  try {
  CompositeObj* compObjs = new CompositeObj[2];
  delete[] compObjs;
  }
  catch(exception& e) {
    cerr << e.what() << endl;
  }
}

void shoud_never_throw()
{
  cout << endl << __FUNCTION__ << endl;
  try {
  CompositeObj compObj;
  throw runtime_error("throw exception");
  }
  catch(exception& e) {
    cerr << e.what() << endl;
  }
}

int main(int argc, char* argv[])
{
  someobj_destractor_is_not_called();
  badobj_destractor_is_called_only_once();
  shoud_never_throw();

  return 0;
}

