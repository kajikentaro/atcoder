#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    ll sum = a + b + c + d;
    rep(i,2)rep(j,2)rep(k,2)rep(l,2){
        ll tmp = 0;
        if(i)tmp += a;
        if(j)tmp += b;
        if(k)tmp += c;
        if(l)tmp += d;
        if(tmp * 2 == sum){
            cout << "Yes" << endl;
            return 0;
        }
    }
        cout << "No" << endl;
        return 0;

}
