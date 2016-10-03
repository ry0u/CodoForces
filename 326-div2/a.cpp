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
    int n;
    cin >> n;

    ll ans = 0, vmin = INF;
    rep(i,n) {
        ll a,p;
        cin >> a >> p;

        vmin = min(vmin, p);
        ans += a * vmin;
    }

    cout << ans << endl;

    return 0;
}