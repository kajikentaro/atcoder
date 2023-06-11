#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
    int n,x;
    cin >> n >> x;
    int sum = 0;
    x *= 100;
    int out = -1;
    rep(i,n){
        int v,p;
        cin >> v >> p;
        sum += v * p;
        if (sum > x){
            out = i + 1;
            break;
        }
    }
    cout << out << endl;
}
