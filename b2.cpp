#include<atcoder/all>
#include<bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define ll long long 
int main(){
    int N;
    cin >> N;
    ll sum = 0;
    for(int i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        sum += (a + b) * (b - a + 1) /2;
    }
    cout << sum << endl;
}