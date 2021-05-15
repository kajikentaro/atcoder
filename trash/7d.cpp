#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[20][2][2] = {};
ll solve(string a,int keta,bool tight,bool flag){
    ll sum = 0;
    bool preflag = flag;
    for(int i=0;i<=(tight ? (a[keta] - '0') : 9);i++){
        flag = (i==4 || i==9 || preflag);
        if(keta == (a.size()-1)){
            sum+=flag;
            continue;
        }
        bool new_tight = tight && (i==a[keta]-'0'); 
        ll cache = dp[keta+1][new_tight][flag];
        if(cache){
            sum += cache;
        }else{
            sum += dp[keta+1][new_tight][flag] = solve(a,keta+1,new_tight,flag);
        }
    }
    return sum;
}
int main(){
    string a,b;
    cin >> a >> b;
    if(a[a.size()-1]=='0'){
        a[a.size()-1] = '9';
        a[a.size()-2]--;
    }else{
        a[a.size()-1]--;
    }
    ll result_b = solve(b,0,true,false);
    for(int i=0;i<20;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                dp[i][j][k] = 0;
            }
        }
    }
    ll result_a = solve(a,0,true,false);
    cout <<  result_b - result_a << endl;
}