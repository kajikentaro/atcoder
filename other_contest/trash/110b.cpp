#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int main(){
    int n;
    cin >> n;
    vector<vector<int>> table(31,vector<int>(31));
    for(int i=2;i<=n;i++){
        int t = i;
        for(int j=2;j <= i;){
            if(t%j==0){
                table[i][j]++;
                t/=j;
            }else{
                j++;
            }
        }
        if(t==i)table[i][t]++;
    }
    ll sum = 1;
    for(int i=2;i<=n;i++){
        int nmax = 0;
        for(int j=2;j<=n;j++){lcm
    }
    cout << sum + 1 << endl;
}
