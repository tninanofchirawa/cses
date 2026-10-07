#include <iostream>

using namespace std;
int main(){
    long nb;
    cin >> nb;
    // Collecting the Numbers
    long n;
    long t = 0;
    cin >> n;
    long high = n;
    for(long i = 1; i < nb; i++)
    {
        cin >> n;

        if(n < high){
            t = t + (high - n);
             }
        else {
            high = n;
             }
    }
    cout << t;
    return 0;
}



// 3 2 5 1 7
//   ^   ^

// The Thought Process --  I want to get the Maximum Drop between any two and say that I will add the Drop to the Second Number and add the following
// 3 3 5 1 7
// 3 3 5 2 7
// 3 3 5 3 7
// 3 3 5 4 7
// 3 3 5 5 7


// Well another waY could and saw that, we can read the Line like --> It will accept the First letter and from there every lettere will be accepted and crossed

// 2 -> 3 -> 4 -> 3 +1 -> 2 + 2 .... likle this

