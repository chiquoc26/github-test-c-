#include <bits/stdc++.h>
using namespace std;
// sinh hoán vị
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

int n,a[100],ok;
void ktao(){
    for(int i = 1; i <= n; i++) {
        a[i] = i;
    }
}

void sinh() {
    int i = n - 1;
    while(i >= 1 && a[i] > a[i + 1]) {
        i--;
    }
    if(i == 0) ok = 0;
    else {
        // đi tìm thằng nhỏ nhất > a[i]
        int j = n;
        while(a[i] > a[j]) j--;
        swap(a[i],a[j]);
        int l = i + 1,r = n;
        while(l < r) {
            swap(a[l],a[r]);
            l++; r--;
        }
    }

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