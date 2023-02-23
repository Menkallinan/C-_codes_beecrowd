/*							Banknotes and Coins
Read a value of floating point with two decimal places. This represents a monetary value. After this, calculate the smallest possible number of notes and coins on which the value can be decomposed. The considered notes are of 100, 50, 20, 10, 5, 2. The possible coins are of 1, 0.50, 0.25, 0.10, 0.05 and 0.01. Print the message “NOTAS:” followed by the list of notes and the message “MOEDAS:” followed by the list of coins.

Input
The input file contains a value of floating point N (0 ≤ N ≤ 1000000.00).

Output
Print the minimum quantity of banknotes and coins necessary to change the initial value, as the given example.

Input Sample:				Output Sample:
576.73					NOTAS:
					5 nota(s) de R$ 100.00
					1 nota(s) de R$ 50.00
					1 nota(s) de R$ 20.00
					0 nota(s) de R$ 10.00
					1 nota(s) de R$ 5.00
					0 nota(s) de R$ 2.00
					MOEDAS:
					1 moeda(s) de R$ 1.00
					1 moeda(s) de R$ 0.50
					0 moeda(s) de R$ 0.25
					2 moeda(s) de R$ 0.10
					0 moeda(s) de R$ 0.05
					3 moeda(s) de R$ 0.01
*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int coin[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 25, 10, 5, 1};
    vector<int> amount(12, 0);
    double value;
    cin >> value;
    int money = round(value * 100);

    int i = 0;
    while(money > 0){
        if(money >= coin[i]){
            amount[i]++;
            money = money - coin[i];
        }
        else
            i++;
    }
    cout << "NOTAS:" << endl;
    for(int i = 0; i < 6; i++){
        double note_value = coin[i] / 100.0;
        printf("%d nota(s) de R$ %.2f\n", amount[i], note_value);
    }
    cout << "MOEDAS:" << endl;
    for(int i = 6; i < 12; i++){
        double coin_value = coin[i] / 100.0;
        printf("%d moeda(s) de R$ %.2f\n", amount[i], coin_value);
    }
    return 0;
}

