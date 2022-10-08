#include <iostream>
#include <math.h>
using namespace std;

bool isprime(int num)
{

    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int a, b, x = 0;
    cout << "ENter two Number:" << endl;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        if (isprime(i))
        {
            x++;
            cout << i << endl;
        }

    cout << "NO of prime number between 2 given integer is : " << x;
    return 0;
}
