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

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main() {

    ll n,k;
    cin >> n >> k;

    vector<ll> v(n);
    rep(i,n) {
        cin >> v[i];
    }

    map<ll,ll> mup;
    rep(i,n) {
        mup[v[i]]++;
    }

    map<ll,ll> mdown;

    ll ans = 0;

    rep(i,n) {
        mup[v[i]]--;
        if(v[i] % k == 0) {
            ll d = v[i]/k;
            ll u = v[i]*k;

            ans += mdown[d] * mup[u];
        }
        mdown[v[i]]++;
    }

    cout << ans << endl;



    return 0;
}
