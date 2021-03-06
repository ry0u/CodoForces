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
    vector<pair< pair<int,int>,int > > v(3);
    int len = 0;

    rep(i,3) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;

        if(v[i].first.first < v[i].first.second) {
            swap(v[i].first.first, v[i].first.second);
        }

        len = max(len , v[i].first.first);
    }

    sort(v.begin(), v.end(),greater<pair<P,int> >());

    int a = v[0].first.first, b = v[0].first.second;
    int c = v[1].first.first, d = v[1].first.second;
    int e = v[2].first.first, f = v[2].first.second;

    char A = char('A' + v[0].second);
    char B = char('A' + v[1].second);
    char C = char('A' + v[2].second);

    if(a == len && c == len && e == len) {
        if(b + d + f == len) {
            cout << len << endl;
            rep(i,b) {
                rep(j,a) cout << A;
                cout << endl;
            }

            rep(i,d) {
                rep(j,c) cout << B;
                cout << endl;
            }

            rep(i,f) {
                rep(j,e) cout << C;
                cout << endl;
            }
        } else {
            cout << -1 << endl;
        }
    } else {
        if(b + c == len && b + e == len && d + f == len) {
            cout << len << endl;
            rep(i,b) {
                rep(j,a) cout << A;
                cout << endl;
            }

            rep(i,c) {
                rep(j,d) cout << B;
                rep(j,f) cout << C;
                cout << endl;
            }
        }
        else if(b + d == len && b + e == len && c + f == len) {
            cout << len << endl;
            rep(i,b) {
                rep(j,a) cout << A;
                cout << endl;
            }

            rep(i,d) {
                rep(j,c) cout << B;
                rep(j,f) cout << C;
                cout << endl;
            }
        } else if(b + c == len && b + f == len && d + e == len) {
            cout << len << endl;
            rep(i,b) {
                rep(j,a) cout << A;
                cout << endl;
            }

            rep(i,c) {
                rep(j,d) cout << B;
                rep(j,e) cout << C;
                cout << endl;
            }
        } else if(b + d == len && b + f == len && c + e == len) {
            cout << len << endl;
            rep(i,b) {
                rep(j,a) cout << A;
                cout << endl;
            }

            rep(i,d) {
                rep(j,c) cout << B;
                rep(j,e) cout << C;
                cout << endl;
            }
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
