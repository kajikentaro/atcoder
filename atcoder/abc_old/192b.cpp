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
int func(){
    string s;
    cin >> s;
    rep(i,s.size()){
        if(i % 2 == 0){
            //奇数
            if(!(s[i] <= 'z' && s[i] >= 'a'))return 1;
        }else{
            //偶数
            if(!(s[i] <= 'Z' && s[i] >= 'A'))return 1;
        }
    }
    return 0;
}
int main(){
    if(func()){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}
