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



struct pos{
    vector<int> series;
    vector<int> pow;
    vector<bool> ban_zero;
};
map<char,pos> input;
vector<int> zs = {0,1,2,3,4,5,6,7,8,9};
ll check(){
    vector<ll> ans(3);
    ll i = 0;
    for(auto iter = input.begin();iter != input.end();iter++){
        pos &c = iter->second;
        ll num = zs[i];

        rep(j,c.series.size()){
            ll series = c.series[j];
            ll pow_v = c.pow[j];
            if(c.ban_zero[j] == true && num == 0)return false;
            ans[series] += pow(10,pow_v) * num;
        }
        i++;
    }
    if(ans[0] + ans[1] == ans[2]){
        rep(i,3){
            cout << ans[i] << endl;
        }
        return true;
    }
    return false;
}
int main(){
    string s[3];
    rep(i,3){
        cin >> s[i];
        rep(j,s[i].size()){
            input[s[i][j]].series.push_back(i);
            input[s[i][j]].pow.push_back(s[i].size() - j - 1);
            input[s[i][j]].ban_zero.push_back(j == 0);
        }

    }
    if(input.size() <= 10){
        while(next_permutation(zs.begin(), zs.end())){
            if(check())return 0;
        }
    }
    cout << "UNSOLVABLE" << endl;
}