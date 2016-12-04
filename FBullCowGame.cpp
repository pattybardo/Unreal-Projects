//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Patrick Bardo on 2016-11-22.
//  Copyright © 2016 Patrick Bardo. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <iostream>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;


FBullCowGame::FBullCowGame()
{
    Reset();
}

int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}
int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const{ return bGameIsWon;}





void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 12;
    const FString HIDDEN_WORD = "cranium";
    
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bGameIsWon = false;
    
    return;
}

FString FBullCowGame::GetRandomWord() // TODO
{
    return "blue";
}



EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (!IsIsogram(Guess)) // if the guess isnt an isogram
    {
        return EGuessStatus::Not_Isogram;
    }
    else if (!IsLowercase(Guess)) // if the guess isnt all lowercase return an error
    {
        return EGuessStatus::Not_Lowercase;
    }
    else if (Guess.length() != GetHiddenWordLength() )
    {
        return EGuessStatus::Wrong_Length;
    }
    else
    {
        return EGuessStatus::OK;
    }

    //If the guess length is wrong
        // return an error
    //Otherwise
        // Return OK
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    
    //loop through all the letters
    int32 WordLength = MyHiddenWord.length(); //Assume both words have same length
        for (int32 i = 0; i < WordLength; i++) {
        // compare the letters against the hidden word
            for (int32 j = 0; j < WordLength; j++) {
            //increment bulls if they're in the same place
                if (MyHiddenWord[i] == Guess[j]){
                    if (i == j){
                        BullCowCount.Bulls++;
                    }
                    else{
                        //increment cows if you have the right letter in the wrong place
                        BullCowCount.Cows++;
                    }
                }
            
            }
            
        }
    if (BullCowCount.Bulls == WordLength) {
        bGameIsWon = true;
    }
    return BullCowCount;
    
}

bool FBullCowGame::IsIsogram(FString Word) const
{
    if (Word.length() <= 1)
    {
        return true;
    }
    TMap<char, bool> LetterSeen; // Example of hash table
    for (auto Letter : Word)
    {
        Letter = tolower(Letter);
        if (LetterSeen[Letter]) {// Check if the letter has shown up in the word before
            return false; // We do NOT hasve an isogram at this stage
        } else // If the letter has not been in the word before, update the hash table to show that the letter has shown up before
        {
            LetterSeen[Letter] = true;
        }
    }
    return true;
};

bool FBullCowGame::IsLowercase(FString Word) const
{
    for (auto Letter : Word)
    {
        if (!islower(Letter)) {
            return false;
        }
    }

    return true;
};
