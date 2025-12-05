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
// - On Base Percent = (hits + walks + beans) / ( atBats + walks + beans + sacrifice flies)
    // - This requires us to know walks, beans, and sac flies, which we do not have ???
// - Singles = hits - (homeruns + triples + doubles)
// - Plate Appearances = atBats + walks (??? we aren't given walks ???)
//

std::string fileLine;
std::string playerFile;

std::string playerName;
int atBats = 0;
int hits = 0;
int singles = 0;
int doubles = 0;
int triples = 0;
int homeruns = 0;
int strikeOuts = 0;
int walks = 0;
int beans = 0;
int battingAverage = 0;
int slugPercent = 0;
int onBasePercent = 0;
int plateAppearances = 0;
std::vector<int> statList;

// Split function to turn a list of integers into a vector of integers
std::vector<int> splitStats(std::string lineHere)
{
    std::vector<int> playerStats = { 0,0,0,0,0,0,0 };
    std::string currentSet = "";
    char delimeter = ' ';
    int counter = 0;
    bool contDet = false;

    // extra space required to push final cycle
    lineHere += ' ';

    for (char elem : lineHere)
    {
        // only consider data up to six elements
        if (counter < 7)
        {
            // if the entry _is_ a character, add it to the current set
            if (elem != delimeter)
            {
                currentSet += elem;
                contDet = true;
            }

            // if it is a space, do not add, and flip the continuity flag
            else if (elem == delimeter and contDet == true)
            {
                contDet = false;
                try
                {
                    playerStats.at(counter) = stoi(currentSet);
                }
                catch (const std::exception& e)
                {
                    std::cout << e.what() << "\nAll data given must be given in integer form. Ending program...\n";
                    exit(0);
                }

                currentSet = "";
                counter++;
            }
        }
    }
    return playerStats;
}

// input validation checks for specifically valid data
void validateStats(std::vector<int> statsHere)
{
    // Makes sure elements are only a single integer
    for (int elem : statsHere)
    {
        if (elem > 9)
        {
            std::cout << "Your data should only include single integers. Ending program...\n";
            exit(0);
        }
    }

    // Makes sure that there are not more homeruns, doubles, and triples than hits
    // Note: I excluded singles because that value is calculated as the difference hits and doubles, triples, and homeruns
    if (statsHere.at(1) < (statsHere.at(2) + statsHere.at(3) + statsHere.at(4)))
    {
        std::cout << "Your data includes more successful homeruns, doubles, and triples than hits. Ending program...\n";
        exit(0);
    }

    // Makes sure that there are not more hits than at-bats
    if (statsHere.at(0) < statsHere.at(1))
    {
        std::cout << "Your data includes more successful hits than at-bats. Ending program...\n";
        exit(0);
    }
}

int main()
{   
    // Accept file
    std::cout << "Welcome to the baseball stats calculator!\nPlease enter the name of your player's file now:\n";
    std::getline(std::cin, playerFile);
    std::ifstream userFile(playerFile); // Make this into user input later

    // Store player name
    getline(userFile, fileLine);
    playerName = fileLine;

    // Loop - turn proceding lines into vectors, test each vector for validity, and sum each element
    while (getline(userFile, fileLine))
    {
        // Get current line
        statList = splitStats(fileLine);

        //validate current line
        validateStats(statList);

        //Sum each element
        atBats += statList.at(0);
        hits += statList.at(1);
        doubles += statList.at(2);
        triples += statList.at(3);
        homeruns += statList.at(4);
        walks += statList.at(5);
        strikeOuts += statList.at(6);
    }

    // Perform and store additional calculations
    singles = hits - (doubles + triples + homeruns);
    beans = atBats - (hits + doubles + singles + triples + homeruns + walks);
    battingAverage = ((1.0 * hits) / (1.0 * atBats)) * 1000;
    slugPercent = ((homeruns * 4.0) + (triples * 3.0) + (doubles * 2.0) + (singles * 1.0)) / (atBats * 1.0) * 1000;
    onBasePercent = ((hits * (1.0) + walks + beans) / (atBats * (1.0) + walks + beans)) * 100;
    plateAppearances = atBats + walks;

    // Print results
    std::cout << "\n" << "Player - " << playerName << "\n\n";
    printf("At Bats:%8d\n", atBats);
    printf("Hits:%11d\n", hits);
    printf("Singles:%8d\n", singles);
    printf("Doubles:%8d\n", doubles);
    printf("Triples:%8d\n", triples);
    printf("Homeruns:%7d\n", homeruns);
    printf("Strikeouts:%5d\n", strikeOuts);
    printf("Walks:%10d\n", walks);
    printf("Plate Apps:%5d\n", plateAppearances);
    printf("On Base %%:%6d\n", onBasePercent);
    printf("Bat Avg:%8d\n", battingAverage);
    printf("Slug %%:%9d\n", slugPercent);

    userFile.close();
}
