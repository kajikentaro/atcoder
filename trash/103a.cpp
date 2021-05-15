#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
int main(){
    vector<pair<int,int>> odd,even;
    int n;
    cin >> n;
    vector<int> odd_v;
    vector<int> even_v;
    rep(i,n){
        int v;
        cin >> v;
        if(i%2){
            odd[v] = odd[v];
            odd_v.push_back(v);
        }else{
            even[v]++;
            even_v.push_back(v);
        }
    }
    rep(i,odd.size()){
    }
}