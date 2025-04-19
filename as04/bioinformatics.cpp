/*
   Fall 2024 CS-11
   Assignment 04: Bioinformatics
   Task: User inputs dna sequence of G's, C'S, A's, and T's.
         Program will outpout the input's compliment, G and
         C count, as well as it's reverse compliment.
   Resources Used: vowel_functions.cpp, rosalind.py (from CS12P),
   https://cplusplus.com/reference/algorithm/reverse/
*/

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

/*
   Calculates and returns the complement of a DNA sequence.
   In DNA sequences, 'A' and 'T' are complements of each other,
   as are 'C' and 'G'. The complement is formed by taking the
   complement of each symbol (e.g., the complement of "GTCA" is "CAGT").

   @param dna - A string representing a DNA sequence of arbitrary length,
                containing only the characters A, C, G and T.

   @return a string representation of the complement of the given sequence
*/

// Use censored function in vowel_functions.cpp
string complement(string dna) {
    for(int i = 0; i < dna.length(); i++) {
        if(dna.at(i) == 'A') {
            dna.at(i) = 'T';
        }else if (dna.at(i) == 'T') {
            dna.at(i) = 'A';
        }else if (dna.at(i) == 'G') {
            dna.at(i) = 'C';
        }else if (dna.at(i) == 'C') {
            dna.at(i) = 'G';
        }
    }
    return dna;
}

/*
   The GC-content of a DNA sequence is given by the percentage of symbols
   in the sequence that are 'C' or 'G'.
   For example, the GC-content of "AGCTATAG" is .375 (37.5%).

   @param dna - a string representing a DNA sequence of arbitrary length,
                containing only the characters A, C, G and T.

   @return the GC-content of the sequence, to double precision.
*/

// Use vowelContent in vowel_functions.cpp
double gcContent(string dna) {
    int gcCount = 0;

    if(dna.length() == 0) {
        return (double) 0;
    }

    for (int i = 0; i < dna.length(); i++) {
        if (dna.at(i) == 'C' || dna.at(i) == 'G') {
            gcCount++;
        }
    }
    return (double) gcCount / dna.length();
}

/*
   Calculates and returns the reverse complement of a DNA sequence.
   In DNA sequences, 'A' and 'T' are complements of each other,
   as are 'C' and 'G'. The reverse complement is formed by
   reversing the symbols of a sequence, then taking the complement of each
   symbol (e.g., the reverse complement of "GTCA" is "TGAC").

   @param dna - a string representing a DNA sequence of arbitrary length,
                containing only the characters A, C, G and T

   @return a string representation of the reverse complement of the given
   sequence
*/

string reverseComplement(string dna) {
    complement(dna);
    for(int i = 0; i < dna.length(); i++) {
        if(dna.at(i) == 'A') {
            dna.at(i) = 'T';
        }else if (dna.at(i) == 'T') {
            dna.at(i) = 'A';
        }else if (dna.at(i) == 'C') {
            dna.at(i) = 'G';
        }else if (dna.at(i) = 'G') {
            dna.at(i) = 'C';
        }
    }

    reverse(dna.begin(), dna.end());

    return dna;
}

int main() {
    string user_dna_input;

    cout << "Input DNA String: " << endl;

    if(cin >> user_dna_input) {
        cout << left << setw(22) << "Complement: " <<
        complement(user_dna_input) << endl;

        cout << left << setw(22) << "GC-content: " << fixed << setprecision(4)
        << gcContent(user_dna_input) << endl;

        cout << left << setw(22) << "Reverse Complement: " <<
        reverseComplement(user_dna_input) << endl;
    }else{
        return 0;
    }

}

