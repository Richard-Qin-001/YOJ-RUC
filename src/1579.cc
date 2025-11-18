#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <limits>
#include <cmath>

using namespace std;

struct Candidate
{
    string name;
    int num;
};


void split(const string&str, const char&seperator, vector<string>&output){
    stringstream ss(str);
    string segment;
    while(getline(ss, segment, seperator)){
        if (!segment.empty()){ 
            output.push_back(segment);
        }
    }
}

bool compare(const Candidate&a, const Candidate&b){
    if(a.num != b.num) return a.num > b.num;
    else return a.name[0] < b.name[0];
    return false;
}

void solve(){
    int N, K, M;
    cin >> N >> K >> M;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string ticket;
    unordered_map<string, int> candidates_map;
    vector<Candidate> candidates;
    while(true){
        getline(cin, ticket);
        if(ticket == "END") break;
        vector<string> names;
        split(ticket, ' ', names);
        bool is_valid_ticket = true;
        if(names.size() > K) continue;;
        unordered_map<string, int> name_list;
        for(auto&name:names) name_list[name]++;
        for(auto&name:name_list) if(name.second > 1) is_valid_ticket = false;
        if(is_valid_ticket)for(auto&name:names) candidates_map[name]++;
    }
    for(auto&candidate:candidates_map){
        Candidate c;
        c.name = candidate.first;
        c.num = candidate.second;
        candidates.push_back(c);
    }
    sort(candidates.begin(), candidates.end(), compare);
    int mid = ceil(N/2.0);
    if(candidates[0].num >= mid){
        int i = 0;
        while(candidates[i].num >= mid){
            cout << candidates[i].name << " " << candidates[i].num << endl;
            i++;
        }
    }
    else{
        int i = 0;
        while(i < candidates.size()){
            if(i < M) cout << candidates[i].name << " " << candidates[i].num << endl;
            else{
                if(candidates[i].num == candidates[i-1].num) cout << candidates[i].name << " " << candidates[i].num << endl;
                else break;
            }
            i++;
        }
    }
    
}

int main(){ios_base::sync_with_stdio(false); cin.tie(NULL); solve(); return 0;}