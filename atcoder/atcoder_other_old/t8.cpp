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
    string s;
    cin >> n >> s;
    vector<mint> dp(8);
    dp[0] = 1;
    const char element[] = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
    rep(i,n){
        rrep(j,7){
            if(element[j] == s[i]){
                dp[j+1] += dp[j];
            }
        }
    }
    cout << dp[7].val() << endl;
}

