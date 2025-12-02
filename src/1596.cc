#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Candidate
{
    int a;
    int b;
    bool is_survive = true;
};

void solve(){
    int n;
    cin >> n;
    vector<Candidate> candidates(n);
    for(auto&c:candidates)cin >> c.a >> c.b;
    sort(candidates.begin(), candidates.end(), [](const Candidate&p1, const Candidate&p2){return p1.a > p2.a;});
    for(int i = 1; i < n; i++)if(candidates[0].a >= candidates[i].b)candidates[i].is_survive=false;
    auto new_end = remove_if(candidates.begin(), candidates.end(), [](const Candidate&c){return !c.is_survive;});
    candidates.erase(new_end, candidates.end());
    ll total_survive = candidates.size();
    if(total_survive != 1)if(candidates[1].a >= candidates[0].b)total_survive--;
    cout << total_survive << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}