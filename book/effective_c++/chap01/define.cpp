#include <iostream>
#include <string>
#include <vector>

using namespace std;
const double AspectRatio = 1.63;

const string AuthorName("Scott Meyers");
class GamePlayer{
    private:
        static const int NumTurns = 5;
        int scores[NumTurns];
};

int main(int argc, char* argv[])
{
    cout << AspectRatio << endl;
    return 0;
}

