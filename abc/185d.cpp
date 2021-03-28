#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int func(){
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    if(m <= 0)return 1;
    if(m == n)return 0;
    rep(i,m)cin >> a[i];
    sort(a.begin(),a.end());
    vector<int> b;
    int pre_p = 0;
    rep(i,m){
        int length = a[i] - pre_p - 1;
        pre_p = a[i];
        if(length > 0)b.push_back(length);
    }
    int length = n - a[m-1];
    if(length > 0)b.push_back(length);
    int min_l = *min_element(b.begin(),b.end());
    ll sum = 0;
    rep(i,b.size()){
        sum += (b[i] + min_l - 1) / min_l;
    }
    return sum;
}
int main(){
    cout << func() << endl;
}
