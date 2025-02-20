#include <bits/stdc++.h>
using namespace std;
// sinh nhị phân
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

int n,a[100], ok;
void ktao(){
    for(int i = 0; i <= n; i++) {
        a[i] = 0;
    }
}

void sinh() {
    //bắt đầu bit cuối cùng, và di chuyển di tìm bit 0 đầu tiên
    int i = n;
    while(i >= 1 && a[i] == 1) {
        a[i] = 0;
        i--;
    }
    if(i == 0) ok = 0;
    else a[i] = 1;
    
}
int main() {
    cin >> n;
    ok = 1;
    ktao();
    while(ok) {
        for(int i = 1; i <= n; i++) {
            cout << a[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}