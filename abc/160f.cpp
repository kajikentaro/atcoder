#include<bits/stdc++.h>
#include<atcoder/modint>
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
vector<vector<int>> path;
mint factorial(int n){
    mint ans = 1;
    orep(i,n){
        ans *= i;
    }
    return ans;
}
mint func(int v){
    mint ans = 1;
    if(path[v].size() == 0)return 1;
    for(auto d : path[v]){
        ans *= func(d);
    }
    return ans * factorial(path[v].size());
}
int main(){
    int n;
    cin >> n;
    path.resize(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        if(a > b)swap(a,b);//a is smaller
        path[a].push_back(b);
    }
    rep(i,n){
        cout << func(0).val() << endl;
    }
}
