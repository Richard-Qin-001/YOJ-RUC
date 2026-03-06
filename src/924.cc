#include <bits/stdc++.h>
using namespace std;

struct Material
{
    int t;
    int d;
};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Material> materials(n);
    for (int i = 0; i < n; ++i){
        cin >> materials[i].t >> materials[i].d;
    }
    stable_sort(materials.begin(), materials.end(), [](const Material &a, const Material &b){
        return a.d < b.d;
    });
    int curr_time = 0;
    priority_queue<int> maxHeep;
    int selected_tasks = 0;
    for (int i = 0; i < n; ++i){
        if(curr_time + materials[i].t <= materials[i].d){
            curr_time += materials[i].t;
            maxHeep.push(materials[i].t);
            selected_tasks++;
        }
        else{
            int t_max = maxHeep.top();
            if(materials[i].t < maxHeep.top()){
                maxHeep.pop();
                maxHeep.push(materials[i].t);
                curr_time = curr_time - t_max + materials[i].t;
            }
        }
    }
    cout << selected_tasks << endl;
    return 0;
}   