#include <iostream>
#include <string>
#include <vector>
using namespace std;


const int MIN_SENIOR_CITIZENS = 10;
const int MAX_SENIOR_CITIZENS = 36;

int getInput(int min, int max) {
    int value;
    do {
        cout << "Enter the number of senior citizens (10-36): ";
        cin >> value;
        if (value < min || value > max) {
            cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << endl;
        }
    } while (value < min || value > max);
    return value;
}

int getCarers(int num) {
    int val = 2;
    if (num > 24) {
        val += 1;
    }
    return val;
 }

float calculateTotalCost(int num) {

    double coachCost = 150; 
    double mealCost = 14.00;
    double theatreTicketCost = 21; // default cost for 12-16
    int elders = num - 2;

    if (num >= 17 && num <= 26) {
        coachCost = 190;
        mealCost = 13.50;
        theatreTicketCost = 20;
    }
    else if (num >= 27 && num<= 39) {
        coachCost = 225;
        mealCost = 13;
        theatreTicketCost = 19;
        elders -=1;
    }

    return coachCost + (elders * mealCost) + (elders * theatreTicketCost);
}

void recordParticipants(vector<string>& names, vector<double>& payments, int numberOfSeniorCitizens) {
    cout << "Recording participants:" << endl;
    for (int i = 0; i < numberOfSeniorCitizens; ++i) {
        string name;
        cout << "Enter name of senior citizen " << i + 1 << ": ";
        cin >> name;
        names.push_back(name);
        float payment;
        cout << "Enter payment made by " << name << ": $";
        cin >> payment;
        payments.push_back(payment);
    }
}

float calculateTotalCollected(const vector<double>& payments) {
    float total = 0;
    for (float payment : payments) {
        total += payment;
    }
    return total;
}

void printParticipants(const vector<string>& names, const vector<double>& payments) {
    cout << "\nList of participants:" << endl;
    for (size_t i = 0; i < names.size(); ++i) {
        cout << names[i] << " - Paid: $" << payments[i] << endl;
    }
}

void calculateProfit(double totalCost, double totalCollected) {
    cout << "\n Calculate break-even point or profit" << endl;
    double profit = totalCollected - totalCost;
    if (profit >= 0) {
        cout << "The outing has made a profit of $" << profit << endl;
    }
    else {
        cout << "The outing has not made a profit. It is short by $" << -profit << " to break even." << endl;
    }
}

int main() {
    // Task 1
    cout << " Calculate total cost of the outing" << endl;
    int numberOfSeniorCitizens = getInput( MIN_SENIOR_CITIZENS, MAX_SENIOR_CITIZENS);
    int numberOfCarers = getCarers(numberOfSeniorCitizens);
    int totalMembers = numberOfCarers + numberOfSeniorCitizens;
    double totalCost = calculateTotalCost(totalMembers);
    cout << "Total cost of the outing: $" << totalCost << endl;

    // Task 2
    vector<string> participantNames;
    vector<double> payments;
    recordParticipants(participantNames, payments, numberOfSeniorCitizens);
    double totalCollected = calculateTotalCollected(payments);
    cout << "Total amount collected: $" << totalCollected << endl;
    printParticipants(participantNames, payments);

    // Task 3
    calculateProfit(totalCost, totalCollected);

    return 0;
}
