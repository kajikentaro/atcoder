#include<bits/stdc++.h>
using namespace std;
#define ll long long
int pow(ll a,ll b, ll m){
    if(b == 0)return 1;
    ll fix = 1;
    if(b % 2 != 0){
        fix = a;
        b--;
    }
    ll tmp = pow(a, b/2, m);
    return tmp * tmp % m * fix % m;
}
int main(){
    ll n,m;
    cin >> n >> m;
    ll res = pow(10,n,m*m);
    cout << res / m << endl;
}