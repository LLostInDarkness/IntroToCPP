/*
  Fall 2024 CS-11
  Assignment 02: Taxes
  Source(s): N/A
  - Write a program named taxes.cpp that calculates the total income tax
    using the provided California 2023 Tax Rate Schedule
  - Prompt for a decimal input (the gross income for that year)
  - OUTPUT: The amount owed after the tax deduction
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {

    double gross_income, tax, total_tax, new_income;

    double income1 = 10412;
    double income2 = 24684;
    double income3 = 38959;
    double income4 = 54081;
    double income5 = 68350;
    double income6 = 349137;
    double income7 = 418961;
    double income8 = 698271;

    double two_pct_tax = 104.12;
    double four_pct_tax = 389.56;
    double six_pct_tax = 960.56;
    double eight_pct_tax = 1867.88;
    double nine_three_pct_tax = 3009.40;
    double ten_three_pct_tax = 29122.59;
    double eleven_three_pct_tax = 36314.46;
    double twelve_three_pct_tax = 67876.49;

    cout << "Please enter your gross income for the year: $";
    cin >> gross_income;

    // Taxes Bracket If Statements
    if (gross_income >= 0 && gross_income <= income1) {		    // 1%
        total_tax = gross_income * 0.01;
    }else if (gross_income > income1 && gross_income <= income2) {  // 2%
        new_income = gross_income - income1;
        tax = new_income * 0.02;
        total_tax = tax + two_pct_tax;
    }else if(gross_income > income2 && gross_income <= income3) {   // 4%
        new_income = gross_income - income2;
        tax = new_income * 0.04;
        total_tax = tax + four_pct_tax;
    }else if (gross_income > income3 && gross_income <= income4) {  // 6%
        new_income = gross_income - income3;
        tax = new_income * 0.06;
        total_tax = tax + six_pct_tax;
    }else if(gross_income > income4 && gross_income <= income5) {   // 8%
        new_income = gross_income - income4;
        tax = new_income * 0.08;
        total_tax = tax + eight_pct_tax;
    }else if(gross_income > income5 && gross_income <= income6) {   // 9.3%
        new_income = gross_income - income5;
        tax = new_income * 0.093;
        total_tax = tax + nine_three_pct_tax;
    }else if (gross_income > income6 && gross_income <= income7) {  // 10.3%
        new_income = gross_income - income6;
        tax = new_income * 0.103;
        total_tax = tax + ten_three_pct_tax;
    }else if(gross_income > income7 && gross_income <= income8) {   // 11.3%
        new_income = gross_income - income7;
        tax = new_income * 0.113;
        total_tax = tax + eleven_three_pct_tax;
    }else if (gross_income > income8) {    			    // 12.3%
        new_income = gross_income - income8;
        tax = new_income * 0.123;
        total_tax = tax + twelve_three_pct_tax;
    }

    cout << "You will have to pay $" << fixed << setprecision(2)
    << round(total_tax) << " to the government.\n";

    // Test Prompts
    // cout << "New_Income Var: " << new_income << endl;
    // cout << "Tax Var: " << tax << endl;
    // cout << "Total Tax Var: " << total_tax << endl;

    return 0;
}
