#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
ll func(){
    int n;
    string s;
    cin >> n >> s;
    if(n==1){
        if(s[0] == '1')return 2e10;
        if(s[0] == '0')return 1e10;
    }
    if(n==2){
        if(s[0] == '1' && s[1] == '1')return 1e10;
        if(s[0] == '0' && s[1] == '0')return 0;
        if(s[0] == '1' && s[1] == '0')return 1e10;
        if(s[0] == '0' && s[1] == '1')return 1e10 - 1;
    }
    char pat[] = {'1','1','0'};
    int off = 0;
    if(s[0]=='1' && s[1]=='1' && s[2]=='0'){
        off = 0;
    }else if(s[0]=='0' && s[1]=='1' && s[2]=='1'){
        off = 1;
    }else if(s[0]=='1' && s[1]=='0' && s[2]=='1'){
        off = 2;
    }else{
        return 0;
    }
    rep(i,n){
        if(s[i] != pat[(i+3-off)%3]){
            return 0;
        }
    }
    ll k = (n + off + 2)/3;
    return (ll)1e10 - (k-1);
}
int main(){
    cout << func() << endl;
}
