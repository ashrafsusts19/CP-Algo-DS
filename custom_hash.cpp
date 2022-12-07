//ashrafsusts19

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


struct custom_hash {
    static uint64_t splitmix64(pair<lli, lli> x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x.first += 0x9e3779b97f4a7c15;
        x.first = (x.first ^ (x.first >> 30)) * 0xbf58476d1ce4e5b9;
        x.first = (x.first ^ (x.first >> 27)) * 0x94d049bb133111eb;
        x.second += 0x9e3779b97f4a7c15;
        x.second = (x.second ^ (x.second >> 30)) * 0xbf58476d1ce4e5b9;
        x.second = (x.second ^ (x.second >> 27)) * 0x94d049bb133111eb;
        lli k1 = x.first ^ (x.first >> 31);
        lli k2 = x.second ^ (x.second >> 31);
        return k1 ^ k2;
    }

    size_t operator()(pair<lli, lli> p) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64({p.first + FIXED_RANDOM, p.second + FIXED_RANDOM});
    }
};



int main()
{
    ios_base::sync_with_stdio(false);  
    cin.tie(0);
    
    

}