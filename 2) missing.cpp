#include <iostream>

using namespace std;
int main()
{
    long n;
    cin >> n;
    long long d = 0;
    long long t = (n)*(n+1)/2;
    for (long i = 0; i < n - 1; i++) {
        long x;
        cin >> x;
        d = d + x;
    }

    cout << t - d;

    return 0;
}
