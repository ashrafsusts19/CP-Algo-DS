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


lli n, m;
vector<set<lli>> roads;
vector<vector<lli>> adjm;
vector<lli> parents;



lli bfs(lli s, lli t){
    fill(parents.begin(), parents.end(), -1);
    parents[s] = -2;
    queue<pair<lli, lli>> q;
    q.push({s, LLONG_MAX});
    
    while (!q.empty()){
        lli ind = q.front().first;
        lli flow = q.front().second;
        q.pop();
        for (lli cind: roads[ind]){
            if (parents[cind] == -1 && adjm[ind][cind] > 0){
                parents[cind] = ind;
                if (cind == t) return min(flow, adjm[ind][cind]);
                q.push({cind, min(adjm[ind][cind], flow)});
            }
        }

    }
    return 0;
}



int main()
{
    ios_base::sync_with_stdio(false);   
    cin.tie(0); 
    
    cin >> n >> m;
    roads.resize(n);
    adjm.resize(n, vector<lli> (n, 0));
    parents.resize(n);
    forp1(m){
        lli a, b, c;
        cin >> a >> b>> c;
        a--, b--;
        roads[a].insert(b);    
        roads[b].insert(a);
        adjm[a][b] += c;
    }
    lli totflow = 0, nflow;
    while (nflow = bfs(0, n - 1)){
        totflow += nflow;
        lli ind = n - 1;
        while (ind != 0){
            adjm[ind][parents[ind]] += nflow;
            adjm[parents[ind]][ind] -= nflow;
            ind = parents[ind];
        }

    }
    prnt(totflow);
}  