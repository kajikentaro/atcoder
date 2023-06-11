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
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n)cin >> x[i] >> y[i];
    int count = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            double d =  (double)(y[i] - y[j]) / (x[i] - x[j]);
            if(abs(d) <= 1)count++;
        }
    }
    cout << count << endl;
}
