// ATM System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<conio.h> // getch function
#include <iostream> 
#include<string>  //string

using namespace std;

/*Mini Project - ATM
-> Check Balance
-> Cash Withdraw
-> User Details
-> Update Mobile No.
*/

class atm {                 //class atm
private:                    //private member variables
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;

public:                     //public member functions
    //setData function is setting data in to the private member variables;
    void setData(long int account_No_a, string name_a, int PIN_a, 
        double balance_a, string mobile_No_a)
    {
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_No = mobile_No_a;
    }
    //getAccountNo function is returning the user's account no.
    long int getAccountNo() {

        return account_No;
    }
    //getName function is returning the user's Name
    string getName() {
        return name;
    }
    //getPin function is returning the user's Pin
    int getPin() {
        return PIN;
    }
    //getBalance function is returning the user's Balance
    double getBalance() {
        return balance;
    }
    //getMobileNo function is returning the user's mobile number
    string getMobileNo() {
        return mobile_No;
    }
    //setMobile function is Updating the user mobile no
    void setMobile(string mob_prev, string mob_new) {
        if (mob_prev == mobile_No) {      //chech old mobile no.
            mobile_No = mob_new;  //Update with new, if old
            //matches 
            cout << endl << "Successfully Updated Mobile no.";
            cin.ignore();  // Clear the input buffer
            cin.get();   // Waits for Enter
        }
        else {
            cout << endl << "Incorrect !!! Old Mobile no";
            cin.ignore();  // Clear the input buffer
            cin.get();   // Waits for Enter
        }
    }
    // this function is udes to withdraw money from atm
    void cashWithDraw(int amount_a) {
        if (amount_a > 0 && amount_a < balance) { // check enterd amount validity
            balance -= amount_a;
            cout << endl << "Please Collect Your Cash";
            cout << endl << "Available Balance :" << balance;
            cin.ignore();  // Clear the input buffer
            cin.get();   // Waits for Enter
        }

        else {
            cout << endl << "Invalid input or Insufficient Balance";
            cin.ignore();  // Clear the input buffer
            cin.get();   // Waits for Enter
        }

    }
};

int main() {
    int choice = 0, enterPIN;		//enterPIN and enterAccountNo. ---> user authentication
    long int enterAccountNo;

    system("cls");

    // created User ( object )
    atm user1;
    // Set User Details ( into object )         ( Setting Default Data )
    user1.setData(1234567, "Abrar", 1111, 45000.90, "9087654321");

    
    do {
        system("cls");  /// to clean the screen


        cout << endl << "Welcome to ATM" << endl;
        cout << endl << "Enter Your Accouont No ";
        cin >> enterAccountNo;

        cout << endl << "Enter PIN ";
        cin >> enterPIN;
        //check whether enter values matches with user details
        if (enterAccountNo == user1.getAccountNo() && enterPIN == user1.getPin()) {
            do
            {
                int amount = 0;
                string oldMobileNo, newMobileNo;

                system("cls");
                //user Interface
                cout << endl << "*****Welcome to ATM*****" << endl;
                cout << endl << "Select Options ";
                cout << endl << "1. Check Balance";
                cout << endl << "2. Cash Withdraw";
                cout << endl << "3. User Details";
                cout << endl << "4. Update Mobile No";
                cout << endl << "5. Exit" << endl;
                cin >> choice; //taking user choice;

                switch (choice) {
                case 1:  //if press 1;
                    cout << endl << "Your Bank balance is: " << user1.getBalance();
                    cin.ignore();  // Clear the input buffer
                    cin.get();   // get() is to hold the screen(untill user press any key )
                    break;
                case 2: 
                    cout << endl << "Enter the amount :";
                    cin >> amount;
                    user1.cashWithDraw(amount);
                    break;
                case 3:
                    cout << endl << "*** User Details are :- ***";
                    cout << endl << "Account no " << user1.getAccountNo();
                    cout << endl << "name " << user1.getName();
                    cout << endl << "Balance " << user1.getBalance();
                    cout << endl << "Mobile No " << user1.getMobileNo();
                    cin.ignore();  // Clear the input buffer
                    cin.get();   // Waits for Enter
                    break;
                case 4:
                    cout << endl << "Enter Old Mobile No. ";
                    cin >> oldMobileNo;

                    cout << endl << "Enter New Mobile No. ";
                    cin >> newMobileNo;

                    user1.setMobile(oldMobileNo, newMobileNo);
                    break;

                case 5:
                    exit(0);

                default:
                    cout << endl << "Enter Valid Data !!!";
                }

            }while (1);
        }
        else
        {
            cout << endl << "User Details are Invalid !!! ";
            cin.ignore();  // Clear the input buffer
            cin.get();   //// Waits for Enter
        }
    } while (1);
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
