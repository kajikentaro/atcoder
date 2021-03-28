#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int func(){
    int n;
    cin >> n;
    if(n<=2)return 0;
    vector<int> l(n);
    rep(i,n){
        cin >> l[i];
    }
    sort(l.begin(),l.end());
    int sum = 0;
    for(int i=0;i<n-2;i++){
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(l[i] == l[j] || l[j] == l[k] || l[k] == l[j])continue;
                if(l[i] + l[j] > l[k])sum++;
            }
        }
    }
    return sum;
}
int main(){
    cout << func() << endl;
}