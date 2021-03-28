#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
struct Ring{
    vector<ll> ring;
    ll offset;
    ll mod;
    Ring(ll a,ll mod){
        ll now = a % mod;
        while(1){
            if(check(now) != -1){
                offset = check(now);
                this->mod = (ll)ring.size() - offset;
                break;
            }else{
                ring.push_back(now);
                now = (now * a) % mod;
            }
        }
    }
    ll check(ll a){
        rep(i,ring.size()){
            if(ring[i] == a)return i;
        }
        return -1;
    }
    ll get(ll p){
        if(p == 0)return ring[offset + mod - 1];
        if(p <= offset) return ring[p-1];
        p %= mod;
        return ring[offset + p-1];
    }
};
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    Ring A(a,10);
    Ring B(b,A.mod);

    ll r2 = B.get(c);
    ll r1 = A.get(r2);
    cout << r1 << endl;
}
