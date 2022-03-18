#include <string>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> chain, vector<bool>& visited, int x){
    visited[x] = true;
    for(int i = 0; i < chain[x].size(); i++){
        if(!visited[chain[x][i]]){
            DFS(chain, visited, chain[x][i]);
        }
    }
}
bool chainFormed(vector<vector<int>> chain, vector<bool> visitedVertex, int x){
    vector<bool> visited(26);
    
    DFS(chain, visited, x);
    for(int i = 0; i < 26; i++){
        if(visitedVertex[i] && !visited[i]){
            return false;
        }
    }
    return true;
}
bool canBeChained(vector<string> a){
    vector<vector<int>> chain(26);  // vector for edges
    vector<int> inD(26), outD(26); // vectors for in-degrees and out-degrees
    vector<bool> visitedVertex(26);
    int n = a.size(), first, last;
    for(int i = 0; i < n; i++){
        first = a[i][0] - 'a';
        last = a[i][a[i].size() - 1] - 'a';
        visitedVertex[first] = visitedVertex[last] = true;
        inD[last]++;
        outD[first]++;
        chain[first].push_back(last);
    }
    int InMinusOut = 0;
    int OutMinusIn = 0;
    int Equal = 0;
    for(int i = 0; i < 26; i++){
        if(inD[i] - outD[i] == 1){
            InMinusOut++;
        }
        if(outD[i] - inD[i] == 1){
            OutMinusIn++;
        }
        if(inD[i] == outD[i] && inD[i] > 1 && outD[i] > 1){
            Equal++;
        }
    }
    
    if(InMinusOut <= 1 || OutMinusIn <= 1 || Equal != n - InMinusOut - OutMinusIn){
        return false;
    } 

    return chainFormed(chain, visitedVertex, a[0][0] - 'a');
}