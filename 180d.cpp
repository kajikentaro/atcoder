#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll x,y,a,b;
    cin >> x >> y >> a >> b;
    ll k = 0;
    while(x<b/(a-1) && y > x*a){
        x *= a;
        k++;
    }
    k += (y - x - 1)/b;
    cout << k << endl;
}