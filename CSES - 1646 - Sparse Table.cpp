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





int main()
{
    ios_base::sync_with_stdio(false);  
    cin.tie(0);
    
    lli n, q;
    cin >> n >> q;
    lli lgn = 1, tmp = n;
    while (tmp > 0){
        tmp >>= 1;
        lgn++;
    }
    
    vector<vector<lli>> lst(lgn, vector<lli> (n, 0));
    forp1(n){
        cin >> lst[0][i];
    }
    for (lli i = 1; i < lgn; i++){
        for (lli j = 0; j + (1ll << i) - 1 < n; j++){
            lst[i][j] = min(lst[i - 1][j], lst[i - 1][j + (1ll << (i - 1))]);
        }
    }
    while (q--){
        lli l, r;
        cin >> l >> r;
        lli rng = r - l + 1;
        lli j = log2(rng);
        prnt(min(lst[j][l - 1], lst[j][r - (1ll << j)]));
    }

}