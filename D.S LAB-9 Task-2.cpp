#include <iostream>
#include <queue>
#include <stack>
using namespace std;
queue<int> road;
stack<int> garage;
// Truck arrives on road
void On_road(int id) {
    road.push(id);
    cout << "Truck " << id << " is on the road.\n";
}
// Move truck from road to garage
void Enter_garage(int id) {
    if (!road.empty() && road.front() == id) {
        garage.push(id);
        road.pop();
        cout << "Truck " << id << " entered the garage.\n";
    } else {
        cout << "Truck " << id << " is not at front of road queue.\n";
    }
}
// Exit truck from garage
void Exit_garage(int id) {
    if (garage.empty()) {
        cout << "Garage is empty.\n";
        return;
    }

    if (garage.top() == id) {
        garage.pop();
        cout << "Truck " << id << " exited the garage.\n";
    } else {
        cout << "Truck is not near garage door.\n";
    }
}
//  trucks on road or garage
void Show_trucks(string place) {
    if (place == "road") {
        cout << "\nTrucks on Road: ";
        queue<int> temp = road;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
    else if (place == "garage") {
        cout << "\nTrucks in Garage: ";
        stack<int> temp = garage;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << "(top is near door)\n";
    }
}
int main() {
    On_road(101);
    On_road(102);
    On_road(103);

    Show_trucks("road");

    Enter_garage(101);
    Enter_garage(102);

    Show_trucks("garage");
    Show_trucks("road");

    Exit_garage(101);   // wrong truck
    Exit_garage(102);   // correct truck

    Show_trucks("garage");
    return 0;
}