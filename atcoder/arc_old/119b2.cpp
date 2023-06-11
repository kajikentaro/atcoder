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
vector<bool> skip;
vector<int> s;
vector<int> t;
int main(){
    #define int long long
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;
    vector<int> s_pos;
    vector<int> t_pos;
    rep(i,n){
        if(s[i] == '0'){
            s_pos.push_back(i);
        }
        if(t[i] == '0'){
            t_pos.push_back(i);
        }
    }
    if(s_pos.size() != t_pos.size()){
        cout << -1 << endl;
        return 0;
    }
    int m = s_pos.size();
    int ans = 0;
    rep(i,m){
        if(s_pos[i] != t_pos[i])ans++;
    }
    cout << ans << endl;
}
