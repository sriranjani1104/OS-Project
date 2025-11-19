#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class RAG {
public:
    unordered_map<string, vector<string>> adj;

    void addNode(string n) { adj[n]; }

    void addEdge(string u, string v) { 
        adj[u].push_back(v); 
    }

    bool dfs(string u, unordered_set<string>& visited, unordered_set<string>& stackSet) {
        visited.insert(u);
        stackSet.insert(u);

        for (auto& v : adj[u]) {
            if (!visited.count(v) && dfs(v, visited, stackSet))
                return true;
            if (stackSet.count(v))
                return true;
        }

        stackSet.erase(u);
        return false;
    }

    bool detectCycle() {
        unordered_set<string> visited, stackSet;

        for (auto& p : adj) {
            if (!visited.count(p.first)) {
                if (dfs(p.first, visited, stackSet))
                    return true;
            }
        }
        return false;
    }

    void printGraph() {
        
      cout << "\n RESOURCE ALLOCATION GRAPH";

        for (auto& p : adj) 
        {
            for (auto& v : p.second)
            {
                cout << p.first << " ---> " << v << endl;
            }
        }
  }    
};

