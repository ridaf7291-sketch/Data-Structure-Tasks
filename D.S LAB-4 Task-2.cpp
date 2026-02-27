#include <iostream>
using namespace std;
// Profile Class
class Profile {
public:
    int id, age;
    string name, gender, email, interest, dob;
    Profile* next;

    Profile(int i, string n, string g, int a, string e, string in, string d) {
        id = i;
        name = n;
        gender = g;
        age = a;
        email = e;
        interest = in;
        dob = d;
        next = NULL;
    }
};
// Portal Class
class Portal {
    Profile* head;
public:
    Portal() {
        head = NULL;
    }
    void InsertProfile(int id, string name, string gender, int age, string email, string interest, string dob) {
        Profile* newNode = new Profile(id, name, gender, age, email, interest, dob);

        if (head == NULL)
            head = newNode;
        else {
            Profile* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
        cout << "Profile Added Successfully!\n";
    }
    void UpdateProfile(int id) {
        Profile* temp = head;

        while (temp != NULL) {
            if (temp->id == id) {
                cout << "Enter New Name: ";
                cin >> temp->name;
                cout << "Enter Gender: ";
                cin >> temp->gender;
                cout << "Enter Age: ";
                cin >> temp->age;
                cout << "Enter Email: ";
                cin >> temp->email;
                cout << "Enter Interest: ";
                cin >> temp->interest;
                cout << "Enter DOB: ";
                cin >> temp->dob;

                cout << "Profile Updated Successfully!\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Profile Not Found!\n";
    }
    void DeleteProfile(string name) {
        Profile *temp = head, *prev = NULL;

        while (temp != NULL) {
            if (temp->name == name) {
                if (prev == NULL)
                    head = temp->next;
                else
                    prev->next = temp->next;

                delete temp;
                cout << "Profile Deleted Successfully!\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Profile Not Found!\n";
    }

    void searchProfile(string name) {
        Profile* temp = head;

        while (temp != NULL) {
            if (temp->name == name) {
                cout << "\nProfile Found:\n";
                cout << "ID: " << temp->id << endl;
                cout << "Name: " << temp->name << endl;
                cout << "Gender: " << temp->gender << endl;
                cout << "Age: " << temp->age << endl;
                cout << "Email: " << temp->email << endl;
                cout << "Interest: " << temp->interest << endl;
                cout << "DOB: " << temp->dob << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Profile Not Found!\n";
    }
    void Display() {
        Profile* temp = head;

        if (temp == NULL) {
            cout << "No Profiles Available\n";
            return;
        }

        while (temp != NULL) {
            cout << "\n-------------------\n";
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            cout << "Gender: " << temp->gender << endl;
            cout << "Age: " << temp->age << endl;
            cout << "Email: " << temp->email << endl;
            cout << "Interest: " << temp->interest << endl;
            cout << "DOB: " << temp->dob << endl;
            temp = temp->next;
        }
    }
};
int main() {
    Portal p;
    int choice, id, age;
    string name, gender, email, interest, dob;

    do {
        cout << "\n===== SOCIAL MEDIA PORTAL =====\n";
        cout << "1. Add New Profile\n";
        cout << "2. Update Profile\n";
        cout << "3. Delete Profile\n";
        cout << "4. Search Profile\n";
        cout << "5. Display All\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Gender: ";
            cin >> gender;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Interest: ";
            cin >> interest;
            cout << "Enter DOB: ";
            cin >> dob;
            p.InsertProfile(id, name, gender, age, email, interest, dob);
            break;

        case 2:
            cout << "Enter ID to Update: ";
            cin >> id;
            p.UpdateProfile(id);
            break;

        case 3:
            cout << "Enter Name to Delete: ";
            cin >> name;
            p.DeleteProfile(name);
            break;

        case 4:
            cout << "Enter Name to Search: ";
            cin >> name;
            p.searchProfile(name);
            break;

        case 5:
            p.Display();
            break;

        case 6:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}