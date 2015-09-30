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

    int ans = 0;
    while(true) {
        bool flag = true;
        int vmax = 0, id = 0;
        REP(i,1,n) {
            if(v[0] <= v[i]) flag = false;
            if(vmax < v[i]) {
                vmax = v[i];
                id = i;
            }
        }

        if(flag) break;

        v[0]++;
        v[id]--;
        ans++;
    }

    cout << ans << endl;



    return 0;
}
