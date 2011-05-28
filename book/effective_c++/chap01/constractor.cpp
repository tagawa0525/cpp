#include <iostream>
#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Base
{
  private:
    virtual void print() = 0;
  public:
    /* constructors cannot be declared virtual */
    Base(){ cout << "Base constractor" << endl; }
    virtual ~Base(){ cout << "Base destractor" << endl; }
};
void Inh1::print() { cout << "Inh2 print" << endl; }

class Inh1 : Base
{
  public:
    Inh1(){ cout << "Inh1 constractor" << endl; }
    ~Inh1(){ cout << "Inh1 destractor" << endl; }
    void print();
};
void Inh1::print() { cout << "Inh2 print" << endl; }

class Inh2 : Inh1
{
  public:
    Inh2(){ cout << "Inh2 constractor" << endl; }
    ~Inh2(){ cout << "Inh2 destractor" << endl; }
    void print();
};
void Inh2::print() { cout << "Inh2 print" << endl; }

class BadBase
{
  public:
    BadBase(){ cout << "BadBase constractor" << endl; }
    ~BadBase(){
      cout << "BadBase destractor" << endl;
      throw;
    }
};

class BadInh : BadBase
{
  public:
    BadInh(){ cout << "BadInh constractor" << endl; }
    ~BadInh(){
      cout << "BadInh destractor" << endl;
      throw;
    }
};

class Pure
{ virtual void print()=0;};

int main(int argc, char* argv[])
{

  Inh2 inh;
  inh.print();

  BadInh binh;

  /* You can not instance, because Pure has pure virtual function */
  //Pure pr;

  return 0;
}

