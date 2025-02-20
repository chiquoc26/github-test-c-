#include<bits/stdc++.h>
using namespace std;
int D[8] = {-1,-1,-1,0,0,1,1,1};
int C[8] = {-1,0,1,-1,1,-1,0,1};
int a[100][100];
void danhdau(int i,int j,int a[][100],int n) {
    a[i][j] = 0;                                              
    for(int t = 0; t < 8; t++) {
        int imoi = i + D[t];
        int jmoi = j + C[t];
        if(a[imoi][jmoi] == 1 && imoi >= 0 && imoi < n && jmoi >= 0 && jmoi < n) danhdau(imoi,jmoi,a,n);
    }
}
int main() {
    int n; cin >> n;
    for(int i = 0;  i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int dem = 0;                                           
    for(int i = 0;  i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(a[i][j] == 1) {
                danhdau(i,j,a,n);
                dem++;
            }
        }
    }
    cout << dem;
    return 0;
}


