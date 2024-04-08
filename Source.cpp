/*
Program name: MonthlyBudget.cpp
Programmer:  Tyler Davies
Date: 9-4-21
Version: 1.0
Description: This program uses a structure to hold a list of expense categories and their max values.
             It passes the structure to three functions. The first function asks the user to enter the
             amounts spent in each budget category during a month. An added second function calculates
             the differences. The third function displays a report indicating whether the amount is over
             or under in each category, as well as the amount under or over for the entire monthly budget.
*/

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

//This structure holds the max value, actual cost, and difference for each of the expense categories.
struct Catagory
{
    const float MAX;
    float actualCost;
    float difference;
    string overUnder;

    //This function calculates the difference between the budget cost and the amount spent.
    void calcDifference()
    {
        difference = MAX - actualCost;
        if (difference < 0)
            overUnder = "over";
        else
            overUnder = "under";
    }
};

//This structure creates the expense categories and initializes the constant value MAX for each.
struct MonthlyBudget
{
    Catagory housing = { 500.0 }, utilities = { 150.0 }, householdExpenses = { 65.0 }, transportation = { 50.0 },
        food = { 250.0 }, medical = { 30.0 }, insurance = { 100.0 }, entertainment = { 150.0 },
        clothing = { 75.0 }, misc = { 50.0 }, total = { 1420 };

    //This function calculates the total cost spent for all categories.
    void calcTotalCost()
    {
        total.actualCost = housing.actualCost + utilities.actualCost + householdExpenses.actualCost + transportation.actualCost +
            food.actualCost + medical.actualCost + insurance.actualCost + entertainment.actualCost + clothing.actualCost + misc.actualCost;
    }
} monthlyBudget;    //Creates a monthly budget variable.

void GetAmountSpent(MonthlyBudget& budget);
void CalcAmountDifferences(MonthlyBudget& budget);
void PrintMonthlyBudgetReport(MonthlyBudget& budget);

int main()
{
    GetAmountSpent(monthlyBudget);
    CalcAmountDifferences(monthlyBudget);
    PrintMonthlyBudgetReport(monthlyBudget);

    exit(0);
}

//This functions prompts and asks the user to enter the amounts spent in each budget category during a month.
void GetAmountSpent(MonthlyBudget& budget)
{
    cout << "Enter the amount spent for Housing: ";
    cin >> budget.housing.actualCost;
    cout << "Enter the amount spent for Utilities: ";
    cin >> budget.utilities.actualCost;
    cout << "Enter the amount spent for Household Expenses: ";
    cin >> budget.householdExpenses.actualCost;
    cout << "Enter the amount spent for Transportation: ";
    cin >> budget.transportation.actualCost;
    cout << "Enter the amount spent for Food: ";
    cin >> budget.food.actualCost;
    cout << "Enter the amount spent for Medical: ";
    cin >> budget.medical.actualCost;
    cout << "Enter the amount spent for Insurance: ";
    cin >> budget.insurance.actualCost;
    cout << "Enter the amount spent for Entertainment: ";
    cin >> budget.entertainment.actualCost;
    cout << "Enter the amount spent for Clothing: ";
    cin >> budget.clothing.actualCost;
    cout << "Enter the amount spent for MISC: ";
    cin >> budget.misc.actualCost;
    cout << endl;

    budget.calcTotalCost();
}

//This function calculates the differences for each catagory.
void CalcAmountDifferences(MonthlyBudget& budget)
{
    budget.housing.calcDifference();
    budget.utilities.calcDifference();
    budget.householdExpenses.calcDifference();
    budget.transportation.calcDifference();
    budget.food.calcDifference();
    budget.medical.calcDifference();
    budget.insurance.calcDifference();
    budget.entertainment.calcDifference();
    budget.clothing.calcDifference();
    budget.misc.calcDifference();
    budget.total.calcDifference();
}

//This function displays a report indicating whether the amount is over or under in each category, as well as the amount under or over for the entire monthly budget.
void PrintMonthlyBudgetReport(MonthlyBudget& budget)
{
    cout << fixed << setprecision(2) << showpoint;
    cout << right << setw(45) << "Monthly Budget Report" << endl << endl;
    cout << left << setw(25) << "Category:" << setw(15) << "Budget:" << setw(15) << "Spent:" << "Over/Under:" << endl;
    cout << setw(25) << "Housing" << setw(15) << budget.housing.MAX << setw(15) << budget.housing.actualCost << budget.housing.overUnder << endl;
    cout << setw(25) << "Utilities" << setw(15) << budget.utilities.MAX << setw(15) << budget.utilities.actualCost << budget.utilities.overUnder << endl;
    cout << setw(25) << "Household Expenses" << setw(15) << budget.householdExpenses.MAX << setw(15) << budget.householdExpenses.actualCost << budget.householdExpenses.overUnder << endl;
    cout << setw(25) << "Transportation" << setw(15) << budget.transportation.MAX << setw(15) << budget.transportation.actualCost << budget.transportation.overUnder << endl;
    cout << setw(25) << "Food" << setw(15) << budget.food.MAX << setw(15) << budget.food.actualCost << budget.food.overUnder << endl;
    cout << setw(25) << "Medical" << setw(15) << budget.medical.MAX << setw(15) << budget.medical.actualCost << budget.medical.overUnder << endl;
    cout << setw(25) << "Insurance" << setw(15) << budget.insurance.MAX << setw(15) << budget.insurance.actualCost << budget.insurance.overUnder << endl;
    cout << setw(25) << "Entertainment" << setw(15) << budget.entertainment.MAX << setw(15) << budget.entertainment.actualCost << budget.entertainment.overUnder << endl;
    cout << setw(25) << "Clothing" << setw(15) << budget.clothing.MAX << setw(15) << budget.clothing.actualCost << budget.clothing.overUnder << endl;
    cout << setw(25) << "MISC" << setw(15) << budget.misc.MAX << setw(15) << budget.misc.actualCost << budget.misc.overUnder << endl;
    cout << setw(25) << "Total" << setw(15) << budget.total.MAX << setw(15) << budget.total.actualCost << budget.total.overUnder << endl << endl;
    cout << "You are " << budget.total.overUnder << " your monthly budget by " << abs(budget.total.difference) << " dollars." << endl;
}