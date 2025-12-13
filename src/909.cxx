#include <bits/stdc++.h>
using namespace std;

void quick_select(int l, int r, int k, vector<int>&a)
{
    if (l >= r)
        return;
    
    int i = l, j = r;

    int pivot = a[(l + r) / 2];

    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (k <= j)
        quick_select(l, j, k, a);
    else if (k >= i)
        quick_select(i, r, k, a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)cin >> a[i];

    quick_select(0, n - 1, k - 1, a);

    cout << a[k - 1] << endl;
    return 0;
}