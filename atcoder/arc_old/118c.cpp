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
void dfs(int now, vector<int> &can, vector<int> &res){
    if(res.size() > 2500)return;
    for(int c : can){
        int new_n = now * c;
        if(new_n < 1e4)continue;
        res.push_back(new_n);
        dfs(new_n, can, res);
    }
}
vector<int> res;
int main(){
    vector<int> tei = {2,3,5,7,11};
    vector<int> def = {15,10,6};
    rep(i,pow(2,5)){
        int bit_n = 0;
        vector<int> can;
        rep(j,5){
            if(1 << j & i){
                bit_n++;
                can.push_back(tei[j]);
            }
        }
        if(bit_n <= 1)continue;
        int now = 1;
        rep(j,can.size()){
            now *= can[j];
        }
        dfs(now, can, res);
    }
    int n;
    cin >> n;
    n -= 3;
    rep(i,3){
        cout << def[i] << " ";
    }
    int c = 0;
    rep(i,n){
        rep(j,3){
            if(res[c] == def[j]){
                c++;
                j--;
            }
        }
        cout << res[c] << " ";
        c++;
    }
    cout << endl;
}
