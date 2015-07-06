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
    ll n,w;
    cin >> n >> w;

    vector<ll> v(n*2);
    rep(i,n*2) cin >> v[i];

    sort(v.begin(),v.end());
    
    ll a = v[0];
    ll b = v[n];

    cout << fixed;
    cout.precision(20);
    if(a*2 <= b) {
        cout << min(a*n + 2*a*n,w) << endl;
    }
    else cout << min(b/2.0*n + b*n,(double)w) << endl;
    
    return 0;
}
