#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class FontHandle
{
  public:
    FontHandle()
      :size(1)
    {}
    void setFontSize(int newSize)
    {
      size = newSize;
    }
  private:
    int size;
};

FontHandle getFont()
{
  FontHandle fh;
  return fh;
}

void releaseFont(FontHandle fh)
{
}

class Font
{
  public:
    explicit Font(FontHandle fh)
      :f(fh)
    {}
    ~Font() {releaseFont(f);}
    FontHandle get() const {return f;}
    operator FontHandle() const {return f;}
  private:
    FontHandle f;
};

void changeFontSize(FontHandle f, int newSize)
{
  f.setFontSize(newSize);
}


BOOST_AUTO_TEST_CASE( test_FontHandle )
{
  Font f(getFont());
  int newFontSize=2;

  changeFontSize(f.get(), newFontSize);
}

BOOST_AUTO_TEST_CASE( test_FontHandle_fail )
{
  Font f1(getFont());
  FontHandle f2 = f1;
}

