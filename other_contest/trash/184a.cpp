#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int inner(ll x,ll y){
    return (x == y || x == -y || abs(x)+abs(y) <= 3);
}
int inner2(ll x,ll y){
    return (abs(x + y) <= 3 || abs(x - y) <= 3  || abs(x)+abs(y) <= 6);
}
int main(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    ll x = c - a;
    ll y = d - b;
    int sum;
    if(x == 0 && y == 0){
        sum = 0;
    }else if(inner(x,y)){
        sum = 1;
    }else if(inner2(x,y) || (a+b)%2 == (c+d)%2){
        sum = 2;
    }else{
        sum = 3;
    }
    cout << sum << endl;
}
