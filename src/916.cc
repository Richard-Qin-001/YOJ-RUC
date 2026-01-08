#include <bits/stdc++.h>
using namespace std;

static constexpr int MAXN = 2e5 + 1;
vector<int> adj[MAXN];
int dfn[MAXN], low[MAXN];
int timer;
int n, start_node, end_node;
int min_cut_node = INT_MAX;

bool tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++timer;
    bool found_B = (u == end_node);
    for(int v : adj[u])
    {
        if(v == fa)continue;
        if(!dfn[v]){
            bool child_found_B = tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(child_found_B){
                found_B = true;
                if (u != start_node && u != end_node && low[v] >= dfn[u])
                {
                    if (u < min_cut_node)
                    {
                        min_cut_node = u;
                    }
                }
            }
        }
        else{
            low[u] = min(low[u], dfn[v]);
        }
    }
    return found_B;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int u, v;
    while (cin >> u >> v && (u != 0 || v != 0))
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> start_node >> end_node;
    timer = 0;
    tarjan(start_node, 0);
    if (min_cut_node == INT_MAX)
    {
        cout << "No solution" << endl;
    }
    else
    {
        cout << min_cut_node << endl;
    }

    return 0;
}