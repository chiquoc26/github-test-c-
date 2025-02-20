#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[100];
    int n,target;
    cin >> n >> target;
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> kq;
    unordered_map<int,int> check;
    for(int i = 0; i < n; i++){
        check.insert({a[i],i});
    }
    for(auto x : check) {
        int tim = target - x.first;
        if(check.count(tim) == 1 && check[tim] != x.second){
            kq.push_back(min(x.second,check[tim]));
            kq.push_back(max(check[tim],x.second));
            break;
        }
    }
    for(int i = 0; i < kq.size(); i++){
        cout << kq[i] << ',';
    }

    
}
