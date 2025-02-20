#include <bits/stdc++.h>
using namespace std;
// sinh tổ hợp chập K của N
/*
-cấu hình đầu tiên
-cấu hình cuối cùng
-phương pháp sinh

<Khởi tạo cấu hình đầu tiên>
while(Khi chưa phải cấu hình cuối cùng) {
     <in ra cấu hình hiện tại>
     <sinh ra cấu hình tiếp theo>
}
*/

int n,k,a[100],ok;
void ktao(){
    for(int i = 1; i <= k; i++) {
        a[i] = i;
    }
}

void sinh() {
    //bắt đầu bit cuối cùng, và di chuyển di tìm bit 0 đầu tiên
    int i = k;
    while(i >= 1 && a[i] == n - k + i) {
        i--;
    }
    if(i == 0) ok = 0;
    else {
        a[i]++;
        for(int j = i + 1; j <= k; j++) {
            a[j] = a[j - 1] + 1;
        }
    }

}
int main() {
    cin >> n >> k;
    ok = 1;
    ktao();
    while(ok) {
        for(int i = 1; i <= k; i++) {
            cout << a[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}