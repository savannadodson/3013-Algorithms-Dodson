/*****************************************************************************
*   
*  GOT HELP FROM A TUTOR 
*                
*  Author:     Savanna Dodson
*  Email:      smdodson1105@my.msutexas.edu
*  Label:      P02
*  Title:      Processing in Linear Time
*  Course:     3013 algorithims
*  Semester:   Spring 2021
* 
*  Description:
*        Read in a file of dictionary words and create a linked list of them.   *        Time how long it takes to do this. Then getch in character and pull up
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

#include "mygetch.hpp"
#include "termcolor.hpp"
#include "timer.hpp"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Description:
 *      Originally wrote this to count size of input file so
 *      I could allocate enough memory for an array of strings
 *      but I went with a vector below. But I'm keeping it and
 *      using it anyway!
 * Params:
 *      string file_name - file to get the line count
 * 
 * Returns:
 *      int - line count
 */
// int CountLines(string file_name) {
//     ifstream inFile(file_name);
//     return count(istreambuf_iterator<char>(inFile), istreambuf_iterator<char>(), '\n');
// }

/**
 * Struct wordNode
 * 
 * Description:
 *      creates a object that holds a word
 * 
 * Public Methods:
 *      wordNode()
 *
 * Private Methods:
 *      None
 *    
 * 
 * Usage: 
 * 
 *     object that holds a word       
 */

struct wordNode
{
  string word;
  //create pointer
  wordNode* next;
  wordNode()
  {
    word = "";
    next = NULL;
  }
};


class wordNodes
{
  private:
    wordNode* head;
    wordNode* tail;
    //number of words in the list
    int numWords;

  public:
    //constructor wordNode
    wordNodes()
    {
      head = NULL;
      tail = NULL;
      numWords = 0;
    }

  /**
 * Public: numWords
 * 
 * Description:
 *      gets the number of words in the linked *      lists
 * 
 * Params:
 *      None
 *
 * Returns:
 *      int num: the number/size of words in *  *       the list
 *    
 * 
 *      
 */
  
  //getter
  int getnumWords()
  {
    return numWords;
  }

  /**
 * Public: addWord
 * 
 * Description:
 *      Adds a word onto the linked list of 
 *      nodes
 * 
 * Params:
 *      wordNode* : pointer to the word/object
 *
 * Returns:
 *      None
 *    
 *    
 */

 void addWord(wordNode* word)
 {
   //if head has nothing in it
   if(head == NULL)
   {
     head = tail = word;

   }
   else
   {
     //if head does have something/word in it
     //point the new word to the next position
     tail -> next = word;
     tail = word;
   }
   //increment the list of words
   numWords++;
 }

  /**
 * Public: findWords
 * 
 * Description:
 *      finds the words in the dictionary input *      that match whats typed and add to the   *      linked list
 * 
 * Params:
 *      string substring : letter that is read *      in
 *
 * Returns:
 *    vector<string>  matches : vector of the  *    matches found from the input
 *    
 * 
 *      
 */

vector<string> findWords(string substring)
{
  //holds the matches that are found from the //input
  vector<string> matches;
  wordNode* curr = head;
  //size of word
  int length;
  //add words to linked list until no more //matches
  while(curr != NULL)
  {
    string temp = " ";
    temp = curr -> word;
    length = substring.length();
    if(temp.substr(0,length)==substring)
    {
      matches.push_back(temp);
    }
    curr = curr->next;
  }
  return matches;
}

/**
 * Public: Print
 * 
 * Description:
 *      prints the linked list of the     
 *       words/matches
 * Params:
 *      None
 *
 * Returns:
 *      None
 *          
 */

 void Print()
 {
   wordNode* curr = head;
   //prints words out until the end of the list
   while(curr != NULL)
   {
     cout << curr -> word << endl;
     curr = curr -> next;
   }
 }
 
};











/**
 * Description:
 *      Loads a file of strings (words, names, whatever) reading them in
 *      with one word per line. So words must be delimited by newlines '\n'
 * Params:
 *      string file_name - file to get the line count
 * 
 * Returns:
 *      int - line count
 */
// vector<string> LoadAnimals(string file_name) {
//     ifstream fin;                            // file to get animal names
//     int count = (CountLines(file_name) + 1); // get size of input file
//     vector<string> array(count);             // allocate vector of correct size

//     fin.open("animal_names.txt"); // open file for reading

//     // knowing the size of the file lets us treat
//     // it like an array without using .push_back(value)
//     for (int i = 0; i < count; i++) {
//         fin >> array[i];           // read in animals
//         for (auto &c : array[i]) { // c++ 11 style loop
//             c = tolower(c);        // lowercase the animal name
//         }
//     }
//     return array;
// }

/**
 * Description:
 *      Finds partial matches in an array of strings and returns them. It
 *      doesn't matter where in the string the match is.
 * Params:
 *      vector<string>  array       - array to search
 *      string          substring   - substring to search for in each word
 * 
 * Returns:
 *      vector<string> - holding all the matches to substring
 */
// vector<string> FindAnimals(vector<string> array, string substring) {
//     vector<string> matches; // to hold any matches
//     size_t found;           // size_t is an integer position of
//                             // found item. -1 if its not found.

//     for (int i = 0; i < array.size(); i++) { // loop through array
//         found = array[i].find(substring);    // check for substr match
//         if (found != string::npos) {         // if found >= 0 (its found then)
//             matches.push_back(array[i]);     // add to matches
//         }
//     }

//     return matches;
// }

int main() 
{
    //opening the input file
    ifstream infile;
    infile.open("dictionary.txt");
    wordNodes list;
    int numberWords;
    char k;                 // holder for character being typed
    string word = "";       // var to concatenate letters to
    vector<string> LoadDictionary; // array of animal names
    vector<string> matches; // any matches found in vector of animals
    vector<string> FirstMatches(10);
    // ofstream fout("temp.txt");

    Timer T;   // create a timer
    Timer secondTime; //timer to match words
    T.Start(); // start it
    

    //read the words from input to the 
    //end of the input
    while(!infile.eof())
    {
      string words;
      infile >> words;
      LoadDictionary.push_back(words);
    }

    //creating the linked list of the words
    for(int i = 0; i < LoadDictionary.size(); i++)
    {
      wordNode* temp = new wordNode;
      string holdWord = LoadDictionary[i];
      temp -> word = holdWord;
      list.addWord(temp);
    }
    T.End(); // end the current timer

    // print out how long it took to load the animals file
    cout << T.Seconds() << " seconds to read in and print json" << endl;
    cout << T.MilliSeconds() << " milli to read in and print json" << endl;

    cout << "Type keys and watch what happens. Type capital Z to quit." << endl;

    // While capital Z is not typed keep looping
    while ((k = getch()) != 'Z') 
    {
        cout << termcolor::magenta << "Substring typed: " << termcolor::reset;
        // Tests for a backspace and if pressed deletes
        // last letter from "word".
        if ((int)k == 127) 
        {
            if (word.size() > 0)
           {
                word = word.substr(0, word.size() - 1);
            }
        } else 
        {
            // Make sure a letter was pressed and only letter
            if (!isalpha(k))
           {
                cout << "Letters only!" << endl;
                continue;
            }

            // We know its a letter, lets make sure its lowercase.
            // Any letter with ascii value < 97 is capital so we
            // lower it.
            if ((int)k < 97) 
            {
                k -= 32;
            }
            word += k; // append char to word
        }
        
        //start the second timer
        secondTime.Start();
        // Find any words in the array that partially match
        // our substr word
        matches = list.findWords(word);
        secondTime.End();
        //end of the second timer
        numberWords = matches.size();

        if ((int)k != 32) 
        { 
          //if k is not a space print it
          //make the text colorful
          cout << termcolor::blue << termcolor::blue << word << endl << termcolor::reset;
            cout << numberWords << " words found in " << secondTime.Seconds() << " seconds" << '\n';
            // This prints out all found matches
            //prints first 10 matches found
            if(matches.size() > 10)
            {
              for(int i = 0; i < 10; i++)
              {
                cout << termcolor::bright_red;
                //put into an array
                FirstMatches[i] = matches[i];
                //print out the array
                cout << FirstMatches[i] << " ";
                cout << termcolor::reset;
              }
            }
            else
            {
              for(int i = 0; i < numberWords; i++)
              {
                cout << termcolor::bright_red;
                //put into an array
                FirstMatches[i] = matches[i];
                //print out the array
                cout << FirstMatches[i] << " ";
                cout << termcolor::reset;

              }
            }
            cout << '\n' << '\n';
      }
    }
    return 0;
}
