#include <iostream>
#include <vector>
using namespace std;
long long spiral(long long a, long long b);

int main()
{
    // Number of tests
    long nb;
    cin >> nb;

    // Taking in the Test
    long x;
    long y;
    for (long long i = 0; i < nb; i++)
    {
        cin >> x >> y;
        i = spiral(x, y);
        cout << i << endl;
    }

    return 0;
}

// Making the Spiral Function
long long spiral(long long a, long long b)
{
    // To which does the Number belong to ??
    long long l = max(a, b);

    // Where is the start value of the number ??
    long long q = min(a, b);
    long long start = q * q;

    // We are going to add the numbers from here
    long long cur = start + 1;

    // We are adding the values till it becomes the point where both X and Y are having the same values here there is a case that the
    for (long long i = 1; i <= l; i++)
    {
        curr = curr + 1;
    }

    // I think that we must make 1 for row side counting and 1 for column side counting
    // We must think that the value will increment every time (in this case i am taking that the row val will bemore) this will result in that the as long as the y value be more than what we need we keep increasing the X (till we reach the x = y ) point
    // I think that this will help me... make this similary

    // there are main 5 cases
    // 1) Row is more and col is less and we count from col
    // 2) Row is more and col is less and we count from row
    // 3) Col is more and row is less and we count from row
    // 4) Col is more and row is less and we count from col
    // 5) Row = Col

    // Make for all these 5 types and we will get the answer ;)

    return cur;
}
// 2 3

// 1  2  9  10
// 4  3  8  11
// 5  6  7  12
// 16 15 14 13

// nOW SO THAT I can enter a particular case
// 1) If it is in the larger number then it will start from the Samller number Area
// 2) If the Number we want to have will be depending on ODD and Even
// 3)
