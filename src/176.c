#include <stdio.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INT_MAX (int)0x7fffffff

inline const int need[8][8] = {
    {100, 500, INT_MAX, 10000, 200, 500, 400, 1200},
    {20, 100, INT_MAX, 10000, 300, INT_MAX, INT_MAX, INT_MAX},
    {10, 8, 100, 17, 22, 200, 1000, 3000},
    {1, 1, INT_MAX, 100, 1, 2000, 1500, 5000},
    {50, 33, INT_MAX, 10000, 100, 50, 30, 70},
    {20, 5, 50, 5, 200, 100, 50, 400},
    {50, 20, 10, 7, 350, 200, 100, 1000},
    {8, 5, 10, 10, 200, 30, 20, 100}};
inline const int cost[8] = {100, 200, 500, 1000, 1000, 600, 600, 2000};
char in_buf[256], out_buf[256];
int in_idx = 0, out_idx = 0;
char *pos = NULL;

int main()
{
    int enemies[8];
    gets(in_buf);
    pos = in_buf;
    int i = 0, value = 0;
    while (*pos != '\0')
    {
        if (*pos == ' ')
        {
            enemies[i] = value;
            value = 0;
            i++;
        }
        else
            value = *pos - '0' + value * 10;
        pos++;
    }
    enemies[i] = value;

    int min_costs = 0;
    for (int i = 0; i < 8; ++i)
    {
        int tmp = INT_MAX;
        for (int j = 0; j < 8; ++j)
        {
            if (need[j][i] == INT_MAX)
                continue;
            tmp = MIN(tmp, cost[j] * need[j][i] * (enemies[i] / 100));
        }

        min_costs += tmp;
    }
    int len = 0;
    int x = min_costs;
    if (x == 0)
    {
        out_buf[len++] = '0';
    }
    else
    {
        char tmp[32];
        int tlen = 0;
        while (x > 0)
        {
            tmp[tlen++] = (x % 10) + '0';
            x /= 10;
        }
        while (tlen > 0)
        {
            out_buf[len++] = tmp[--tlen];
        }
    }
    out_buf[len] = '\0';
    puts(out_buf);
    return 0;
}