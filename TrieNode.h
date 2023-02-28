// File name: TrieNode.h
// Name: Devin Arrants
// VUnetid: arrantdg
// Email: devin.g.arrants@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor statement: I pledge on my honor that I have neither given nor received unauthorized aid
// Description: Maintains a TrieNode.  Contains functions
//     prototypes to insert, print, check if word is in subtree, and node count
// Last Changed: 4/15/2018

#ifndef TRIENODE_H
#define TRIENODE_H

#include <cstddef>
#include <string>

const int LETTERS = 26;

class TrieNode{
private:
    typedef TrieNode* TrieNodePtr;
    bool end;
    char ch;
    TrieNodePtr alphabet[LETTERS];

public:
    //The constructor. Takes a character for the node, and a bool
    //indicating whether it represents the end of a word. Note, there is no
    //default ctor.
    TrieNode(char c, bool b);

    //copy constructor
    // pre:  Class object, TrieNode, exists
    // post: Object is initialized to be a copy of the parameter
    TrieNode(const TrieNode& rhs);

    //destructor
    // Destroys a TrieNode
    // pre:  Class object exists
    // post: Class object does not exist
    ~TrieNode( );

    //Assignment Operator
    // Assigns a TriNode to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const TrieNode& operator= (const TrieNode& rhs);

    //insert
    //inserts a string into the given TrieNode. Create new TrieNodes as needed.
    //pre: TrieNode exists and string is passed
    //post: string is inserted and boolean flag on last node is true.
    void insert (const std::string& str);

    //isWord
    //Returns true if str is in the sub-Trie starting at the given TrieNode,
    //pre: TrieNode exists and string is passed
    //post: if string is in sub trie returns true. else returns false.
    bool isWord (const std::string& str) const;

    //isPrefix
    //checks if word is in sub-trie
    //pre: TrieNode exists and string is passed
    //post: returns true if pre is a prefix of a word in the sub-Trie starting at
    //the given TrieNode, else returns false
    bool isPrefix (const std::string& pre) const;

    //print
    //Prints all words starting at the given TrieNode.
    //The parameter string str stores the letters of all previous TrieNode objects up to
    //the node currently being processed
    //pre: TrieNode exists and string is passed
    //post: all words staring at given trieNode is printed
    void print (const std::string& str) const;

    //wordCount
    //counts nodes in sub-Trie that ends a word
    //pre: TrieNode exists
    //post: returns a count all the nodes in the sub-Trie that end a word
    size_t wordCount ( ) const;
};
#endif
