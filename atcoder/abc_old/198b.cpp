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
int func(){
    string s;
    cin >> s;
    int front = 0;
    int end = s.size() - 1;
    while(s[end] == '0'){
        end--;
    }
    while(1){
        if(front >= end)return true;
        if(s[front] == s[end]){
            front++;
            end--;
        }else{
            return false;
        }
    }
}
int main(){
    if(func()){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}