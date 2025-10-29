#include <iostream>
#include <vector>

using namespace std;

// int partition(vector<int>&arr, int&low, int&high){
//     int pivot = arr[high];
//     int i = (low - 1);
//     for(int j = low; j < high; j++){
//         if (arr[j] <= pivot){
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i + 1], arr[high]);
//     return (i + 1);
// }

// void QuickSort(vector<int>&arr, int low, int high){
//     if (low < high){
//         int pivot_index = partition(arr, low, high);
//         QuickSort(arr, low, (pivot_index-1));
//         QuickSort(arr, pivot_index + 1, high);
//     }
// }

int partition(vector<vector<int>>&arr, int&low, int&high){
    int pivot = arr[high][1];
    int i = (low - 1);
    for(int j = low; j < high; j++){
        if (arr[j][1] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(vector<vector<int>>&arr, int low, int high){
    if (low < high){
        int pivot_index = partition(arr, low, high);
        QuickSort(arr, low, (pivot_index-1));
        QuickSort(arr, pivot_index + 1, high);
    }
}

void solve(){
    int M;
    cin >> M;
    vector<vector<int>> ranges(M, vector<int>(2));
    for(auto&r:ranges) cin >> r[0] >> r[1];
    QuickSort(ranges, 0, M-1);
    int count = 0, last_point = -2000000000;
    for(int i = 0; i < M; i++){
        if(ranges[i][0] > last_point){
            last_point = ranges[i][1];
            count++;
        }
    }
    cout << count << endl;
}
int main(){ios_base::sync_with_stdio(false);cin.tie(NULL);solve();return 0;}