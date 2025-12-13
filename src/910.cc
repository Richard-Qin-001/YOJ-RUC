#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Node
{
    ll g;
    int l;
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Node> last;

    ll max_v = 0;

    for(int i = 1; i <= n; ++i)
    {
        ll val;
        cin >> val;

        vector<Node> curr;

        for(auto&node : last)
        {
            node.g = gcd(node.g, val);
            if (curr.empty() || node.g != curr.back().g)
            {
                curr.push_back(node);
            }
        }

        if (curr.empty() || val != curr.back().g)
        {
            curr.push_back({val, i});
        }

        for(auto & node : curr)
        {
            max_v = max(max_v, node.g * (i - node.l + 1));
        }
        last = curr;
    }
    cout << max_v << endl;
    return 0;
}