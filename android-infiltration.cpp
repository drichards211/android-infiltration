#include <iostream> // Preprocessor Directive
#include <ctime> // Provides access to computer's time for seeding rand()
#include <cstdlib> // Provides communication with the environment

void ClearScreen() // Command for clearing the terminal display is OS specific:
{
#ifdef _WIN32 // Shorthand for "#if defined _WIN32". Note: #ifdef cannot use compound conditionals
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}

void PrintIntroduction() // "void" data type = function returns no data
{
// Expression Statements:
  std::cout << 
  "\n\nSTAR TREK: THE NEXT GENERATION -- ANDROID INFILTRATION"
<< "\n\n                                _____\n"
<< "                       __...---'-----`---...__\n"
<< "                  _===============================\n"
<< " ______________,/'      `---..._______...---'\n"
<< "(____________LL). .    ,--'\n"
<< " /    /.---'       `. /\n"
<< "'--------_  - - - - _/\n"
<< "          `~~~~~~~~'\n\n";

  std::cout << "Commander Data, your mission is to gain entry to the laboratory\n"
  << "of Dr. Noonian Soong. \n"; // can also use <std::cout << std::endl;> to end the current line
}

bool PlayGame(int Difficulty) 
{
  // Declaration Statements:
  const int CodeA = rand() % Difficulty + 2; // int between 0 and 32,767, % limits int to less than value specified, + 2 (prevents possible occurence of zero, augments difficulty) 
  const int CodeB = rand() % Difficulty + 2;
  const int CodeC = rand() % Difficulty + 2;

  const int CodeSum = CodeA + CodeB + CodeC;
  const int CodeProduct = CodeA * CodeB * CodeC;
  
  // Expression Statements:
  std::cout << "\n\nThis is door " << Difficulty << " of 5. You must enter the correct code to proceed...\n\n";
  std::cout << "+ There are 3 numbers in the code\n";
  std::cout << "+ The codes add up to: " << CodeSum << "\n";
  std::cout << "+ The codes multiply to give: " << CodeProduct << "\n\n"; // could also usle << std::endl
  std::cout << "Enter the three code numbers separated by spaces:\n";
  // Capture and store player guesses
  int GuessA, GuessB, GuessC;
  std::cin >> GuessA >> GuessB >> GuessC;
  /* std::cout << "You entered: " << GuessA << GuessB << GuessC; */

  int GuessSum = GuessA + GuessB + GuessC;
  int GuessProduct = GuessA * GuessB * GuessC;

  // Check if player's guess is correct
  if (GuessSum == CodeSum && GuessProduct == CodeProduct)
  {
    ClearScreen();
    std::cout << "\n*** Correct ***\n"
    << "The door opens and you proceed further into the lab...";
    return true;
  }
  else
  {
    ClearScreen();
    std::cout << "\n*** INCORRECT ***\n"
    << "A laser beam fires from the ceiling, and you narrowly dodge it.";
    return false;
  }
}

int main() // Main Function
{
  srand(time(NULL)); // Creates new random sequence based on time of day

  int LevelDifficulty = 1;
  const int MaxDifficulty = 5;

  PrintIntroduction();

  while (LevelDifficulty <= MaxDifficulty) // Loops game until all levels completed
  {
    bool bLevelComplete = PlayGame(LevelDifficulty);
    std::cin.clear(); // Clears any errors
    std::cin.ignore(); // Discards the buffer

    if (bLevelComplete) 
    {
      ++LevelDifficulty;
    }
  }
  std::cout << "\n\nThis was the final door. Well done, Mr. Data!\n"
  << "Please deactivate the force field so the away team can beam down.\n\n";
  return 0; // Return Statement
}
