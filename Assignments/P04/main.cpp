/*****************************************************************************
*   
*  GOT HELP FROM A TUTOR 
*                
*  Author:     Savanna Dodson
*  Email:      smdodson1105@my.msutexas.edu
*  Label:      P04
*  Title:      Processing with a Trie
*  Course:     3013 algorithims
*  Semester:   Spring 2021
* 
*  Description:
*        Read in a file of dictionary words and create a trie of the words.   *        *Time how long it takes to do this. Then getch in character and pull up
*        the first 10 search results. Time how long it takes to do this too.
* 
*  Usage:
*        Type in a word to search for. Use backspace if neccessary. Type a 
*        capital z to quit the program.
* 
*  Files:            main.cpp
*                    dictionary.txt
*                    getch.hpp
*                    termcolor.hpp
*                    timer.hpp
*****************************************************************************/



#include <vector>
#include <iostream>
#include<fstream>
#include "mygetch.hpp"
#include "timer.hpp"
#include "termcolor.hpp"

using namespace std;

/**
 * struct TrieNode
 *
  * Description:
 *     creates all nodes for the trie
 *      
 * 
 * Public Methods:
 *      - trieNode()
 * 
 * Private Methods:
 *      - None
 *
 * Usage:
 *
 *  trieNode a;
 * 
 */

struct trieNode
{
  //if leaf = end of word
  bool isLeaf;

  //point to all letters in the alphabet
  trieNode* alphabet[26];

  //default constructor
  trieNode()
  {

    this -> isLeaf = false;

    //points to each letter in the alphabet
    for(int i = 0; i < 26; i++)
    {
      this -> alphabet[i] = NULL; 
    }
  }

};

/**
 * Class trie
 *
 * Description:
 *    
 *      
 *
 * Public Methods:
 *      - Trie()
 *      - void insertWord(string)
 *      - int findWord(string)
 *      - void Print()
 * 
 * Private Methods:
 *      - void findWord(TrieNode*&, string)
 *
 */

class trie
{
  private: 

  //pointer to the head
  trieNode* root;
  //creates a vector of all the matches 
  vector <string> matches; 

  public:

  //default constructor
  trie()
  {
    root = new trieNode;
  }
  
  /**
 * Public: insertWord
 * 
 * Description:
 *     inserts the typed input into the trie
 * 
 * Params:
 *      string word
 *
 * Returns:
 *      void
 *    
 * 
 *      
 */

  void insertWord(string word)
  {
    //points the typed letter to the root
    trieNode* typedLetter = root;

    //adds each letter of the word typed to //the trie until the end
    for (int i = 0; i < word.length(); i++)
    {
        //if the path isn't there make a new
        //path in the trie
        if(typedLetter -> alphabet[word[i]-97] == NULL)
        {
           typedLetter->alphabet[word[i] - 97] = new trieNode();
        }

       typedLetter = typedLetter->alphabet[word[i] - 97];
    }
    //last letter in the word typed becomes 
    //the leaf
   typedLetter->isLeaf = true;

  }

  /**
 * Public: findWord
 * 
 * Description:
 *     takes the input and looks through the 
 *     trie to find matching words
 * 
 * Params:
 *      -string : the word typed
 *
 * Returns:
 *      - int : amount of matches in the trie
 *    
 * 
 *      
 */

  int findWord(string word)
    {
        //looks at the begging of the trie
        trieNode* typedLetter = root;         


        matches.clear();                        
        //look/traverse through the trie for 
        //matches
        for (int i = 0; i < word.length(); i++)
        {   
              //if word doesnt exist
            if (typedLetter->alphabet[word[i] - 97] == NULL) 
            {
                //return 0 if no matches
                return 0;       
            }                                    
            //moves to the next letter
            typedLetter = typedLetter->alphabet[word[i] - 97]; 

        }

        //calls private function
        findWord(typedLetter, word);          

        //returns the amount of matches found
        return matches.size();                  

    }


    /**
 * Public: Print
 * 
 * Description:
 *     Prints the matches found
 * 
 * Params:
 *     void
 *
 * Returns:
 *      None
 *    
 * 
 *      
 */


    void Print()
    {
      //prints out only 10 matches if more than 10
      //matches are found
      if(matches.size() >= 10)
      {
          //prints out first 10 matches
          for (int i = 0; i < 10; i++)  
      {
        if(i == 0)                  
        {
        //prints words in color
        cout << termcolor::magenta;    
        }

        cout << matches[i] << "   ";
        //resets the color
        cout << termcolor::reset;   
      }

      }
      else 
      //prints the matches when less than 10 matches
      {
      for (int i = 0; i < matches.size(); i++) 
      {    
        if(i == 0)
        {
        //prints in color
        cout << termcolor::magenta;   
        }  

        cout << matches[i] << "   ";
        //resets the color
        cout << termcolor::reset;   
      }
    }
   } 


 /**
 * Private: findWord
 * 
 * Description:
 *     looks through the trie to find matches/the word
 * 
 * Params:
 *    trieNode* & : pointer pointing to the next letter in 
 * the trie
 *
 *    string : word used to look for matches    
 *
 * Returns:
 *      None
 *    
 * 
 *      
 */

    private:
    void findWord(trieNode* & curr, string word)
    {
      //if the node is the last letter in the trie/word
      if(curr->isLeaf)            
        {
          //add the word to the vector
          matches.push_back(word);  
        }

        for(int i = 0; i < 26; i++)
        {
          if(curr->alphabet[i])
          {
            //look through trie and find matches
             findWord(curr->alphabet[i], word+char(i+97)); 
          }
        }

    }
};

int main() 
{
  //create the trie
  trie *dictionaryWords = new trie();

  //the letter typed 
  char letterTyped;
  //size of the typed word
  int wordSize = 0;
  string word = "";

  //word added to the trie
  string addedWord;
  int totalWords;
    
  //declare variables
  double sec;


  //open and declare input file
  ifstream infile;
  infile.open ("dictionary.txt");

    //declaring the clock
    Timer clock;



  //reading in the file till the end of the file
  while (!infile.eof()) 
    {   
        //reads in the words from the input
        infile >> addedWord;   
        //adds the words to the trie          
        dictionaryWords->insertWord(addedWord);    
    }

    cout << "input: ";     

    
     while ((int)(letterTyped = getch()) != 10) 
    { 
        //once user has typed a letter/key
        wordSize++;                   

        //if key typed is backspace
        if((int)letterTyped == 127)         
        {
          if(wordSize > 0)            
          {
            word.erase(wordSize-2, 1); 
            wordSize-=2;              
          }
        }

        //else add letter to previous letter
        else                            
        {
          //adds letter to word
          word += letterTyped;               
        }

      
       //prints current letters
        cout << "input: ";
        cout << termcolor::magenta << word;  
        cout << termcolor::reset <<'\n';  
        //starts clock
        clock.Start();    
        //finds matches               
        totalWords = dictionaryWords->findWord(word);


        cout << termcolor::magenta << totalWords;  
        cout << termcolor::reset;         
        cout << " words found in ";
        //ends clock when all words found
        clock.End();                   
        //prints out the time it took to find matches
        sec = clock.Seconds();            
        cout << sec << " seconds" << '\n';

        //prints out the 10 matches found
        dictionaryWords -> Print();  
        cout << '\n';              
        
    }

}
