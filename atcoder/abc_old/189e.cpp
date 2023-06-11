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
struct status{
    ll x_d = 1;
    ll y_d = 0;
    ll x = 0;
    ll y = 0;
    status rotateRight(){
        status out;
        out.x_d = (x_d + 1) % 4;
        out.y_d = (y_d + 1) % 4;
        out.x = y;
        out.y = -x;
        return out;
    }
    status rotateLeft(){
        status out;
        out.x_d = (x_d + 3) % 4;
        out.y_d = (y_d + 3) % 4;
        out.x = -y;
        out.y = x;
        return out;
    }
    status foldX(ll p){
        status out;
        if(x_d % 2 == 1){
            out.x_d = (x_d + 2) % 4;
            out.y_d = (y_d + 0) % 4;
        }else{
            out.x_d = (x_d + 0) % 4;
            out.y_d = (y_d + 2) % 4;
        }
        out.x = (2 * p - x);
        out.y = y;
        return out;
    }
    status foldY(ll p){
        status out;
        if(x_d % 2 == 0){
            out.x_d = (x_d + 2) % 4;
            out.y_d = (y_d + 0) % 4;
        }else{
            out.x_d = (x_d + 0) % 4;
            out.y_d = (y_d + 2) % 4;
        }
        out.x = x;
        out.y = (2 * p - y);
        return out;
    }
};
void add(ll &ox,ll &oy, ll d, ll a){
    switch(d){
        case 0:
            oy += a;
            break;
        case 1:
            ox += a;
            break;
        case 2:
            oy -= a;
            break;
        case 3:
            ox -= a;
            break;
    }
}
int main(){
    ll n;
    cin >> n;
    vector<ll> inx(n);
    vector<ll> iny(n);
    rep(i,n)cin >> inx[i] >> iny[i];
    ll m;
    cin >> m;
    vector<status> s(1);
    rep(i,m){
        ll op;
        cin >> op;
        switch(op){
            case 1:
                s.push_back(s[i].rotateRight());
                break;
            case 2:
                s.push_back(s[i].rotateLeft());
                break;
            case 3:
                ll p;
                cin >> p;
                s.push_back(s[i].foldX(p));
                break;
            case 4:
                cin >> p;
                s.push_back(s[i].foldY(p));
                break;
        }
    }
    ll q;
    cin >> q;
    vector<pair<ll,ll>> result;
    rep(i,q){
        ll a,b;
        cin >> a >> b;
        b--;
        ll ansx = s[a].x;
        ll ansy = s[a].y;
        add(ansx,ansy,s[a].x_d,inx[b]);
        add(ansx,ansy,s[a].y_d,iny[b]);
        result.emplace_back(ansx,ansy);
    }
    rep(i,q){
        cout << result[i].first << " " << result[i].second << endl;
    }
}#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
}
