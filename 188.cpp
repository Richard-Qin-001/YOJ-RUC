# include <iostream>

using namespace std;

int main(){
    int x1, x2, x3, y1, y2, y3;
    int vx1, vy1, vx2, vy2;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    cout << 3 << endl;
    vx1 = x1-x3;
    vx2 = x2-x3;
    vy1 = y1-y3;
    vy2 = y2-y3;
    cout << x3 + vx1 + vx2 << " " << y3 + vy1 + vy2 << endl;
    vx1 = x1-x2;
    vx2 = x3-x2;
    vy1 = y1-y2;
    vy2 = y3-y2;
    cout << x2 + vx1 + vx2 << " " << y2 + vy1 + vy2 << endl;
    vx1 = x2-x1;
    vx2 = x3-x1;
    vy1 = y2-y1;
    vy2 = y3-y1;
    cout << x1 + vx1 + vx2 << " " << y1 + vy1 + vy2 << endl;
    
   
    return 0;
}