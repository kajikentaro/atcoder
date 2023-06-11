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
string func(){
        ll n;
        cin >> n;
        int odd = 1;//1の分
        int even = 0;
        while(n % 2 == 0){
            n /= 2;
            even++;
            if(n==1)break;
        }
        if(odd == even)return "Same";
        if(odd > even)return "Odd";
        if(even > odd)return "Even";
}
int main(){
    int t;
    cin >> t;
    rep(i,t)cout << func() << endl;
}
