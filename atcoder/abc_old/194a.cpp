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
int func(){
    int a,b;
    cin >> a >> b;
    int koke = a + b;
    int sibo = b;
    if(koke >= 15 && sibo >= 8)return 1;
    else if(koke >= 10 && sibo >= 3)return 2;
    else if(koke >= 3)return 3;
    else return 4;
}
int main(){
    cout << func() << endl;
}
