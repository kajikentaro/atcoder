#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
int main(){
    int n;
    cin >> n;
    int pt,px,py;
    pt = px = py = 0;
    rep(i,n){
        int t,x,y;
        cin >> t >> x >> y;
        int time = t-pt;
        int dist = abs(x - px) + abs(y - py);
        if(time < dist){
            cout << "No" << endl;
            return 0;
        }
        if(time > dist && (time - dist) % 2 == 1){
            cout << "No" << endl;
            return 0;
        }
        pt = t;
        px = x;
        py = y;
    }
    cout << "Yes" << endl;
    return 0;
}