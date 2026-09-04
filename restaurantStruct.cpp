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
void outputRestaurant(const Restaurant&);
Restaurant initializeRestaurant();


//Start of the main() function
int main()
{
    //Set up the restaurant setup
    Restaurant myRest = initializeRestaurant();

    //Print out the whole myRest structure
    outputRestaurant(myRest);

    //Try to print out four structs with using a file input
    const int MAX_NUM = 4;
    Restaurant col[MAX_NUM];
    ifstream file;

    //Also initialize the separate variables related to the file method
    string file_name, file_address, line;
    int file_numTables;
    string file_outsideSpots, file_hasBathroom;
    int index = 0;

    //Open the input file
    file.open("input.txt");

    //Check if the file is open
    if (file.is_open())
    {
        //Use a while loop to go through all of the lines
        while (file >> file_numTables)
        {
            file.ignore(); //Ignore the first line since it's being used for file_numTables
            //Get the rest of the four variables
            getline(file, file_name); //Get the address
            getline(file, file_address); //Get the address
            file >> file_outsideSpots; //Get the outside spot check
            file >> file_hasBathroom; //Get the bathroom check

            //NOTE: The boolean variables are usually done while the temporary restaurant structure is defined,
            //so when the variables gathered from the file are added to the t struct, the booleans are automatically
            //going to get defined whether file_outsideSpots or file_hasBathroom are either written as 'yes' (true) or 'no' (false)
           
            //Use a temporary Restaurant structure to store all of the file input variables
            Restaurant t;
            t.name = file_name;
            t.address = file_address;
            t.numTables = file_numTables;
            t.outsideSpots = (file_outsideSpots == "yes") ? true : false;
            t.hasBathroom = (file_hasBathroom == "yes") ? true : false;

            //Store the t struct into the col[] array & add up the index
            col[index++] = t;
        }
    }

    //Print out the four Restaurant structs
    cout << endl;
    for (int i = 0; i < MAX_NUM; i++)
    {
        //Print out the restaurant number
        cout << "Restaurant #" << i+1 << ": " << endl;
        //Print out the parts of the structure as usual
        outputRestaurant(col[i]);
        //Use a endl to leave some extra space for the next restaurant number
        cout << endl;
    }
}
//End of the main() function

//Initialize trueOrFalse() this is used for 
bool trueOrFalse()
{
    //Define a temporary variable which will be used for returning
    char input;

    //Do a while(true) validation loop 
    while (true)
    {
        //Ask the user to do a input
        cin >> input;
        cin.ignore(1000, 10);
        //Convert the input character to lowercase
        input = tolower(input);
        //If the user inputted a letter that is not Y or N, ask the user to try again
        if (input != 'y' && input != 'n')
            cout << "ERROR: Y / N only! Try again: ";
        else //Otherwise break the loop itself...
            break;
    }
    //...and return the boolean; if the input is 'y', the boolean is true and if the input is 'n', the boolean is false.
    return (input == 'y') ? true : false;
}

//Initialize the function initializeRestaurant() which is used for the creation of a Restaurant struct through user-input
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

//Initialize outputRestautant(): it prints out the restaurant's information.
void outputRestaurant(const Restaurant &t)
{
    //Print out the name
    cout << "\t- Name: " << t.name << endl;
    //Print out the location
    cout << "\t- Address: " << t.address << endl;
    //Print out the number of tables
    cout << "\t- Number of tables: " << t.numTables << endl;
    //Print out the spot
    cout << "\t- Has Outside Tables: " << ((t.outsideSpots) ? "Yes" : "No") << endl;
    //Print out the name
    cout << "\t- Has Bathroom: " << ((t.hasBathroom) ? "Yes" : "No") << endl;
}