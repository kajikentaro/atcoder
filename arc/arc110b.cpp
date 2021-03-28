#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
    int n;
    string t;
    if(n == 1){

    }
    if(n == 2){

    }
    if(t[0] == '1' && t[1] == '1' && t[2] == '0'){}
    if(t[0] == '1' && t[1] == '0' && t[2] == '1')t = "1" + t;
    if(t[0] == '0' && t[1] == '1' && t[2] == '1')t = "11" + t;
    
    if(t[n-3] == '1' && t[n-2] == '1' && t[n-1] == '0'){}
    if(t[n-3] == '1' && t[n-2] == '0' && t[n-1] == '1')t = t + "10";
    if(t[n-3] == '0' && t[n-2] == '1' && t[n-1] == '1')t = t + "0";

    cout << (ll)1e10 / (t.size() / 3)
}
