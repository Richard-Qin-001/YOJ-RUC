# include <iostream>


using namespace std;

int main(){
    int a1, a2, b1, b2, c1, c2, d1, d2, count=0;
    cin >> a2>>b2>>c2>>d2;
    a1 = 0;
    b1 = 1;
    c1 = 1;
    d1 = 0;
    if (a2==a1) count++;
    if (c2==b1) count++;
    if (d2==c1) {
        count++;;
    }
    if (d2==d1) count++;
    cout << count << endl;
    return 0;

}
