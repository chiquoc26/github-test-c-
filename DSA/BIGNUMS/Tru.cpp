#include <bits/stdc++.h>
using namespace std;

typedef string bigint;

bigint tru(bigint a,bigint b) {
    if(a.length() < b.length()) swap(a,b);
    else if(a.length() == b.length()) {
        for(int i = 0; i < a.size(); i++) {
            if(a[i] < b[i]) {
                swap(a,b);
                break;
            }
            if(a[i] > b[i]) break;
        }
    }
    bigint kq = "";
    int du = 0;
    int chenh = a.size() - b.size();
    for(int i = b.size() - 1; i >= 0; i--) {
        int so;
        if((a[i + chenh] - '0') < ((b[i] - '0') + du)) {
            so = (a[i + chenh] - '0') + 10 - (b[i] - '0') - du;
            if(du == 0) du++;
        }
        else {
            so = abs(a[i + chenh] - '0') - (b[i] - '0') - du;
            if(du > 0) du--;
        }
        kq += so + '0';
    }

    for(int i = chenh - 1; i >= 0; i--){
        int so;
        if((a[i] - '0') < du) {
            so = (a[i] - '0') + 10 - du;
        }else {
            so = (a[i] - '0') - du;
            if(du > 0) du--;
        }
        kq += (so % 10) + '0';
    }
    while(kq.size() > 1 && kq.back() == '0') kq.pop_back();
    reverse(kq.begin(),kq.end());
    return kq;
}




int main() {
    bigint a,b; cin >> a >> b;
    cout << tru(a,b);
}