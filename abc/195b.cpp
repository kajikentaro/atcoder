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
int main(){
    int a,b,w;
    cin >> a >> b >> w;
    w *= 1000;
    int min_v = (w + b - 1)/ b;
    int max_v = w / a;
    if(min_v > max_v){
        cout << "UNSATISFIABLE" << endl;
    }else{
        cout << min_v << endl;
        cout << max_v << endl;
    }
}