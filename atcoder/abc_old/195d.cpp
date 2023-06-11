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
struct Item{
    int w,v;
    static bool comp_v(Item &a, Item &b){
        return a.v > b.v;
    }
};
int main(){
    int n,m,q;
    cin >> n >> m >> q;
    vector<Item> items(n);
    rep(i,n)cin >> items[i].w >> items[i].v;
    vector<int> x(m);
    rep(i,m)cin >> x[i];
    sort(items.begin(),items.end(),Item::comp_v);
    rep(i,q){
        int l,r;
        cin >> l >> r;
        l--;r--;
        vector<bool> used(m,false);
        int ans = 0;
        for(Item item : items){
            int min_x = 1e9;
            int min_x_p = -1;
            rep(j,m){
                if(l <= j && j <= r)continue;
                if(used[j])continue;
                if(x[j] < item.w)continue;
                if(chmin(min_x, x[j]))min_x_p = j;
            }
            if(min_x_p == -1)continue;
            used[min_x_p] = true;
            ans += item.v;
        }
        cout << ans << endl;
    }
}
