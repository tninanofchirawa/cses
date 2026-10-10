#include <iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;

    long k = 0;
    long t = 5;
    while (true)
    {
        if (t > n)
        {
            break;
        }
        else
        {
            k = k + n / t;
            t = t * 5; // It is really interesting find out why there was an edit here
        }
    }
    cout << k;

    return 0;
}
