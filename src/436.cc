#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string A, B;
    A.reserve(9), B.reserve(9);
    for(int r = 0; r < 6; ++r){
        for(int c = 0; c < 3; ++c){
            int x; cin >> x;
            if(r < 3)A += to_string(x);
            else B += to_string(x);
        }
    }
    const array<vector<int>, 9> adj = {
        vector<int>{1, 3},
        vector<int>{0, 2, 4},
        vector<int>{1, 5},
        vector<int>{0, 4, 6},
        vector<int>{1, 3, 5, 7},
        vector<int>{2, 4, 8},
        vector<int>{3, 7},
        vector<int>{4, 6, 8},
        vector<int>{5, 7}
    };
    unordered_map<string, int> dist;
    queue<string> q;
    dist[A] = 0;
    q.push(A);
    while (!q.empty()){
        string s = q.front(); q.pop();
        if(s == B){
            cout << dist[B] << "\n";
            return 0;
        }
        int z = s.find('0');
        for(int t : adj[z]){
            string ns = s;
            swap(ns[z], ns[t]);
            if (!dist.count(ns)){
                dist[ns] = dist[s] + 1;
                q.push(ns);
            }
        }
    }
    return 0;
}