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
    vector<int> be(n,0);
    const int inf = 1e9;
    vector<int> x_min(n,inf);
    vector<int> x_max(n,-inf);
    rep(i,n){
        int x,c;
        cin >> x >> c;
        c--;
        be[c] = 1;
        chmin(x_min[c], x);
        chmax(x_max[c], x); 
    }
    ll now_1 = 0;
    ll now_2 = 0;
    ll ans_1 = 0;
    ll ans_2 = 0;
    rep(i,n){
        if(be[i] == 0)continue;
        {
            ans_1 = min(abs(now_1 - x_min[i]) + abs(x_min[i] - x_max[i]) + ans_1,abs(now_2 - x_min[i]) + abs(x_min[i] - x_max[i]) + ans_2);
        }
        {
            ans_2 = min(abs(now_1 - x_max[i]) + abs(x_min[i] - x_max[i]) + ans_2,abs(now_2 - x_max[i]) + abs(x_min[i] - x_max[i]) + ans_1);
        }
        now_1 = x_max[i];
        now_2 = x_min[i];
    }
    ans_1 += abs(now_1);
    ans_2 += abs(now_2);
    cout << min(ans_1, ans_2) << endl;
}
