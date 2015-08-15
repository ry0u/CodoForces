#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

ll dp[4005][4005];
ll memo[4005][4005];

ll nCr(ll n,ll r)
{
    if(n < r) return 0;
    if(n == r) return 1;
    if(r == 1) return n;
    if(memo[n][r] != -1) return memo[n][r];

    return memo[n][r] = (nCr(n-1,r)+nCr(n-1,r-1))%MOD;
}

int main() {
    int n;
    cin >> n;

    memset(dp,0,sizeof(dp));
    rep(i,4005) rep(j,4005) memo[i][j] = -1;

    dp[0][0] = 1;
    REP(i,1,4005) {
        REP(j,1,4005) {
            dp[i][j] += dp[i-1][j] * j;
            dp[i][j] += dp[i-1][j-1];
            dp[i][j] %= MOD;
        }
    }

    ll ans = 1;
    REP(i,1,n) {
        ll a = nCr(n,i);
        ll b = 0;

        REP(j,1,i+1) {
            b += dp[i][j];
            b %= MOD;
        }

        ans += (a * b) % MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
