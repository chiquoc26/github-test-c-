#include <bits/stdc++.h>
using namespace std;
int main() {
    queue<string> number;
    int n; cin >> n;
    vector<string> print;
    int cnt = 1;
    print.push_back("1");
    number.push("1");
    while(print.size() < 10000) {
        string top = number.front();
        print.push_back(top + "0");
        print.push_back(top + "1");
        number.pop();
        number.push(top + "0");
        number.push(top + "1");

        
    }
    for(int i = 0; i < n; i++) cout << print[i] << " ";
    return 0;
}