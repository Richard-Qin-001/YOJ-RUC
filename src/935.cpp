#include <iostream>
#include <string>
using namespace std;

int main()
{
   try
   {
      int x;
      cin >> x;

    //   ____qcodep____
      if (x % 2 == 0)
      {
          throw string("0");
      }
      else
      {
          throw to_string(x);
      }
   }

    // ____qcodep____
   catch (string s)
   {
      cout << s << endl;
      return 1;
   }

   return 0;
}
