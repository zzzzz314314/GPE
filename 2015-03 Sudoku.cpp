// https://www.tutorialspoint.com/sudoku-solver-in-cplusplus
#include <iostream>
#define N 9
using namespace std;
int grid[N][N];

bool isPresentInCol(int col, int num){ //check whether num is present in col or not
   for (int row = 0; row < N; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool isPresentInRow(int row, int num){ //check whether num is present in row or not
   for (int col = 0; col < N; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool isPresentInBox(int boxStartRow, int boxStartCol, int num){
//check whether num is present in 3x3 box or not
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}
void sudokuGrid(){ //print the sudoku grid after solve
   for (int row = 0; row < N; row++){
      for (int col = 0; col < N; col++){
         cout << grid[row][col] <<" ";
      }
      cout << endl;
   }
}
bool findEmptyPlace(int &row, int &col){ //get empty location and update row and column
   for (row = 0; row < N; row++)
      for (col = 0; col < N; col++)
         if (grid[row][col] == 0) //marked with 0 is empty
            return true;
   return false;
}
bool isValidPlace(int row, int col, int num){
   //when item not found in col, row and current 3x3 box
   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 ,
col - col%3, num);
}
bool solveSudoku(){
   int row, col;
   if (!findEmptyPlace(row, col))
      return true; //when all places are filled
   for (int num = 1; num <= 9; num++){ //valid numbers are 1 - 9
      if (isValidPlace(row, col, num)){ //check validation, if yes, put the number in the grid
         grid[row][col] = num;
         if (solveSudoku()) //recursively go for other rooms in the grid
            return true;
         grid[row][col] = 0; //turn to unassigned space when conditions are not satisfied
      }
   }
   return false;
}
int main(){
   int n;
   cin >> n;

   for (int i = 0; i < n; i++)
   {
       // read in the sudoku
       for (int row = 0; row < N; row++)
       {
           for (int col = 0; col < N; col++)
                cin >> grid[row][col];
       }
       if (solveSudoku() == true)
            sudokuGrid();
   else
       cout << "No" << endl;
   }

}
