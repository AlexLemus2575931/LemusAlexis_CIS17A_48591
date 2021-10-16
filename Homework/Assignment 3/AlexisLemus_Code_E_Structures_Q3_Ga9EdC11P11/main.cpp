 /* 
 * File: Code-E Chapter 11 Structures Q1  
 * Author: Alexis Lemus
 * Created on 10/6/2021
 * Purpose: Determine a student's budget
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct MonthlyBudget {
    float housing;      // Housing costs
    float utilts;       // Utilities
    float hExpns;       // Household Expenses
    float transp;       // Transportation
    float food;         // Food 
    float med;          // Medical
    float insur;        // Insurance
    float entrnmt;      // Entertainment
    float clothes;      // Clothing
    float misc;         // Miscellaneous
};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getData(MonthlyBudget&);       // Getting money spent.
void change(float&, float&);        // To adjust structure members.
void prntRes(MonthlyBudget&);       // Printing results.
void result(float);                 // To print even, over, under.

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variable Data Types and Constants
    MonthlyBudget budget = { 500, 150, 65, 50, 250,
                             30, 100, 150, 75, 50}; 
    
    //Process or map Inputs to Outputs
    getData(budget);
    
    //Display Outputs
    prntRes(budget);

    //Exit stage right!
    return 0;
}

void getData(MonthlyBudget& bud) {
    // Declaring variable to augment the structure with user inputs.
    float adjust;       // Budget adjuster.
    
    cout << "Enter housing cost for the month:$" << endl;
    cin >> adjust;
    change(bud.housing, adjust);
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> adjust;
    change(bud.utilts, adjust);
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> adjust;
    change(bud.hExpns, adjust);
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> adjust;
    change(bud.transp, adjust);
    cout << "Enter food cost for the month:$" << endl;
    cin >> adjust;
    change(bud.food, adjust);
    cout << "Enter medical cost for the month:$" << endl;
    cin >> adjust;
    change(bud.med, adjust);
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> adjust;
    change(bud.insur, adjust);
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> adjust;
    change(bud.entrnmt, adjust);
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> adjust;
    change(bud.clothes, adjust);
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> adjust;
    change(bud.misc, adjust);
}

void change(float& member, float& adjust) {
    member -= adjust;
    adjust = 0;     // Reset adjuster to zero. 
}

void prntRes(MonthlyBudget& bud) {
    float total;        // To hold total budget.
    
    total = bud.housing+bud.utilts+bud.hExpns+bud.transp+bud.food+
            bud.med+bud.insur+bud.entrnmt+bud.clothes+bud.misc;
            
    cout << "Housing ";
    result(bud.housing);
    cout << "Utilities ";
    result(bud.utilts);
    cout << "Household Expenses ";
    result(bud.hExpns);
    cout << "Transportation ";
    result(bud.transp);
    cout << "Food ";
    result(bud.food);
    cout << "Medical ";
    result(bud.med);
    cout << "Insurance ";
    result(bud.insur);
    cout << "Entertainment ";
    result(bud.entrnmt);
    cout << "Clothing ";
    result(bud.clothes);
    cout << "Miscellaneous ";
    result(bud.misc);
    
    // Display total budget
    cout << fixed << showpoint << setprecision(2);
    cout << "You were $";
    if  (total > 0)
        cout << total << " under budget";
    else
        cout << (total * -1) << " over budget";
    
}

void result(float member) {
    if (member > 0)
        cout << "Under";
    else if (member == 0)
        cout << "Even";
    else
        cout << "Over";
    
    cout << endl;
}