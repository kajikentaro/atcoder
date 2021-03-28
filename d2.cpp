#include<atcoder/all>
#include<bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define ll long long 
void test(ll S){
    if(S < 10 && S!=8){
        cout << "No" << endl;
        return;
    }
    ll T = (S%10)*10 + (S/10);
    if(S%8==0 || T%8 ==0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
int main(){
    ll S;
    cin >> S;
    ll a[10] = {};
    if(S < 100){
        test(S);
        return 0;
    }
    if(S < 100)a[0] = 1;
    if(S < 10)a[0] = 2;
    while(S > 0){
        a[S%10]++;
        S /= 10;
    }
    ll b[1000][11] = {};
    ll bc = 0;
    for(ll i=1;i<1001;i++){
        if(i%8 == 0){
            bc++;
            ll e,f,g;
            e = i%10;
            f = (i/10)%10;
            g = (i/100)%10;
            b[bc-1][e]++;
            b[bc-1][f]++;
            b[bc-1][g]++;
        }
    }
    for(ll i=1;i<11;i++){
        for(ll j=0;j<124;j++){
            ll flag = 1;
            for(ll k=0;k<11;k++){
                if(a[k] < b[j][k])flag = 0;
            }
            if(flag){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}