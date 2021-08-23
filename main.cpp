/*
Program: Tic Tac Toe
Author: Spencer Peters
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
using namespace std;
//Name: Setup
//Input: Current values of the board
//Output: A vector filled from 1-9 in positions 0-8, of characters
//Purpose: Reset the board to an base state.
// 49 Represents the ASCII value for 1
void setup (vector<char>& game){
  for (unsigned int i = 0; i < game.size(); i++){
    game.at(i) = i + 49;
  }

}
// Name: Board
// Input: Input is the current vector of elements on the board
// Output: Draws the 3x3 board with current status of game.
// Purpose: Keeps track of the current gamestate in a vector
void board (vector<char> gameState){
  cout << "  " << gameState.at(0) << "  " << "|" << "  " << gameState.at(1) << "  " << "|" << "  " << gameState.at(2) << "  " << endl;
  cout << "*****|*****|*****" << endl;
  cout << "  " << gameState.at(3) << "  " << "|" << "  " << gameState.at(4) << "  " << "|" << "  " << gameState.at(5) << "  " << endl;
  cout << "*****|*****|*****" << endl;
  cout << "  " << gameState.at(6) << "  " << "|" << "  " << gameState.at(7) << "  " << "|" << "  " << gameState.at(8) << "  " << endl;
}

//Name: HasWon
//Input: takes in a vector of the current board of moves that have been made
//Output: Returns true if any winning combinations of X's have been made or if any winning combinations of O's have been made
//Purpose: Helps end the game if a winning combination is made by a chain of if-else statements.
bool hasWon(vector<char> gameState){
  if(gameState.at(0) == 'X' && gameState.at(1) == 'X' && gameState.at(2) == 'X'){
    return true;
  }else if(gameState.at(0) == 'X' && gameState.at(3) == 'X' && gameState.at(6) == 'X'){
    return true;
  }else if(gameState.at(1) == 'X' && gameState.at(4) == 'X' && gameState.at(7) == 'X'){
    return true;
  }else if(gameState.at(2) == 'X' && gameState.at(5) == 'X' && gameState.at(8) == 'X'){
    return true;
  }else if(gameState.at(3) == 'X' && gameState.at(4) == 'X' && gameState.at(5) == 'X'){
    return true;
  }else if(gameState.at(6) == 'X' && gameState.at(7) == 'X' && gameState.at(8) == 'X'){
    return true;
  }else if(gameState.at(0) == 'X' && gameState.at(4) == 'X' && gameState.at(8) == 'X'){
    return true;
  }else if(gameState.at(2) == 'X' && gameState.at(4) == 'X' && gameState.at(6) == 'X'){
    return true;
  }else if(gameState.at(0) == 'O' && gameState.at(1) == 'O' && gameState.at(2) == 'O'){
    return true;
  }else if(gameState.at(0) == 'O' && gameState.at(3) == 'O' && gameState.at(6) == 'O'){
    return true;
  }else if(gameState.at(1) == 'O' && gameState.at(4) == 'O' && gameState.at(7) == 'O'){
    return true;
  }else if(gameState.at(2) == 'O' && gameState.at(5) == 'O' && gameState.at(8) == 'O'){
    return true;
  }else if(gameState.at(3) == 'O' && gameState.at(4) == 'O' && gameState.at(5) == 'O'){
    return true;
  }else if(gameState.at(6) == 'O' && gameState.at(7) == 'O' && gameState.at(8) == 'O'){
    return true;
  }else if(gameState.at(0) == 'O' && gameState.at(4) == 'O' && gameState.at(8) == 'O'){
    return true;
  }else if(gameState.at(2) == 'O' && gameState.at(4) == 'O' && gameState.at(6) == 'O'){
    return true;
  }else{
    return false;
  }

}

//Name: Previously Entered
//Input: Current state of the game with index being the indended move
//Output: True if there is an X or an O at the index. False if the selection has not been taken
//Purpose: To maintain unique inputs for player moves
bool prevEntered(vector<char> gameState, int index){
  if(gameState.at(index) == 'X' || gameState.at(index) == 'O'){
    return true;
  }else{
    return false;
  }
}

//Name: Check Draw
//Input: Current state of the game
//Output: Is true if there are 9 entries on the gameboard, false if there is not.
//Purpose: Checks to see if the gameboard has been filled by moves to help trigger a draw ending.
bool checkDraw(vector<char> gameState){
  int entered = 0;
  for(unsigned int i = 0; i < gameState.size(); i++){
    if(prevEntered(gameState, i)){
      entered += 1;
    }

  }
  if(entered == 9){
    return true;
  }else{
    return false;
  }

}

//Name: Clear Screen
//Output: outputs a bunch of endls' due to linux being unable to use system('CLS')
//Purpose: To clear the output with endl's to make it seem like different game screens
void clearScreen(){
  for(int i = 0; i < 30; i++){
    cout << endl;
  }
}

int main(){
  int userInput, computerInput;
  int turnCount = 0;
  bool valid;
  bool playerWinner, computerWinner, draw;
  playerWinner = false;
  computerWinner = false;
  srand(time(0));

  vector <char> game(9);
  setup(game);


  while(playerWinner != true && computerWinner != true){

    // v-- This turn counter means that it is the players turn
    if(turnCount %2 == 0){
      //Player Turn Functionality
      do {
        cout << "Tic Tac Toe" << endl;
        cout << "Select Cell: 1-9" << endl;
        board(game);
        cin >> userInput;

        if(userInput > 9){
          clearScreen();
          valid = false;
          cout << "Out of range" << endl;
        }else if(prevEntered(game, userInput - 1)){
          clearScreen();
          valid = false;
          cout << "Already taken." << endl;
        }else{
          valid = true;
        }

      }while(valid != true);

      game.at(userInput - 1)  = 'X';
      turnCount +=1;
      playerWinner = hasWon(game);
    //Else means that it is the computers turn
    }else{
        // Computer Turn functionality
      do{
        computerInput = rand() % 9;

      }while(prevEntered(game, computerInput));
      game.at(computerInput) = 'O';
      board(game);
      turnCount +=1;
      computerWinner = hasWon(game);
    }

    draw = checkDraw(game);
    if(draw == true){
      clearScreen();
      break;
    }
    clearScreen();
  }

// Outcome if Draw
  if(draw == true && playerWinner != true && computerWinner != true){
    cout << "Draw! No winner!" << endl;
    board(game);
  }

// Outcome if Player is the winner
  if(playerWinner == true){
    cout << "Congratulations you have won!" << endl;
    board(game);
  }

// Outcome if Computer is the winner
  if(computerWinner == true){
    cout << "You have lost to the computer!" << endl;
    board(game);
  }

  return 0;
}
