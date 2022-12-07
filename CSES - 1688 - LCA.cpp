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


lli n, q, lgn;
vector<vector<lli>> parents;
vector<vector<lli>> roads;
vector<lli> ldpt;


void dfs(lli ind){
    for (lli i = 1; i < lgn; i++){
        if (parents[ind][i - 1] != -1){
            parents[ind][i] = parents[parents[ind][i - 1]][i - 1];
        }
        
    }
    for (lli cind: roads[ind]){
        ldpt[cind] = ldpt[ind] + 1;
        dfs(cind);
    }
}

lli getLca(lli a, lli b){
    if (ldpt[a] < ldpt[b]){
        swap(a, b);
    }
    lli k = ldpt[a] - ldpt[b];
    for (lli i = 0; i < lgn; i++){
        if (k & (1ll << i)){
            a = parents[a][i];
        }
    }
    if (a == b) return a;
    //Note, it must begin from highest to lowest
    for (lli i = lgn - 1; i >= 0; i--){
        if (parents[a][i] != parents[b][i]){
            a = parents[a][i];
            b = parents[b][i];
        }
    }
    return parents[a][0];
}


int main()
{
    ios_base::sync_with_stdio(false);   
    cin.tie(0); 
    
    cin >> n >> q;
    lgn = log2(n) + 1;

    parents.resize(n, vector<lli> (lgn, -1));
    
    ldpt.resize(n);
    roads.resize(n);

    forp2(1, n){
        cin >> parents[i][0];
        parents[i][0]--;
        roads[parents[i][0]].push_back(i);
    }
    
    ldpt[0] = 0;
    
    dfs(0);
    
    while (q--){
        lli a, b;
        cin >> a >> b;
        a--, b--;
        prnt(getLca(a, b) + 1);
    }

}  