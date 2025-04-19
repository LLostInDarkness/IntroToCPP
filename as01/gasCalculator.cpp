/*
  Fall 2024 CS-11
  Assignment 01: Gas Calculator
  Program asks user to input three numbers which is the calcuated to see how much will it cost the
  user to drive for their gas car tgrip.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Variables as doubles
    double cost_per_gal;
    double mpg;
    double trip_miles;

    // Prompts for User Input
    cout << "Cost Per Gallon of Gas: \n";
    cin >> cost_per_gal;
    cout << "How Many Miles Per Gallon? \n";
    cin >> mpg;
    cout << "How Many Miles Are in this Trip? \n";
    cin >> trip_miles;

    // Arithmetic
    double total;
    double miles;
    miles = trip_miles / mpg;
    total = miles * cost_per_gal;

    cout << "It will cost you $" << fixed << setprecision(2) << total
    << " for your trip." << endl;
    return 0;
}
