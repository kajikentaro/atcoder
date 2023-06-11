#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
#define ll long long
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> path(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    vector<int> sign(n,-1);
    sign[0] = 0;
    queue<int> q;
    q.push(0);
    while(1){
        int c = q.front();
        q.pop();
        for(auto d : path[c]){
            if(sign[d] != -1)continue;
            q.push(d);
            sign[d] = c;
        }
        if(q.size() == 0)break;
    }
    rep(i,n){
        if(i==0)continue;
        if(sign[i] == -1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    rep(i,n){
        if(i==0)continue;
        cout << sign[i] + 1 << endl;
    }
}
