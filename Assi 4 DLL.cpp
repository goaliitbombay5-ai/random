#include <iostream>
#include <string>
using namespace std;

class StudentNode {
public:
    string name;
    int rollNo;
    float marks;
    StudentNode* prev;
    StudentNode* next;

    StudentNode(string name, int rollNo, float marks) {
        this->name = name;
        this->rollNo = rollNo;
        this->marks = marks;
        this->prev = Nullptr;
        this->next = Nullptr;
    }
};

class StudentList {
private:
    StudentNode* head;

    void swap(StudentNode* a, StudentNode* b) {
        std::swap(a->name, b->name);
        std::swap(a->rollNo, b->rollNo);
        std::swap(a->marks, b->marks);
    }

public:
    StudentList() {
        head = nullptr;
    }

    void insertStudent(string name, int rollNo, float marks) {
        StudentNode* newNode = new StudentNode(name, rollNo, marks);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        StudentNode* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    void displayList() {
        StudentNode* temp = head;
        if (!temp) {
            cout << "List is empty.\n";
            return;
        }

        cout << "\nStudent List:\n";
        cout << "----------------------------------\n";
        while (temp != nullptr) {
            cout << "Name: " << temp->name << "| Roll No: " << temp->rollNo << "| Marks: " << temp->marks << endl;
            temp = temp->next;
        }
        cout << "----------------------------------\n";
    }

    void sortByMarksAscending() {
        if (!head) return;

        for (StudentNode* i = head; i->next != nullptr; i = i->next) {
            for (StudentNode* j = i->next; j != nullptr; j = j->next) {
                if (i->marks > j->marks) {
                    swap(i, j);
                }
            }
        }

        cout << "List sorted by marks in ascending order.\n";
    }
};

int main() {
    StudentList list;
    int choice;
    string name;
    int rollNo;
    float marks;

    do {
        cout << "\n--- Student Doubly Linked List Menu ---\n";
        cout << "1. Insert Student\n";
        cout << "2. Display Students\n";
        cout << "3. Sort by Marks (Ascending)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter roll number: ";
                cin >> rollNo;
                cout << "Enter marks ( /50): ";
                cin >> marks;
                list.insertStudent(name, rollNo, marks);
                break;

            case 2:
                list.displayList();
                break;

            case 3:
                list.sortByMarksAscending();
                list.displayList();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
