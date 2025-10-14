# include <iostream>
# include <algorithm>
using namespace std;
int main(){
    int n, t = 2;
    int ab = 0, ac = 0, ad = 0, bc = 0, bd = 0, cd = 0;
    int occupied_ab, occupied_bc, occupied_cd;
    char c1, c2;
    cin >> n;
    while(t != 0){
        cin >> t;
        if (t == 0) break;
        cin >> c1 >> c2;
        if (c1 == 'A' && c2 == 'B'){
            if (t == 1) ab++;
            else if (t == 2) ab--;
        }
        else if (c1 == 'A' && c2 == 'C'){
            if (t == 1) ac++;
            else if (t == 2) ac--;
        }
        else if (c1 == 'A' && c2 == 'D'){
            if (t == 1) ad++;
            else if (t == 2) ad--;
        }
        else if (c1 == 'B' && c2 == 'C'){
            if (t == 1) bc++;
            else if (t == 2) bc--;
        }
        else if (c1 == 'B' && c2 == 'D'){
            if (t == 1) bd++;
            else if (t == 2) bd--;
        }
        else if (c1 == 'C' && c2 == 'D'){
            if (t == 1) cd++;
            else if (t == 2) cd--;
        }
    }
    occupied_ab = ab + ac + ad;
    occupied_bc = ac + ad + bc + bd;
    occupied_cd = ad + bd + cd;



    cout << n-max(occupied_ab, max(occupied_bc, occupied_cd)) << endl;
    return 0;
}

//这里分成每个区间，分别计算每个区间占用座位数，进而计算全程能剩下几个座位
