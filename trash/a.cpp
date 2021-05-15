#include<atcoder/all>
#include<bits/stdc++.h>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define ll long long
int main(void){
    ll a,b,c;
    cin >> a >> b >> c;
    mint sum(1),A(a),B(b),C(c);
    sum *=(1+a)*a/2;
    sum *=(1+b)*b/2;
    sum *=(1+c)*c/2;
    cout << sum.val() << endl;
    return 0;
}