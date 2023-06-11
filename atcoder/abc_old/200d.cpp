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
vector<int> dp(200,-1);
vector<int> a;
vector<int> func(int p){
    vector<int> ans;
    if(p == 0 && dp[p] != -1){
        ans.push_back(dp[p]);
        p = (p - a[dp[p]] + 200) % 200;
    }
    while(p != 0){
        ans.push_back(dp[p]);
        p = (p - a[dp[p]] + 200) % 200;
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    a.resize(n);
    rep(i,n){
        int t;
        cin >> t;
        t %= 200;
        a[i] = t;
    }
    rep(i,n){
        rep(j,200){
            if(dp[j] == i)continue;
            if(j == 0 || dp[j] != -1){
                int p = (a[i] + j) % 200;
                if(dp[p] != -1){
                    cout << "Yes" << endl;
                    vector<int> ans1 = func(p);
                    vector<int> ans2 = func(j);
                    ans2.insert(ans2.begin(), i);
                    cout << ans1.size() << " ";
                    rrep(k,ans1.size()){
                        cout << ans1[k] + 1 << " ";
                    }
                    cout << endl << ans2.size() << " ";
                    rrep(k,ans2.size()){
                        cout << ans2[k] + 1 << " ";
                    }
                    cout << endl;
                    return 0;
                }
                dp[p] = i;
            }
            //if((dp[j] == -1 || dp[j] == i) && j!=0)continue;
        }
    }
    cout << "No" << endl;
}
