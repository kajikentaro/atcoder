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
vector<int> ans;
void dfs(vector<int> &col,vector<int> &col_used,vector<bool> &p_used,vector<vector<int>> &path, int now_p){
    if(p_used[now_p])return;
    if(col_used[col[now_p]] == 0)ans.push_back(now_p);
    col_used[col[now_p]]++;
    p_used[now_p] = true;
    for(int new_p : path[now_p]){
        dfs(col,col_used,p_used,path,new_p);
    }
    col_used[col[now_p]]--;
    p_used[now_p] = false;
}
int main(){
    int n;
    cin >> n;
    vector<int> col(n);
    rep(i,n)cin >> col[i];
    vector<vector<int>> path(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    vector<int> col_used(1e5+10,0);
    vector<bool> p_used(n,false);
    dfs(col,col_used,p_used,path,0);
    sort(ans.begin(),ans.end());
    for(auto i : ans){
        cout << i + 1 << endl;
    }
}
