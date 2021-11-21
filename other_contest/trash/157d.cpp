#include<bits/stdc++.h>
using namespace std;
#define rep(x,y) for(int x=0;x<y;x++)
struct dsu{
    vector<int> d;
    dsu(int n=0): d(n,-1){}
    int find(int a){
        if(d[a] < 0)return a;
        return d[a] = find(d[a]);
    }
    int size(int a){
        return -d[find(a)];
    }
    bool isSame(int a,int b){
        int root_a = find(a);
        int root_b = find(b);
        return (root_a == root_b);
    }
    int merge(int a,int b){
        int root_a = find(a);
        int root_b = find(b);
        if(root_a == root_b)return 0;
        if(size(root_a) > size(root_b))swap(root_a, root_b);//a is smaller
        d[root_b] += d[root_a];
        d[root_a] = root_b;
        return 1;
    }
};
int main(){
    int n,m,k;
    cin >> n >> m >> k;
    dsu dsu(n);
    vector<int> friends(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        friends[a]++;
        friends[b]++;
        dsu.merge(a,b);
    }
    vector<int> sizes(n);
    rep(i,n){
        sizes[i] = dsu.size(i);
    }
    rep(i,k){
        int a,b;
        cin >> a >> b;
        a--;b--;
        if(dsu.isSame(a,b)){
            sizes[a]--;
            sizes[b]--;
        }
    }
    rep(i,n){
        printf("%d ",sizes[i]-friends[i]-1);
    }
    puts("");
    return 0;


}