/*
Yash Patel, Rahul Pemmasani, Ashwin Vaithiyalingam,  Krrishiv Kohli
Github-athon! Project
6/17/22
Extra:
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stdlib.h>
#include <fstream>

using namespace std;
void bubbleSort(vector <string> &Locations, vector <double> &ticketPrices);


struct variables {
  string checkIn, checkOut;
  string des;
  double charge, priceRange;
  
};

struct locations {
	vector <string> Locations = { "Cancún", "Fiji", "Santo Domingo ", "Parsippany", "Los Angelos", "Twizzytopia", "London", "Antartica", "North Korea", "Tokyo", "Berlin"};

	vector<double> ticketPrices = {8499.99, 7499.99, 9249.99, 7537.99, 6965.99, 5848.99, 9604.99, 8283.99, 5471.99, 6350.99, 9009.99};

  vector <string> userChoice;
  vector <double> userChoicePrice;
};

int main() {
  variables v;
  string use, pass, newUse, newPass;

  //Creating dummy variable
  string dummy = " ";
  
  //Calling structure in main
  struct variables var;
  
  cout << "--WELCOME TO BUSSYPEDIA\n";

 
  int logIn;//Title screen
  
  do {
    cout << "Choose from the following options: \n1. Log in \n2. Sign up(new user)\n";
    cin >> logIn;//log in orsign p page
  } while(logIn != 1 && logIn != 2);
  
  if (logIn == 1){ //error checking
    cout << "You need to make an account username and password first!\n\n";
    cout << "Create a strong Username and Password: \n";
    cin >> newUse;//stores new username and password
    cin >> newPass;
    cout << "Now that you have created an account, try signing in!\n\n";
    cout << "Enter Username: \n";
    cin >> use;//enters new username
    cout << "Enter Password: \n";
    cin >> pass;//user new password
  
    if (pass != newPass || use != newUse){//checks if username and password are correct
      do {
        cout << "\nThe following username or password is invalid. Please try agian.\n\n";//if not this prints
        cout << "Enter Username: \n";
        cin >> use;
        cout << "Enter Password: \n";
        cin >> pass;
        
      } while (pass != newPass || use != newUse);
    }
  }
  
  
  
  
  
  if (logIn == 2){//continues to this if they choose to create new account
    cout << "Create a strong Username and Password: \n";
    cin >> newUse;
    cin >> newPass;
    cout << "Now that you have created an account, try signing in!\n\n";
    cout << "Enter Username: \n";
    cin >> use;
    cout << "Enter Password: \n";
    cin >> pass;
  
    if (pass != newPass || use != newUse){
      do {//error checks for incorrect password and/or username
        cout << "\nThe following username or password is invalid. Please try agian.\n\n";
        cout << "Enter Username: \n";
        cin >> use;
        cout << "Enter Password: \n";
        cin >> pass;
        getline(cin, dummy);

    //vector<int> tran;
        
      } while(pass != newPass || use != newUse);
    }
  //all code above will only be gone through once
   
    struct locations V;
    struct variables N;
    bubbleSort(V.Locations, V.ticketPrices); //Calling sorting method

    cout << "Please enter your desired price range for a ticket: ";
    cin >> N.priceRange;

    //Linear search
    for (int i = 0; i < V.Locations.size(); i++) {
      if (V.ticketPrices[i] <= N.priceRange) {
        V.userChoice.push_back(V.Locations[i]);
        V.userChoicePrice.push_back(V.ticketPrices[i]);
      }
    }

    //Error Trapping method
    bool errorTrap = true;
    while (errorTrap == true) {
      try {
        cout << "\nPlease choose a ticket from the following destinations: \n";
        for (int index = 0; index < V.userChoice.size(); index++) { 
      cout << (index + 1) <<  ") " << V.userChoice[index] << endl;//prints new vector
        }
        int ticket;
        cin >> ticket;
        if (ticket > 0 && ticket <= 11) {
          var.des = V.userChoice[ticket];
          errorTrap = false;
        } else {
          cout << "\nInvalid input, please choose a valid destination\n";
        }
      } catch (invalid_argument) { 
        cout << "\nInvalid input, please choose a valid destination\n";
      }
    }

    cout << "Please enter the date you wish to travel: ";
    getline(cin, N.checkIn);

    cout << "Please enter the date of your return trip: ";
    getline(cin, N.checkOut);

    //Printing final reciept
    
   
}

//Sorting method
void bubbleSort(vector <string> &Locations, vector <double> &ticketPrices) {
  int i, j, flag = 1; // set flag to 1 to start first pass
  
  // holding variables
  string temp; 
  double temp2;
  
  int numLength = Locations.size(); 
  for (i = 1; (i <= numLength) && flag; i++) {
    flag = 0;
    for (j=0; j < (numLength -1); j++) {
      if (Locations[j+1] < Locations[j]) { 
        temp = Locations[j];// swap elements
        Locations[j] = Locations[j+1];
        Locations[j+1] = temp;
        temp2 = ticketPrices[j];
        ticketPrices[j] = ticketPrices[j+1];
        ticketPrices[j+1] = temp2;
        flag = 1; // indicates that a swap occurred.
      }
    }
  }
}