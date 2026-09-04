//COMSC-210 | Lab 3 | Eric-Giulio Hedes
#include <iostream>
#include <fstream>
using namespace std;

//Define & Initialize the Restaurant structure
struct Restaurant
{
    string name, address;
    int numTables;
    bool outsideSpots, hasBathroom;
};

//Define all prototype functions here
bool trueOrFalse();
Restaurant initializeRestaurant();


//Start of the main function
int main()
{
    //Set up the restaurant setup
    Restaurant myRest = initializeRestaurant();
}

bool trueOrFalse()
{
    char input;
    while (true)
    {
        cin >> input;
        cin.ignore(1000, 10);
        input = tolower(input);
        if (input != 'y' && input != 'n')
            cout << "ERROR: Y / N only! Try again: ";
        else
            break;
    }

    return (input == 'y') ? true : false;
}

Restaurant initializeRestaurant()
{
    //Initialize the temporary variable
    Restaurant t;
    //Prompt the user to enter the name of the restaurant
    cout << "Enter the name of the restaurant: ";
    getline(cin, t.name);
    //Prompt the user to enter the address of the restaurant
    cout << "Enter the address of the restaurant: ";
    getline(cin, t.address);
    //Prompt the user to enter the number of tables of the restaurant
    cout << "Enter the number of tables of the restaurant: ";
    cin >> t.numTables;
    cin.ignore(1000, 10);
    //Prompt the user to decide whether or not the restaurant has outside eating spots
    cout << "Does it have eating spots outside? (Y/N): ";
    t.outsideSpots = trueOrFalse();
    //Prompt the user to decide whether or not the restaurant has bathrooms
    cout << "Does it have a bathroom? (Y/N): ";
    t.hasBathroom = trueOrFalse();
    //Return the temporary variable
    return t;
}