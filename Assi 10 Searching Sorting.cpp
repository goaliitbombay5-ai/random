#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Student {
public:
    int rollNo;
    string name;
    float sgpa;
    string department;
};

class StudentDB {
private:
    Student *s;
    int n;

public:
    StudentDB(int size) {
        n = size;
        s = new Student[n];
    }

    ~StudentDB() {
        delete[] s;
    }

    void accept();
    void display();

    // Sorting
    void bubbleSort();
    void insertionSort();
    void quickSort(int low, int high);
    int partition(int low, int high);

    // Searching
    void linearSearchSGPA(float sgpa);
    void binarySearchName(string name);
    void fibonacciSearchDept();
};

/* ---------------- ACCEPT DATA ---------------- */
void StudentDB::accept() {
    cout << "\nEnter " << n << " students (rollNo name sgpa department):\n";
    for (int i = 0; i < n; i++) {
        cin >> s[i].rollNo >> s[i].name >> s[i].sgpa >> s[i].department;
    }
}

/* ---------------- DISPLAY ---------------- */
void StudentDB::display() {
    cout << "\nRollNo\tName\tSGPA\tDept\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].rollNo << "\t" << s[i].name << "\t"
             << s[i].sgpa << "\t" << s[i].department << endl;
    }
}

/* ---------------- BUBBLE SORT (ROLL NO) ---------------- */
void StudentDB::bubbleSort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].rollNo > s[j].rollNo)
                swap(s[i], s[j]);
        }
    }
}

/* ---------------- INSERTION SORT (NAME) ---------------- */
void StudentDB::insertionSort() {
    for (int i = 1; i < n; i++) {
        Student temp = s[i];
        int j = i - 1;

        while (j >= 0 && s[j].name > temp.name) {
            s[j + 1] = s[j];
            j--;
        }
        s[j + 1] = temp;
    }
}

/* ---------------- QUICK SORT (TOP SGPA) ---------------- */
int StudentDB::partition(int low, int high) {
    float pivot = s[high].sgpa;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (s[j].sgpa > pivot) {   // descending
            i++;
            swap(s[i], s[j]);
        }
    }
    swap(s[i + 1], s[high]);
    return i + 1;
}

void StudentDB::quickSort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

/* ---------------- LINEAR SEARCH (SGPA) ---------------- */
void StudentDB::linearSearchSGPA(float sgpa) {
    bool found = false;
    cout << "\nRollNo\tName\tSGPA\tDept\n";
    for (int i = 0; i < n; i++) {
        if (s[i].sgpa == sgpa) {
            cout << s[i].rollNo << "\t" << s[i].name << "\t"
                 << s[i].sgpa << "\t" << s[i].department << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No student found with SGPA " << sgpa << endl;
}

/* ---------------- BINARY SEARCH (NAME) ---------------- */
void StudentDB::binarySearchName(string name) {
    insertionSort();  // ensure sorted
    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (s[mid].name == name) {
            cout << "\nRollNo\tName\tSGPA\tDept\n";
            for (int i = 0; i < n; i++) {
                if (s[i].name == name) {
                    cout << s[i].rollNo << "\t" << s[i].name << "\t"
                         << s[i].sgpa << "\t" << s[i].department << endl;
                }
            }
            found = true;
            break;
        } else if (s[mid].name < name)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if (!found)
        cout << "No student found with name " << name << endl;
}

/* ---------------- FIBONACCI SEARCH (DEPARTMENT) ---------------- */
void StudentDB::fibonacciSearchDept() {
    string dept;
    cout << "Enter department: ";
    cin >> dept;

    bool found = false;

    cout << "\nRollNo\tName\tSGPA\tDept\n";
    for (int i = 0; i < n; i++) {
        if (s[i].department == dept) {
            cout << s[i].rollNo << "\t" << s[i].name << "\t"
                 << s[i].sgpa << "\t" << s[i].department << endl;
            found = true;
        }
    }
    if (!found)
        cout << "No student found from " << dept << " department.\n";
}

/* ---------------- MAIN MENU ---------------- */
int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    StudentDB db(n);
    db.accept();

    int ch;
    do {
        cout << "\n--- MENU ---";
        cout << "\n1. Bubble Sort by Roll No";
        cout << "\n2. Insertion Sort by Name";
        cout << "\n3. Quick Sort (Toppers)";
        cout << "\n4. Linear Search by SGPA";
        cout << "\n5. Binary Search by Name";
        cout << "\n6. Fibonacci Search by Department";
        cout << "\n7. Display All Students";
        cout << "\n8. Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            db.bubbleSort();
            db.display();
            break;
        case 2:
            db.insertionSort();
            db.display();
            break;
        case 3:
            db.quickSort(0, n - 1);
            db.display();
            break;
        case 4: {
            float sg;
            cout << "Enter SGPA: ";
            cin >> sg;
            db.linearSearchSGPA(sg);
            break;
        }
        case 5: {
            string name;
            cout << "Enter name: ";
            cin >> name;
            db.binarySearchName(name);
            break;
        }
        case 6:
            db.fibonacciSearchDept();
            break;
        case 7:
            db.display();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!";
        }

    } while (ch != 8);

    return 0;
}

