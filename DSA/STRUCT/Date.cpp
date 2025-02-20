#include <bits/stdc++.h>
using namespace std;

struct tg{
    string ngay;
    int day,month,year;
};
bool namnhuan(tg a) {
    if((a.year % 400 == 0) || (a.year % 4 == 0 && a.year % 100 != 0)) return true;
    return false;
}
void doiso(tg &a) {
    int dem = 0;
    string so = "0";
    for(int i = 0; i < a.ngay.size(); i++) {
        if(a.ngay[i] != '/') so += a.ngay[i];
        else if(dem == 0) {
            dem++;
            a.day = stoi(so);
            so = "0";
        }else if(dem == 1) {
            dem++;
            a.month = stoi(so);
            so = "0";
        }
        if(i == a.ngay.size() - 1) a.year = stoi(so);
    }
}

bool check(tg a) {
    set<int> th30 = {4,6,9,11};
    if(a.year < 1) return false;
    if(a.month > 12 || a.month < 1) return false;
    if(a.day > 31 || a.day < 1) return false;
    if(th30.count(a.month) == 1 && a.day == 31 ) return false;
    if(a.month == 2) {
        if(namnhuan(a) && a.day > 29) return false;
        if(!namnhuan(a) && a.day > 28) return false;
    }
    
    return true;
}

long long sangso(tg a) {
    long long dem = 0;
    dem = (a.year - 1) * 365 + (a.year - 1) / 4 - (a.year - 1) / 100 + (a.year - 1) / 400;
    set<int> th30 = {4,6,9,11};
    set<int> th31 = {1,3,5,7,8,10,12};
    for(int i = 1; i < a.month; i++) {
        if(th30.count(i) == 1) dem += 30;
        else if(th31.count(i) == 1) dem += 31;
        else if(i == 2 && namnhuan(a)) dem += 29;
        else dem += 28;
    }
    dem += a.day;
    return dem;
}


int main() {
    tg a,b; cin >> a.ngay >> b.ngay;
    doiso(a);
    doiso(b);
    if(!check(a) || !check(b)) cout << "-1";
    else {
        cout << abs(sangso(a) - sangso(b)); 
       
    } 
    return 0;
}
