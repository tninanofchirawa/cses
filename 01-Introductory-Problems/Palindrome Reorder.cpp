#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
string func(string a);
int main(){
    // Input
    string n;
    cin >> n;
    string y;
    y = func(n);
    cout << y<< endl;

    return 0;
}

string func(string a){

    // Calculate the frequency
    long lc;
    vector <long> freq(26);
    for(char c:a){
        lc = c - 'A';
        freq[lc]++;
    }

    // Loop the String
    string out;
    char k;
    char middle = '?'; // This is thanks to errichito algorithms
    bool is_mid = false;
    for(long j = 0; j < 26; j++){
            k = j + 'A';
            long p = freq[j]/2;
        if(freq[j]%2 == 1 && is_mid == false ){
            middle = k;
            is_mid = true;
            for (long i = 0; i < p; i++ ){
                out.push_back(k);
            }
        }
        else if(freq[j]%2 == 1 && is_mid == true ){
            return "NO SOLUTION";
        }
        else{
            for(long i = 0; i < p; i++ ){
                out.push_back(k);
            }
        }
    }
    string out2 = out;
    reverse(out2.begin(),out2.end());
    if(is_mid){
    return out +middle + out2;
    }

    else{
        return out+ out2;
    }
}
