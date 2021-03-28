#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
using namespace std;
using ll = long long;
int ringmod(int in, int mod){
    if(in > mod) return in % mod + mod;
    return in;
}
int modpow(int in, int exp, int mod){
    in = ringmod(in,mod);
    ll ans = 1;
    rep(i,exp){
        ans = ringmod(ans * in,mod);
    }
    return ans;
}
int main(){
    int a,b,c;
    cin >> a >> b >> c;

    int c_ans = modpow(c,1,2);
    int b_ans = modpow(b,c_ans,4);
    int a_ans = modpow(a,b_ans,10);

    a_ans %= 10;

    cout << a_ans << endl;
}