/*
// THis is Based on this - https://www.geeksforgeeks.org/dsa/writing-power-function-for-large-numbers/

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;
void powr(long k);
vector<int> multi(vector<int>&j);


int main(){
    // Input
    long k;
    cin >> k;

    powr(k);
    return 0;
}


void powr(long k){
    vector <int> j = {1};

    long i = 1;
    while(i <= k){
        j = multi(j);
        i++;
    }

    long h = j.size();
    for (long i = h - 1; i >= 0; i--) {
        cout << j[i];
    }
    cout<< endl;
}

vector<int> multi(vector<int>&j){
    long n;
    n = j.size();

    // Multiplying
    int d;
    int carry = 0;
    for(long i = 0; i < n;i++){
                d = 2 * j[i] + carry;
                carry = d/10;
        j[i] = d%10;
    }
    if (carry != 0){
        j.push_back(carry);
    }

    // Return the vector
    return j;
}

*/

#include <iostream>
using namespace std;
long MOD = 1e9 + 7;

int main(){
    // Input
    long k;
    cin >> k;

    long h = 1;
    for (long i = 0; i < k; i++)
    {
        h =  h * 2;
        h = h % MOD;
    }

    cout << h;
    return 0;
}
