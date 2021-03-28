#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
#define chmax(a,b) a = max(a,b)
int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> p(n);
    vector<ll> c(n);
    rep(i,n)cin >> p[i];
    rep(i,n)cin >> c[i];
    rep(i,n)p[i]--;
    ll best = -1e18;
    rep(i,n){
        vector<ll> score;
        ll x = i;
        ll score_now = 0;
        do{
            x = p[x];
            score_now += c[x];
            score.push_back(score_now);
        }while(x != i);
        ll score_size = score.size();
        ll best_tmp;
        ll round_max = *max_element(score.begin(),score.end());
        ll round_score = score[score_size - 1];
        if(score_size >= k)best_tmp = *max_element(score.begin(),score.begin() + k);
        else if(round_score < 0)best_tmp = round_max;
        else{
            best_tmp = round_max + (k / score_size - 1) * round_score;
            ll new_k = k % score_size;
            if(new_k != 0)chmax(best_tmp, *max_element(score.begin(),score.begin() + new_k) + (k / score_size) * round_score);
        }
        chmax(best,best_tmp);
    }
    cout << best << endl;
}
