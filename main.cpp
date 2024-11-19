#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle {
private:
    vector<string> items;
    vector<int> quantities; 
public:
    void setRoute(int routeId) {
        cout << "Маршрут установлен: " << routeId << endl;
    }
    void moveToNextStop() {
        cout << "Транспортное средство переезжает к следующей остановке" << endl;
    }
};

class Driver {
private:
    string name;
public:
    void assignDriver(string name) {
        this->name = name;
        cout << "Назначен водитель: " << name << endl;
    }
    string getDriverInfo() {
        return name;
    }
};

class PassengerCounter {
private:
    int counter = 0;
public:
    void passengerBoard(int count) {
        counter += count;
        cout << "Пассажиров в салоне: " << counter << endl;
    }
    void passengerExit(int count) {
        if (counter >= count) {
        counter -= count;
        cout << "Пассажиров вышло: " << count << endl;
        }
    }
};

class TransportSystem : public Vehicle, public Driver , public PassengerCounter {
public:
    void operateRoute(int routeId, string driverName) {
        setRoute(routeId);
        assignDriver(driverName);

        cout << "Симуляция работы транспортного средства" << endl;
        moveToNextStop();
        passengerBoard(10);
        passengerExit(5);
        moveToNextStop();
        passengerBoard(15);
        passengerExit(10);
    }
};

int main() {
    TransportSystem ts;
    ts.operateRoute(1, "Иванов Иван");
    return 0;
    cout << "Hello World!";
}
