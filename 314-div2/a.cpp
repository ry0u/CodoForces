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

    vector<ll> v(n);
    rep(i,n) cin >> v[i];

    ll vmin = INF;
    ll vmax = -INF;

    rep(i,n) {
        vmin = min(vmin,v[i]);
        vmax = max(vmax,v[i]);
    }

    rep(i,n) {
        if(i == 0) {
            cout << abs(v[i]-v[i+1]) << " " << abs(vmax-v[i]) << endl;
        }
        else if(i == n-1) {
            cout << abs(v[i]-v[i-1]) << " " << abs(vmin-v[i]) << endl;
        }else {
            cout << min(abs(v[i]-v[i-1]),abs(v[i]-v[i+1])) << " " << max(abs(vmin-v[i]),abs(vmax-v[i])) << endl;
        }

    }

    return 0;
}
