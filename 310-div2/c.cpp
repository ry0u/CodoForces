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
    int n,k;
    cin >> n >> k;

    vector<int> a[k];
    rep(i,k) {
        int t;
        cin >> t;

        rep(j,t) {
            int x;
            cin >> x;

            a[i].push_back(x);
        }
    }
    
    int ans = 0;

    rep(i,k) {
        if(a[i][0] == 1) {
            rep(j,a[i].size()-1) {
                if(a[i][j]+1 == a[i][j+1]) {
                    continue;
                }
                else {
                    int size = a[i].size() - (j+1);
                    ans += size + size;
                    break;
                }
            }
        }else {
            ans += a[i].size() - 1 + a[i].size();
        }
    }

    cout << ans << endl;

    return 0;
}
