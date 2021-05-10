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
struct Mura{
    int a;
    int b;
    int pos;
    double dist;
    void cal(double m,double n){
        dist = b * n - a * m;
    }
    static bool comp_pos(Mura &a, Mura &b){
        return a.pos < b.pos;
    }
    static bool comp_dist(Mura &a, Mura &b){
        return a.dist < b.dist;
    }
};
int main(){
    ll k,n,m;
    cin >> k >> n >> m;
    vector<Mura> mura(k);
    ll sum_b = 0;
    rep(i,k){
        cin >> mura[i].a;
        mura[i].b = m * mura[i].a / n;
        sum_b += mura[i].b;
        mura[i].pos = i;
        mura[i].cal(m,n);
    }
    ll dist_b = m - sum_b;
    sort(mura.begin(), mura.end(), Mura::comp_dist);
    if(dist_b > m)dist_b /= 0;
    rep(i,dist_b){
        mura[i % k].b++;
    }
    sort(mura.begin(), mura.end(), Mura::comp_pos);
    rep(i,k){
        cout << mura[i].b << " ";
    }
    cout << endl;
}
