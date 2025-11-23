#include <iostream>
#include <vector>
#include <list>
#include <iomanip>
using namespace std;

class Hashing {
public:
    void linearProbing();
    void separateChaining();
    void quadraticProbing();
};

/* ============================
      LINEAR PROBING
   ============================ */
void Hashing::linearProbing() {
    cout << "\n--- LINEAR PROBING ---\n";
    
    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    vector<int> hashTable(size, -1);

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;

        int index = key % size;
        int start = index;

        // linear probing
        while (hashTable[index] != -1) {
            index = (index + 1) % size;
            if (index == start) {
                cout << "Hash table is full!\n";
                break;
            }
        }

        if (hashTable[index] == -1)
            hashTable[index] = key;
    }

    cout << "\nHash Table (Linear Probing)\n\n";
    cout << setw(8) << "Index" << setw(12) << "Key\n\n";

    for (int i = 0; i < size; ++i) {
        cout << setw(8) << i << setw(12);
        if (hashTable[i] == -1)
            cout << "NULL";
        else
            cout << hashTable[i];
        cout << '\n';
    }
    cout << '\n';
}

/* ============================
     SEPARATE CHAINING
   ============================ */
void Hashing::separateChaining() {
    cout << "\n--- SEPARATE CHAINING ---\n";

    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    vector< list<int> > hashTable(size);

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;

        int index = key % size;
        hashTable[index].push_back(key);
    }

    cout << "\nHash Table (Separate Chaining)\n\n";

    for (int i = 0; i < size; ++i) {
        cout << setw(3) << i << " -> ";

        for (list<int>::iterator it = hashTable[i].begin();
             it != hashTable[i].end(); ++it) {
            cout << *it << " -> ";
        }

        cout << "NULL\n";
    }
    cout << '\n';
}

/* ============================
     QUADRATIC PROBING
   ============================ */
void Hashing::quadraticProbing() {
    cout << "\n--- QUADRATIC PROBING ---\n";

    int size;
    cout << "Enter size of hash table: ";
    cin >> size;

    vector<int> hashTable(size, -1);

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        int key;
        cin >> key;

        int index = key % size;
        bool inserted = false;

        for (int j = 0; j < size; j++) {
            int pos = (index + j * j) % size;

            if (hashTable[pos] == -1) {
                hashTable[pos] = key;
                inserted = true;
                break;
            }
        }

        if (!inserted) {
            cout << "Could not insert " << key
                 << " — table full or probe failed.\n";
        }
    }

    cout << "\nHash Table (Quadratic Probing)\n\n";
    cout << setw(8) << "Index" << setw(12) << "Key\n\n";

    for (int i = 0; i < size; ++i) {
        cout << setw(8) << i << setw(12);
        if (hashTable[i] == -1)
            cout << "NULL";
        else
            cout << hashTable[i];
        cout << '\n';
    }
    cout << '\n';
}

/* ============================
            MAIN
   ============================ */
int main() {
    Hashing h;
    int choice = 0;

    cout << "===============================\n";
    cout << "        HASHING PROGRAM        \n";
    cout << "===============================\n";

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Linear Probing (without replacement)\n";
        cout << "2. Separate Chaining (linked list)\n";
        cout << "3. Quadratic Probing (without replacement)\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            h.linearProbing();
            break;
        case 2:
            h.separateChaining();
            break;
        case 3:
            h.quadraticProbing();
            break;
        case 4:
            cout << "Exiting. Goodbye.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
            break;
        }

    } while (choice != 4);

    return 0;
}

