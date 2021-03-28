#include<bits/stdc++.h>
using namespace std;
#define inf 100000000
int func(){
    int a,b,x,y;
    cin >> a >> b >> x >> y;
    vector<int> costa(101,inf);
    vector<int> costb(101,inf);
    costa[a] = 0;
    costb[a] = x;
    if(a == b)return x;
    if(a < b){
        int c = a + 1;
        do{
            costa[c] = min(costa[c-1] + y, costb[c-1] + x);
            costb[c] = min(costa[c] + x, costb[c] + y);
            c++;
        }while(c != b+1);
        return costb[b];
    }else{
        int c = a - 1;
        do{
            costb[c] = min(costa[c+1] + x,costb[c+1] + y);
            costa[c] = min(costa[c+1] + y,costb[c] + x);
            c--;
        }while(c != b-1);
        return costb[b];
    }
}
int main(){
    cout << func() << endl;
    return 0;
}