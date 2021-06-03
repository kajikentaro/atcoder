#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int,int>;
struct IE{
    int x,y;
    int pos;
    static bool compX(IE &a, IE &b){
        return a.x < b.x;
    }
    static bool compY(IE &a, IE &b){
        return a.y < b.y;
    }
};
struct RES{
    int dist;
    ll pos;
    RES(int dist,int posa,int posb):dist(dist){
        if(posa < posb)swap(posa,posb);//posb is small
        pos = (ll)posb * 1e6 + (ll)posa;
    }
    static bool comp(RES &a, RES &b){
        return a.dist > b.dist;
    }
};
int main(){
    #define int long long
    int n;
    cin >> n;
    vector<IE> x(n);
    rep(i,n){
        cin >> x[i].x >> x[i].y;
        x[i].pos = i;
    }
    vector<RES> can;
    sort(x.begin(), x.end(),IE::compX);
    can.push_back(RES(x[n-1].x - x[0].x,x[n-1].pos, x[0].pos));
    can.push_back(RES(x[n-2].x - x[0].x,x[n-2].pos, x[0].pos));
    can.push_back(RES(x[n-1].x - x[1].x,x[n-1].pos, x[1].pos));
    sort(x.begin(), x.end(),IE::compY);
    can.push_back(RES(x[n-1].y - x[0].y,x[n-1].pos, x[0].pos));
    can.push_back(RES(x[n-2].y - x[0].y,x[n-2].pos, x[0].pos));
    can.push_back(RES(x[n-1].y - x[1].y,x[n-1].pos, x[1].pos));
    sort(can.begin(),can.end(),RES::comp);

    if(can[0].pos == can[1].pos){
        cout << can[2].dist << endl;
    }else{
        cout << can[1].dist << endl;
    }
}
