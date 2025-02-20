#include <bits/stdc++.h>
using namespace std;
#define MAXDIGITS 10000
#define PLUS 1
#define MINUS -1
struct bignum {
    char digits[MAXDIGITS];
    int signbit; // dấu
    int lastdigit; // số cuối
};
bool ktr(string temp) { //hàm check số có hợp lệ hay không
    if(temp[0] != '-' && !isdigit(temp[0])) return false;
    int length = temp.size();
    for(int i = 1; i < length; i++) {
        if(!isdigit(temp[i])) return false;
    }
    return true;
}
void scan(bignum &n) {
    string temp;
    getline(cin, temp);
    if(!ktr(temp)) { // nếu là số không hợp lệ
        n.signbit = PLUS;
        n.lastdigit = 0;
        n.digits[0] = 0;
    }
    else {
        if(temp[0] != '-') { // so duong
            n.signbit = PLUS;
            n.lastdigit = temp.size() - 1; // lấy chỉ số để lưu vào mảng
            for(int i = 0; i <= n.lastdigit; i++) {
                n.digits[i] = temp[n.lastdigit - i] - '0'; // lưu ngược lại từ phải sang trái
            }
        }
        else {
            n.signbit = MINUS;
            n.lastdigit = temp.size() - 2;
            for(int i = 0; i <= n.lastdigit; i++) {
                n.digits[i] = temp[n.lastdigit + 1 - i] - '0'; // lưu lại và bỏ dấu trừ
            }
        }
    }
}


void print(bignum n) {
    if(n.signbit == MINUS) cout << "-";
    for(int i = n.lastdigit; i >= 0; i--) { // in từ phải sang trái(từ cuối mảng đến đầu mảng để thành số đúng)
        cout << int(n.digits[i]);
    }
    cout << endl;
}



void cong(bignum a,bignum b){
    
}






int main() {
    bignum a,b;
    cout << "Nhap a va b cho bo : ";
    scan(a);

    cout << "In cc nay ra : ";
    print(a);
    

}