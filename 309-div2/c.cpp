#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define MOD 1000000007

using namespace std;
typedef long long ll;

ll memo[1005][1005];

ll nCr(ll n,ll r)
{
    if(n < r) return 0;
    if(n == r || r == 0) return 1;
    if(r == 1) return n;
    if(memo[n][r] != -1) return memo[n][r];
    
    return memo[n][r] = (nCr(n-1,r)+nCr(n-1,r-1))%MOD;
}


int main() {
    int n;
    cin >> n;

    vector<ll> v(n);
    int sum = 0;

    rep(i,n) {
        cin >> v[i];
        sum += v[i];
    }

    rep(i,1005) rep(j,1005) memo[i][j] = -1;

    ll ans = 1;
    for(int i=n-1;i>=1;i--) {
        ans *= nCr(sum-1,v[i]-1);
        ans %= MOD;

        sum -= v[i];
    }

    cout << ans << endl;

    return 0;
}
