#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int gcd(int a,int b){
    while(a % b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return b;
}
int main(){
    int n;
    cin >> n;
    int a;
    cin >> a;
    rep(i,n-1){
        int b;
        cin >> b;
        a = gcd(a,b);
    }
    cout << a << endl;
}
