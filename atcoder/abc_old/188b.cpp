#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    int sum = 0;
    rep(i,n)sum += a[i] * b[i];
    if(sum ==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
