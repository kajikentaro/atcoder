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
vector<int> z(1e8);
ll func(int a){
    int b = a;
    int count = 0;
    while(a != 1){
        a /= z[a];
        count++;
    }
    cout << b << " " << count << endl;
    return count;
}
int main(){
    int n;
    cin >> n;
    z[1] = 1;
    for(int i=2;i * i < 2e7;i++){
        if(z[i] != 0)continue;
        for(int j = i;j < 2e7;j+=i){
            z[j] = i;
        }
    }
    ll sum = 0;
    for(int i=1;i<=n;i++){
        sum += i * pow(2,func(i));
    }
    cout << sum << endl;
    return 0;
}