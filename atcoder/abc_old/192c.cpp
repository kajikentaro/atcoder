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
int main(){
    string n;
    int k;
    cin >> n >> k;
    string a = n;
    rep(i,k){
        string g1 = a;
        string g2 = a;
        sort(g2.begin(),g2.end());
        sort(g1.rbegin(),g1.rend());
        int p = (atoi(g1.c_str()) - atoi(g2.c_str()));
        a = to_string(p);
    }
    cout << a << endl;
}
