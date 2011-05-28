#include <iostream>
#include <string>
#include <vector>

using namespace std;
static const int NumArray = 5;

class Hoge
{
  public:
    static const int num = 8;
};

void needconst(const int *array)
{
  for(int i=0; i<NumArray; i++){
    cout << array[i] << endl;
  }
}

int main(int argc, char* argv[])
{
  int array[NumArray];

  for(int i=0; i<NumArray; i++){
    array[i] = i*2;
  }
  needconst(array);

  Hoge hoge;
  cout << hoge.num << endl;

  return 0;
}

