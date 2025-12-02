#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll merge(vector<int>&arr, vector<int>&temp, int left, int mid, int right){
    int i = left, j = mid + 1, k = left;
    ll inversion_count = 0;
    while (i <= mid && j <= right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else{
            inversion_count += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= right){
        temp[k++] = arr[j++];
    }
    for (int idx = left; idx <= right; ++idx) {
        arr[idx] = temp[idx];
    }
    return inversion_count;
}

ll merge_sort(vector<int>&arr, vector<int>&temp, int left, int right){
    ll inversion_count = 0;
    if(left < right){
        int mid = left + (right - left) / 2;
        inversion_count += merge_sort(arr, temp, left, mid);
        inversion_count += merge_sort(arr, temp, mid+1, right);
        inversion_count += merge(arr, temp, left, mid, right);
    }
    return inversion_count;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> features(n, vector<int>(m));
    vector<int> cards(n);
    for(int i = 0; i < n; i++)cards[i] = i;
    for(int i = 0; i < n; i++)for(int j = 0; j < m; j++)cin >> features[i][j];
    int queries;
    cin >> queries;
    for(int i = 0; i < queries; i++){
        int x, y;
        cin >> x >> y;
        x--, y--;
        vector<int> target = cards;
        stable_sort(target.begin(), target.end(), [&features, &y](const int a, const int b){
            if(features[a][y] != features [b][y])return features[a][y] < features[b][y];
            return a < b;
        });
        vector<int> permx = cards;
        stable_sort(permx.begin(), permx.end(), [&features, &x](const int a, const int b){
            if(features[a][x] != features [b][x])return features[a][x] < features[b][x];
            return a < b;
        });
        vector<int> target_map(n);
        for(int j = 0; j < n; j++)target_map[target[j]] = j;
        vector<int> perm(n);
        for(int j = 0; j < n; j++)perm[j] = target_map[permx[j]];
        vector<int> temp(n);
        int min_count = merge_sort(perm, temp, 0, n-1);
        cout << min_count << endl; 
    }
    return 0;
}