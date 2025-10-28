#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Candidate
{
    int id;
    int score;
};

bool compareForLine(const Candidate& a, const Candidate& b) {
     return a.score > b.score;
}

bool compareForOutput(const Candidate& a, const Candidate& b) {
    if (a.score != b.score) {
        return a.score > b.score;
    }
    return a.id < b.id;
}

void solve(){
    int n, m;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    vector<Candidate> candidates(n);

    for (int i = 0; i < n; i++){
        if (!(cin >> candidates[i].id >> candidates[i].score)) return;
    }

    int targetCount = floor(m * 1.5);

    sort(candidates.begin(), candidates.end(), compareForLine);

    int P_index = min(n, targetCount) - 1;

    int score_line = candidates[P_index].score;

    vector<Candidate> accepted_candidates;
    for (const auto& c : candidates) {
        if (c.score >= score_line) {
            accepted_candidates.push_back(c);
        }
    }

    cout << score_line << " " << accepted_candidates.size() << endl;

    sort(accepted_candidates.begin(), accepted_candidates.end(), compareForOutput);

    for (const auto& c : accepted_candidates) {
        cout << c.id << " " << c.score << endl;
    }
}

int main(){
    solve();
    return 0;
}