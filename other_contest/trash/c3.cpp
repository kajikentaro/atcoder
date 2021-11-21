#include<atcoder/all>
#include<bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define ll long long 
int main(){
    int N;
    cin >> N;
    int x[N],y[N];
    for(int i=0;i<N;i++){
        cin >> x[i] >> y[i];
    }
    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            for(int k=j+1;k<N;k++){
                int px = x[j] - x[i];
                int py = y[j] - y[i];
                int qx = x[k] - x[i];
                int qy = y[k] - y[i];
                if(qx*py==px*qy){
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}