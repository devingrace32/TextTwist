// File name: TextTwist.cpp
// Name: Devin Arrants
// VUnetid: arrantdg
// Email: devin.g.arrants@vanderbilt.edu
// Class: CS2201
// Assignment Number: 10
// Honor statement: I pledge on my honor that I have neither given nor received unauthorized aid
// Description: given 7 letters from user, determines all words that can be created from those
//              letters
// Last Changed: 04/23/2018


#include <cstddef>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Trie.h"
#include <string>

const size_t NUMLETTERS = 7;

void getLetters(char letterArr[]);
bool validWord(const std::string &str, const Trie &wordsFound, const Trie &lexicon);
void findWords(std::string str, const Trie &lexicon, char arr[], bool notUsed[], Trie wordsFoundd);

int main(){
    Trie lexicon;
    Trie wordsFound;
    std::cout<<"Loading valid words. Please wait..."<<std::endl;
    lexicon.loadFromFile("ospd.txt");

    std::cout<<"Welcome to the TEXT TWIST Solver."<<std::endl;

    std::string str = "";
    char letterArr[NUMLETTERS];
    getLetters(letterArr);
    bool notUsed[NUMLETTERS];

    for(size_t i = 0; i < NUMLETTERS; i++){ //populate array
        notUsed[i] = true;
    }

    Trie wordsFoundd;
    findWords("", lexicon, letterArr, notUsed, wordsFoundd); //find all the words that can be
    // spelled


}


//getLetters
//gets 7 letters from user and puts into map. If more or less, re-prompts user
//pre: map must exists
//post: letters from user are returned in map where every key is character, and value is number
//of times it appears in the input
void getLetters(char letterArr[]){
    std::cout<<"Enter the 7 letters of the Text Twist game:"<<std::endl;
    std::string userLetters;
    std::cin>> userLetters;
    while(userLetters.length() != NUMLETTERS){
        std::cout<<"You must enter exactly 7 characters."<<std::endl;
        std::cout<<"Enter the 7 letters of the Text Twist game:"<<std::endl;
        std::cin>> userLetters;
    }
    for(size_t i = 0; i < NUMLETTERS; i++ ) {
        userLetters[i] = tolower(userLetters[i]);
        letterArr[i] = userLetters[i];
    }

}

//validWord
//determines if string passed is a valid word
//pre: string is passed
//post: if string is legal, true is returned, else, false
bool validWord(const std::string &str, const Trie &wordsFound, const Trie &lexicon){
    //must be at least three letters
    if(str.length() < 3) {
        return false;
    }
    //must be in lexicon
    else if(!lexicon.isWord(str)) {
        return false;
    }
    //current word has not been considered.
    else if(wordsFound.isWord(str)) {
        return false;
    }
    else {
        return true;
    }
}

//findWords
//finds all legal words that can be spelled with given string
//Pre: lexicon is in Trie, all arrays exists and wordsFound Trie exists
//Post: Trie of all legal words is printed
void findWords(std::string str, const Trie &lexicon, char arr[], bool notUsed[], Trie wordsFound){
    //given a starting letter, find all possible words
    if(validWord(str,wordsFound,lexicon)){
        wordsFound.insert(str);
    }
    //recursively follow valid word paths
    for(size_t i = 0; i < NUMLETTERS; i++){
        if(notUsed[i]){
            if(lexicon.isPrefix(str + arr[i])){
                str = str + arr[i];
                notUsed[i] = false;
                findWords(str, lexicon, arr, notUsed, wordsFound);
                notUsed[i] = true;
                str = str.substr(0, str.length()-1);
            }
        }
    }
    wordsFound.print();
}
