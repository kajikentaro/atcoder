#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> table(n+1);
    for(int i=2;i*i<=n;i++){
        for(int j=i;j<=n;j+=i){
            if(table[j]==0)table[j] = i;
        }
    }
    for(int i=1;i<n;i++){
        vector<int> factor;
        int c = i;
        while(){
            if(table[c]!=0){
                factor.push_back(table[c]);
                c/=table[c];
            }else{
                
            }
        }
    }
    return 0;

}