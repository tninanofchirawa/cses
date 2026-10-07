#include <iostream>

using namespace std;
int main()
{
    long nb;
    cin >> nb;

    if (nb == 3 || nb == 2)
    {
        cout << "NO SOLUTION";
    }
    else
    {
        // Writing the Odd Numbers
        for (long i = nb - 1; i > 0; i = i - 2)
        {
            cout << i << " ";
        }
        cout << nb << " ";
        for (long i = nb - 2; i > 0; i = i - 2)
        {
            cout << i << " ";
        }
    }
    return 0;
}
