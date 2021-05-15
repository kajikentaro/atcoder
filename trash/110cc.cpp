#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
#define getp(x) x-1
#define revp(x) x+1
vector<int> opelog;
int func(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n)cin >> p[i];
    vector<int> a(n);
    rep(i,n)a[i] = i+1;
    for(int i=0;i<n;){
        if(p[i] == a[i]){
            i++;
            continue;
        }
        int c = getp(p[i]);
        if(c <= i)return 0;
        while(c!=i){
            swap(a[c],a[c-1]);
            opelog.push_back(c);
            c--;
        }
        i = getp(p[i]);
    }
    rep(i,n){
        if(a[i] != p[i])return 0;
    }
    return 1;
}
int main(){
    if(func()){
        rep(i,opelog.size()){
            cout << opelog[opelog.size() - i - 1] << endl;
        }
    }else{
        cout << -1 << endl;
    }

}