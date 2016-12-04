//
//  main.cpp
//  BullCowGame
//
//  Created by Patrick Bardo on 2016-11-21.
//  Copyright © 2016 Patrick Bardo. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

using FText = std::string;
using int32 = int;


void PrintIntro();
void PlayGame();
FText GetValidGuess();
void PrintGuess(FText Guess);
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame;

// The main function
int main()
{
    do{
        PrintIntro();
        PlayGame();
    } while (AskToPlayAgain());
    return 0;
}

// Print the beginning blurb
void PrintIntro()
{
    std::cout << "\n\nWelcome to Bulls and Cows" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I am thinking of? \n";
    return;
}

//Play the actual game
void PlayGame()
{
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    //Loop asking for guesses
    //while the game is NOT won and there are still remaining guesses
    do {//TODO cleanup this loop
        FText Guess = GetValidGuess();
        
        
        
        // Submit a valid guess to the game, and receive a count
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

        
        std::cout << "Bulls: " << BullCowCount.Bulls;
        std::cout << ", Cows: " << BullCowCount.Cows<< "\n";
        
        } while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries );
    //TODO SUMMMARISE GAME
    
    PrintGameSummary();
    
    return;
}


FText GetValidGuess()
{
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    do {
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try "<< CurrentTry << ". Enter your guess: ";
        std::getline (std::cin, Guess);
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
            case EGuessStatus::Wrong_Length:
                std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word \n";
                break;
            case EGuessStatus::Not_Isogram :
                std::cout << "Please enter a word which is an isogram \n";
                break;
            case EGuessStatus::Not_Lowercase :
                std::cout << "Please enter all lowercase characters \n";
                break;
            default:
                //assume the guess is valid
                break;
        }
        std::cout << std::endl;
    } while (Status != EGuessStatus::OK); // Keep looping until the guess is valid
    return Guess;
}


bool AskToPlayAgain()
{
    std::cout << "Do you want to play again with the same word? (y/n): ";
    FText Response = "";
    std::getline(std::cin,Response);
    std::cout << std::endl;
    return (Response[0] == 'y' || Response[0] == 'Y');
   
}

void PrintGameSummary()
{
    if (BCGame.IsGameWon())
    {
        std::cout << "Congratulations, you have won the game! \n";
    }
    else
    {
        std::cout << "Sorry, you lose. \n";
    }
    return;
}
