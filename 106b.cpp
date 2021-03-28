#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;
int main(){
    int n,m;
    cin >> n >> m;
    vector<int> before(n);
    vector<int> after(n);
    rep(i,n)cin >> before[i];
    rep(i,n)cin >> after[i];
    dsu uf(n);
    rep(i,m){
        int c,d;
        cin >> c >> d;
        c--;d--;
        uf.merge(c,d);
    }
    vector<vector<int>> graph;
    graph = uf.groups();
    rep(i,graph.size()){
        ll margin = 0;
        rep(j,graph[i].size()){
            margin += before[graph[i][j]];
            margin -= after[graph[i][j]];
        }
        if(margin!=0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}