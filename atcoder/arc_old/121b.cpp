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
using P = pair<long long,char>;
using PP = pair<long long,long long>;
ll func(){
    ll n;
    cin >> n;
    n*=2;
    ll rn,gn,bn;
    rn = gn = bn = 0;
    vector<P> mix;
    rep(i,n){
        ll a;
        char c;
        cin >> a >> c;
        mix.emplace_back(a,c);
        if(c == 'R')rn++;
        if(c == 'G')gn++;
        if(c == 'B')bn++;
    }
    rn %= 2;
    gn %= 2;
    bn %= 2;

    if(rn == 0 && gn == 0 && bn == 0)return 0;
    //if(rn == 0)
    if(gn == 0){
        rep(i,n){
            if(mix[i].second == 'G')mix[i].second = 'R';
            else if(mix[i].second == 'R')mix[i].second = 'G';
        }
    }
    if(bn == 0){
        rep(i,n){
            if(mix[i].second == 'B')mix[i].second = 'R';
            else if(mix[i].second == 'R')mix[i].second = 'B';
        }
    }
    //r is zero;
    sort(mix.begin(), mix.end());
    const ll inf = 1e17;
    ll idxG = -1;
    ll idxB = -1;
    ll idxR = -1;
    ll min_cost = inf;
    ll idx_from = -1;
    ll idx_to = -1;

    vector<PP> dist_RB;
    vector<PP> dist_RG;
    rep(i,n){
        if(mix[i].second == 'R'){
            if(idxG != -1)dist_RG.emplace_back(mix[i].first - mix[idxG].first,i);
            if(idxB != -1)dist_RB.emplace_back(mix[i].first - mix[idxB].first,i);
            idxR = i;
            continue;
        }
        if(mix[i].second == 'G'){
            if(idxR != -1)dist_RG.emplace_back(mix[i].first - mix[idxR].first,idxR);
            idxG = i;
            if(idxB == -1)continue;
            if(chmin(min_cost, mix[i].first - mix[idxB].first)){
                idx_from = idxB;
                idx_to = i;
            }
        }
        if(mix[i].second == 'B'){
            if(idxR != -1)dist_RB.emplace_back(mix[i].first - mix[idxR].first,idxR);
            idxB = i;
            if(idxG == -1)continue;
            if(chmin(min_cost, mix[i].first - mix[idxG].first)){
                idx_from = idxG;
                idx_to = i;
            }
        }
    }
    ll tmp = inf;
    if(dist_RB.size() && dist_RG.size()){
        tmp = 0;
        sort(dist_RB.begin(),dist_RB.end());
        sort(dist_RG.begin(),dist_RG.end());
        tmp += dist_RB[0].first;
        tmp += dist_RG[0].first;
        if(dist_RB[0].second == dist_RG[0].second){
            tmp = min(dist_RB[0].first + dist_RG[1].first,dist_RG[0].first + dist_RB[1].first);
        }
    }
    return min(tmp,min_cost);
}

int main(){
    cout << func() << endl;
}