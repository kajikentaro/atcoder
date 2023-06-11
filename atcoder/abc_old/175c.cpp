#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
ll x,k,d;
ll get(ll t){
    return abs(x - d * t);
}
ll func(){
    cin >> x >> k >> d;
    x = abs(x);
    ll t1 = x/d;
    ll t2 = t1 + 1;
    if(get(t1) < get(t2))swap(t1,t2);//t1 is best
    if(k <= t1)return get(k);
    ll r = k - t1;
    if(r % 2 == 0)return get(t1);
    else return get(t2);
}
int main(){
    cout << func() << endl;
}
