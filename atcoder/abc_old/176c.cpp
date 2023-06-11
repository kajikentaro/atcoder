#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
using ll = long long;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    ll sum = 0;
    int max = a[0];
    rep(i,n){
        if(max > a[i]){
            sum += max - a[i];
        }else{
            max = a[i];
        }
    }
    cout << sum << endl;
}