// chris singleton, December 2nd, 2025. CMPSC 330, Ganther. Baseball Stats Final
// This program is designed to read input from files as batting statistics for a baseball player
// The program then performs calculations to derive further stats, and prints out the information together.
//

#include <iostream>
#include <fstream>
#include <string>

std::string myText;
std::ifstream myFile("Bobson Dugnutt.txt");

int atBats;
int hits;
int doubles;
int triples;
int homeruns;
int strikeOuts;


int main()
{   
    while (getline(myFile, myText))
    {
        std::cout << myText;
    }

    myFile.close();
}
