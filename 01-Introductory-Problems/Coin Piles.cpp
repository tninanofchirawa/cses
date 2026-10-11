#include <iostream>
#include <vector>
using namespace std;

string Check(long long c, long long r);

int main()
{
    // Input
    long n;
    cin >> n;

    // Basic Work Flow

    // Now some rules that we make
    // 1) We will find the Min and Max
    // 2) We will remove 1 from Min and 2 from Max
    // 2.5) If we sum the Values and it does not make the sum that is divisble by 3 then we say NO
    // 3) We will check if the subtractions each are divisble by 3 if not then we will stop and say NO (as long as it is greater than 3)
    // 3.5) If we sum the Values and it does not make the sum that is divisble by 3 then we say NO
    // 4) If both are saying YES then we will Say Yes and end the loop
    // 5) We will keep repeating the Process till we get Both Zeros --> Yes; else NO
    vector<string> answers;
    string j;
    long long first;
    long long second;
    for (long i = 0; i < n; i++)
    {
        cin >> first >> second;
        j = Check(first, second);
        answers.push_back(j);
    }

    for (string ans : answers)
    {
        cout << ans << endl;
    }
    return 0;
}

string Check(long long f, long long s)
{
    long long sm;
    // Giving both an Equal and a random value for sake of loop
    long long q = f;
    long long w = s;

    sm = q + w;
    // CHecking if the sm will be not clean -- not divisble
    if (sm%3 != 0){
        return "NO";
    }
    else{

    q = max(f,s);
    w = min(f,s);

    // Check if the subtraction will work
    if (q > 2*w){
        return "NO";
    }

    else if (w == 0 && q > 0){
        return "NO";
    }
    else if(q== 0 && w > 0){
        return "NO";
    }
    else if(sm%3 == 0){
        return "YES";
    }

    }
}
