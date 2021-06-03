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
using P = pair<long,long>;
int main(){
    #define int long long
    int n,k;
    cin >> n >> k;
    vector<P> human(n);
    rep(i,n)cin >> human[i].first >> human[i].second;
    sort(human.begin(),human.end());
    ll sum = k;
    ll pre_pos = 0;
    rep(i,n){
        int locate, money;
        tie(locate, money) = human[i];
        if(sum - locate < 0){
            break;
        }else{
            sum += money;
        }
    }
    cout << sum << endl;
}
