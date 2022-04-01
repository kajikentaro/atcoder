#include<bits/stdc++.h>
#define rep(x,y) for(int x=0;x<y;x++)
using namespace std;
struct UF{
    vector<int> uf;
    UF(int n):uf(n, -1){}
    int find(int a){
        if(uf[a] < 0)return a;
        return uf[a] = find(uf[a]);
    }
    int size(int a){
        return -uf[find(a)];
    }
    int merge(int a,int b){
        int ra = find(a);
        int rb = find(b);
        if(ra == rb)return 0;
        if(size(ra) < size(rb))swap(ra,rb);//sb is smaller
        uf[ra] += uf[rb];
        uf[rb] = ra;
        return 1;
    }
    int same(int a,int b){
        if(find(a) == find(b))return 1;
        return 0;
    }
};
int main(){
    int n;
    UF uf(10);
    cout << uf.size(0) << endl;
    cout << uf.size(1) << endl;
    cout << uf.merge(0,1) << endl;
    cout << uf.size(0) << endl;
    cout << uf.size(1) << endl;
    cout << uf.merge(0,3) << endl;
    cout << uf.size(0) << endl;
    return 0;
}