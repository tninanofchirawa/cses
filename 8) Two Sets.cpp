#include <iostream>
#include <vector>
using namespace std;
int main(){
    long nb;
    cin >> nb;

    //Checking if this will get the sum
    long s = ((nb)*(nb+1)/2);
    if (s%2 != 0)
    {
        cout << "NO";
    }
    else{
        cout << "YES"<< endl;
        long hlf = s/2;
        long b = hlf;
        // Making the First vector
        vector<long> a1;
        vector<long> a2;
        for(long i = nb; i > 0; i -- ){
            if(i <= b){
                a1.push_back(i);
                b = b - i;
            }
            else{
                a2.push_back(i);
            }
        }
        cout << a1.size()<< endl;
        for(long a : a1){
            cout << a << " ";
        }
        cout <<endl;
        cout << a2.size()<< endl;
        for(long a : a2){
            cout << a << " ";
        }
        }

    return 0;
}
