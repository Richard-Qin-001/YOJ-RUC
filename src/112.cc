#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int bisearch( int ary[], int left, int right, int num )
{
// ____qcodep____
cout << "search " << num << " from " << left << " to " << right << endl;
if (left > right) return -1;
int mid = left + (right - left) / 2;
int tmp = ary[mid];
if (num == tmp) return mid;
else if(num < tmp)return bisearch(ary, left, mid-1, num);
else return bisearch(ary, mid+1, right, num);
}

int main()
{
    int n, array[10000], i, num;
    scanf("%d", &n);
    scanf("%d", &num);
    for (i = 0; i < n; i ++ )
    {
        scanf("%d", &array[i]);
    }

    printf( "%d", bisearch(array, 0, n-1, num));
    cout << endl;
    return 0;
}    
