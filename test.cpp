#include <bits/stdc++.h>
using namespace std;
int n,m,a[1001][1001];
void initwsolve(){
    cin>>m>>n;
    for(int i=0; i <m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j]
        }
        if(i==0||j==0){
            a[i][j]=1;
            else a[i][j] = a[i-1][j] + a[i][j+1];
        }

    }
    cout <<a[m-1][n-1]<<endl;
}
int main(){
    
    initwsolve();
    return 0;
}

