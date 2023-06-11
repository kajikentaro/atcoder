#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int,int>;
int main(){
    int x,y,a,b,c;
    cin >> x >> y >> a >>  b >> c;
    vector<int> p(a),q(b),r(c);
    rep(i,a) cin >> p[i];
    rep(i,b) cin >> q[i];
    rep(i,c) cin >> r[i];
    sort(p.rbegin(),p.rend());
    sort(q.rbegin(),q.rend());
    sort(r.rbegin(),r.rend());
    int cp = x - 1;
    int cq = y - 1;
    int cr = -1;
    while(1){
        int p_value = p[cp];
        int q_value = q[cq];
        int r_value = r[cr+1];

        if(cq == -1 || p_value <= q_value){
            if(r_value > p_value){
                cr++;
                cp--;
            }else break;
        }else if(cp == -1 || p_value > q_value){
            if(r_value > q_value){
                cr++;
                cq--;
            }else break;
        }

        if(cr == c-1)break;
        if(cp == -1 && cq == -1)break;
    }
    ll ans = 0;
    rep(i,cp+1){
        ans += p[i];
    }
    rep(i,cq+1){
        ans += q[i];
    }
    rep(i,cr+1){
        ans += r[i];
    }
    cout << ans << endl;
}
