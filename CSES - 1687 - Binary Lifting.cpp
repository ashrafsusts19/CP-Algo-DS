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


lli n, lgn;
vector<vector<lli>> parents;


int main()
{
    ios_base::sync_with_stdio(false);   
    cin.tie(0);
    lli q;
    cin >> n >> q;
    lgn = 1;
    lli tmp = n;
    while (tmp > 0){
        lgn++;
        tmp >>= 1;
    }

    parents.resize(n, vector<lli> (lgn, -1));
    
    
    forp2(1, n){
        cin >> parents[i][0];
        parents[i][0]--;
    }
    forp2(1, lgn){
        for (lli j = 0; j < n; j++){
            if (parents[j][i - 1] != -1){
                parents[j][i] = parents[ parents[j][i - 1] ][i - 1];
            }
        }
    }
    while (q--){
        lli a, k;
        cin >> a >> k;  
        a--;
        for (lli i = 0; (1ll << i) <= k; i++){
            if (k & (1ll << i)){
                a = parents[a][i];
                if (a == -1) {
                    a -= 1;
                    break;
                }
            }
        }
        prnt(a + 1);
    }
    
}  