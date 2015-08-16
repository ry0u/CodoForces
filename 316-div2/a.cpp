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
    int n,m;
    cin >> n >> m;

    int cnt[105];
    memset(cnt,0,sizeof(cnt));

    rep(i,m) {
        int vmax = -1;
        int id = 0;
        rep(j,n) {
            ll a;
            cin >> a;

            if(vmax < a) {
                vmax = a;
                id = j;
            }
        }

        cnt[id]++;
    }

    int d = cnt[0];
    int ans = 0;
    rep(i,n) {
        if(d < cnt[i]) {
            d = cnt[i];
            ans = i;
        }
    }

    cout << ans+1 << endl;
    return 0;
}
