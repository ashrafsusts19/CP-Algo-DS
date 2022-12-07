#include <bits/stdc++.h>
#include <limits>

using namespace std;
typedef long long int lli;
#define prnt(a) cout << a << "\n"
#define prnt2(a, b) cout << a << " " << b << "\n";
#define forp1(a) for (lli i = 0; i < a; i++)
#define forp2(a, b) for (lli i = a; i < b; i++)
#define forf(a, b, c) for (lli i = a; i < b; i += c)

void debug(vector<lli> &lst)
{
    cout << "Debug: ";
    for (lli i = 0; i < lst.size(); i++)
    {
        cout << lst[i] << " ";
    }
    cout << "\n";
}

lli MOD = 1000000007;


//memorization for factorial
vector<lli> fac(1005, 0);


lli power(lli num, lli pow)
{
    lli res = 1;
    num = num % MOD;
    while (pow > 0)
    {
        if (pow & 1)
            res = (res * num) % MOD;
        pow >>= 1;
        num = (num * num) % MOD;
    }
    return res;
}

lli modInverse(lli num)
{
    return power(num, MOD - 2);
}

lli getFac(lli n)
{
    if (fac[n] != 0)
        return fac[n];
    else
        return fac[n] = (n * getFac(n - 1)) % MOD;
}

lli ncr(lli n, lli r)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (getFac(n) * ((modInverse(getFac(r)) * modInverse(getFac(n - r))) % MOD)) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
}