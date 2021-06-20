#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

// The purpose of this program is to help the user calculate the total cost of shipping an item
// depending on the cost of the actual item, the destination, and whether or not it is fFee.

// These variables are declared as constants to prevent any changes occurring to their values since
// the shipping costs and the range of the cost of the item they apply to will remain the same.
const double SMALL = 50.00, MED = 100.00, LARGE = 150.00, FREESHIP = 0.00;
const double USA1 = 6.00, USA2 = 9.00, USA3 = 12.00;
const double CAN1 = 8.00, CAN2 = 12.00, CAN3 = 15.00;
const double AUS1 = 10.00, AUS2 = 14.00, AUS3 = 17.00;

// An item may or may not be fragile, so this variable may change.
double fFee = 2.00;

// Constant to print variable to file Order.txt
const string myFile = "Order.txt";

int main()
{
    // Variable declarations
    string itemName, destination;
    char fragile;
    double orderTotal, shipCost, totalShip;

    // Variable declaration to have program write out to Order.txt
    ifstream fs;
    fs.open(myFile, ios::out);


        // Title to give the user a clue into what this program entails. Setfill and setw used to
        // distinguish title from the rest of the program.
        cout << setw(58) << setfill('.') << "" << endl;
        cout << "ITCS 2530 - Programming Assignment for week #3" << endl;
        cout << setw(58) << setfill('.') << "" << endl;

        //// Print title to Order.txt
        //myFile << setw(58) << setfill('.') << "" << endl;
        //myFile << "ITCS 2530 - Programming Assignment for week #3" << endl;
        //myFile << setw(58) << setfill('.') << "" << endl;

        cout << "Please enter the item name (no spaces)" << setw(20) << ":";
        cin >> itemName;

        // This will determine whether the $2.00 fee needs to be added for a fragile item.
        cout << "Is the item fragile? (y=yes/n=no)" << setw(25) << ":";
        cin >> fragile;

        // This is a structure that will decide the value of fFee or end the program if
        // the user enters an invalid value for line 38.
        switch (fragile)
        {
            // This structure will accept answers of either case, upper or lower.
        case 'y':
        case 'Y':
            // The fragile fee will remain $2.00 in the case of the item being fragile.
            break;

        case 'n':
        case 'N':
            // The shipping cost is not upcharged if the item is not fragile.
            fFee = 0;
            break;

        default:
            cout << endl; // blank line
            // Here is where the program will end upon an invalid entry.
            cout << "Invalid entry, exiting" << endl;
            return 0;

        }

        // Order total will determine the cost of shipping without the added fee for a fragile item.
        cout << "Please enter your order total" << setw(29) << ":";
        cin >> orderTotal;

        // The destination will also be a factor in determining the cost of shipping.
        cout << "Please enter destination. (usa/can/aus)" << setw(19) << ":";
        cin >> destination;

        // Nested if-structures are used to determine shipping cost since 2 factors are used
        // which are destination and cost of the item. 3 different countries and 4 separate price
        // ranges are specified.
        if (destination == "usa")
        {
            if (orderTotal <= SMALL)
            {
                shipCost = USA1;
            }
            else if ((orderTotal > SMALL) && (orderTotal <= MED))
            {
                shipCost = USA2;
            }
            else if ((orderTotal > MED) && (orderTotal <= LARGE))
            {
                shipCost = USA3;
            }
            else
            {
                shipCost = FREESHIP;
            }

        }
        else if (destination == "can")
        {
            if (orderTotal <= SMALL)
            {
                shipCost = CAN1;
            }
            else if ((orderTotal > SMALL) && (orderTotal <= MED))
            {
                shipCost = CAN2;
            }
            else if ((orderTotal > MED) && (orderTotal < LARGE))
            {
                shipCost = CAN3;
            }
            else
            {
                shipCost = FREESHIP;
            }
        }
        else if (destination == "aus")
        {
            if (orderTotal <= SMALL)
            {
                shipCost = AUS1;
            }
            else if ((orderTotal > SMALL) && (orderTotal <= MED))
            {
                shipCost = AUS2;
            }
            else if ((orderTotal > MED) && (orderTotal < LARGE))
            {
                shipCost = AUS3;
            }
            else
            {
                shipCost = FREESHIP;
            }

        }
        // The program will also end in the case of an invalid entry for the destination of the item as well.
        else
        {
            cout << endl; // blank line
            cout << "Invalid entry, exiting" << endl;
            return 0;
        }

        // The following 2 lines capitalize all strings through the rest of the program.
        transform(itemName.begin(), itemName.end(), itemName.begin(), ::toupper);
        transform(destination.begin(), destination.end(), destination.begin(), ::toupper);

        // The total cost of the item, shipping, and possible fee if the item is fragile is calculated.
        shipCost = shipCost + fFee;
        totalShip = shipCost + orderTotal;

        // This line formats all decimals to be to 2 places.
        cout << fixed << showpoint << setprecision(2) << endl;

        // Info entered by user as well as info determined by the program will be printed for the user.
        cout << "Your item is" << setw(55) << itemName << endl;

        cout << "Your shipping cost is" << setw(38) << "$" << shipCost << endl;

        cout << "You are shipping to" << setw(42) << destination << endl;

        cout << "Your total shipping costs are" << setw(30) << "$" << totalShip << endl;

        cout << endl; // blank line

        cout << setw(68) << setfill('.') << "Thank you!" << endl;


        // Output results of program to Order.txt file
        myFile << "Your item is" << setw(55) << itemName << endl;

        myFile << "Your shipping cost is" << setw(38) << "$" << shipCost << endl;

        myFile << "You are shipping to" << setw(42) << destination << endl;

        myFile << "Your total shipping costs are" << setw(30) << "$" << totalShip << endl;

        myFile << endl; // blank line

        myFile << setw(68) << setfill('.') << "Thank you!" << endl;

        // Writing out program to Order.txt has completed, so it must be closed out.
        fs.close();

    return 0;
    // End program
}

