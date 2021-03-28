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
bool score(vector<int> s, vector<int> t){
    int score_s = 0;
    int score_t = 0;
    orep(i,9){
        score_s += i * pow(10,s[i]);
    }
    orep(i,9){
        score_t += i * pow(10,t[i]);
    }
    if(score_t < score_s)return true;
    return false;
}
int main(){
    int k;
    string s,t;
    cin >> k >> s >> t;
    int all = 9 * k;
    vector<int> card(10,k);
    vector<int> t_card(10);
    vector<int> s_card(10);
    rep(i,4){
        t_card[t[i] - '0']++;
        s_card[s[i] - '0']++;
        card[s[i] - '0']--;
        card[t[i] - '0']--;
    }
    auto p = [&](int a,int b){
        if(a == b){
            return (ll)card[a] * (card[b] - 1) ;
        }else{
            return (ll)card[a] * card[b] ;
        }
    };
    ll ans = 0;
    orep(i,9)orep(j,9){
        vector<int> t_card_tmp = t_card;
        vector<int> s_card_tmp = s_card;
        t_card_tmp[i] ++;
        s_card_tmp[j] ++;

        bool flag = false;
        orep(ttt,9){
            if(t_card_tmp[ttt] + s_card_tmp[ttt] >  k)flag = true;
        }
        if(flag)continue;
       /*
        if(t_card_tmp[i] >= k)continue;
        if(s_card_tmp[j] >= k)continue;
        */
        if(score(s_card_tmp, t_card_tmp)){
            ans += p(i,j) ;
        }
    }
    ll child = ans * 1e6;
    ll family = ((ll)(all - 8) * (all - 9));

    ll right = 1e7 ,left = 0;
    ll center;
    while(1){
        if(right - left <= 1)break;
        center = (right + left) / 2;
        if(child < center * family){
            right = center;
        }else{
            left = center;
        }
    }
    printf("%.18lf", (double)center / 1e6);
}
