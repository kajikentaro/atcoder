#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int main(){
    int n;
    string s;
    cin >> n >> s;
    if(n<3){
        ll ans;
        if(n==1){
            if(s[0]=='1'){
                ans = 2e10;
            }else{
                ans = 1e10;
            }
        }
        if(n==2){
            if(s[0]=='1' && s[1]=='1'){
                ans = 1e10;
            }
            if(s[0]=='1' && s[1]=='0'){
                ans = 1e10;
            }
            if(s[0]=='0' && s[1]=='1'){
                ans = 1e10 - 1;
            }
            if(s[0]=='0' && s[1]=='0'){
                ans = 0;
            }
        }
        cout << ans << endl;
        return 0;
    }
    char pat[] = {'1','1','0'};
    int off = 0;
    if(s[0]=='1' && s[1]=='1' && s[2]=='0'){
        off = 0;
    }else if(s[0]=='0' && s[1]=='1' && s[2]=='1'){
        off = 2;
    }else if(s[0]=='1' && s[1]=='0' && s[2]=='1'){
        off = 1;
    }else{
        cout << 0 << endl;
        return 0;
    }
    rep(i,n){
        if(s[i] != pat[(i+off)%3]){
            cout << 0 << endl;
            return 0;
        }
    }
    ll k = (n + off + 2)/3;
    cout << (ll)1e10 - (k-1) << endl;
}