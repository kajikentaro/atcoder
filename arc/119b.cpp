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
vector<bool> skip;
vector<int> s;
vector<int> t;
int main(){
    //1の個数違うNO
    //それ以外YEｓ
    int n;
    cin >> n;
    string input,output;
    cin >> input >> output;
    rep(i,n){
        if(input[i] == '1')s.push_back(i);
        if(output[i] == '1')t.push_back(i);
    }
    if(s.size() != t.size()){
        cout << -1 << endl;
        return 0;
    }
    int one_size = s.size();
    skip.resize(one_size);
    rep(i,one_size){
        if(i+1 <= one_size -1 && s[i+1] <= t[i] && t[i] <= t[i+1]){//みぎ
            skip[i] = 1;
            t[i] = t[i+1];
            s[i+1] = s[i];
        }
        if(i-1 >= 0 && t[i-1] <= t[i] && t[i] <= s[i-1]){
            skip[i-1] = true;
            t[i] = t[i-1];
            s[i-1] = s[i];
        }
    }
    ll ans = 0;
    rep(i,one_size){
        if(skip[i])continue;
        if(s[i] > t[i])swap(s[i],t[i]);//sが小さい
        for(int j=s[i];j<=t[i];j++){
            if(input[j] == '0')ans++;
        }
    }
    cout << ans << endl;
}
