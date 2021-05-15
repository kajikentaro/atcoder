#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
int main(){
    int n,m;
    cin >> n >> m;
    if(m <0||(n-m<2&&m>0)){
        cout << -1 << endl;
        return 0;
    }
    printf("%d %d\n",1,8+4*m);
    for(int i=0;i<n-1;i++){
        printf("%d %d\n",5+i*4,7+i*4);
    }
    return 0;
}