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

    vector<int> v(n);
    rep(i,n) cin >> v[i];

    int vmax = 0;
    vector<int> ans(n);
    for(int i=n-1; i>=0; i--) {
        if(vmax < v[i]) ans[i] = 0;
        else ans[i] = vmax+1 - v[i];

        vmax = max(vmax,v[i]);
    }

    rep(i,n) {
        cout << ans[i];

        if(i ==n -1) cout << endl;
        else cout << " ";
    }

    return 0;
}
