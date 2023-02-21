/*								TDA Rational
You were invited to do a little job for your Mathematic teacher. The job is to read a Mathematic expression in format of two rational numbers (numerator / denominator) and present the result of the operation. Each operand or operator is separated by a blank space. The input sequence (each line) must respect the following format: number, (‘/’ char), number, operation char (‘/’, ‘*’, ‘+’, ‘-‘), number, (‘/’ char), number. The answer must be presented followed by ‘=’ operator and the simplified answer. If the answer can’t be simplified, it must be repeated after a ‘=’ operator.

Considering N1 and D1 as numerator and denominator of the first fraction, follow the orientation about how to do each one of these 4 operations:

Sum: (N1*D2 + N2*D1) / (D1*D2)
Subtraction: (N1*D2 - N2*D1) / (D1*D2)
Multiplication: (N1*N2) / (D1*D2)
Division: (N1/D1) / (N2/D2), that means (N1*D2)/(N2*D1)

Input
The input contains several cases of test. The first value is an integer N (1 ≤ N ≤ 1*104), indicating the amount of cases of test that must be read. Each case of test contains a rational value X (1 ≤ X ≤ 1000), an operation (-, +, * or /) and another rational value Y (1 ≤ Y ≤ 1000).

Output
The output must be a rational number, followed by a “=“ sign and another rational number, that is the simplification of the first value. In case of the first value can’t be simplified, the same value must be repeated after the ‘=’ sign.

Input Sample:				Output Sample:
4                       		
1 / 2 + 3 / 4                           10/8 = 5/4
1 / 2 - 3 / 4                           -2/8 = -1/4
2 / 3 * 6 / 6                           12/18 = 2/3
1 / 2 / 3 / 4				4/6 = 2/3

*/


#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;



// Function that returns the simplified form of a request
string simplified(int numerator, int denominator) {
    int factor = 2;
    while (factor <= numerator || factor <= denominator) {
        if (numerator % factor == 0 && denominator % factor == 0) {
            numerator /= factor;
            denominator /= factor;
        }
        else {
            factor++;
        }
    }
    return to_string(numerator) + "/" + to_string(denominator);
}

// Function that performs arithmetic operations between fractions
string account(int denominator1, int numerator1, int denominator2, int numerator2, char symbol) {
    int numerator, denominator;
    string result;
    if (symbol == '+') {
        denominator = denominator1 * denominator2;
        numerator = (denominator / denominator1) * numerator1 + (denominator / denominator2) * numerator2;
    }
    else if (symbol == '-') {
        denominator = denominator1 * denominator2;
        numerator = (denominator / denominator1) * numerator1 - (denominator / denominator2) * numerator2;
    }
    else if (symbol == '*') {
        numerator = numerator1 * numerator2;
        denominator = denominator1 * denominator2;
    }
    else {
        numerator = numerator1 * denominator2;
        denominator = denominator1 * numerator2;
    }
    result = to_string(numerator) + "/" + to_string(denominator) + " = " + simplified(numerator, denominator);
    return result;
}

int main() {
    int cases;
    vector<string> answers;

    cin >> cases;

    for (int i = 0; i < cases; i++) {
        int denominator1, numerator1, denominator2, numerator2;
        char a, b, symbol;
        cin >> numerator1 >> a >> denominator1 >> symbol >> numerator2 >> b >> denominator2;
        answers.push_back(account(denominator1, numerator1, denominator2, numerator2, symbol));
    }

    for (const auto& answer : answers) {
        cout << answer << endl;
    }

    return 0;
}
