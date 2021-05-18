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
    int n,l,k;
    cin >> n >> l >> k;
    vector<int> a(n);
    rep(i,n)cin >> a[i];

    a.push_back(l);
    n++;

    int ac = 1;
    int wa = 1e9;
    while(wa - ac != 1){
        int wj = (ac + wa) / 2;

        int pre_cut = 0;
        int cut_cnt_left = k+1;
        rep(i,n){
            int now_length = a[i] - pre_cut;
            if(now_length >= wj){
                pre_cut = a[i];
                cut_cnt_left--;
            }
        }
        if(cut_cnt_left <= 0)ac = wj;
        else wa = wj;
    }
    cout << ac << endl;
}
