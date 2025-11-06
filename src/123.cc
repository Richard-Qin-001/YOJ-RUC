#include <iostream>

using namespace std;

int step_count = 0;

void move(int n, char source, char destination, char auxiliary){
    if(n==1){
        step_count++;
        cout << "[step " << step_count << "]  move plate 1#  from " << source <<" to " << destination << endl;
        return;
    }
    else{
        move(n-1, source, auxiliary, destination);
        step_count++;
        cout << "[step " << step_count << "]  move plate " << n << "#  from " << source <<" to "<< destination << endl;
        move(n-1, auxiliary, destination, source);
    }
}

void solve(){
    int n;
    cin >> n;
    move(n, 'a', 'c', 'b');
    cout << step_count << endl;
}
int main(){solve(); return 0;}