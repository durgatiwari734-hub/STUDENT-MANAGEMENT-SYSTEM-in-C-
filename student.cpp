#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
public:
    string name, roll, course;
    int age;

    void addStudent();
    void showAllStudents();
    void searchStudent();
    void deleteStudent();
};

void Student::addStudent() {
    ofstream file("students.txt", ios::app);
    cout << "\nEnter Name: ";
    cin >> name;
cout << "Enter Roll No: ";
    cin >> roll;
    cout << "Enter Course: ";
    cin >> course;
    cout << "Enter Age: ";
    cin >> age;

    file << name << " " << roll << " " << course << " " << age << endl;
    file.close();
    cout << "\nStudent record added successfully!\n";
}

void Student::showAllStudents() {
    ifstream file("students.txt");
    if (!file) {
        cout << "\nNo record found.\n";
        return;
    }

    cout << "\n--- Student Records ---\n";
    while (file >> name >> roll >> course >> age) {
        cout << "Name: " << name
             << ", Roll No: " << roll
             << ", Course: " << course
             << ", Age: " << age << endl;
    }
    file.close();
}

void Student::searchStudent() {
    ifstream file("students.txt");
    if (!file) {
        cout << "\nNo record found.\n";
        return;
    }

    string r;
    cout << "\nEnter Roll No to search: ";
    cin >> r;
    bool found = false;
    while (file >> name >> roll >> course >> age) {
        if (roll == r) {
            cout << "\nRecord Found:\n";
            cout << "Name: " << name
                 << ", Roll: " << roll
                 << ", Course: " << course
                 << ", Age: " << age << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nNo record found for this roll number.\n";

    file.close();
}
void Student::deleteStudent() {
    ifstream file("students.txt");
    ofstream temp("temp.txt");

    if (!file) {
        cout << "\nNo record found.\n";
        return;
    }

    string r;
    cout << "\nEnter Roll No to delete: ";
    cin >> r;

    bool deleted = false;
    while (file >> name >> roll >> course >> age) {
        if (roll == r) {
            deleted = true;
            continue;  
        }
                temp << name << " " << roll << " " << course << " " << age << endl;
    }

    file.close();
    temp.close();

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (deleted)
        cout << "\nRecord deleted successfully!\n";
    else
        cout << "\nRoll number not found.\n";
}

int main() {
    Student s;
    int choice;

    while (true) {
        cout << "\n--- Student Management System ---";
        cout << "\n1. Add Student";
        cout << "\n2. Show All Students";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: s.addStudent(); break;
            case 2: s.showAllStudents(); break;
            case 3: s.searchStudent(); break;
            case 4: s.deleteStudent(); break;
            case 5: exit(0);
            default: cout << "\nInvalid choice!\n";
        }
}
}