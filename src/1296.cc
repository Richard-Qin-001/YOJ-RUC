#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);

    string pdnf, pcnf;

    cout << "[Part 1: Truth Table]" << endl;
    for (int i = 0; i < 4; ++i) {
        bool p = (i >> 1) & 1;
        bool q = (i >> 0) & 1;
        bool A = !p || q;
        cout << "p=" << p << " q=" << q << " p>q=" << A << endl;
        if (A) {
            pdnf += ( "m" + to_string(i) + '|' ); 
        } else {
            pcnf += ( "M" + to_string(i) + '&' );
        }
    }

    cout << endl << "[Part 2: Normal Forms]" << endl;
    pdnf.pop_back();
    pcnf.pop_back();
    cout << "PDNF: " << pdnf << endl;
    cout << "PCNF: " << pcnf << endl;

    cout << endl << "[Part 3: Entailment Validation]" << endl;
    bool valid = true;
    for (int i = 0; i < 8; ++i) {
        bool p = (i >> 2) & 1;
        bool q = (i >> 1) & 1;
        bool r = (i >> 0) & 1;
        bool A = !p || q;
        bool B = !(!q || r) || (!p || r);
        cout << "p=" << p << " q=" << q << " r=" << r << ": A=" << A << ", B=" << B << endl;
        if (A > B) {
            valid = false;
        }
    }
    cout << "Result: " << (valid ? "yes" : "no") << endl;
    return 0;
}