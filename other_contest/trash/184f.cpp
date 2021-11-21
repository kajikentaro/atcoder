#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(x,y) for(int x=0;x<y;x++)
struct UF{
    vector<int> d;
    UF(int n): d(n,-1){}
    int find(int k){
        if(d[k] < 0)return k;
        return d[k] = find(d[k]);
    }
    int size(int k){
        int parent_k = find(k);
        return -d[parent_k];
    }
    bool marge(int a,int b){
        int parent_a = find(a);
        int parent_b = find(b);
        if(parent_a == parent_b) return false;
        if(d[parent_a] > d[parent_b]) swap(a,b); //a is smaller
        d[parent_b] += d[parent_a];
        d[parent_a] = parent_b;
        return true;
    }
};
int main(){
    UF d(100);
    cout << d.size(0) << endl ;
    cout << d.marge(1,2) << endl ;
    cout << d.marge(0,2) << endl ;
    cout << d.size(0) << endl ;
    cout << d.size(1) << endl ;
    cout << d.size(2) << endl ;
    cout << d.size(4) << endl ;

}
