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

int cnt[1000005];

int main() {
    int n;
    cin >> n;

    vector<pair<string,int> > v(n);
    rep(i,n) {
        cin >> v[i].first >> v[i].second;
    }

    vector<int> p;
    memset(cnt,0,sizeof(cnt));

    int sum = 0;

    rep(i,n) {
        string t = v[i].first;
        int d = v[i].second;

        if(t == "-" && cnt[d] == 0) {
            sum++;
        }

        if(t == "+") {
            cnt[d]++;
        }
    }

    int ans = sum;
    rep(i,n) {
        string t = v[i].first;
        int d = v[i].second;

        if(t == "+") {
            sum++;
        }else {
            sum--;
        }

        ans = max(ans,sum);
    }

    cout << ans << endl;


    return 0;
}
