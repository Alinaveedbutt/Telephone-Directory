#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;
class Student {
public:
    string id;
    string name;
    string address;
    string phone;

    void input() {
        cout<<"Enter ID:"<<endl;
        cin>>id;
        cin.ignore();
        cout<<"Enter Name:"<<endl;
        getline(cin, name);
        cout<<"Enter Address:"<<endl;
        getline(cin, address);
        cout<<"Enter Phone Number:"<<endl;
        getline(cin, phone);
    }
    void display() {
        cout<<"ID:"<<id<<endl;
        cout<<"Name:"<<name<<endl;
        cout<<"Address:"<<address<<endl;
        cout<<"Phone:"<<phone<<endl;
    }
};

class Directory {
private:
    Student students [MAX];
    int total = 0;
    int findById (string id) {
        for (int i = 0; i < total; i++) {
            if (students[i].id == id) {
                return i;
            }
        }
        return -1;
    }
    int findByName (string name) {
        for (int i = 0; i < total; i++) {
            if (students[i].name == name) {
                return i;
            }
        }
        return -1;
    }
public:
    void insert() {
        while (true) {
            if (total >= MAX) {
                cout<<"Directory is full"<<endl;
                return;
            }
            Student s1;
            s1.input();
            if (findById (s1.id) != -1) {
                cout<<"ID exists, can not insert"<<endl;
            }
            else {
                int save;
                cout<<"Press 1 to save and press 0 to not save"<<endl;
                cin>>save;
                if (save == 1) {
                    students[total] = s1;
                    total++;
                    cout<<"Record saved successfully"<<endl;
                }
            }
            char again;
            cout<<"Do you want to add another record? [y/n]:"<<endl;
            cin>>again;
            if (again == 'n' || again == 'N')
                break;
        }
    }
    void update() {
        while (true) {
            string key;
            cout<<"Enter ID or Name:"<<endl;
            cin>>key;
            int index = findById(key);
            if (index == -1) index = findByName(key);
            if (index != -1) {
                cout<<"Current Information is:"<<endl;
                students[index].display();
                char choice;
                cout<<"Do you want to update [y/n]?:"<<endl;
                cin>>choice;
                cin.ignore();
                if (choice == 'y' || choice == 'Y') {
                    Student s1;
                    s1.input();
                    students[index] = s1;
                    cout<<"Record updated successfully"<<endl;
                }
            }
            else {
                cout<<"Record not found"<<endl;
            }
            char again;
            cout<<"Do you want to update another record? [y/n]:"<<endl;
            cin>>again;
            if (again == 'n' || again == 'N')
                break;
        }
    }
    void deleteRecord() {
        while (true) {
            string id;
            cout<<"Enter ID:"<<endl;
            cin>>id;
            int index = findById(id);
            if (index != -1){
                cout<<"Current Information is:"<<endl;
                students[index].display();
                char choice;
                cout<<"Do you want to delete this record [y/n]?:"<<endl;
                cin>>choice;
                if (choice == 'y' || choice == 'Y') {
                    for (int i = index; i < total - 1; i++) {
                        students[i] = students[i + 1];
                    }
                    total--;
                    cout<<"Record deleted successfully"<<endl;
                }
            }
            else {
                cout<<"Record not found"<<endl;
            }
            char again;
            cout<<"Do you want to delete another record? [y/n]:"<<endl;
            cin>>again;
            if (again == 'n' || again == 'N')
                break;
        }
    }
    void search() {
        while (true) {
            string key;
            cout<<"Enter ID or Name:"<<endl;
            cin>>key;
            int index = findById(key);
            if (index == -1) index = findByName(key);
            if (index != -1) {
                cout<<"Record Found"<<endl;
                students[index].display();
            }
            else {
                cout<<"Record not found"<<endl;
            }
            char again;
            cout<<"Do you want to search another record? [y/n]:"<<endl;
            cin>>again;
            if (again == 'n' || again == 'N')
                break;
        }
    }
    void listAll(){
        cout<<"****************************************"<<endl;
        cout<<"Telephone Directory Members"<<endl;
        cout<<"****************************************"<<endl;
        if (total == 0) {
            cout<<"No records found"<<endl;
        }
        else {
            for (int i = 0; i < total; i++) {
                cout<<"Record "<<i + 1<<":"<<endl;
                students[i].display();
                cout<<endl;
            }
            cout<<"Total "<<total<<"records shown successfully"<<endl;
        }
        char m;
        cout<<"Press ‘m’ to go to Main Menu:"<<endl;
        cin >> m;
    }
};
int main() {
    Directory dir;
    int option;
    while (true){
        cout<<endl;
        cout<<"********************************"<<endl;
        cout<<"Telephone Directory's Main Menu"<<endl;
        cout<<"********************************"<<endl;
        cout<<"Enter 1 to insert a new student"<<endl;
        cout<<"Enter 2 to update an existing student"<<endl;
        cout<<"Enter 3 to delete a record"<<endl;
        cout<<"Enter 4 to search for a student (using the Name or ID)"<<endl;
        cout<<"Enter 5 to list directory"<<endl;
        cout<<"Select the option you want: ";
        cin>>option;
        switch (option) {
            case 1:
                dir.insert();
                break;
            case 2:
                dir.update();
                break;
            case 3:
                dir.deleteRecord();
                break;
            case 4:
                dir.search();
                break;
            case 5:
                dir.listAll();
                break;
            default:
                cout<<"Invalid option"<<endl;
        }
    }
    return 0;
}
