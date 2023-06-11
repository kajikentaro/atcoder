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
float x,y,r;
double f(double new_x, double i){
    return (pow(new_x - x,2) + pow(i - y,2));
}
int main(){
    cin >> x >> y >> r;
    ll y_max = floor(y + r);
    ll y_min = ceil(y - r);
    double r2 = r * r;
    ll sum = 0;
    for(ll i=y_min;i<=y_max;i++){
        ll x_max_left, x_max_right;
        {
            ll x_right = ceil(x), x_left = -1e9;
            while(1){
                if(x_right - x_left <= 1)break;
                ll new_x = (x_right + x_left) / 2;
                if(f(new_x, i) > r2)x_left = new_x;
                else x_right = new_x;
            }
            x_max_left = x_left;
        }
        {
            ll x_right = 1e9, x_left = floor(x);
            while(1){
                if(x_right - x_left <= 1)break;
                ll new_x = (x_right + x_left) / 2;
                if(f(new_x, i) > r2)x_right = new_x;
                else x_left= new_x;
            }
            x_max_right = x_right;
        }
        sum += x_max_right - x_max_left - 1;
    }
    cout << sum << endl;
}