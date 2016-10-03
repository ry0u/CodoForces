#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <cmath>

#define REP(i,k,n) for(int i=k;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1<<30
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

bool prime[10000000];
void Eratosthenes(int n) {
    rep(i,n) prime[i] = true;
    prime[0] = false;
    prime[1] = false;

    REP(i,2,(int)sqrt(n)) {
        if(prime[i]) {
            for(int j=0;i*(j+2)<n;j++) {
                prime[i*(j+2)] = 0;
            }
        }
    }
}

bool check(string s) {
    rep(i,s.size()/2) {
        if(s[i] != s[s.size()-1-i]) return false;
    }

    return true;
}

int main() {
    double p,q;
    cin >> p >> q;

    int N = 1500000;

    Eratosthenes(N);
    vector<int> pi(N);
    int cnt = 0;

    rep(i,N+5) {
        if(prime[i]) {
            cnt++;
        }

        pi[i] = cnt;
    }


    vector<int> rub(N);
    cnt = 0;
    REP(i,1,N+5) {
        stringstream ss;
        ss << i;

        if(check(ss.str())) {
            cnt++;
        }

        rub[i] = cnt;
    }

    double A = p/q;
    int ans = 0;

    for(int i=N;i>=1;i--) {
        ll a = pi[i];
        ll b = rub[i];

        if(a <=  A * b) {
            cout << i << endl;
            break;
        }
        else {
            continue;
        }
    }

    return 0;
}
