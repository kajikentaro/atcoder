#include<bits/stdc++.h>
using namespace std;
void func(int &n){
    n++;
}
int main(){
    int n = 0;
    n = 1;
    func(n);
    cout << n << endl;
}