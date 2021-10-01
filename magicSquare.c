//Gravino, Andrew
//CS2600, In Class Coding Assignment 2
//10-1-21

/*
1. Hard code an array initialization and definition that will be evaluted by Lo Shu Magic Square if conditions
2. The if conditions will assign certain truth values to booleans initialized at the beginning
3. Nearing the end of the file, the booleans will all be checked and it will print out whether or not the provided array was a magic square or not
*/
#include <stdlib.h>
#include <stdbool.h>

int main(){
    bool rows15 = false; //done
    bool columns15 = false; //done
    bool diagonals15 = false; //done
    bool containsAll = true; //not done
    bool noRepeats = true; //done
    bool betweenOneAndNine = true; //done

    int tableInput[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int checkerArray[10] = {}; //this declaration and initialization will be used for comparison later down the line
    int checkerIndex = 0;
    for(int rowIndex = 0; rowIndex < 3; rowIndex++){
        for(int columnIndex = 0; columnIndex < 3; columnIndex++){
            checkerArray[checkerIndex] = tableInput[rowIndex][columnIndex];
        }
        checkerIndex++; //way of "iterating" through our empty array
    }

    int oneThroughNine[10] = {0,1,2,3,4,5,6,7,8,9}; 

    for(int rowIndex = 0; rowIndex < 3; rowIndex++){
        for(int columnIndex = 0; columnIndex < 3; columnIndex++){
            if(tableInput[rowIndex][columnIndex] > 9 || tableInput[rowIndex][columnIndex] < 1){
                betweenOneAndNine = false; //if we detect anything outside 1-9, the boolean becomes false
                break;
            }
        }
    }   

    for(int firstOneDIndex = 0; firstOneDIndex < 9; firstOneDIndex++){ //these go up to 9 instead of 10 because
        for(int secondOneDIndex = firstOneDIndex + 1; secondOneDIndex < 9; secondOneDIndex++){ //secondOneDIndex is + 1 each time to increment through and there's no need to compare to items before it since we already do that
            if(checkerArray[firstOneDIndex] == checkerArray[secondOneDIndex]){
                noRepeats = false; //if we detect that the second index finds anything equivalent 
                break;
            }
        }
    }

    int row1 = tableInput[0][0] + tableInput[0][1] + tableInput[0][2];
    int row2 = tableInput[1][0] + tableInput[1][1] + tableInput[1][2];
    int row3 = tableInput[2][0] + tableInput[2][1] + tableInput[2][2];
    if(row1 == 15 && row2 == 15 && row3 == 15){ //this and the next 3 if statements will all check for the equal value of 15
        rows15 = true;
    }

    int column1 = tableInput[0][0] + tableInput[1][0] + tableInput[2][0];
    int column2 = tableInput[0][1] + tableInput[1][1] + tableInput[2][1];
    int column3 = tableInput[0][2] + tableInput[1][2] + tableInput[2][2];
    if(column1 == 15 && column2 == 15 && column3 == 15){
        columns15 = true;
    }

    int diagonal1 = tableInput[0][0] + tableInput[1][1] + tableInput[2][2];
    int diagonal2 = tableInput[0][2] + tableInput[1][1] + tableInput[2][0];
    if(diagonal1 == 15 && diagonal2 == 15){
        diagonals15 = true;
    }

    printf("This is what your array looks like:\n"); //printing our hard coded input
    for(int rowIndex = 0; rowIndex < 3; rowIndex++){
        printf("\n");
        for(int columnIndex = 0; columnIndex < 3; columnIndex++){
            printf(tableInput[rowIndex][columnIndex]);
        }
    }
    if(rows15 && columns15 && diagonals15){
        printf("\nThe array is a magic square!"); //printing final evaluations
    }
    else{
        printf("\nThe array is not a magic square.");
    }

    return EXIT_SUCCESS;
}