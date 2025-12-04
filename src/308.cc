#include <bits/stdc++.h>
using namespace std;

struct Factory
{
    int id;
    int status;
    int capacity;
    int basic_cost;
    int raise_cost_perPig;
};


int main(){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    vector<Factory> valid_fac_A, valid_fac_B, valid_fac_C;
    valid_fac_A.reserve(n), valid_fac_B.reserve(n), valid_fac_C.reserve(n);
    Factory fac;
    for(int i = 0; i < n; ++i){
        cin >> fac.id >> fac.status >> fac.capacity >> fac.basic_cost >> fac.raise_cost_perPig;
        if(fac.status==0){
            if(fac.capacity >= a)valid_fac_A.emplace_back(fac);
            if(fac.capacity >= b)valid_fac_B.emplace_back(fac);
            if(fac.capacity >= c)valid_fac_C.emplace_back(fac);
        }
    }
    int global_min = INT32_MAX, current_min = 0;
    vector<vector<int>> solutions;
    vector<int> solution(3);
    for(int i = 0; i < valid_fac_A.size(); ++i){
        for(int j = 0; j < valid_fac_B.size(); ++j){
            for(int k = 0; k < valid_fac_C.size(); ++k){
                int id1 = valid_fac_A[i].id, id2 = valid_fac_B[j].id, id3 = valid_fac_C[k].id;
                if (id1 != id2 && id1 != id3 && id2 != id3)
                {
                    current_min = valid_fac_A[i].basic_cost + valid_fac_A[i].raise_cost_perPig * a 
                    + valid_fac_B[j].basic_cost + valid_fac_B[j].raise_cost_perPig * b 
                    + valid_fac_C[k].basic_cost + valid_fac_C[k].raise_cost_perPig * c;
                    if(current_min < global_min){
                        solutions.clear();
                        solution = {id1, id2, id3};
                        solutions.emplace_back(solution);
                        global_min = current_min;
                    }
                    else if(current_min == global_min){
                        solution = {id1, id2, id3};
                        solutions.emplace_back(solution);
                    }
                }
            }
        }
    }
    if(solutions.empty()){
        cout << "NO" << endl;
        return 0;
    }
    sort(solutions.begin(), solutions.end());
    cout << global_min << "\n";
    cout << solutions[0][0] << " " << solutions[0][1] << " " << solutions[0][2] << endl;
    return 0;
}