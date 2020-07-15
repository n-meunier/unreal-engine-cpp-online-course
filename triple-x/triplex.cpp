#include <iostream>

void PrintIntroduction(int Difficulty)
{
    // Print welcome messages to the terminal
    std::cout << "\n    _____     _       _       __  __\n";
    std::cout << "\n   |_   _| __(_)_ __ | | ___  \\ \\/ /\n";
    std::cout << "\n     | || '__| | '_ \\| |/ _ \\  \\  / \n";
    std::cout << "\n     | || |  | | |_) | |  __/  /  \\ \n";
    std::cout << "\n     |_||_|  |_| .__/|_|\\___| /_/\\_\\ \n";
    std::cout << "\n               |_|                  \n";
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty << " secure server room\n";
    std::cout << "Enter the correct code to continue...\n\n";
}

bool PlayGame(int Difficulty)
{

    const int MaxCodeNumber = 4;

    // Declare 3 number code
    const int CodeA = (rand() % MaxCodeNumber * Difficulty + 1);
    const int CodeB = (rand() % MaxCodeNumber * Difficulty + 1);
    const int CodeC = (rand() % MaxCodeNumber * Difficulty + 1);

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    // Print sum and product to the terminal
    std::cout << "Level " << Difficulty << " server room.";
    std::cout << "\n* There are 3 numbers in the code";
    std::cout << "\n* The codes add-up to: " << CodeSum;
    std::cout << "\n* The codes multiply to give: " << CodeProduct << std::endl;

    // Declare player guess codes
    int GuessA, GuessB, GuessC;
    // Get players code inputs
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if the players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) 
    {
        std::cout << "\n** Well done agent! You have extracted the level " << Difficulty << " file! Keep going! **\n";
        return true;
    }
    else 
    {
        std::cout << "\n** You entered the wrong code! Careful agent! Try again! **\n";
        return false;
    }
}

int main()
{
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;
    
    PrintIntroduction(LevelDifficulty);

   while (LevelDifficulty <= MaxDifficulty) // Loop the game until all levels are cleared
   {
       bool bLevelComplete = PlayGame(LevelDifficulty);
       std::cin.clear(); // Clears any errors
       std::cin.ignore(); // Discards the buffer

       if (bLevelComplete) {
           ++LevelDifficulty;
       }
   }
    
    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***";
    return 0;
}