// chris singleton, December 2nd, 2025. CMPSC 330, Ganther. Baseball Stats Final
// This program is designed to read input from files as batting statistics for a baseball player
// The program then performs calculations to derive further stats, and prints out the information together.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Program requirements
// Need a split function, doesn't need to be robust, we're splitting on spaces
// Read data from a given text file.
// The first line will be the player's name, which may include spaces.
// Every line after that gets converted into a vector. Each element of the vector is then += into its respective variable to total it.
// I don't need to use cases. Once each vector is made, I can just refer to each index directly. The loop just makes sure I check ever line
// 
// 
// Make sure to verify that input data is valid.
// If there is ever an error, spit out an error message and end the program
// 
// Exceptions:
// - # of hits cannot be greater than # of at bats
// - total of singles, doubles, triples, and home runs cannot exceed # of hits
// - all stats must be a single numerical digit
// - Note: since we delimit with spaces, this automatically ignores empty lines
// 
// Calculations:
// - Batting average ((hits / atBats) * 1000)
// - Slugging Percent = (((homeruns * 4) + (triples * 3) + (doubles * 2) + singles) / (atBats)) * 1000 !!! MUST BE AN INT
// - On Base Percent = 
// - Singles = hits - (homeruns + triples + doubles)
// - Plate Appearances = atBats + walks (??? we aren't given walks ???)
//

std::string fileLine;

std::string playerName;
int atBats = 0;
int hits = 0;
int singles = 0;
int doubles = 0;
int triples = 0;
int homeruns = 0;
int strikeOuts = 0;
std::vector<int> statList;

// Split function to turn a list of integers into a vector of integers
std::vector<int> splitStats(std::string lineHere)
{
    std::vector<int> playerStats;

    // - Loop through the given string, concatenating each character until you hit a space
    // - Store in case 1 (first element of the vector)
        // - Note: this step needs a try-catch in case the inputs aren't integers
    // - Increment the counter
    // - Repeat looping until you hit another space
    // - Store in case 2 etc...
    // Quit the loop once all cases are exhausted/ the counter is at 6
    
    return playerStats;
}

void validateStats(std::vector<int> lineHere)
{
    // - # of hits cannot be greater than # of at bats
    // - total of singles, doubles, triples, and home runs cannot exceed # of hits
    // - all stats must be a single numerical digit
}

int main()
{   
    // Accept file
    std::ifstream userFile("Bobson Dugnutt.txt"); // Make this into user input later

    // Store player name
    getline(userFile, fileLine);
    playerName = fileLine;

    std::cout << fileLine << "\n"; // TEST CODE

    // Loop - turn proceding lines into vectors, test each vector for validity, and sum each element
    while (getline(userFile, fileLine)) // placeholder. this will be a for loop later
    {
        // Get current line
        statList = splitStats(fileLine);

        //validate current line
        validateStats(statList);

        //Sum each element

        std::cout << fileLine << "\n"; // TEST CODE
    }

    // Perform and store additional calculations
    // Print results
    //


    /*getline(userFile, fileLine);
    std::cout << fileLine << "\n";

    while (getline(userFile, fileLine))
    {
        std::cout << fileLine << "\n";
    }*/

    userFile.close();
}
