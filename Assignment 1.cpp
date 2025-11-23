#include <iostream>
using namespace std;

const int MAX = 100;

class CustomerSystem {
    long int id[MAX];
    string name[MAX];
    string contact[MAX];
    int count;

public:
    CustomerSystem();
    void insert();
    void display();
    void update();
    void delete1();
};

CustomerSystem::CustomerSystem() {
    count = 0;
}

void CustomerSystem::insert() {
    if (count < MAX) {
        cout << "Enter Customer ID: ";
        cin >> id[count];

        cout << "Enter Name (no spaces): ";
        cin >> name[count];

        cout << "Enter Contact: ";
        cin >> contact[count];

        count++;
        cout << "Customer added successfully!\n";
    } else {
        cout << "Customer limit reached!\n";
    }
}

void CustomerSystem::display() {
    if (count == 0) {
        cout << "No customer records found!\n";
        return;
    }

    cout << "\n----- Customer Records -----\n";
    for (int i = 0; i < count; i++) {
        cout << "ID: " << id[i]
             << "  Name: " << name[i]
             << "  Contact: " << contact[i] << endl;
    }
}

void CustomerSystem::update() {
    long int cid;  
    cout << "Enter Customer ID to update: ";
    cin >> cid;

    for (int i = 0; i < count; i++) {
        if (id[i] == cid) {
            cout << "Enter new Name: ";
            cin >> name[i];
            cout << "Enter new Contact: ";
            cin >> contact[i];
            cout << "Record updated successfully!\n";
            return;
        }
    }
    cout << "Customer ID not found!\n";
}

void CustomerSystem::delete1() {
    long int cid;
    cout << "Enter Customer ID to delete: ";
    cin >> cid;

    for (int i = 0; i < count; i++) {
        if (id[i] == cid) {
            for (int j = i; j < count - 1; j++) {
                id[j] = id[j + 1];
                name[j] = name[j + 1];
                contact[j] = contact[j + 1];
            }
            count--;
            cout << "Record deleted successfully!\n";
            return;
        }
    }
    cout << "Customer ID not found!\n";
}

int main() {
    CustomerSystem cs;
    int choice;

    do {
        cout << "\n--- Customer Management System ---\n";
        cout << "1. Insert\n";
        cout << "2. Display\n";
        cout << "3. Update\n";
        cout << "4. Delete\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cs.insert(); break;
            case 2: cs.display(); break;
            case 3: cs.update(); break;
            case 4: cs.delete1(); break;
            case 5: cout << "Exiting..."; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}

