#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int main(){
    int n,m,t;
    cin >> n >> m >> t;
    int max = n;
    vector<int> a(m);
    vector<int> b(m);
    rep(i,m){
        cin >> a[i] >> b[i];
    }
    int c = 0;
    rep(i,m){
        n -= (a[i] - c);
        if(n <= 0){
            cout << "No" << endl;
            return 0;
        }
        c = a[i];
        n += b[i] - c;
        if(n >= max)n = max;
        c = b[i];
    }
    n -=  (t - c);
    if(n <= 0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;

}
