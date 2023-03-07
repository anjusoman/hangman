#include "header.h"




string randomWord()
{
  
  srand(time(NULL));
  
  
  int randomNum;
  
  string wordList[100] = {"today","parts","eventually","adjective","independent","bring","made","suppose","fell","pull"
  "luck","final","got","doubt","ground","noon","recall","ocean","game","observe"
  "type","quarter","known","border","helpful","fireplace","poem","blood","here","plates"
  "owner","selection","industry","surrounded","afternoon","firm","maybe","properly","likely","vowel"
  "silly","average","mostly","heart","sudden","trail","book","mouse","interest","aside"
  "case","say","rhyme","low","feel","feathers","fall","pool","brave","west"
  "fifty","stage","active","ago","coming","beat","wish","travel","avoid","castle"
  "possible","cabin","occasionally","please","laid","time","cast","anyone","noise","everything"
  "attack","dog","tower","tongue","forest","earlier","problem","eager","interior","heart"
  "younger","level","stick","invented","shoulder","ill","anywhere","its","birthday","nor"
  "trail","enough","key","congress","beside","specific","who","most","interior","book"};
  
  randomNum = rand() % 100;
  
  return wordList[randomNum];

}



string initUnderscores(string word)
{

  int length;
  string unsolvedWord = "-";
  length = word.length();
  
  
  
  for (int i = 0; i < length - 1; i++)
  {
    unsolvedWord += "-";
  }
  
  return unsolvedWord;
}



char askForLetter(string guessedLetters)
{
  char letter;
  
  cout << "Guess a Letter: ";
  cin >> letter;
      
  while (guessedLetters.find(letter) != std::string::npos || !isalpha(letter) || !islower(letter))
  {
    if (guessedLetters.find(letter) != std::string::npos)
    {
      cout << "Letter was already guessed.\n\nGuess a new letter: ";
      cin >> letter;
      cout << endl;
    }
    
    else if (!isalpha(letter))
    {
      cout << "That is not a letter.\n\nGuess a letter: ";
      cin >> letter;
      cout << endl;
    }
    
    
    else if (!islower(letter))
    {
      letter = tolower(letter);
    }
  
  }
  
  
  return letter;

}

 
void updateUnderscores(string word, string& underscores, char letter)
{

  int elementNum;
  elementNum = word.find(letter);
  
  
  while (elementNum != std:: string::npos)
  {
    
    underscores[elementNum] = letter;
    elementNum = word.find(letter, elementNum+1);
  }
  
  
}




void hangmanUpdate(int wrongGuess, string underscores, string guesses)
{
  string pics[7] = 
       {"+---+\n  |   |\n      |\n      |\n      |\n      |\n=========", 

        "+---+\n  |   |\n  O   |\n      |\n      |\n      |\n=========",

        "+---+\n  |   |\n  O   |\n  |   |\n      |\n      |\n=========",

        "+---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n=========", 

        "+---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n=========",

        "+---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n=========",

        "+---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========="} ;

 
  cout << pics[wrongGuess] << "\n\n";
  cout << "Mystery Word: " << underscores << "\nGuessed letters:" << guesses << "\n\n\n";


}

