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
    int n,t;
    cin >> n >> t;

    map<int,int> m;
    vector<int> v(n);

    rep(i,n) {
        cin >> v[i];
        m[v[i]]++;
    }

    cout << "--------- input -----------=" << endl;
    map<int,int>::iterator ite;
    for(ite = m.begin(); ite != m.end(); ite++) {
        cout << ite->first << " " << ite->second << endl;
    }


    if(t == 1) {
        int dp[105];
        memset(dp,0,sizeof(dp));

        int res = 0;
        rep(i,n) {
            dp[i] = 1;
            rep(j,i) {
                if(v[j] < v[i]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }

            res = max(res, dp[i]);
        }
        
        cout << res << endl;
        return 0;
    }


    int dp[105][105];
    memset(dp,0,sizeof(dp));

    int ans = 0;
    // int dp[105];

    // rep(s,n) {
    //     REP(t,s+1,n+1) {
    //         // s -> t 
    //
    //         int res = 0, last = -1;
    //         int sum = 0;
    //         memset(dp,0,sizeof(dp));
    //
    //         REP(i,s,t) {
    //             dp[i] = 1;
    //             REP(j,s,i) {
    //                 if(v[j] < v[i]) {
    //                     dp[i] = max(dp[i], dp[j] + 1);
    //                 }
    //             }
    //
    //             if(res < dp[i]) {
    //                 res = dp[i];
    //                 last = v[i];
    //             } else if(res == dp[i]) {
    //                 last = min(last, v[i]);
    //             }
    //         }
    //
    //         sum += res;
    //         int vmax = 0;
    //         memset(dp,0,sizeof(dp));
    //
    //         rep(l,n) {
    //             if(v[l] >= last) {
    //                 int res = 0;
    //                 REP(i,l,n) {
    //                     dp[i] = 1;
    //                     REP(j,l,i) {
    //                         if(v[j] < v[i]) {
    //                             dp[i] = max( dp[i] , dp[j] + 1);
    //                         }
    //                     }
    //                     res = max(res, dp[i]);
    //                 }
    //               
    //                 vmax = max(vmax, res);
    //             }
    //         }
    //     }
    // }

    rep(k,n) {
        int res = 0, last = -1;
        int sum = 0;
        REP(i,k,n) {
            dp[k][i] = 1;
            REP(j,k,i) {
                if(v[j] < v[i]) {
                    dp[k][i] = max( dp[k][i] , dp[k][j] + 1);
                }
            }
    
            if(res < dp[k][i]) {
                res = dp[k][i];
                last = v[i];
            } else if(res == dp[k][i]) {
                res = dp[k][i];
                last = min(last, v[i]);
            }
        }
    
        sum += res;
    
        int dp2[105][105];
        memset(dp2,0,sizeof(dp2));
    
        int vmax = 0;
        rep(l,n) {
            if(last <= v[l]) {
                int res = 0;
                REP(i,l,n) {
                    dp2[l][i] = 1;
                    REP(j,l,i) {
                        if(v[j] < v[i]) {
                            dp2[l][i] = max( dp2[l][i] , dp2[l][j] + 1);
                        }
                    }
                    res = max(res, dp2[l][i]);
                }
               
                vmax = max(vmax, res);
            }
        }
    
        cout << "k:" << k << " l:" << last << " " << res << " " << vmax << endl;
    
        sum += vmax;
        sum += m[last] * (t-2);
    
        ans = max(ans,sum);
    }
    
    cout << ans << endl;

    return 0;
}
