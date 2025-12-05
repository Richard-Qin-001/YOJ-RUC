#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 5

const int COEFFS[N] = {1, 4, 6, 4, 1};

int result[N];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool check_sum(int arr[N], int target_sum)
{
    int current_sum = 0;
    for (int i = 0; i < N; i++)
    {
        current_sum += arr[i] * COEFFS[i];
    }
    return current_sum == target_sum;
}

bool generate_permutations(int arr[N], int k, int target_sum)
{
    if (k == N)
    {
        if (check_sum(arr, target_sum))
        {
            for (int i = 0; i < N; i++)
            {
                result[i] = arr[i];
            }
            return true;
        }
        return false;
    }

    for (int i = k; i < N; i++)
    {
        swap(&arr[k], &arr[i]);

        if (generate_permutations(arr, k + 1, target_sum))
        {
            return true;
        }

        swap(&arr[k], &arr[i]);
    }

    return false;
}

int main()
{
    int sum;
    if (scanf("%d", &sum) != 1)
    {
        return 1;
    }

    int initial_arr[N] = {1, 2, 3, 4, 5};

    if (generate_permutations(initial_arr, 0, sum))
    {
        for (int i = 0; i < N; i++)
        {
            printf("%d%s", result[i], (i == N - 1) ? "" : " ");
        }
        printf("\n");
    }

    return 0;
}