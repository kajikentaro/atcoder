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
int main(){
    int a,b;
    cin >> a >> b;
    int sum_a = 0;
    int sum_b = 0;
    while(a != 0){
        sum_a += a % 10;
        a /= 10;
    }
    while(b != 0){
        sum_b += b % 10;
        b /= 10;
    }
    if(sum_a > sum_b)swap(sum_a, sum_b);
    cout << sum_b << endl;

}
