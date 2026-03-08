#include <bits/stdc++.h>
using namespace std;

int calc_score(const vector<int>& dice){
    array<int, 7> cnt;
    for (int d : dice)
        cnt[d]++;
    if (cnt[4] == 4 && cnt[1] == 2)
        return 2048;
    if (cnt[4] == 6)
        return 1024;
    if (cnt[1] == 6)
        return 512;
    for (int i = 2; i <= 6; ++i)
    {
        if (i == 4)
            continue;
        if (cnt[i] == 6)
            return 256;
    }
    if (cnt[4] == 5)
        return 128;
    for (int i = 1; i <= 6; ++i)
    {
        if (i == 4)
            continue;
        if (cnt[i] == 5)
        {
            return 64 + (cnt[4] == 1 ? 1 : 0);
        }
    }
    if (cnt[4] == 4)
    {
        int extra = 0;
        for (int i = 1; i <= 6; i++)
        {
            if (i != 4)
                extra += i * cnt[i];
        }
        return 32 + extra;
    }
    bool straight = true;
    for (int i = 1; i <= 6; ++i)
    {
        if (cnt[i] != 1)
            straight = false;
    }
    if (straight)
        return 16;
    if (cnt[4] == 3)
        return 8;
    for (int i = 1; i <= 6; ++i)
    {
        if (i == 4)
            continue;
        if (cnt[i] == 4)
        {
            if (cnt[4] == 2)
                return 4 + 2;
            if (cnt[4] == 1)
                return 4 + 1;
            return 4;
        }
    }
    if (cnt[4] == 2)
        return 2;
    if (cnt[4] == 1)
        return 1;

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> A(6), B(6), pool;
    for (int i = 0; i < 6; i++)
    {
        cin >> A[i];
        pool.push_back(A[i]);
    }
    for (int i = 0; i < 6; i++)
    {
        cin >> B[i];
        pool.push_back(B[i]);
    }

    int orig_A_score = calc_score(A);

    int max_u1 = -1, max_u2 = -1;

    for (int mask = 0; mask < (1 << 12); ++mask){
        if (__builtin_popcount(mask) == 6){
            vector<int> S1;
            vector<int> S2;

            for (int i = 0; i < 12; ++i)
            {
                if ((mask >> i) & 1)
                    S1.push_back(pool[i]);
                else
                    S2.push_back(pool[i]);
            }

            int score1 = calc_score(S1);
            int score2 = calc_score(S2);

            max_u1 = max(max_u1, score1);

            if (score2 >= orig_A_score)
            {
                max_u2 = max(max_u2, score1);
            }

        }
    }
    cout << max_u1 << " " << max_u2 << endl;
    return 0;
}