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
    string s;
    cin >> s;
    ll res = 0;
    rep(i,10000){
        int a = i;
        vector<int> ans(4);
        rep(j,4){
            ans[j] = a % 10;
            a /= 10;
        }
        bool ok2 = true;
        rep(j,10){
            if(s[j] == 'x'){
                bool ok = true;
                rep(k,4){
                    if(ans[k] == j)ok = false;
                }
                if(ok == false)ok2 = false;
            }
            if(s[j] == 'o'){
                bool ok = false;
                rep(k,4){
                    if(ans[k] == j)ok = true;
                }
                if(ok == false)ok2 = false;
            }
        }
        if(ok2){
            res++;
        }
    }
    cout << res << endl;
}
