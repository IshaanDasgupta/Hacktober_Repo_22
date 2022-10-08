// CPP program for calculation huge powers in a optimised manner.

/*
Instead of the using the standard pow function in cpp which will give a complexity of O(power) here we use binary exponenetiation which gives use a complexity of O(log(power))

Example:

Input: 2 3
Output: 8

Input: 5 3
Output: 125

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// function to caculate the power
ll binaryExponentiation(ll base, ll power)
{
    // base case
    if (power == 0)
    {
        return 1;
    }

    // NOTE : Here power/2 == greater interger less than power/2 (as the float value of power/2 will be converted to long long)

    // if the power is odd then power/2 + power/2 + 1 == power so, we recursively call 2 power/2 and to ammount for that 1 we multiply an extra base
    if (power % 2)
    {
        return binaryExponentiation(base, power / 2) * binaryExponentiation(base, power / 2) * base;
    }

    // if the power is even then power/2 + power/2 == power so we just recursively call them
    return binaryExponentiation(base, power / 2) * binaryExponentiation(base, power / 2);
}

// Driver code
int main()
{
    ll base, power;
    cin >> base >> power;
    ll result = binaryExponentiation(base, power);
    cout << result << "\n";
    return 0;
}
