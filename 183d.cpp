#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;
int main(){
    vector<ll> use(300000,0);
    ll n,w;
    cin >> n >> w;
    rep(i,n){
        int s,t,p;
        cin >> s >> t >> p;
        use[s] += p;
        use[t] -= p;
    }
    vector<ll> water(300000,0);
    ll now_use = 0;
    rep(i,300000){
        now_use += use[i];
        water[i] = now_use;
    }
    sort(water.rbegin(),water.rend());
    if(water[0] > w){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}