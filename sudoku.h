#ifndef SUDOKU_H
#define SUDOKU_H

#include <iostream>
#include <fstream>

using namespace std;

class Sudoku{


private:
    int grid[9][9];
    // a 9*9 2D array

public:

    void setSudoku(int row, int column, int n);
    // stores the digit n in the 2D array

    void printSudokuGrid(ostream &writeToFile);
    // prints the solution to the screen and to a file

    bool numAlreadyInRow(int row, int num);
    // checks whether the given number is in this row
    
    bool numAlreadyInColumn(int column, int num);
    // checks whether the given number is in this column

    bool canPlaceNum(int &row, int &column,int num);
    // checks whether the given number can be placed in this row and this column (and this 3*3 box)

    bool findEmptyGridSlot(int &row,int &column);
    // if there is remaining emply (0) slots in the 9*9 sudoku, stores its coordinates in its arguments return true. If not, return false

    bool numAlreadyInBox(int smallGridRow, int smallGridCol, int num);
    // checks whether the given number is in this 3*3 box.

    bool solveSudoku();
    // a recursive funciton. If it cannot place any number, it will return to the previous step (when it just found the empty grid). And if it still cannot place then goes back again
};
#endif