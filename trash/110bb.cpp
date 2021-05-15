#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
ll func(){
    int n;
    string s;
    cin >> n >> s;
    if(n==1){
        if(s == "1")return 2e10;
        if(s == "0")return 1e10;
    }
    if(n==2){
        if(s == "11")return 1e10;
        if(s == "00")return 0;
        if(s == "10")return 1e10;
        if(s == "01")return 1e10 - 1;
    }
    if(s[n-3] == '0' && s[n-2] == '1' && s[n-1] == '1')s = s + "0";
    if(s[n-3] == '1' && s[n-2] == '0' && s[n-1] == '1')s = s + "10";
    if(s[0] == '0' && s[1] == '1' && s[2] == '1')s = "11" + s;
    if(s[0] == '1' && s[1] == '0' && s[2] == '1')s = "1"  + s;
    char unit[] = {'1','1','0'};
    rep(i,s.size()){
        if(s[i] != unit[i%3])return 0;
    }
    return 1e10 - s.size()/3 + 1;
}
int main(){
    cout << func() << endl;
}
