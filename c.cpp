#include<atcoder/all>
#include<bits/stdc++.h>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define ll long long
int main(void){
    ll n,k;
    cin >> n >> k;
    int m[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> m[i][j];
        }
    }
    dsu row(n),col(n);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int row_flag = 1,col_flag=1;
            for(int p=0;p<n;p++){
                if(m[i][p] + m[j][p] > k){
                    row_flag = 0;
                }
                if(m[p][i] + m[p][j] > k){
                    col_flag = 0;
                }
            }
            if(row_flag){
                row.merge(i,j);
            }
            if(col_flag){
                col.merge(i,j);
            }
        }
    }
    vector<vector<int>> row_result = row.groups();
    vector<vector<int>> col_result = col.groups();
    mint row_sum(1),col_sum(1);
    for(int i=0;i<row_result.size();i++){
        for(int j=row_result[i].size();j>1;j--){
            row_sum *= j;
        }
    }
    for(int i=0;i<col_result.size();i++){
        for(int j=col_result[i].size();j>1;j--){
            col_sum *= j;
        }
    }
    row_sum *= col_sum;
    cout << row_sum.val() << endl;
    return 0;
}