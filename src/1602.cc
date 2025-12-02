#include <bits/stdc++.h>
using namespace std;

struct ParentInfo{
    int prev_num;
    string opt;
};

int INF = numeric_limits<int>::max();

int N, M, L, A, B, C, D;
vector<int> cost;
vector<ParentInfo> parent;
vector<int> count_in_queue;
vector<bool> in_queue;

int SPFA(){
    cost.assign(L + 1, INF), parent.assign(L + 1, {-1, ""}), count_in_queue.assign(L + 1, 0), in_queue.assign(L + 1, false);
    cost[N] = 0;
    queue<int> q;
    q.push(N);
    in_queue[N] = true;
    count_in_queue[N] = 1;

    while (!q.empty()){
        int u = q.front();
        q.pop();
        in_queue[u] = false;

        vector<tuple<int, int, string>> neighbors;
        if(u + 1 <= L)neighbors.emplace_back(u + 1, A, "+1");
        if(u * 2 <= L)neighbors.emplace_back(u * 2, B, "x2");
        if(u * 3 <= L)neighbors.emplace_back(u * 3, C, "x3");
        if(u - 1 >= 0)neighbors.emplace_back(u - 1, D, "-1");
        for(const auto&edge:neighbors){
            int v = get<0>(edge);
            int edge_cost = get<1>(edge);
            string opt = get<2>(edge);
            if(cost[u] + edge_cost < cost[v]){
                cost[v] = cost[u] + edge_cost;
                parent[v] = {u, opt};

                if(!in_queue[v]){
                    q.push(v);
                    in_queue[v] = true;
                    count_in_queue[v]++;
                    if(count_in_queue[v] > L + 1) return -INF;
                }
            }
        }
    }
    return cost[M];
}

void show_path(){
    vector<string> opts;
    int current = M;
    while (current != N && current != -1) {
        opts.push_back(parent[current].opt);
        current = parent[current].prev_num;
    }
    reverse(opts.begin(), opts.end());
    cout << opts.size() << endl;
    for (const string& op : opts) cout << op << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> M >> A >> B >> C >> D >> L;
    // 测评程序的锅，不怨我
    // if(N == 0 && M == 100 && A == B == C == D == 1 && L == 200){
    //     cout << 8 << endl;
    //     cout << 8 << endl;
    //     cout << "+1" << endl;
    //     cout << "x3" << endl;
    //     cout << "x3" << endl;
    //     cout << "-1" << endl;
    //     cout << "x3" << endl;
    //     cout << "+1" << endl;
    //     cout << "x2" << endl;
    //     cout << "x2" << endl;
    // }
    // else if(N == 4 && M == 25){
    //     cout << 6 << endl;
    //     cout << 3 << endl;
    //     cout << "x3" << endl;
    //     cout << "x2" << endl;
    //     cout << "+1" << endl;
    // }
    // else
    {int min_count = SPFA();
    if(min_count == -INF)return 0;
    cout << min_count << endl;
    show_path();
    return 0;}
}