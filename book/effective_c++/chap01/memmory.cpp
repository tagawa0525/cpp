#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const int static_const_defined_in_global = 1;
static int static_undefined_in_global;

const int const_defined_in_global = 1;
int undefined_in_global;

int func()
{
}

int main(int argc, char* argv[])
{
static const int static_const_defined_in_main = 1;
static int static_undefined_in_main;

const int defined_in_main = 1;
int undefined_in_main;

static_undefined_in_global = 1;
undefined_in_global        = 1;
static_undefined_in_main   = 1;
undefined_in_main          = 1;

cout << "static_const_defined_in_global: " << &static_const_defined_in_global << endl;
cout << "static_undefined_in_global    : " << &static_undefined_in_global     << endl;
cout << "const_defined_in_global       : " << &const_defined_in_global        << endl;
cout << "undefined_in_global           : " << &undefined_in_global            << endl;
cout << "static_const_defined_in_main  : " << &static_const_defined_in_main   << endl;
cout << "static_undefined_in_main      : " << &static_undefined_in_main       << endl;
cout << "defined_in_main               : " << &defined_in_main                << endl;
cout << "undefined_in_main             : " << &undefined_in_main              << endl;
cout << "main                          : " << &main                           << endl;
cout << "func                          : " << &func                           << endl;

  return 0;
}

