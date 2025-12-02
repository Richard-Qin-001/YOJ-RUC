#include <stdio.h>
#include <stdlib.h>

void mySort(int array [], int left, int right)
{
// ____qcodep____
for(int i = left; i <= right; i++){
    int min_pos = i;
    for(int j = i; j <= right; j++){
        if(array[j] < array[min_pos])min_pos = j;
    }
    int *a = &array[i];
    int *b = &array[min_pos];
    int temp = array[i];
    *a = *b;
    *b = temp;
}
}

int main()  
{  
    int array[100], i, n;
    
    scanf("%d",&n);

    for ( i = 0; i < n; i ++ ){
        scanf("%d", &array[i]);
    }

    mySort(array, 0, n - 1);

    for ( i = 0; i < n; i ++ ){
        printf("%d ", array[i]);
    }
    printf("\n");  
    return 0;  
}  