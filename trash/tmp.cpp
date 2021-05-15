#include<bits/stdc++.h>
using namespace std;
tuple<int,int,int> extgcd(int a, int b){
    int re_x, re_y, re_r;
    int x,y,r;
    if(b == 0){
        re_x = 1;re_y = 0, re_r = a;
    }else{
        tie(x,y,r) = extgcd(b, a % b);
        {re_x = y; re_y =  x + y * (-a / b); re_r = r;}
    }
    cout << a << " * " << re_x << " + " << b << " * " << re_y << " = " << re_r << endl;
    return {re_x, re_y, re_r};
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
