#include<bits/stdc++.h>
using namespace std;
int a[1000];
int main() {
    stack<int> hop;
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int Smax = 0;
    int t = 0;
    while(t < n) {
        if(hop.empty() || a[t] >= a[hop.top()]) hop.push(t); // check trong stack còn không hoặc nó lớn hơn đầu stack
        else {
            while( a[t] < a[hop.top()] ) {
                int right  = t;
                int high = a[hop.top()];
                hop.pop();
                if(hop.empty()) { // tính S nếu nó nhỏ hơn và ko có cận trái (không có ptu nào trước nó nhỏ hơn nó)
                    int S = high*right;
                    Smax = max(Smax,S);
                }else { // tính S nếu có cận trái
                    int left = hop.top();
                    int S = high * (right - left -  1);
                    Smax = max(Smax,S);
                }    
                if(hop.empty()) break;    
            } 
            hop.push(t);
        }
        t++;
    }
    while(!hop.empty()) { // tính S cho các ptu còn lại trong stack
        int high = a[hop.top()];
        hop.pop();
        if(!hop.empty()) {
            int left =  hop.top();
            int S = high*(t - left - 1);
            Smax = max(S,Smax);
        } else Smax = max(Smax,t*high);
    }
    cout << Smax;
    return 0;
}