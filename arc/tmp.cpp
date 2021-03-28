#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 7;
    int k = 19;
    for(int i=0;i<k+2;i++){
        int n = pow(a,i);
        cout << n << " " << n % k << endl;
    }
    return 0;
}