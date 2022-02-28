#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>


std::vector<std::vector<int>> adjlst;
std::vector<int> indegrees;
int main()
{
    int nodes, edges, a, b;
    adjlst.resize(nodes);
    indegrees.resize(nodes);
    for (int i = 0; i < nodes; i++){
        indegrees[i] = 0;
    }
    std::cin >> nodes >> edges;
    for (int i = 0; i< edges; i++){
        std::cin >> a >> b;
        adjlst[a].push_back(b);
        indegrees[b]++;
    }
    std::vector<int> seq;
    for (int i = 0; i < nodes; i++){
        if (indegrees[i] == 0){
            seq.push_back(i);
        }
    }
    std::vector<int> orderTraverse;
    while (seq.size() > 0){
        int node = seq[seq.size() - 1];
        orderTraverse.push_back(node);
        seq.pop_back();
        for (int cnode: adjlst[node]){
            if (!(--indegrees[cnode])){
                seq.push_back(cnode);
            }
        }
    }
    for (int i = 0; i < nodes; i++){
        std::cout << orderTraverse[i] << " ";
    }
    std::cout << "\n";
}
