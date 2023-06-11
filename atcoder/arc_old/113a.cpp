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
using P = pair<int,int>;
struct T{
    int a,b,c;
    T(int a,int b,int c):a(a), b(b), c(c){}
};
int main(){
    map<int,int> M;
    int k;
    cin >> k;
    int k_backup = k;//1!!!!!
    for(int i=2;i*i<=k_backup;i++){
        while(k % i == 0){
            M[i]++;
            k /= i;
        }
    }
    for(auto m : M){
        int x,n;
        tie(x, n) = m;
        rep(i,n){
            for(int j=i;j<n;j++){
                if(i + j >= n)break;
                for(int k=j;k<n;k++){
                    if(i + j + k >= n)break;

                }
            }
        }
    }
}
