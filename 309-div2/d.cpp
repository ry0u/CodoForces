#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
typedef long long ll;

const int MOD = 1000000007;
const int MAX = 1005;
long long C[MAX][MAX];

void initial()
{
    memset(C, 0, sizeof(C));
    for(int i = 0; i < MAX; i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j <= i/2; j++)
            C[i][j] = C[i][i - j] = (C[i - 1][j] + C[i - 1][j - 1])%MOD;
    }
}

int main()
{
    initial();
    int k, c[MAX];
    while(scanf("%d", &k) != EOF)
    {
        int sum = 0;
        for(int i = 0; i < k; i++)
        {
            scanf("%d", &c[i]);
            sum += c[i];
        }

        cout << "sum:" << sum << endl;
        long long ans = 1;
        while(k--)
        {
            cout << "comb:" << sum-1 << " " << c[k] - 1 << endl;
            ans = ans*(C[sum - 1][c[k] - 1])%MOD;
            sum -= c[k];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
