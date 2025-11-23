#include <iostream>
using namespace std;

class node {
public:
    int Age;
    string name;
    double Aadhar_no;
    node* next;
};

class SLL {
    node* head;
public:
    SLL() {
        head = NULL;
    }
    void create();
    void display();
    void search();
    void insert_at_begin();
    void insert_at_end();
    void insert_in_between();
    void delete1();
    void update();
    void sorting();
};
void SLL::create() {
    if (head != NULL) {
        char confirm;
        cout << "A linked list already exists. Do you want to overwrite it? (y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y') {
           
            node* p = head;
            while (p != NULL) {
                node* temp = p;
                p = p->next;
                delete temp;
            }
            head = NULL; 
            cout << "Existing list cleared.\n";
        } else {
            cout << "Appending to the existing list...\n";
            return; 
        }
    }

    node* temp = NULL, *p = NULL;
    int c = 1;
    while (c != 0) {
        temp = new node;
        cout << "Enter Name: ";
        cin >> temp->name;
        cout << "Enter Age: ";
        cin >> temp->Age;
        cout << "Enter Aadhar_no: ";
        cin >> temp->Aadhar_no;
        temp->next = NULL;

        if (head == NULL) {
            head = temp;
            p = head;
        } else {
            p->next = temp;
            p = temp;
        }

        cout << "Enter 0 to stop, any other number to continue: ";
        cin >> c;
    }
}


void SLL::display() {
    node* p = head;
    if (head == NULL) {
        cout << "\nLinked list is empty...\n";
    } else {
        cout << "\nLinked List Contents:\n";
        while (p != NULL) {
            cout << "Name: " << p->name << ", Age: " << p->Age << ", Aadhar No: " << p->Aadhar_no << endl;
            p = p->next;
        }
    }
}

void SLL::search() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    string target;
    cout << "Enter name to search: ";
    cin >> target;

    node* p = head;
    while (p != NULL) {
        if (p->name == target) {
            cout << "Record Found:\n";
            cout << "Name: " << p->name << ", Age: " << p->Age << ", Aadhar No: " << p->Aadhar_no << endl;
            return;
        }
        p = p->next;
    }

    cout << "Record with name \"" << target << "\" not found.\n";
}

void SLL::insert_at_begin() {
    node* temp = new node;
    cout << "Enter Name: ";
    cin >> temp->name;
    cout << "Enter Age: ";
    cin >> temp->Age;
    cout << "Enter Aadhar_no: ";
    cin >> temp->Aadhar_no;
    temp->next = head;
    head = temp;
}

void SLL::insert_at_end() {
    node* temp = new node;
    cout << "Enter Name: ";
    cin >> temp->name;
    cout << "Enter Age: ";
    cin >> temp->Age;
    cout << "Enter Aadhar_no: ";
    cin >> temp->Aadhar_no;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        node* p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void SLL::insert_in_between() {
    int pos;
    cout << "Enter the position to insert at: ";
    cin >> pos;

    if (pos <= 0) {
        cout << "Invalid position!\n";
        return;
    }

    node* temp = new node;
    cout << "Enter Name: ";
    cin >> temp->name;
    cout << "Enter Age: ";
    cin >> temp->Age;
    cout << "Enter Aadhar_no: ";
    cin >> temp->Aadhar_no;
    temp->next = NULL;

    if (pos == 1) {
        temp->next = head;
        head = temp;
        cout << "Node inserted at position 1.\n";
        return;
    }

    node* p = head;
    for (int i = 1; i < pos - 1 && p != NULL; i++) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Position out of bounds. Node inserted at the end.\n";
       
        if (head == NULL) {
            head = temp;
        } else {
            node* q = head;
            while (q->next != NULL) {
                q = q->next;
            }
            q->next = temp;
        }
    } else {
        temp->next = p->next;
        p->next = temp;
        cout << "Node inserted at position " << pos << ".\n";
    }
}


void SLL::delete1() {
    int ch;
    cout << "\nDelete Options:\n1. Delete at Beginning\n2. Delete at End\n3. Delete by Position\n4. Exit\nEnter choice: ";
    cin >> ch;

    switch (ch) {
    case 1: {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        node* p = head;
        head = head->next;
        delete p;
        cout << "Node deleted from beginning.\n";
        break;
    }

    case 2: {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
        } else {
            node* p = head;
            while (p->next->next != NULL) {
                p = p->next;
            }
            delete p->next;
            p->next = NULL;
        }
        cout << "Node deleted from end.\n";
        break;
    }

    case 3: {
        int pos;
        cout << "Enter position to delete: ";
        cin >> pos;

        if (pos <= 0 || head == NULL) {
            cout << "Invalid position or empty list.\n";
            return;
        }

        if (pos == 1) {
            node* temp = head;
            head = head->next;
            delete temp;
        } else {
            node* p = head;
            for (int i = 1; i < pos - 1 && p->next != NULL; i++) {
                p = p->next;
            }

            if (p->next == NULL) {
                cout << "Position out of bounds.\n";
                return;
            }

            node* temp = p->next;
            p->next = temp->next;
            delete temp;
        }
        cout << "Node deleted from position " << pos << ".\n";
        break;
    }

    case 4:
        return;

    default:
        cout << "Invalid choice.\n";
    }
}

void SLL::update() {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    string target;
    cout << "Enter name to update: ";
    cin >> target;

    node* p = head;
    while (p != NULL) {
        if (p->name == target) {
            cout << "Record Found!!./n Enter new details:-\n";
            cout << "Enter New Name: ";
            cin >> p->name;
            cout << "Enter New Age: ";
            cin >> p->Age;
            cout << "Enter New Aadhar No: ";
            cin >> p->Aadhar_no;
            cout << "Record updated successfully.\n";
            return;
        }
        p = p->next;
    }

    cout << "Record with name \"" << target << "\" not found.\n";
}

void SLL::sorting(){

   
    if (!head) return; 
    node *p = head, *s;

    while (p != NULL) {
        s = p->next;

        while (s != NULL) {
            if (p->name > s->name) {
                
                string tempName = p->name;
                p->name = s->name;
                s->name = tempName;

                int tempAge = p->Age;
                p->Age = s->Age;
                s->Age = tempAge;

                double tempAadhar = p->Aadhar_no;
                p->Aadhar_no = s->Aadhar_no;
                s->Aadhar_no = tempAadhar;
            }
            s = s->next;
        }

        p = p->next;
    }

    cout << "\nLinked List is sorted by name:\n";
    display();
}

int main() {
    SLL obj;
    int choice;
    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Create Linked List\n";
        cout << "2. Display Linked List\n";
        cout << "3. Search by Name\n";
        cout << "4. Insert at Beginning\n";
        cout << "5. Insert at End\n";
         cout << "6. Insert in between\n";
        cout << "7. Delete \n";
        cout << "8. Update \n";
        cout << "9. Sorting Linked List \n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: obj.create(); break;
        case 2: obj.display(); break;
        case 3: obj.search(); break;
        case 4: obj.insert_at_begin(); break;
        case 5: obj.insert_at_end(); break;
        case 6: obj.insert_in_between(); break;
        case 7: obj.delete1(); break;
        case 8: obj.update(); break;
        case 9: obj.sorting(); break;
        case 0:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
