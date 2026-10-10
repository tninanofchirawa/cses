// # Dont use this code... try to see the pattern if you can find here -- this is too bad code.
#include <iostream>
#include <vector>
using namespace std;
long long spiral(long long y, long long x);

int main()
{
    // Number of tests
    long long nb;
    cin >> nb;

    // Taking in the Test
    long long x;
    long long y;
    long long k;
    vector<long long> answers;
    for (long long i = 0; i < nb; i++)
    {
        cin >> y >> x;
        k = spiral(x, y);
        answers.push_back(k);
    }
    for (long long ans : answers)
    {
        cout << ans << endl;
    }
    return 0;
}

// Making the Spiral Function
long long spiral(long long col, long long row)
{
    // To which does the Number belong to ??
    long long big = max(row, col);

    // Where is the start value of the number ??
    long long small = min(row, col);
    long long right = big - 1;
    long long curr = right * right;

    // Values of Temporary Columns and Rows
    long long temp_row = 1;
    long long temp_col = 1;
    // We are adding the values till it becomes the point where both Y and X are having the same values here there is a case that the

    if (small == big)
    {
        curr = big * big - big + 1;
        return curr;
    }
    // We got to maintain a tab on the "Y" and "X" and then the End Goal 'y' and 'x'
    // There are 4 Possibilities -
    // 1) We have a smaller odd number (thus we start the counting from the row)
    else
    {
        if (big % 2 != 0)
        {
            //          - If the Column is smaller number we have to only change the column value (from 1 to the current value)
            //            here y is row and x is column
            if (col == small)
            {
                curr = curr + (col);
            }

            //          - If the Row is the smaller number then we have to a) Change the column value till we reach the point that the column value is equal to the end goal column value
            //                                                             b) Now we will reduce the row values till we reach the actual row value
            else if (row == small)
            {
                curr = curr + 2 * col - row;
            }
        }
        //
        // 2) We have a smaller even number (thus we start the counting from the column)
        //

        else if (big % 2 == 0)
        {
            //           - If the row is smaller number we have to only change the row value
            //            here y is row and x is column
            if (col == small)
            {
                curr = curr + 2 * row - col;
            }

            //          - If the Column is the smaller number then we have to a) Change the row value till we reach the point that the row value is equal to the end goal row value
            //                                                             b) Now we will reduce the column values till we reach the actual column value
            else if (row == small)
            {
                curr = curr + row;
            }
        }

        //          3) If we have a point which is on the diagonal then we can just actually put it in either of the formulas and run it... it will be working.
        //          The Entire time we move left or right / top or bottom we will keep updating that one 'curr' value increaing it till we reach the End -- Thank You Jesus
        return curr;
    }
}
