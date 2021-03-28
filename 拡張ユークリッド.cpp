#include<bits/stdc++.h>
using namespace std;
tuple<int,int,int> extgcd(int a, int b){
    int x,y,r;
    if(b == 0) return {1, 0, a};
    tie(x,y,r) = extgcd(b, a % b);
    return {y, x + y * (-a / b), r};
}
int main(){
    while(1){
        int a,b;
        cin >> a >> b;
        int x,y,g;
        tie(x,y,g) = extgcd(a,b);
        cout << a << " * " << x << " + " << b << " * " << y << " = " << g << endl;
    }
}
