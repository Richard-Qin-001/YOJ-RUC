#include <stdio.h>
#include <string.h>
int main()
{
    char a[15] = {'\0'}; // 存放数字字符串
    long long b[500] = {0};    // 存放每个加法表达式结果
    int num = 0, flag = 0;
    scanf("%s", a);
    num = strlen(a);
    for (int i = 0; i < num-3; i++)
    { // 遍历不同加号位置
        for (int j = i + 1; j < num-2; j++)
        {
            for ( int k = j + 1; k < num-1; k++)
            {
                char n1[15] = {'\0'}; // 存放每个数
                char n2[15] = {'\0'};
                char n3[15] = {'\0'};
                char n4[15] = {'\0'};
                for (int i1 = 0; i1 <= i; i1++)
                {
                    n1[i1] = a[i1];
                }
                int i12 = 0, i13 = 0, i14 = 0;
                for (int i1 = i + 1; i1 <= j; i1++)
                {
                    n2[i12] = a[i1];
                    i12++;
                }
                for (int i1 = j + 1; i1 <= k; i1++)
                {
                    n3[i13] = a[i1];
                    i13++;
                }
                for (int i1 = k+1 ; i1 < num; i1++)
                {
                    n4[i14] = a[i1];
                    i14++;
                }
                int num1 = 0, num2 = 0, num3 = 0, num4 = 0;
                num1 = strlen(n1);
                num2 = strlen(n2);
                num3 = strlen(n3);
                num4 = strlen(n4);
                long long x1 = 0, x2 = 0, x3 = 0, x4 = 0;
                for (int i1 = num1 - 1; i1 >= 0; i1--)
                { // 求出每个数数值大小

                    long long t = n1[i1] - 48;
                    for (int j1 = 0; j1 < num1 - i1 - 1; j1++)
                    {
                        t *= 10;
                    }
                    x1 += t;
                }
                for (int i1 = num2 - 1; i1 >= 0; i1--)
                {
                    long long t = n2[i1] - 48;
                    for (int j1 = 0; j1 < num2 - i1 - 1; j1++)
                    {
                        t *= 10;
                    }
                    x2 += t;
                }
                for (int i1 = num3 - 1; i1 >= 0; i1--)
                {
                    long long t = n3[i1] - 48;
                    for (int j1 = 0; j1 < num3 - i1 - 1; j1++)
                    {
                        t *= 10;
                    }
                    x3 += t;
                }
                for (int i1 = num4 - 1; i1 >= 0; i1--)
                {
                    long long t = n4[i1] - 48;
                    for (int j1 = 0; j1 < num4 - i1 - 1; j1++)
                    {
                        t *= 10;
                    }
                    x4 += t;
                }
                b[flag] = x1 + x2 + x3 + x4;
                flag++;
            }
        }
    }
    int temp = 0;
    for (int i = 0; i < flag; i++)
    {
        for (int j = 0; j < flag - i - 1; j++)//将求得结果排序
        {
            if (b[j] < b[j + 1])
            {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < flag; i++)
    {
        printf("%lld ", b[i]);
    }
    return 0;
}