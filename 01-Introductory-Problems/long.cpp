#include <iostream>

using namespace std;
int main()
{
    string n;
    cin >> n;

    // getting the length of the string
    long i = 0;
    while (n[i] != '\0')
    {
        i++;
    }

    // Now Checking the length of each largest digit
    long curr = 1;
    long mx = 1;
    for (long j = 0; j < i; j++)
    {
        if (n[j] == n[j + 1])
        {
            curr++;
            mx = max(mx, curr);
        }
        else
        {
            curr = 1;
        }
    }
    cout << mx;
    return 0;
}
