// File Name: assign1_h_k40.cpp
//
// Author: Harkiran Kaur
// Date: 9/13/2019
// Assignment Number: 1
// CS 2308.005 Fall 2019
// Instructor: J. Marcos Palacios
//
// The program shows the user different Apple products offered by the vending
// machine, allows the user to select multiple items from the menu (by number),
// and calculates and prints the bill (including sub-total, tax, and total.
// The program also asks the user to enter a new order or exit after the first
// input. Once the user selects exit, the program outputs the total amount of
// money taken in (the sum of all orders) and outputs the description and count
// of the item that was ordered most frequently. The program stores menu
// information and order count in an array of structures, named menuItem.

#include <iostream>
#include <iomanip>

using namespace std;

struct menuItem
{
    string description;
    float price;
    int num_times;
};

menuItem menuList[6] =  {
                        {"Macbook Air" , 1099.00, 0},
                        {"MacBook Pro" , 1299.00, 0},
                        {"iPad Air" , 499.00, 0},
                        {"iPad Pro 11-in" , 799.00, 0},
                        {"iPad Pro 12.9-in" , 999.00, 0},
                        {"Watch S4" , 399.00, 0}
                        };

void displayMenu ();
void printCheck (float grand_total , struct menuItem menuList[]);
void getTotals (float subtotal , float & grand_total);

int main ()
{
    int order; //allows user to input item number for order and quit
    float subtotal = 0; //temporary holder before user chooses menu items
    float grand_total = 0; //temporary holder that calculates end of day total
    char new_order; // allows user to select new order or exit based on input

    displayMenu ();

    cout << "Input the item numbers for the order, 0 to quit" << endl;

    while (cin >> order)
    {
        switch(order)
        {
            case 0 :
            getTotals(subtotal, grand_total);
            cout << "Please enter 'N' to take a new order and 'E' to exit: ";
            cin >> new_order;
            if ( new_order == 'N' || new_order == 'n')
            {
                subtotal = 0; //temporary holder for new order subtotal
                displayMenu ();
                cout << "Input the item numbers for the order, 0 to quit"
                     << endl;
            }
            else if ( new_order == 'E' || new_order == 'e')
            {
                printCheck (grand_total, menuList);
                return 0;
            }
            else
            {
                cout << "*Error: Please enter 'N' to take a new order ";
                cout << "and 'E' to exit." << endl;
            }
            break;
            case 1 :
                subtotal += menuList[0].price;
                menuList[0].num_times++;
                break;
            case 2 :
                subtotal += menuList[1].price;
                menuList[1].num_times++;
                break;
            case 3 :
                subtotal += menuList[2].price;
                menuList[2].num_times++;
                break;
            case 4 :
                subtotal += menuList[3].price;
                menuList[3].num_times++;
                break;
            case 5 :
                subtotal += menuList[4].price;
                menuList[4].num_times++;
                break;
            case 6 :
                subtotal += menuList[5].price;
                menuList[5].num_times++;
                break;
            default :
                cout << "*Error: There is no item " << order << "." << endl;
                cout << "Processing other items..." << endl;
                break;
        }
    }
    return 0;

}

//***********************************************************
// displayMenu: displays menu (descriptions and prices only)
//***********************************************************

void displayMenu ()
{
    for (int i = 0;i<6;i++)
    {
        cout << "[" << i+1 << "] " << setw(20) << left
             << menuList[i].description << "$" << setw(7) << fixed
             << setprecision(2) << right << menuList[i].price << endl;
    }
}

//***********************************************************
// getTotals: takes order and calculates subtotal, tax, and total
// subtotal the calculated subtotal of the items
// grand_total used to calculate the total sales at the end of day
//***********************************************************

void getTotals(float subtotal, float & grand_total)
{
    float tax = subtotal*.0825;
    float total = tax + subtotal;
    cout << "Subtotal...$" << setw(8) << setprecision(2) << right
         << subtotal << endl; //subtotal;
    cout << "Tax........$" << setw(8) << setprecision(2) << right
         << tax << endl; //tax;
    cout << "Total......$" << setw(8) << setprecision(2) << right
         << total << endl << endl;
    grand_total += total;
}

//***********************************************************
// printCheck: finds the index of the item with the highest count
// grand_total used to calculate the total sales at the end of day
// menuList the array of menuItem information
//***********************************************************

void printCheck (float grand_total, struct menuItem menuList[])
{
    cout << "*** End of Day:" << endl;
    cout << "Total sales: $" << grand_total << endl;

    int max = 0;
    int location =  0;

    for (int i=0; i<7; i++)
    {
        if (menuList[i].num_times > max)
        {
            max = menuList[i].num_times;
            location = i;
        }
    }
    cout << "Item ordered most often: " << menuList[location].description
         << " was purchased " << menuList[location].num_times << " times."
         << endl;
}
