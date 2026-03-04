#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;

vector<int> head_arr, tail_arr, nxt_arr;
vector<int> child_count;
vector<ll> data_size;

vector<int> in_time, out_time, initial_depth;
int dfs_timer = 0;
vector<int> bit;
vector<vector<int>> adj;

void bit_add(int idx, int val){
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}

void range_add(int l, int r, int val){
    if (l > r)
        return;
    bit_add(l, val);
    bit_add(r + 1, -val);
}

int bit_query(int idx){
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

void dfs(int u, int depth){
    in_time[u] = ++dfs_timer;
    initial_depth[u] = depth;
    for(int v: adj[u]){
        dfs(v, depth+1);
    }
    out_time[u] = dfs_timer;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    head_arr.assign(n + 1, 0);
    tail_arr.assign(n + 1, 0);
    nxt_arr.assign(n + 1, 0);
    child_count.assign(n + 1, 0);
    data_size.assign(n + 1, 0);

    in_time.assign(n + 1, 0);
    out_time.assign(n + 1, 0);
    initial_depth.assign(n + 1, 0);
    bit.assign(n + 2, 0);
    adj.assign(n + 1, vector<int>());

    for (int i = 2; i <= n; ++i){
        int p;
        cin >> p;
        adj[p].push_back(i);

        child_count[p]++;

        if (head_arr[p] == 0)
        {
            head_arr[p] = i;
            tail_arr[p] = i;
        }
        else
        {
            nxt_arr[tail_arr[p]] = i;
            tail_arr[p] = i;
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cin >> data_size[i];
    }

    dfs(1, 1);

    for (int i = 0; i < m; ++i){
        int op, target;
        cin >> op >> target;

        if(op == 1){
            int x = target;
            ll new_data_size = data_size[x];
            int new_child_count = 0;
            int new_head = 0, new_tail = 0;

            for (int y = head_arr[x]; y != 0; y = nxt_arr[y]){
                new_data_size += data_size[y];
                if(head_arr[y] != 0){
                    if (new_head == 0)
                    {
                        new_head = head_arr[y];
                        new_tail = tail_arr[y];
                    }
                    else
                    {
                        nxt_arr[new_tail] = head_arr[y];
                        new_tail = tail_arr[y];
                    }
                    new_child_count += child_count[y];
                }

            }

            data_size[x] = new_data_size;
            child_count[x] = new_child_count;
            head_arr[x] = new_head;
            tail_arr[x] = new_tail;

            if (in_time[x] < out_time[x])
            {
                range_add(in_time[x] + 1, out_time[x], -1);
            }

            cout << child_count[x] << " " << data_size[x] << "\n";
        }
        else if (op == 2){
            int z = target;
            int curr_depth = initial_depth[z] + bit_query(in_time[z]);
            cout << curr_depth << "\n";
        }
    }
    return 0;
}