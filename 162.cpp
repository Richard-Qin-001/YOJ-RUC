# include <iostream>

using namespace std;

int main(){
    int _1, _2, n1, n2, i_n;
    char ch, ch_1, ch_2;
    cin >> _1 >> ch >> _2 >> ch >> n1 >> ch >> ch_1;
    int a, b, c, d, e, tmp;
    a = n1 / 10000;
    tmp = n1 - a * 10000;
    b = tmp / 1000;
    tmp = tmp - b * 1000;
    c = tmp / 100;
    tmp = tmp - c * 100;
    d = tmp / 10;
    e = tmp - d * 10;

    int f, g ,h;
    f = _2 / 100;
    tmp = _2 - f * 100;
    g = tmp / 10;
    h = tmp - g * 10;
    i_n = (_1 + 2 * f + 3 * g + 4 * h + 5 * a + 6 * b + 7 * c + 8 * d + 9 * e) % 11;
    if (i_n != 10){
        ch_2 = char(i_n + '0');
        if (ch_1 == ch_2){
        cout << "Right";
    }
        else cout << _1 << ch << _2 << ch << n1 << ch << i_n;
    }
    else {
        ch_2 = 'X';
        if (ch_1 == ch_2) cout << "Right";
        else cout << _1 << ch << _2 << ch << n1 << ch << 'X';
    }
    cout << endl;
    
    return 0;

}