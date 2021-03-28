#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll unsigned long long int
using namespace std;
using namespace atcoder;   
int main(){
    ll l;
    cin >> l;
    l--;
    ll sum = 1;
    int bai[] = {1,2,3,2,2,5,2,3,7,2,2,2,3,3,2,5,11};
    rep(i,11){
        int copy_l = l;
        rep(j,17){
            if(copy_l % bai[j] == 0){
                copy_l /= bai[j];
                bai[j] = 1;
            }
        }
        sum *= (copy_l);
        l--;
    }
    cout << sum << endl;
}
