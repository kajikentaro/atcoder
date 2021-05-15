#include<bits/stdc++.h>
#include<atcoder/all>
#define rep(x,y) for(int x=0;x<y;x++)
#define ll long long
using namespace std;
using namespace atcoder;   
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    double dp[101][101][101] = {};
    dp[a][b][c] = 1;
    double sum = 0;
    bool flag_i = true,flag_j = true,flag_k = true;
    for(int i=a;i<100;i++){
        for(int j=b;j<100;j++){
            for(int k=c;k<100;k++){
                int ii = i+1;
                int jj = j+1;
                int kk = k+1;
                int sosa = -a -b -c +i+j+k+1;
                dp[ii][j][k] += dp[i][j][k] * (double)i/(i+j+k);
                dp[i][jj][k] += dp[i][j][k] * (double)j/(i+j+k);
                dp[i][j][kk] += dp[i][j][k] * (double)k/(i+j+k);
                if(ii == 100 && flag_i){
                    sum += sosa * dp[ii][j][k];
                    //flag_i = false;
                }
                if(jj == 100 && flag_j){
                    sum += sosa *dp[i][jj][k];
                    //flag_j = false;
                }
                if(kk == 100 && flag_k){
                    sum += sosa *dp[i][j][kk];
                    //flag_k = false;
                }
            }
        }
    }
    printf("%.10lf",sum);
}
