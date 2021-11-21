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
    int n;
    cin >> n;
    vector<string> ans;
    rep(i,pow(2,n)){
        bool ok = true;
        int a = 0;
        int b = 0;
        rep(j,n){
            if(1 << j & i){
                //(
                a++;
            }else{
                //)
                b++;
            }
            if(a < b)ok = false;
        }
        if(a != b)ok = false;
        if(!ok)continue;
        string tmp = "";
        rep(j,n){
            if(1 << j & i) tmp += "(";
            else tmp += ")";
        }
        ans.push_back(tmp);
    }
    sort(ans.begin(), ans.end());
    rep(i,ans.size())cout << ans[i] << endl;
}