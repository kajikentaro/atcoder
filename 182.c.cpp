#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
int main(){
    int N,max[1001]={},a[1001];
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    for(int i=2;i<1001;i++){
        int tmp = 0;
        for(int j=0;j<N;j++){
            if(a[j] % i  == 0){
                tmp ++;
            }
        }
        max[i] = tmp;
    }
    int maxx = 0;
    int maxp = 0;
    for(int i=2;i<1001;i++){
        if(maxx <= max[i]){
            maxx = max[i];
            maxp = i;
        }
    }
    cout << maxp << endl;
}