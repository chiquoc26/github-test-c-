#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m; cin >> n >> m;
    int a[n+1][m+1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m;j ++) cin >> a[i][j];
    }
    /*
     Hình dung mỗi phần tử trong mảng này sẽ là diện tích của hình chữ nhật 
     tính theo từ a[1][1] đến a[i][j] sẽ được lưu vào pre[i][j] 
    */
    int pre[n + 1][m + 1] = {0};
    for(int i = 1;i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    int q; cin >> q;
    while(q--) {
        int h1,h2,c1,c2; cin >> h1 >> h2 >> c1 >> c2;
        // S ta cần tính bằng S tổng trừ đi diện tích của HCN ngang trên và HCN bên trái sau đó cộng lại 1 HCN đã bị trùng của 2 HCN trên
        cout << (pre[h2][c2] - pre[h1 - 1][c2] - pre[h2][c1 - 1] + pre[h1 - 1][c1 - 1]) << endl;
    }
    return 0;
}