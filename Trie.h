// File name: Trie.h
// Name: Devin Arrants
// VUnetid: arrantdg
// Email: devin.g.arrants@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor statement: I pledge on my honor that I have neither given nor received unauthorized aid
// Description: Maintains a Trie. contains functions of
//     prototypes to insert, print, load from file, check if word is in trie, and word count
// Last Changed: 4/18/2018

#ifndef BINARYTRIE_TRIE_H
#define BINARYTRIE_TRIE_H
#include <cstddef>
#include <iostream>
#include "TrieNode.h"

typedef char ItemType;

class Trie
{
private:
    TrieNode root;
public:
    //default constructor
    //create a Trie
    //post: new Trie is created with root initialized to a space
    Trie();

    //insert
    //inserts a string into the Trie. Create new TrieNodes as needed.
    //pre: Trie exists and string is passed
    //post: string is inserted and boolean flag on last node is true.
    void insert (const std::string& word);

    //loadFromFile
    //Insert all words in the specified file into the Trie. Throws a
    //std::invalid_argument exception if the specified file cannot be
    //opened.
    //Pre: Trie exists and string has length greater than 1.
    //Post: all the words in the file are inserted into the tree
    void loadFromFile (const std::string& filename);

    //isWord
    //Returns true if str is in the Trie
    //pre: Trie exists and string of length greater or equal to 1 is passed
    //post: if string is in Trie returns true. else returns false.
    bool isWord (const std::string& word) const;

    //isPrefix
    //checks if word is in Trie
    //pre: Trie exists and string of length greater or equal to 1 is passed
    //post: returns true if pre is a prefix of a word in the Trie, else returns false
    bool isPrefix (const std::string& pre) const;

    //print
    //Prints all words in Trie.
    //pre: Trie exists
    //post: all words in the Trie are printed
    void print ( ) const;

    //wordCount
    //counts words in a Trie
    //pre: Trie exists
    //post: returns a count all the nodes in the Trie that end a word
    size_t wordCount ( ) const;

};

#endif