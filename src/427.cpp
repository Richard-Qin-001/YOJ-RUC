#include <stdio.h>
#include <stdlib.h>
#define N 25

// ____qcodep____

void TransposeOutput(int (*p)[N], int n, int m)
{
    int i, j;
    for (j = 0; j < m; j++){
        for (i = 0; i < n; i++){
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
}

int main()
{
    int n, m, i, j;
    // ____qcodep____
    int (*p)[N]; // 声明p;
    int matrix[N][N]={{0}};
    p = matrix;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i ++)
    {
        for(j = 0; j < m; j ++)
        {
            scanf("%d", * (p + i) + j );
            
        }
    }
    TransposeOutput(p, n, m);
    return 0;
}
