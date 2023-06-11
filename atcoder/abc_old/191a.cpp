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
string func(){
    int v,t,s,d;
    cin >> v >> t >> s >> d;
    int disappear_s = v * t;
    int disappear_e = v * s;
    if(disappear_s <= d && disappear_e >= d){
        return "No";
    }
    return "Yes";
}
int main(){
    cout << func() << endl;
}
