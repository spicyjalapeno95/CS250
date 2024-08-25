#include "InvestmentAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

InvestmentAccount::InvestmentAccount() {}

InvestmentAccount::InvestmentAccount(double t_initialInvestment, double t_monthlyDeposit, double t_annualInterest, double t_numYears) { //Set each of the variables to the contructor
    initialInvestment = t_initialInvestment;
    monthlyDeposit = t_monthlyDeposit;
    annualInterest = t_annualInterest;
    numYears = t_numYears;
}

double InvestmentAccount::getInitialInvestment() {//Use accessors to use private variables
    return initialInvestment;
}

double InvestmentAccount::getMonthlyDeposit() {
    return monthlyDeposit;
}

double InvestmentAccount::getNumYears() {
    return numYears;
}

double InvestmentAccount::getAnnualInterest() {
    return annualInterest;
}

void InvestmentAccount::printUserInput() { //Create the main menu input
    cout << "*************************************" << endl;
    cout << "***************Data Input************" << endl;
    cout << "Initial Investment Amount: $";
    cin >> initialInvestment;
    cout << endl;
    while (initialInvestment < 1) { //Creates a check for the initial investment to repeat until number is above 0.
        cout << "Please enter a number higher than 0 to begin your investment process, thank you.";
        cin >> initialInvestment;
        cout << endl;
    }

    cout << "Monthly Deposit: $";
    cin >> monthlyDeposit;
    cout << endl;
    while (monthlyDeposit < 0) { //Checks for the monthly deposit to be higher than 0
        cout << "The monthly deposit has to be 0 or greater, please try again.";
        cin >> monthlyDeposit;
        cout << endl;
    }

    cout << "Annual Interest: %"; 
    cin >> annualInterest;
    cout << endl;
    annualInterest = annualInterest / 100.0; //Converts to a decimal to use in calculations later

    cout << "Number of Years: ";
    cin >> numYears;
    cout << endl;

    cout << "Press any key to continue . . ." << endl;
}

void InvestmentAccount::printReports() { //Display all data from above function
    double yearEndBalance;
    double yearEarnedInterest;

    // Report without additional monthly deposits
    cout << "=========================================================" << endl;
    cout << "   Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "=========================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "---------------------------------------------------------" << endl;

    yearEndBalance = initialInvestment;
    for (int i = 0; i < numYears; ++i) { //For loop continues until number of years are reached
        yearEarnedInterest = yearEndBalance * annualInterest;
        yearEndBalance += yearEarnedInterest;
        cout << (i + 1) << "\t$" << fixed << setprecision(2) << yearEndBalance //use setprecision to get two decimal places
            << "\t\t$" << fixed << setprecision(2) << yearEarnedInterest << endl;
    }

    cout << endl;

    // Report with additional monthly deposits
    cout << "=========================================================" << endl;
    cout << "   Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "=========================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;
    cout << "---------------------------------------------------------" << endl;

    yearEndBalance = initialInvestment;
    for (int i = 0; i < numYears; ++i) { //Loops through the number of years
        yearEarnedInterest = 0;
        for (int j = 0; j < 12; ++j) { //Breaks it farther down into months to get total amount with monthly deposits.
            double monthlyInterest = (yearEndBalance + monthlyDeposit) * (annualInterest / 12);
            yearEarnedInterest += monthlyInterest;
            yearEndBalance += monthlyDeposit + monthlyInterest;
        }
        cout << (i + 1) << "\t$" << fixed << setprecision(2) << yearEndBalance
            << "\t\t$" << fixed << setprecision(2) << yearEarnedInterest << endl;
    }
}