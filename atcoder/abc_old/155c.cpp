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
struct myitem{
    string s;
    int n;
    myitem(string sin, int nin){
        s = sin;
        n = nin;
    }
};
bool cmp(const myitem &a, const myitem &b){
    if(a.n == b.n){
        return a.s < b.s;
    }else{
        return a.n > b.n;
    }
}
int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    rep(i,n){
        cin >> s[i];
    }
    sort(s.begin(),s.end());
    string now = s[0];
    int now_i = 1;
    vector<myitem> myitems;
    rep(i,n){
        if(i==0)continue;
        if(now != s[i]){
            myitems.push_back(myitem(now, now_i));
            now_i = 1;
            now = s[i];
        }else{
            now_i ++;
        }
    }
    myitems.emplace_back(now, now_i);
    sort(myitems.begin(), myitems.end(),cmp);
    int max_v = myitems[0].n;
    rep(i,n){
        if(myitems[i].n != max_v)break;
        cout << myitems[i].s << endl;
    }
    return 0;
}
