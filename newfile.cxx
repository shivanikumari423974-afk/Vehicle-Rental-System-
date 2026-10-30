#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle
{
protected:
    int id;
    string model;
    double rate;

public:
    // Constructor
    Vehicle(int i, string m, double r)
    {
        id = i;
        model = m;
        rate = r;
    }

    // Display vehicle details
    void display()
    {
        cout << "Vehicle ID: " << id << endl;
        cout << "Model: " << model << endl;
        cout << "Rate per day: Rs. " << rate << endl;
    }

    // Virtual function
    virtual double calculateRent(int days)
    {
        return rate * days;
    }
};

// Car class inherits Vehicle
class Car : public Vehicle
{
public:
    Car(int i, string m) : Vehicle(i, m, 1500)
    {
    }

    // Function overriding
    double calculateRent(int days) override
    {
        return rate * days + 200;
    }
};

// Bike class inherits Vehicle
class Bike : public Vehicle
{
public:
    Bike(int i, string m) : Vehicle(i, m, 500)
    {
    }

    // Function overriding
    double calculateRent(int days) override
    {
        return rate * days + 50;
    }
};

int main()
{
    int choice, id, days;
    string model;

    cout << "===== VEHICLE RENTAL SYSTEM =====" << endl;
    cout << "1. Rent a Car" << endl;
    cout << "2. Rent a Bike" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice != 1 && choice != 2)
    {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    cout << "Enter vehicle ID: ";
    cin >> id;

    if (id <= 0)
    {
        cout << "Invalid vehicle ID!" << endl;
        return 0;
    }

    cout << "Enter model name (one word): ";
    cin >> model;

    cout << "Enter rental days: ";
    cin >> days;

    if (days <= 0)
    {
        cout << "Rental days must be greater than zero!" << endl;
        return 0;
    }

    if (choice == 1)
    {
        Car c(id, model);

        cout << "\n===== CAR RENTAL BILL =====" << endl;
        c.display();
        cout << "Rental days: " << days << endl;
        cout << "Total rent: Rs. "
             << c.calculateRent(days) << endl;
    }
    else
    {
        Bike b(id, model);

        cout << "\n===== BIKE RENTAL BILL =====" << endl;
        b.display();
        cout << "Rental days: " << days << endl;
        cout << "Total rent: Rs. "
             << b.calculateRent(days) << endl;
    }

    return 0;
}