#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
int phi[MAXN];
int prime[MAXN];
bool is_not_prime[MAXN];
int cnt = 0;

void precompute_phi(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (!is_not_prime[i]) {
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < cnt && i * prime[j] <= n; ++j)
        {
            is_not_prime[i * prime[j]] = true;
            if (i % prime[j] == 0)
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
            else
            {
                phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    
    precompute_phi(n);

    for (int i = m; i <= n; ++i)
    {
        cout << phi[i] << (i == n ? "" : " ");
    }
    cout << endl;
    return 0;
}