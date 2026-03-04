#include <bits/stdc++.h>
using namespace std;

int c, m, n;

struct Node
{
    int pos;
    int w;
    int left;
    int right;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> c >> m >> n;
    vector<pair<int, int>> initial_drops(m);
    for(int i = 0; i < m; ++i){
        cin >> initial_drops[i].first >> initial_drops[i].second;
    }
    sort(initial_drops.begin(), initial_drops.end());
    vector<Node> nodes(m+2);
    map<int, int> pos_to_idx;

    for (int i = 1; i <= m; ++i)
    {
        nodes[i].pos = initial_drops[i - 1].first;
        nodes[i].w = initial_drops[i - 1].second;
        nodes[i].left = i - 1;
        nodes[i].right = i + 1;
        pos_to_idx[nodes[i].pos] = i;
    }

    int current_m = m;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; ++i){
        int p;
        cin >> p;
        int idx = pos_to_idx[p];

        nodes[idx].w++;
        if (nodes[idx].w == 5){
            pq.push(nodes[idx].pos);
        }

        while (!pq.empty()) 
        {
            int curr_pos = pq.top();
            pq.pop();

            int curr_idx = pos_to_idx[curr_pos];
            if (nodes[curr_idx].w < 5)
                continue;
            nodes[curr_idx].w = 0;
            current_m--;
            int l_idx = nodes[curr_idx].left;
            int r_idx = nodes[curr_idx].right;
            if (l_idx >= 1 && l_idx <= m)
                nodes[l_idx].right = r_idx;
            if (r_idx >= 1 && r_idx <= m)
                nodes[r_idx].left = l_idx;

            if (l_idx >= 1 && l_idx <= m && nodes[l_idx].w > 0)
            {
                nodes[l_idx].w++;
                if (nodes[l_idx].w == 5)
                    pq.push(nodes[l_idx].pos);
            }

            if (r_idx >= 1 && r_idx <= m && nodes[r_idx].w > 0)
            {
                nodes[r_idx].w++;
                if (nodes[r_idx].w == 5)
                    pq.push(nodes[r_idx].pos);
            }
        }
        cout << current_m << endl;
    }
    return 0;
}