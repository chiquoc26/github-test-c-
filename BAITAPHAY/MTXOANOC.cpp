#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[100][100]; // Ma trận với kích thước tối đa 100 x 100
    int value = 1;   // Giá trị bắt đầu điền vào ma trận

    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // Đi từ trái sang phải trên hàng 'top'
        for (int i = left; i <= right; i++) {
            a[top][i] = value++;
        }
        top++;

        // Đi từ trên xuống dưới trên cột 'right'
        for (int i = top; i <= bottom; i++) {
            a[i][right] = value++;
        }
        right--;

        // Đi từ phải sang trái trên hàng 'bottom' (nếu còn hàng)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                a[bottom][i] = value++;
            }
            bottom--;
        }

        // Đi từ dưới lên trên trên cột 'left' (nếu còn cột)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                a[i][left] = value++;
            }
            left++;
        }
    }

    // In ra ma trận xoắn ốc
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}