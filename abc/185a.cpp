#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int main(){
    vector<int> a(4);
    rep(i,4){
        cin >> a[i];
    }
    int min = *min_element(a.begin(),a.end());
    cout << min << endl;

}
