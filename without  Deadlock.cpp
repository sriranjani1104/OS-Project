void runWithoutDeadlock() {
    RAG g;

    // Nodes
    g.addNode("P1"); g.addNode("P2"); g.addNode("P3"); g.addNode("P4");
    g.addNode("R1"); g.addNode("R2"); g.addNode("R3"); g.addNode("R4");

    // Edges (NO Deadlock)
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
