// File name: Trie.cpp
// Name: Devin Arrants
// VUnetid: arrantdg
// Email: devin.g.arrants@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor statement: I pledge on my honor that I have neither given nor received unauthorized aid
// Description: Impliments a Trie.  Contains functions
//     prototypes to insert, print, load from file, check if word is in trie, and word count
// Last Changed: 4/18/2018

#include <cstddef>
#include <iostream>
#include "Trie.h"
#include <fstream>
#include <string>
#include <sstream>

//default constructor
//create a Trie
//post: new Trie is created with root initialized to a space
Trie::Trie():root(' ', false){
}

//insert
//inserts a string into the Trie. Create new TrieNodes as needed.
//pre: Trie exists and string is passed
//post: string is inserted and boolean flag on last node is true.
void Trie::insert (const std::string& word){
    root.insert(word);
}

//loadFromFile
//Insert all words in the specified file into the Trie. Throws a
//std::invalid_argument exception if the specified file cannot be
//opened.
//Pre: Trie exists and string has length greater than 1.
//Post: all the words in the file are inserted into the tree
void Trie::loadFromFile (const std::string& filename){
    std::ifstream infile;
    infile.open(filename.c_str());
    if (infile.fail()) {
        throw std::invalid_argument("Error opening input data file");
    }
    std::string token;
    while(infile >> token){
        root.insert(token);
    }
}

//isWord
//Returns true if str is in the Trie
//pre: Trie exists and string of length greater or equal to 1 is passed
//post: if string is in Trie returns true. else returns false.
bool Trie::isWord (const std::string& word) const{
    return root.isWord(word);
}

//isPrefix
//checks if word is in Trie
//pre: Trie exists and string of length greater or equal to 1 is passed
//post: returns true if pre is a prefix of a word in the Trie, else returns false
bool Trie::isPrefix (const std::string& pre) const{
    return root.isPrefix(pre);
}

//print
//Prints all words in Trie.
//pre: Trie exists
//post: all words in the Trie are printed
void Trie::print ( ) const{
    root.print("");
}

//wordCount
//counts words in a Trie
//pre: Trie exists
//post: returns a count all the nodes in the Trie that end a word
size_t Trie::wordCount ( ) const{
    return root.wordCount();
}

