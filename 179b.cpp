#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x =0;x<y;x++)
int main(){
    int n;
    cin >> n;
    int count = 0;
    int result = 0;
    rep(i,n){
        int a,b;
        cin >> a >> b;
        if(a == b){
            count ++;
        }else{
            count = 0;
        }
        if(count == 3){
            result = 1;
        }
    }
    if(result){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}