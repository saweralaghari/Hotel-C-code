#include <iostream>
#include <iomanip> 
#include <string>
using namespace std;

const int MENU_SIZE = 5;


void displayHotelName() {
    cout << "=========================================" << endl;
    cout << "           WELCOME TO DELICIA HOTEL      " << endl;
    cout << "=========================================" << endl;
}


void displayMenu() {
    cout << "*****************************************" << endl;
    cout << " No     Menu Item            Price (Rs)" << endl;
    cout << "*****************************************" << endl;
    cout << " 1      Chicken Curry        700" << endl;
    cout << " 2      Mutton Curry         1000" << endl;
    cout << " 3      Chicken Achari       800" << endl;
    cout << " 4      Roti                 10" << endl;
    cout << " 5      Chapati              15" << endl;
    cout << "*****************************************" << endl;
}


void takeOrder(int no[], int qty[], string name[], long price[], float total[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Please enter your choice (" << i + 1 << ") = ";
        cin >> no[i];
        cout << "Enter the quantity = ";
        cin >> qty[i];

        
        switch (no[i]) {
            case 1:
                name[i] = "Chicken Curry";
                price[i] = 700;
                break;
            case 2:
                name[i] = "Mutton Curry";
                price[i] = 1000;
                break;
            case 3:
                name[i] = "Chicken Achari";
                price[i] = 800;
                break;
            case 4:
                name[i] = "Roti";
                price[i] = 10;
                break;
            case 5:
                name[i] = "Chapati";
                price[i] = 15;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
                i--; 
                continue;
        }
        total[i] = price[i] * qty[i]; 
    }
}


void displayOrder(int qty[], string name[], long price[], float total[], int n, float jum) {
    cout << "************** Order Summary **************" << endl;
    cout << setw(5) << "Qty" << setw(20) << "Item" << setw(12) << "Unit Price" << setw(15) << "Total Price" << endl;
    cout << "******************************************" << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(5) << qty[i] << setw(20) << name[i] << setw(12) << price[i] << setw(15) << total[i] << endl;
    }

    cout << "******************************************" << endl;
    cout << "Grand Total: Rs. " << jum << endl;
}


int main() {
    int n, no[MENU_SIZE], qty[MENU_SIZE];
    string name[MENU_SIZE];
    long price[MENU_SIZE];
    float total[MENU_SIZE] = {0}, jum = 0, pay, change;

    
    displayHotelName();
    displayMenu();

    cout << "How many dishes would you like to order? (1-" << MENU_SIZE << "): ";
    cin >> n;

    if (n <= 0 || n > MENU_SIZE) {
        cout << "Invalid number of dishes. Please enter a number between 1 and " << MENU_SIZE << "." << endl;
        return 1;
    }


    takeOrder(no, qty, name, price, total, n);


    for (int i = 0; i < n; i++) {
        jum += total[i];
    }

 
    system("cls");

    
    displayHotelName();
    displayMenu();
    displayOrder(qty, name, price, total, n, jum);

    
    cout << "Enter the amount you will pay: Rs. ";
    cin >> pay;

    if (pay >= jum) {
        change = pay - jum;
        cout << "Payment successful! Your change is: Rs. " << change << endl;
    } else {
        cout << "Insufficient payment. You still owe Rs. " << jum - pay << endl;
    }

    return 0;
}

