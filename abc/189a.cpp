#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
int main(){
    char a[3];
    rep(i,3)cin >> a[i];
    rep(i,2){
        if(a[i] != a[2]){
            cout << "Lost"<< endl;
            return 0;
        }
    }
    cout << "Won" << endl;
}