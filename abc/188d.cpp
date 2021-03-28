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
struct Prime{
    int day,fee;
    Prime(int a,int b){
        day = a;
        fee = b;
    }
};
bool cmp(const Prime &a, const Prime &b){
    return a.day < b.day;
}
int main(){
    int n;
    ll c;
    cin >> n >> c;
    vector<Prime> list;
    rep(i,n){
        int a,b,c;
        cin >> a >> b >> c;
        list.push_back(Prime(a,c));
        list.push_back(Prime(b + 1,-c));
    }
    sort(list.begin(),list.end(),cmp);
    ll now_fee = 0;
    ll now_time = 0;
    ll cash = 0;
    rep(i,n * 2){
        ll next_time = list[i].day;
        cash += min(c, now_fee) * (next_time - now_time);

        now_fee += list[i].fee;
        now_time = next_time;
    }
    cout << cash << endl;
}
