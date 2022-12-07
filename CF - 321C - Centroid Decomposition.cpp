//ashrafsusts19

//Wtih Centroid decomposition



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


lli n;
vector<vector<lli>> roads;
vector<pair<lli, lli>> centroids;
vector<bool> iscentroid;
vector<lli> subsize;

lli dfs(lli ind, lli parent){
    lli tot = 1;
    for (lli cind: roads[ind]){
        if (cind == parent || iscentroid[cind]) continue;
        tot += dfs(cind, ind);
    }
    subsize[ind] = tot;
    return tot;

}

lli getCen(lli ind, lli parent, lli tnodes){
    
    for (lli cind: roads[ind]){
        if (cind == parent || iscentroid[cind]) continue;
        if (subsize[cind] > tnodes / 2) return getCen(cind, ind, tnodes);
    }
    return ind;
}

int main()
{
    ios_base::sync_with_stdio(false);   
    cin.tie(0);
    cin >> n;
    roads.resize(n);
    subsize.resize(n);
    iscentroid.resize(n, false);
    forp1(n - 1){
        lli a, b;
        cin >> a >> b;
        roads[--a].push_back(--b);
        roads[b].push_back(a);
    }
    
    dfs(0, 0);
    lli cen = getCen(0, 0, n);
    centroids.push_back({cen, 0});
    iscentroid[cen] = true; 
    for (lli i = 0; i < centroids.size(); i++){
        lli ind = centroids[i].first, level = centroids[i].second;
        for (lli cind: roads[ind]){
            if (iscentroid[cind]) continue;
            lli tnodes = dfs(cind, ind);
            cen = getCen(cind, ind, tnodes);
            iscentroid[cen] = true;
            centroids.push_back({cen, level + 1});
        }

    }
    bool ispos = true;
    if (centroids[n - 1].second >= 26){
        ispos = false;
    }
    if (ispos){
        vector<char> ans(n);
        forp1(n){
            ans[centroids[i].first] = centroids[i].second + 'A';
        }
        forp1(n){
            cout << ans[i] << " ";
        }
        prnt("");
    }
    else {
        prnt("Impossible!");
    }
    
}  