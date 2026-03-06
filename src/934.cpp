#include <iostream>
#include <set>
using namespace std;

// ____qcodep____
struct classcomp
{
    bool operator()(const pair<int, int>&a, const pair<int, int>&b) const {
        return a.second > b.second;
    }
};


void print_set(std::set<pair<int,int>, classcomp> &s)
{
   for (auto it = s.begin(); it != s.end(); it++)
   {
      cout << "{" << it->first << "," << it->second << "}";
   }
   cout << endl;
}

int main()
{
	std::set<pair<int,int>, classcomp> fifth;
	for (int i = 0; i < 3; i++)
	{
		int x, y;
		cin >> x >> y;
		fifth.insert({x,y});
	}
   print_set(fifth);
   return 0;
}