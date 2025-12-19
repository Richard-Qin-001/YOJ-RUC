#include <stdio.h>
#include <stdlib.h>

// 你需要完成的函数，返回最大收益
// ary表示股票价格的数组从下标0开始；n表示数组大小
// pBuyTime, pSellTime分别表示获得最大收益的购买时间和卖出时间
int maxProfit(int *ary, int n, int *pbuyTime, int *psellTime)
{
// ____qcodep____
    if (n < 2)return 0;
    int min_price = ary[0];
    int min_idx = 0;
    int max_p = 0;

    *pbuyTime = 0;
    *psellTime = 0;

    for (int i = 1; i < n; i++){
        if (ary[i] - min_price > max_p){
            max_p = ary[i] - min_price;
            *psellTime = i;
            *pbuyTime = min_idx;
        }
        if (ary[i] < min_price)
        {
            min_price = ary[i];
            min_idx = i;
        }
    }
    return max_p;
}

int main()
{
    int n, i, buyTime = 0, sellTime = 0, maxP = 0;
    int ary[10001];
    
    scanf("%d", &n);
    for ( i = 0; i < n; i++ )
        scanf("%d", &ary[i]);
    //说明：这里的for循环没有任何意义，只是为了增加程序的运行时间
    for ( i = 0; i < n; i ++ )
    {
        //你需要填写如何调用函数。
        // maxP = maxProfit(____qcodep____);
        maxP = maxProfit(ary, n, &buyTime, &sellTime);
    }

    printf("%d\n", maxP);    
    return 0;
}
