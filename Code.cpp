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
void runWithoutDeadlock() {
    RAG g;

    g.addNode("P1"); g.addNode("P2"); g.addNode("P3"); g.addNode("P4");
    g.addNode("R1"); g.addNode("R2"); g.addNode("R3"); g.addNode("R4");

    g.addEdge("P1", "R1");
    g.addEdge("R1", "P2");
    g.addEdge("P2", "R2");
    g.addEdge("R2", "P3");
    g.addEdge("P3", "R3");
    g.addEdge("R3", "P4");
    g.addEdge("P4", "R4");

    g.printGraph();

    cout << "\nStatus: ";
    if (g.detectCycle())
        cout << "Deadlock Detected\n";
    else
        cout << "No Deadlock\n";
}
void runWithDeadlock() {
    RAG g;

    g.addNode("P1"); g.addNode("P2"); g.addNode("P3"); g.addNode("P4");
    g.addNode("R1"); g.addNode("R2"); g.addNode("R3"); g.addNode("R4");

    g.addEdge("P1", "R1");
    g.addEdge("R1", "P2");
    g.addEdge("P2", "R2");
    g.addEdge("R2", "P3");
    g.addEdge("P3", "R3");
    g.addEdge("R3", "P4");
    g.addEdge("P4", "R4");
    g.addEdge("R4", "P1"); 

    g.printGraph();

    cout << "\nStatus: ";
    if (g.detectCycle())
        cout << "Deadlock Detected\n";
    else
        cout << "No Deadlock\n";
}

int main() {
    int choice;

    cout << "\nResource Allocation Graph";
    cout << "\n1. Resource Allocation WITHOUT Deadlock";
    cout << "\n2. Resource Allocation WITH Deadlock";
    cout << "\nEnter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: runWithoutDeadlock(); break;
        case 2: runWithDeadlock(); break;
        default: cout << "Invalid Option!\n";
    }

    return 0;
}
