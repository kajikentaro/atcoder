#include<bits/stdc++.h>
#include<atcoder/modint>
#define rep(x,y) for(int x=0;x<y;x++)
#define rrep(x,y) for(int x=y-1;x>=0;x--)
using namespace std;
using namespace atcoder;
using mint = modint1000000007;
int main(){
    int x,y;
    cin >> x >> y;
    if(x > y)swap(x,y);
    if(x + 3 > y){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}