//Gravino, Andrew
//CS2600, In Class Coding Assignment 2
//10-1-21

/*
1. Hard code an array initialization and definition that will be evaluted by Lo Shu Magic Square if conditions
2. The if conditions will assign certain truth values to booleans initialized at the beginning
3. Nearing the end of the file, the booleans will all be checked and it will print out whether or not the provided array was a magic square or not
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void swapper(int *a, int *b){
    int c = *a;
    *a = *b;
    *b = c;
}

void randomArrayGenerator(int array[], int a){
    time_t t;
    srand((unsigned) time(&t));

    for(int x = a - 1; x > 0; x--){
        int y = rand() % (x+1);
        swapper(&array[x], &array[y]);
    }
}

int main() {
    bool rows15 = false;
    bool columns15 = false;
    bool diagonals15 = false;

    int iterationAttemptCount = 0;

    int tableInput[3][3];
    int checkerIndex = 0;
    int oneThroughNine[9] = {1,2,3,4,5,6,7,8,9}; //this sets the random pool to only 1-9

    if (rows15 == false || columns15 == false || diagonals15 == false) {
        do {
            rows15 = false; //refresh
            columns15 = false;
            diagonals15 = false;

            int a = sizeof(oneThroughNine)/sizeof(oneThroughNine[0]);
            randomArrayGenerator(oneThroughNine, a); 
            for (int rowIndex = 0; rowIndex < 3; rowIndex++) {
                for (int columnIndex = 0; columnIndex < 3; columnIndex++) {
                    tableInput[rowIndex][columnIndex] = oneThroughNine[checkerIndex]; //this gets rid of having duplicates 
                    checkerIndex++;
                }
            }
            checkerIndex = 0;

            int row1 = tableInput[0][0] + tableInput[0][1] + tableInput[0][2];
            int row2 = tableInput[1][0] + tableInput[1][1] + tableInput[1][2];
            int row3 = tableInput[2][0] + tableInput[2][1] + tableInput[2][2];
            if (row1 == 15 && row2 == 15 && row3 == 15) { //this and the next 3 if statements will all check for the equal value of 15
                rows15 = true;
            }

            int column1 = tableInput[0][0] + tableInput[1][0] + tableInput[2][0];
            int column2 = tableInput[0][1] + tableInput[1][1] + tableInput[2][1];
            int column3 = tableInput[0][2] + tableInput[1][2] + tableInput[2][2];
            if (column1 == 15 && column2 == 15 && column3 == 15) {
                columns15 = true;
            }

            int diagonal1 = tableInput[0][0] + tableInput[1][1] + tableInput[2][2];
            int diagonal2 = tableInput[0][2] + tableInput[1][1] + tableInput[2][0];
            if (diagonal1 == 15 && diagonal2 == 15) {
                diagonals15 = true;
            }

            iterationAttemptCount++;
            printf("Running test: %d...\n", iterationAttemptCount);
            for(int i = 0; i < 9; i++){
                printf("%d", oneThroughNine[i]);
            }
            printf("\n");
        } while (rows15 == false || columns15 == false || diagonals15 == false);
    }

    printf("This is what your successful array looks like:\n"); //printing our hard coded input in the 3 by 3 format requested
    for (int rowIndex = 0; rowIndex < 3; rowIndex++) {
        printf("[ ");
        for (int columnIndex = 0; columnIndex < 3; columnIndex++) {
            printf("%d ", tableInput[rowIndex][columnIndex]);
        }
        printf("]\n");
    }
    printf("It took %d attempts to get here.", iterationAttemptCount);

    return EXIT_SUCCESS;
}