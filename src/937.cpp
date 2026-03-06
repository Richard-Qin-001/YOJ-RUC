#include <iostream>
#include <list>
using namespace std;

int main()
{
   list<int> Link;
   int item;
   for (int i = 0; i < 5; i++)
   { 
      cin >> item;
      Link.push_back(item);
   }

//    ____qcodep____
   for (std::list<int>::iterator it = Link.begin(); it != Link.end(); ++it){
    cout << *it << " ";
   }

   return 0;
}
