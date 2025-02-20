#include <bits/stdc++.h>
using namespace std;
bool a[1000000];
void sangsont(int n) {
    for(int i = 0; i < n ; i++) {
        a[i] = true;
    }
    a[0] = a[1] = false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(a[i] == true) {
            for(int j = i * i; j <= n; j += i) {
                a[j] = false; 
            }
        }
    }
}
int main() {
    int n; cin >> n;
    sangsont(n);
    for(int i = 0; i < n; i++ ) {
        if(a[i] == true) {
            cout << i << " ";
        }
    }
}