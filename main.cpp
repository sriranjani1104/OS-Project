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
