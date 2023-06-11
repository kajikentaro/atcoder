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
    int n;
    cin >> n;
    vector<vector<int>> c(n,vector<int>(n));
    rep(i,n)rep(j,n)cin >> c[i][j];
    vector<int> diff_h(n);
    rep(i,n) diff_h[i] = c[i][0] - c[0][0];
    vector<int> diff_w(n);
    rep(i,n) diff_w[i] = c[0][i] - c[0][0];

    int min_h = *min_element(diff_h.begin(), diff_h.end());
    int min_w = *min_element(diff_w.begin(), diff_w.end());
    
    int must_h = -min_h;
    int must_w = -min_w;

    if(must_h + must_w > c[0][0]){
        cout << 1/0 << endl;
        cout << "No" << endl;
        return 0;
    }

    int plus_h = must_h;
    int plus_w = c[0][0] - must_h;

    rep(i,n) diff_h[i] += plus_h;
    rep(i,n) diff_w[i] += plus_w;

    rep(i,n)rep(j,n){
        if(c[i][j] != diff_h[i] + diff_w[j]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    rep(i,n)cout << diff_h[i] << " ";
    cout << endl;
    rep(i,n)cout << diff_w[i] << " ";
    cout << endl;
    
}
