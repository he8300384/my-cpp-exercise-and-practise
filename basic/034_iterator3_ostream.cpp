#include <iterator>
#include <vector>
#include <iostream>

int main( )
{
   using namespace std;

   

   // ostream_iterator for stream cout
   // with new line delimiter:
    ostream_iterator<int > intOut ( cout , "\n" );
    ostream_iterator<char > charOut ( cout , "\n" );

   // Standard iterator interface for writing
   // elements to the output stream:
   cout << "The integers written to the output stream\n"
        << "by intOut are:" << endl;
*intOut = 101;
*intOut = 20;
*intOut = 30;
*charOut = 'a';
}