#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
int main(){
    ll n;
    cin >> n;
    vector<ll> three;
    vector<ll> five;
    ll tmp3 = 3;
    ll tmp5 = 5;
    three.push_back(-99);
    five.push_back(-99);
    while(tmp3 <= 1e18){
        three.push_back(tmp3);
        tmp3 *= 3;
    }while(tmp5 <= 1e18){
        five.push_back(tmp5);
        tmp5 *= 5;
    }
    rep(i,three.size()){
        rep(j,five.size()){
            if(i==0 || j==0)continue;
        if(three[i] + five[j] == n){
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;

}