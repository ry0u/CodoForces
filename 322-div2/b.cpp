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

struct RMQ {
    int n;
    vector<int> dat;

    RMQ(int n_) {
        n = 1;
        while(n < n_) n *= 2;

        dat.resize(n*4);
        rep(i,n*4) dat[i] = -INF;
    }

    void update(int k,int a) {
        int i = k+n-1;
        dat[i] = a;

        while(i > 0) {
            i = (i-1) / 2;
            dat[i] = max(dat[i*2+1],dat[i*2+2]);
        }
    }

    //[a,b)
    //query(a,b,0,0,n)
    int _query(int a,int b,int k,int l,int r)
    {
        if(r <= a || b <= l) return -INF;

        if(a <= l && r <= b) return dat[k];
        else { 
            int vl = _query(a,b,k*2+1,l,(l+r)/2);
            int vr = _query(a,b,k*2+2,(l+r)/2,r);
            return max(vl,vr);
        }
    }

    //[a,b)
    int query(int a,int b) {
        return _query(a,b,0,0,n);
    }

};

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    RMQ rmq(n);
    rep(i,n) {
        cin >> v[i];
        rmq.update(i,v[i]);
    }

    rep(i,n) {
        int d = rmq.query(i,n+1);
        int d2 = rmq.query(i+1,n+1);

        if(d == v[i] && v[i] != d2) cout << 0;
        else cout << d+1 - v[i];

        if(i == n-1) cout << endl;
        else cout << " ";
    }

    return 0;
}
