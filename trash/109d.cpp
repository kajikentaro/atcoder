#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(ll x=0;x<y;x++)
#define ll long long
int main(){
    ll t;
    cin >> t;
    vector<ll> ans(t);
    rep(i,t){
        ll shape[2][2] = {};
        ll mx = 1e18;
        ll my = 1e18;
        ll x[3],y[3];
        rep(j,3){
            cin >> x[j] >> y[j];
            mx = min(mx,x[j]);
            my = min(my,y[j]);
        }
        rep(j,3){
            shape[x[j] - mx][y[j] - my] = 1;
        }
        ll tmp_ans = 2 * max(abs(mx),abs(my)) + 1;
        ll margin = 0;
        if(mx == 0 && my ==0){
            if(shape[1][1] == 0)ans[i] = 0;
            else ans[i] = 1;
            continue;
        }
        if(abs(mx) <= abs(my)){
            if(my >= 0){
                //up
                if(shape[0][0] && shape[1][0])margin = 1;
            }
            if(my <= 0){
                //down
                margin = 1;
                if(shape[0][1] && shape[1][1])margin = 2;
            }
        }
        if(abs(mx) >= abs(my)){
            if(mx >= 0){
                //right
                if(shape[0][0] && shape[0][1])margin = 1;
            }
            if(mx <= 0){
                //left
                margin = 1;
                if(shape[1][1] && shape[1][0]){
                    margin = 2;
                    if(abs(mx) == abs(my)){
                        margin = 1;
                    }
                }
            }
        }
        ans[i] = tmp_ans - margin;
    }
    rep(i,t){
        cout << ans[i] << endl;
    }
}