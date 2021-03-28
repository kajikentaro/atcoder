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
ll n;
vector<ll> a;
ll bit__or(vector<ll> in){
    ll ans = 0;
    for(auto a : in){
        ans = ans | a;
    }
    return ans;
}
ll bit__xor(vector<ll> in){
    ll ans = 0;
    for(auto a : in){
        ans = ans ^ a;
    }
    return ans;
}
const ll inf = 1e18;
ll func(ll i, vector<ll> stack, vector<ll> ans){
    ll res = inf;
    if(i == n){
        if(stack.size() != 0){
            ans.push_back(bit__or(stack));
        }
        return bit__xor(ans);
    }
    stack.push_back(a[i]);
    {
        vector<ll> ans2 = ans;
        ans2.push_back(bit__or(stack));
        chmin(res,func(i+1, {}, ans2));
    }
    {
        vector<ll> ans2 = ans;
        vector<ll> stack2 = stack;
        chmin(res,func(i+1, stack2, ans2));
    }
    return res;
}
int main(){
    cin >> n;
    a.resize(n);
    rep(i,n)cin >> a[i];
    cout << func(0,{},{}) << endl;
}
