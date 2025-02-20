#include <bits/stdc++.h>
#include <stack>
using namespace std;
// last in first out 
/*
push : đẩy 1 ptu vào ngắn xếp
pop  : lấy 1 ptu ra khỏi ngăn xếp
top  : lấy 1 ptu đỉnh ngăn xếp
size : trả về sl ptu trong ngăn xếp
empty: check ngăn xếp có rỗng hay không
O(1)
*/
int main() {
    stack<int>  st;
    // chuyển 1 số thành số nhị phân biểu diễn nó 
     int n; cin >> n;
    while(n != 0) {
        int x = n % 2;
        st.push(x);
        n = n / 2;
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}