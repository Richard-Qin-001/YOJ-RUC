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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> list(n), temp(n);
    for(auto&p:list)cin >> p;
    ll inversion_count = merge_sort(list, temp, 0, n - 1);
    cout << inversion_count << endl;
}
/*
归并排序和逆序对
*/