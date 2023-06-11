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
    int n,q;
    string s;
    cin >> n >> s >> q;
    string front = "";
    string back = "";
    front = s.substr(0,n);
    back = s.substr(n);
    rep(i,q){
        int t,a,b;
        cin >> t >> a >> b;
        a--;b--;
        if(t==1){
            char *a_p, *b_p;
            if(a < n){
                a_p = &front[a];
            }else{
                a_p = &back[a-n];
            }
            if(b < n){
                b_p = &front[b];
            }else{
                b_p = &back[b-n];
            }
            swap(*a_p, *b_p);
        }
        if(t==2){
            swap(front,back);
        }
    }
    cout << front + back << endl;
}
