/*
  Fall 2024 CS-11-01
  Assignment 03 - Postal Code
  Author: Rebecca (Ren) Negrete
  Source(s): Zybooks 4.3.1 Code (used as reference) & char_add.cpp
  Task: Input Zipcode and the output will be the zipcode with a check digit
  translated to a barcode using colons (:) as half bars and pipes (|) as
  full bars.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    const string BAR0 = "||:::";
    const string BAR1 = ":::||";
    const string BAR2 = "::|:|";
    const string BAR3 = "::||:";
    const string BAR4 = ":|::|";
    const string BAR5 = ":|:|:";
    const string BAR6 = ":||::";
    const string BAR7 = "|:::|";
    const string BAR8 = "|::|:";
    const string BAR9 = "|:|::";

    string check = "";
    string bars = "";

    int check_digit = 0;
    int sum = 0;
    string zipcode;

    cout << "Input Zipcode: ";
    cin >> zipcode;

    for (int i = 0; i < zipcode.length(); i++) {
        if (zipcode.substr(i,1) == "0") {
            bars = bars + BAR0;
        }else if (zipcode.substr(i,1) == "1") {
            bars = bars + BAR1;
        }else if (zipcode.substr(i,1) == "2") {
            bars = bars + BAR2;
        }else if (zipcode.substr(i,1) == "3") {
            bars = bars + BAR3;
        }else if (zipcode.substr(i,1) == "4") {
            bars = bars + BAR4;
        }else if (zipcode.substr(i,1) == "5") {
            bars = bars + BAR5;
        }else if (zipcode.substr(i,1) == "6") {
            bars = bars + BAR6;
        }else if (zipcode.substr(i,1) == "7") {
            bars = bars + BAR7;
        }else if (zipcode.substr(i,1) == "8") {
            bars = bars + BAR8;
        }else if (zipcode.substr(i,1) == "9") {
            bars = bars + BAR9;
        }
    }

    for (int j = 0; j < zipcode.length(); j++) {
        sum = sum + (zipcode.at(j) - '0');

        if(sum % 10 == 0) {
            check_digit == 0;
            check = BAR0;
        }else{
            check_digit = 10 - (sum %10);

            if(check_digit == 9) {
                check = BAR9;
            }else if (check_digit == 8) {
                check = BAR8;
            }else if (check_digit == 7) {
                check = BAR7;
            }else if (check_digit == 6) {
                check = BAR6;
            }else if (check_digit == 5) {
                check = BAR5;
            }else if (check_digit == 4) {
                check = BAR4;
            }else if (check_digit == 3) {
                check = BAR3;
            }else if (check_digit == 2) {
                check = BAR2;
            }else if (check_digit == 1) {
                check = BAR1;
            }
        }
    }

    cout <<"Barcode:" << "|" << bars << check << "|" << endl;

    return 0;
}
