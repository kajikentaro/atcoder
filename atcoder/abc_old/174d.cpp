#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int w,r;
    w = r = 0;
    rep(i,n){
        if(s[i] == 'W')w++;
        else r++;
    }
    int sum = 0;
    rep(i,r){
        if(s[i] == 'W')sum++;
    }
    cout << sum << endl;
}
