// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    
    // Setting Up Game
    InitGame();

    PrintLine(TEXT("[DEBUG] The HiddenWord is: %s"), *HiddenWord);

    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bulls & Cows!"));
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); // Change the hardcoded number
    PrintLine(TEXT("Type your guess and \nPress <Enter> to continue..."));

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();

    // Check if Input is an isogram
    if (Input == HiddenWord)
    {
        PrintLine(TEXT("You found the Hidden Word! Well done!"));
        PrintLine(Input);
    } 
    else
    {
        // Prompt to GuessAgain
        PrintLine(TEXT("Wrong answer, try again!"));
    }
    
        // Remove live
        // Check if live < 0
        // If yes GuessAgain
        // If No Show GameOver and HiddenWord
        // Prompt to play again
        // Check User Input
        // PlayAgain or Quit
}

void UBullCowCartridge::InitGame()
{
    HiddenWord = TEXT("computer");
    Lives = 4;
}