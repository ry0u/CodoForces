#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <queue>

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

    vector<int> L(n),D(n);
    rep(i,n) cin >> L[i];
    rep(i,n) cin >> D[i];

    vector<int> id(L.begin(),L.end());
    sort(id.begin(),id.end());
    id.erase(unique(id.begin(),id.end()),id.end());

    int sum = 0;
    map<int,vector<int> > m;
    rep(i,n) {
        m[L[i]].push_back(D[i]);
        sum += D[i];
    }
    
    int ans = sum;
    priority_queue<int> que;
    rep(i,id.size()) {
        vector<int> v(m[id[i]].begin(),m[id[i]].end());
        int res = sum;
        int cnt = v.size()-1;

        rep(j,v.size()) res -= v[j];

        vector<int> t;
        while(que.size() && cnt) {
            int q = que.top();
            que.pop();

            res -= q;
            t.push_back(q);
            cnt--;
        }

        ans = min(ans,res);

        rep(j,t.size()) que.push(t[j]);
        rep(j,v.size()) que.push(v[j]);
    }
    
    cout << ans << endl;

    return 0;
}
