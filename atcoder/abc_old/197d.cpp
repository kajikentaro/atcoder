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
int main(){
    ll n;
    cin >> n;
    ll x0,y0,xn2,yn2;
    cin >> x0 >> y0 >> xn2 >> yn2;
    x0 *= 1e8;
    y0 *= 1e8;
    xn2 *= 1e8;
    yn2 *= 1e8;

    ll a = (x0 + xn2) / 2;
    ll b = (y0 + yn2) / 2;

    double theta = (double)2 * M_PI / n;
    ll ansx = (x0 - a) * cos(theta) - sin(theta) * (y0 - b) + a;
    ll ansy = (x0 - a) * sin(theta) + cos(theta) * (y0 - b) + b;

    printf("%.10lf %.10lf",(double)(ansx) / 1e8,(double)(ansy) / 1e8);
}
