#include <iostream>
#include <vector>
#include <unordered_set>
#include <bits/stdc++.h>
using namespace std;
long long func(long a);
int main(){

     // Input the number of letters
    long n;
    cin >> n;

    // WE know if it is odd the we are assured an odd one out :)
    long t;
    vector <long> it;
    for(long u = 0; u < n; u++){
        cin >> t;
        it.push_back(t);
    }

    set<long> num(it.begin(), it.end());
    cout << num.size();
    return 0;
}
