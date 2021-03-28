#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
#define MAX 100100
int func(){
    map<int,int> odd;
    map<int,int> even;
    int n;
    cin >> n;
    rep(i,n){
        int v;
        cin >> v;
        if(i%2)odd[v]++;
        else even[v]++;
    }
    vector<pair<int,int>> o;
    vector<pair<int,int>> e;
    for(auto i: odd){
        o.emplace_back(i.second,i.first);
    }
    for(auto i: even){
        e.emplace_back(i.second,i.first);
    }
    sort(o.rbegin(),o.rend());
    sort(e.rbegin(),e.rend());
    if(o[0].second == e[0].second){
        if(o.size() <= 1 || e.size() <= 1)return n/2;
        int prior_o = o[0].first + e[1].first;
        int prior_e = e[0].first + o[1].first;
        if(prior_o < prior_e)return n-prior_e;
        return n-prior_o;
    }
    return n - o[0].first - e[0].first;
}
int main(){
    cout << func() << endl;
}