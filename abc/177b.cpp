#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define orep(x,y) for(int x=1;x<=y;x++)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
using P = pair<int,int>;
int main(){
    string s,t;
    cin >> s >> t;
    int ss = s.size(), ts = t.size();
    int min_v = 1e9;
    rep(i,ss){
        int same_cnt = 0;
        if(i + ts - 1 >= ss)break;
        rep(j,ts){
            //s[i] ~ 
            if(s[i + j] == t[j])same_cnt++;
        }
        chmin(min_v, ts - same_cnt);
    }
    cout << min_v << endl;
}
