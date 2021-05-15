#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
int main(){
    long long N;
    cin >> N;
    int a[10] ={};
    int max = 0;
    int keta = 0;
    while(N > 0){
        keta ++;
        a[N % 10] ++;
        max += N%10;
        N/=10;
    }
    if(max %3 ==0){
        cout << 0 << endl;
        return 0;
    }
    int x  = a[1] + a[4] + a[7];//1
    int y = a[2] + a[5] + a[8];//2
    int z = a[3] + a[6] + a[9];//2
    if(max % 3 ==1 && x >0){
        if(x + y + z-1  >=1){
        cout <<1 << endl;
        return 0;
        }
    }
    if(max % 3 ==2 && y >0){
        if(x + y + z-1 >=1){
        cout <<1 << endl;
        return 0;
        }
    }
    if(max % 3 ==2 && x >1){
        if(x + y + z-2 >=1){
        cout <<2 << endl;
        return 0;
        }
    }
    if(max % 3 ==1 && y >1){
        if(x + y + z -2>=1){
        cout <<2 << endl;
        return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}