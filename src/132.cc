#include <stdio.h>
#include <stdlib.h>

int findMax(int *p, int nSize)
{
// ____qcodep____
int *pr = p;
int current = *pr;
int global_max = *pr;
int *gol_m = pr;

for(int i = 0; i < nSize; i++){
    current = *pr;
    if (global_max < current){
        global_max = current;
        gol_m = pr;
    }
    *pr++;
}
int tmp;
tmp = *p;
*p = *gol_m;
*gol_m = tmp;
return global_max;
}

int main()
{
    int ary[2100] = {3, 2, 1, 5, 6, 7, 9, 10}, n = 8, nMax, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ary[i]);

    nMax = findMax(ary, n);

    for (i = 0; i < n; i++)
        printf("%d ", ary[i]);
    printf("\n");

    printf("%d\n", nMax);
    return 0;
}