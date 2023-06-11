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
struct A{
    vector<vector<int>> a;
    vector<int> b;
    A(vector<vector<int>> a_, vector<int> b_):a(a_), b(b_){}
};
A dot(A a, A b){
    A c({{0,0},{0,0}}, {0,0});
    rep(i,2)rep(j,2)rep(k,2){
        c.a[i][j] += a.a[i][k] * b.a[k][j];
    }
    rep(i,2){
        c.b[i] = a.b[i] + b.b[i];
    }
    return c;
}
vector<int> dot2(A a, vector<int> b){
    vector<int> c;
    rep(i,2)rep(j,2){
        c[i] += b[i] * a.a[i][j];
    }
    rep(i,2){
        c[i] += a.b[i];
    }
    return c;
}
const A rotateRight({{0,1},{-1,0}},{0,0});
const A rotateLeft({{0,-1},{1,0}},{0,0});
A foldX(int p){return A({{-1,0},{0,1}}, {2*p,0});}
A foldY(int p){return A({{1,0},{0,-1}}, {0,2*p});}
int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    int m;
    cin >> m;
    vector<A> ope;
    ope.push_back(A({{1,0},{0,1}},{0,0}));
    rep(i,m){
        int op;
        cin >> op;
        switch(op){
            case 1:
                ope.push_back(dot(rotateRight, ope[i]));
                break;
            case 2:
                ope.push_back(dot(rotateLeft, ope[i]));
                break;
            case 3:
                int p;
                cin >> p;
                ope.push_back(dot(foldX(p), ope[i]));
                break;
            case 4:
                int p;
                cin >> p;
                ope.push_back(dot(foldY(p), ope[i]));
                break;
        }
    }
    int q;
    cin >> q;
    rep(i,q){
        int a,b;
        cin >> a >> b;
        b--;
        A ans = dot2(ope[a], )
    }
}
