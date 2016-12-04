//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Patrick Bardo on 2016-11-22.
//  Copyright © 2016 Patrick Bardo. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include <string>

using FString = std::string;
using int32 = int;

#endif /* FBullCowGame_hpp */

struct FBullCowCount
{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum EGuessStatus
{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame {
public:
    FBullCowGame();
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;
    
    FString GetRandomWord(); // TODO implement
    void Reset(); // TODO Have a more rich reset method
    FBullCowCount SubmitValidGuess(FString);


private:
    //See ctor for initializations
    int32 MyMaxTries;
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool bGameIsWon;
    
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;
};
