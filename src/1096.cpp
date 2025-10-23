// # include <iostream>
// # include <algorithm>
// # include <string>
// # include <unordered_map>

// using namespace std;

// int main(){
//     // 提高输入输出速度
//     std::ios_base::sync_with_stdio(false);
//     std::cin.tie(NULL);
//     // 否则读入大量数据会报错
//     string dna_sequence;
//     cin >> dna_sequence;
//     int k;
//     cin >> k;
//     int N = dna_sequence.length();
//     int max_count = 0;
//     unordered_map<string, int> kmer_counts;
//     for(int i = 0; i <= N - k; i++){
//         string kmer = dna_sequence.substr(i, k);
//         kmer_counts[kmer]++;
//         max_count = max(kmer_counts[kmer], max_count);

//     }
//     cout << max_count;
//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> mp;
int main()
{
    string a;
    cin >> a;
    int n;
    cin >> n;
    int maxx = -1;
    int len = a.size();
    for (int i = 0; i < len - n + 1; i++)
    {
        // string b;
        //  b.assign(a, i, n);
        string b = a.substr(i, n);
        maxx = max(++mp[b], maxx);
    }
    cout << maxx;
}

