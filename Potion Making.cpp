#include <iostream>
#include <math.h>

using namespace std;

int num, den;
bool is_prime(int number)
{
    for(int i = 2; i*i <= number; i++)
    {
        if(number % i == 0)
        {
            return false;
        }
    }
    return true;
}

void reduce(int numerator, int denominator)
{
    num = numerator;
    den = denominator;
    //cout << "Numerator: " << num << " " << "Denominator: " << den << endl;
    if(den % num == 0)
    {
        den = den/num;
        num = 1;
        return;
    }
    for(int i = 1; i <= den; i++)
    {
        if(is_prime(den))
        {
            return;
        }
        if(num%i == 0 && den%i == 0)
        {
            num = num/i;
            den = den/i;
        }
    }
    for(int i = 1; i <= den; i++)
    {
        if(is_prime(den))
        {
            return;
        }
        if(num%i == 0 && den%i == 0)
        {
            num = num/i;
            den = den/i;
        }
    }
    return;
}

int main()

{
    int tests;
    cin >> tests;
    for(int t = 0; t < tests; t++)
    {
        int n;
        cin >> n;
        reduce(n, 100);
        //cout << "num: " << n << " den: " << 100 << endl;
        cout << den << endl;
    }
}
