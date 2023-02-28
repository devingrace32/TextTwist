// File name: TrieNode.cpp
// Name: Devin Arrants
// VUnetid: arrantdg
// Email: devin.g.arrants@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor statement: I pledge on my honor that I have neither given nor received unauthorized aid
// Description: Impliments a TrieNode.  Contains functions
//     prototypes to insert, print, check if word is in subtree, and node count
// Last Changed: 4/18/2018

#include <cstddef>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "TrieNode.h"


//The constructor. Takes a character for the node, and a bool
//indicating whether it represents the end of a word. Note, there is no
//default ctor.
TrieNode::TrieNode(char c, bool b): end(b), ch(c), alphabet{nullptr}{

}

//copy constructor
// pre:  Class object, TrieNode, exists
// post: Object is initialized to be a copy of the parameter
TrieNode::TrieNode(const TrieNode& rhs): end(rhs.end), ch(rhs.ch), alphabet{nullptr} {
    for(size_t i = 0; i < LETTERS; i ++){
        if(rhs.alphabet[i] != nullptr){
            alphabet[i] = new TrieNode(*rhs.alphabet[i]);

        }
    }
}

//destructor
// Destroys a TrieNode
// pre:  Class object exists
// post: Class object does not exist
TrieNode::~TrieNode( ){
    for(size_t i = 0; i < LETTERS; i++){
        delete alphabet[i];
        alphabet[i] = nullptr;
    }
}

//Assignment Operator
// Assigns a TriNode to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
const TrieNode &TrieNode::operator= (const TrieNode& rhs){
    if(this != &rhs) {
        TrieNode tmp(rhs);
        std::swap(end, tmp.end);
        std::swap(ch, tmp.ch);
        std::swap(alphabet, tmp.alphabet);
    }
    return *this;
}

//insert
//inserts a string into the given TrieNode. Create new TrieNodes as needed.
//pre: TrieNode exists and string is passed
//post: string is inserted and boolean flag on last node is true.
void TrieNode::insert (const std::string& str){
    if(str == ""){
        end = true;
        return;
    }
    int loc = str.at(0) - 'a';
    if(alphabet[loc] == nullptr){
        TrieNode *newNode = new TrieNode(str.at(0), false);
        alphabet[loc] = newNode;
    }
    alphabet[loc]->insert(str.substr(1,str.size()));
}

//isWord
//Returns true if str is in the sub-Trie starting at the given TrieNode,
//pre: TrieNode exists and string is passed
//post: if string is in sub trie returns true. else returns false.
bool TrieNode::isWord (const std::string& str) const{
    if(str == "" ){
        return end;
    }
    int loc = str.at(0) - 'a';
    if(alphabet[loc] != nullptr){
        return alphabet[loc] -> isWord(str.substr(1, str.length()));
    }
    else{
        return false;
    }
}

//isPrefix
//checks if word is in sub-trie
//pre: TrieNode exists and string is passed
//post: returns true if pre is a prefix of a word in the sub-Trie starting at
//the given TrieNode, else returns false
bool TrieNode::isPrefix (const std::string& pre) const{
    if(pre == ""){
        return true;
    }
    int loc = pre.at(0) - 'a';

    if(alphabet[loc] != nullptr){
        return alphabet[loc] -> isPrefix(pre.substr(1, pre.length()));
    }
    else {
        return false;
    }
}

//print
//Prints all words starting at the given TrieNode.
//The parameter string str stores the letters of all previous TrieNode objects up to
//the node currently being processed
//pre: TrieNode exists and string is passed
//post: all words staring at given trieNode is printed
void TrieNode::print (const std::string& str) const{
    if(end) {
        std::cout << str << std::endl;
    }
    for(size_t i = 0; i < LETTERS; i++){
        if(alphabet[i] != nullptr ) {
            alphabet[i]->print(str + alphabet[i]->ch);
        }
    }
}

//wordCount
//counts nodes in sub-Trie that ends a word
//pre: TrieNode exists
//post: returns a count all the nodes in the sub-Trie that end a word
size_t TrieNode::wordCount ( ) const{
    size_t cnt = 0;
    if(end){
        cnt++;
    }
    for(size_t i = 0; i < LETTERS; i++){
        if(alphabet[i]!= nullptr) {
            cnt += alphabet[i]->wordCount();
        }
    }
    return cnt;
}