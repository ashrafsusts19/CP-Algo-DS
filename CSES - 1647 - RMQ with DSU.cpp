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
 
 
struct Query {
    lli l, r, id;
};
 
 
lli n, q;
vector<Query> lq;
vector<lli> lst;
vector<lli> parents;
vector<lli> ans;
 
bool cmp(Query &a, Query &b){
    if (a.r < b.r) return true;
    else if (a.r == b.r && a.l < b.l) return true;
    return false;
}
 
 
lli getp(lli ind){
    if (parents[ind] == ind) return ind;
    else return parents[ind] = getp(parents[ind]);
}
 
int main()
{
    ios_base::sync_with_stdio(false);  
    cin.tie(0);
    cin >> n >> q;
    lst.resize(n);
    parents.resize(n);
    lq.resize(q);
    ans.resize(q);
    
    forp1(n){
        cin >> lst[i];
        parents[i] = i;
    }
    forp1(q){
        cin >> lq[i].l >> lq[i].r;
        lq[i].l--, lq[i].r--;
        lq[i].id = i;
    }
    sort(lq.begin(), lq.end(), cmp);
 
    lli qno = 0;
    stack<lli> s;
    for (lli i =0; i < n; i++){
        while (!s.empty() && lst[s.top()] > lst[i]){
            parents[s.top()] = i;
            s.pop();
        }
        s.push(i);
        while (qno < q && lq[qno].r == i){
            ans[lq[qno].id] = lst[getp(lq[qno].l)];
            qno++;
        }
    }
    forp1(q){
        cout << ans[i] << " ";
    }
    prnt("");
 
}