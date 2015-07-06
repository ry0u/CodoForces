#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define mp make_pair

using namespace std;
typedef long long ll;

bool used[10000005];

int main() {
    int n;
    cin >> n;
   
    // end start id
    vector<pair<pair<int,int>,int > > v;
    vector<int> X(n);
    int vmax = 0;

    rep(i,n) {
        int x,h;
        cin >> x >> h;

        X[i] = x;
        vmax = max(vmax,x);
        // x-h -> x
        v.push_back(mp(mp(x-1,x-h),i));
        // x -> x+h
        v.push_back(mp(mp(x+h,x+1),i));
    }


    sort(v.begin(),v.end());
    sort(X.begin(),X.end());

    int ans = 0;
    int pre = -(1<<30);
    memset(used,0,sizeof(used));    

    rep(i,v.size()) {
        int l = v[i].first.second;
        int r = v[i].first.first;
        int id = v[i].second;

        if(binary_search(X.begin(),X.end(),l) || binary_search(X.begin(),X.end(),r)) {
            continue;
        }
        
        vector<int>::iterator left = lower_bound(X.begin(),X.end(),l);
        vector<int>::iterator right = lower_bound(X.begin(),X.end(),r);
        
        if(pre < l) {
            if(!used[id] && left == right) {
                if((left == X.end() && right == X.end()) || (left != X.end() && right != X.end())) {
                    pre = r;
                    ans++;
                    used[id] = true;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
