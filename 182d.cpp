#include<bits/stdc++.h>
#include<atcoder/all>
using namespace std;
int main(){
    long long N;
    cin >> N;
    vector<long long> a(N);
    vector<long long> b(N);
    cin >> a[0];
    b[0] = a[0];
    for(int i=1;i<N;i++){
        cin >> a[i];
        b[i] = b[i-1] + a[i];
    }
    long long max = 0;
    long long now = 0;
    long long tmp = 0;
    for(int i=0;i<N;i++){
        now += b[i];
        if(now > max){
            max = now;
            tmp = b[i];
       }
    }
    cout << max + tmp;
    return 0;
}