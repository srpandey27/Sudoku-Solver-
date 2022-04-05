// The name of the program: Lab 6.
// This program is written by Saurav Pandey (pandey1@kenyon.edu) and Lucas (Yiyang) Lu (lu1@kenyon.edu). We contributed about equally to the development of the program and we followed the guidelines for Pair Programming.
// This program asks users to take the incomplete sudoku from the file "puzzle". It lets the user enter a file name in order to store the solution of the given sudoku. It can also print out the result on the screen.
#include <iostream>
#include <fstream>
#include <string>
#include "sudoku.h"
using namespace std;

int main() {
    int solveAgain=1;
    while (solveAgain==1){
      cout << "--------------------------------------------------" << endl;
      cout << endl<< "Hello, and welcome to the Sudoku Solver !" << endl;
      Sudoku sudoku_puzzle;
      int number, digit, temp, choice=1;
      bool failOpen;
      string inputFileName,outputFileName;
      ifstream infile;
      ofstream outfile;
      do { // makes sure to open a file that exists.
          
          choice=0;
          failOpen=true;
          cout << "We have four puzzles with us. Their file names are as follows:"<<endl;
          cout << "1. puzzle1" <<endl;
          cout << "2. puzzle2" << endl;
          cout << "3. puzzle3" << endl;
          cout << "4. puzzle4" << endl<<endl;
          cout << "We will solve your desired sudoku puzzle.";
          cout << endl << "Enter the name of the file you want to open : ";
          
          getline(cin,inputFileName); 
          
          infile.open(inputFileName);
          if (infile.fail()){
              cout << "Sorry, the file could not be opened" << endl;
              cout << "Do you want to try again? Enter 1 to open a file again, 0 to exit : ";
              cin>>choice;
              cin.ignore();
              failOpen=false;
          }
          
      } while (choice==1);

      if (failOpen){   // Only if the file was opened, perform the following computations.

          for (int i=0; i<=8; i++){
              infile>>number;
              for (int j=8; j>=0; j--){
                  temp=number;
                  digit=temp%10;
                  sudoku_puzzle.setSudoku(i,j,digit);
                  number=number/10;
              }
          }
          infile.close();
          cout  << "Enter the name of the file to write the solution to: "; // output file.
          getline(cin,outputFileName);
          outfile.open(outputFileName);

          if (sudoku_puzzle.solveSudoku()){
              sudoku_puzzle.printSudokuGrid(outfile);
          }
          else{
              cout << "There are no solutions to the Sudoku puzzle.";
              outfile<< "There are no solutions to the Sudoku puzzle."; 
          }
          outfile.close();
      }
      else
      {
          cout << "No file received. Program has been terminated. "; // if no file was opened.
      }

      cout << endl<< "Do you want to solve another puzzle? Enter 1 if you want to. Enter 0 to exit : ";
      cin>>solveAgain;
      cin.ignore();   // this was necessary to prevent any error caused by the getline function
    }
    cout << endl << endl << "-----------------------------------------------------" << endl;
}
