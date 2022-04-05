#include <iostream>
#include <string>
#include <fstream>
#include "sudoku.h"
using namespace std;
// All comments for these methods are in the header file.


    // stores the digit n in the 2D array
    void Sudoku::setSudoku(int row, int column, int n){
        grid[row][column]=n;
    }


    void Sudoku::printSudokuGrid(ostream &writeToFile){  // writes the solution to the screen and to a file.
        cout << endl << "Here is the solution to your Sudoku: "<<endl<<endl;
        for (int i=0; i<=8; i++){
            for (int j=0; j<=8; j++){
                cout << grid[i][j];
                cout << " | ";
                writeToFile << grid[i][j];
                writeToFile << " | ";
            }
            cout << endl << "===================================" << endl;
            writeToFile << endl << "===================================" << endl;
        } 
    }


    bool Sudoku::numAlreadyInRow(int row, int num){
        for (int j=0; j<=8; j++){    // same row, different columns.
            if (grid[row][j]==num){
                return true;
            }
        }
        return false;
    }

    bool Sudoku::numAlreadyInColumn(int column, int num){
        for (int i=0; i<=8; i++){  // same column, different rows.
            if (grid[i][column]==num){
                return true;
            }
        }
        return false;
    }

    bool Sudoku::canPlaceNum(int &row, int &column,int num){
        bool rowFilled, columnFilled, numInBox;
        int smallGridRow=row-row%3;   // finds out the range of rows within which the number lies.
        int smallGridCol=column-column%3;  // finds out the range of columns within which the number lies
        numInBox=numAlreadyInBox(smallGridRow, smallGridCol, num);
        rowFilled=numAlreadyInRow(row, num);
        columnFilled=numAlreadyInColumn(column,num);
        if (numInBox || rowFilled || columnFilled){
            return false;
        }
        else{
            return true;
        }

    }

    // if there is remaining emply (0) slots in the 9*9 sudoku, stores its coordinates in its arguments and return true. If not, return false.
    bool Sudoku::findEmptyGridSlot(int &row,int &column){
        for (row=0; row<=8; row++){
            for (column=0; column<=8; column++){
                if (grid[row][column]==0){
                    return true;
                }
            }
        }
        return false;
    }

    bool Sudoku::numAlreadyInBox(int smallGridRow, int smallGridCol, int num){
        for (int i=smallGridRow; i<=smallGridRow+2; i++){
            for (int j=smallGridCol; j<=smallGridCol+2; j++){
                if (grid[i][j]==num){
                    return true;
                }
            }
        }
        return false;
    }


    bool Sudoku::solveSudoku(){
        int row, col;

        if (findEmptyGridSlot(row, col))
        {
            for (int num = 1; num <= 9; num++)
            {
                if (canPlaceNum(row, col, num))
                {
                    grid[row][col] = num;
                    if (solveSudoku()) //recursive call
                        return true;
                    grid[row][col] = 0; // put 0 back
                }
            }
            return false; //backtrack
        }
        else
            return true; //there are no empty slots
    }






