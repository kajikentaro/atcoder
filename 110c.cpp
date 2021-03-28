#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,n)cin >> p[i];
    vector<int> a(n);
    rep(i,n){
        a[i] = i+1;
    }
    int c = 0;
    queue<int> que;
    queue<int> que2;
    vector<int> did;
    while(1){
        if(que.size()){
            int k = que.front();
            int kk = que2.front();
            if(p[k] == a[k+1]){
                swap(a[k+1],a[k]);
                did.push_back(k);
                que.pop();
                que2.pop();
                continue;
            }
            if(kk == a[c+1]){
                swap(a[c+1],a[c]);
                did.push_back(c);
                c++;
                continue;
            }
        }
        if(p[c] == a[c+1]){
            swap(a[c+1],a[c]);
            did.push_back(c);
            c++;
        }else{
            que.push(c);
            que2.push(p[c]);
            c++;
        }
        if(que.size() == 0 && c==n-1)break;
        if(que.size() != 0 && c==n){
            cout << -1 << endl;
            return 0;
        }
    }
    int z = did.size();
    rep(i,z){
        cout << did[z-i-1] + 1 << endl;
    }
}
