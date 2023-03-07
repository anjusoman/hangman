#include "header.h"





int main(void)
{
    
    string word;
    string underscores;
    
    char letter;
    string guessedLetters = " ";
    
    bool check;
    
    int numWrong = 0;
    string hangman;
    
    
    
    word = randomWord();
    underscores = initUnderscores(word);
    

    while (underscores != word)
    {
    
      letter = askForLetter(guessedLetters);
      guessedLetters += letter;
      
      check = (word.find(letter) == std::string::npos);
    
      if (check)
      {
        numWrong+=1;
        cout << "That letter is not in the mystery word." << endl;
        
      }
      
      else
      {
        cout << "That letter is in the mystery word!" << endl;
        updateUnderscores(word, underscores, letter);
      }
      
      
      hangmanUpdate(numWrong, underscores, guessedLetters);
      
      if (numWrong >= 6)
      {
        cout << "GAME OVER\nYou lost" << endl;
        cout << "The word was: " << word << endl;
        break;
      }
      
      else if (underscores == word)
      {
        cout << "GAME OVER\nCongrats, you win!" << endl;
        cout << "The word was: "<< word << endl;
        
        break;
      }
      

    }
      
      
      
      

    
    
    
    
    return 0;
}