#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
struct dsu{
    vector<int> d;
    vector<map<int,int>> c;
    dsu(int n): d(n,-1),c(n){};
    int find(int a){
        if(d[a] < 0)return a;
        return d[a] = find(d[a]);
    }
    bool isSame(int a,int b){
        return (find(a) == find(b));
    }
    int size(int a){
        return -d[find(a)];
    }
    int merge(int a,int b){
        int root_a = find(a);
        int root_b = find(b);
        if(root_a == root_b)return 0;
        if(size(root_a) > size(root_b))swap(root_a,root_b);//a is smaller, new-root is b
        for(auto i:c[root_a]){
            c[root_b][i.first] += i.second;
        }
        d[root_b] += d[root_a];
        d[root_a] = root_b;
        return 1;
    }
};
int main(){
    int n,q;
    cin >> n >> q;
    dsu dsu(n);
    rep(i,n){
        int c;
        cin >> c;
        c--;
        dsu.c[i][c]++;
    }
    rep(i,q){
        int f,a,b;
        cin >> f >> a >> b;
        a--;b--;
        if(f==1){
            dsu.merge(a,b);
        }else{
            cout << dsu.c[dsu.find(a)][b] << endl;
        }
    }
    return 0;
}