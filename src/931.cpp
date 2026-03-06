#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// ____qcodep____
void read_file(string file_name){
    ifstream fin(file_name);

    string line;
    if(fin.is_open()){
        while (getline(fin, line))
        {
            cout << line << endl;
        }
        
    }
    else {
        cerr << "Unable to open file!" << endl;
    }
}

int main()
{
	int n;
	string file_name, s;
	ofstream fout;
	cin >> file_name;
	fout.open(file_name);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		fout << s << endl;
	}
	fout.close();
	read_file(file_name + "wrong_name");
	read_file(file_name);
	return 0;
}