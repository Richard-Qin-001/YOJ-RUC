# include <iostream>
# include <iomanip>

int main(){
    using namespace std;
    int n;
    cin >> n;
    cout << setw(15) << right << n << endl;
    cout << setw(15) << right << static_cast<unsigned int>(n) << endl;
    cout << setw(15) << right << oct << n << endl;
    cout << setw(15) << right << hex << n << endl;
    return 0;
}