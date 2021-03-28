#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
ll x_0,y_0,r_0;
ll margin = 10000;
bool ok(ll x, ll y, ll r){
    ll a =  (x - x_0)*(x - x_0);
    ll b = (y - y_0)*(y - y_0);
    ll c = r * r;
    return a + b <= c;
}
int main(){
    double x_, y_, r_;
    cin >> x_ >> y_ >> r_;
    x_0 = (ll)round(x_ * margin);
    y_0 = (ll)round(y_ * margin);
    r_0 = (ll)round(r_ * margin);
    ll y_max = (y_0 + r_0) / margin * margin + 3 * margin;
    ll y_min = (y_0 - r_0) / margin * margin - 3 * margin;
    ll ans = 0;
    int c = 0;
    for(ll i = y_max ; i >= y_min ;i-=margin){
        if(ok(x_0,i,r_0) == false)continue;
        ll x_left_max, x_right_max;
        {
            ll x_left =  x_0 - r_0 - 100;
            ll x_right = x_0;
            while(1){
                ll x = (x_left + x_right) / 2;
                if(ok(x, i, r_0))x_right = x;
                else x_left = x;
                if(x_right - x_left == 1)break;
            }
            x_left_max = x_right;
        }
        {
            ll x_left = x_0;
            ll x_right = x_0 + r_0 + 100;
            while(1){
                ll x = (x_left + x_right) / 2;
                if(ok(x, i, r_0))x_left = x;
                else x_right = x;
                if(x_right - x_left == 1)break;
            }
            x_right_max = x_left;
        }
        ll debug = floor((double)x_right_max/margin) - ceil((double)x_left_max/margin) + 1; 
        if(debug){
            ans += debug;
            c++;
            if(c==54733){
                int a;
                c--;
                c++;
            }
        }
    }
    cout << ans << endl;
}
