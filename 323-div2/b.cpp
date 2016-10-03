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


    bool used[1005];
    memset(used,0,sizeof(used));

    int now = 0, dir = 0,cnt = 0;
    while(true) {



        if(dir%2 == 0) {
            rep(i,v.size()) {
                if(v[i] <= now && !used[i]) {
                    now++;
                    used[i] = true;
                }
            }
        } else {
            for(int i=v.size()-1; i>=0; i--) {
                if(v[i] <= now && !used[i]) {
                    used[i] = true;
                    now++;
                }
            }
        }

        bool flag = true;
        rep(i,v.size()) {
            if(!used[i]) flag = false;
        }

        if(flag) break;

        cnt++;
        dir++;
    }

    cout << cnt << endl;

    return 0;
}
