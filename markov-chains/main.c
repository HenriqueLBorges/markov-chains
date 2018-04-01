//
//  main.c
//  markov-chains
//
//  Created by Henrique Borges on 31/03/18.
//  Copyright © 2018 Henrique Borges. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

//Functions
void testMarkovChain(){
    int states = 0, option = 0;
    printf("How many states your markov chain has?\n");
    scanf("%d", &states);
    
    float **matrix = createNewMatrix(states, states);
    matrix = clearMatrix(matrix, states);
    
    while(1){
        insertsData(matrix, states);
        printMatrix(matrix, states);
        printf("Do you want to modify any value?\n");
        printf("Any other key - Yes\n");
        printf("0 - No\n");
        scanf("%d", &option);
        if(option == 0)
            break;
    }
    
    matrix = diagonalAjust(matrix, states);
    printMatrix(matrix, states);
    
    float values [states];
    
    //Test states probabilities loop.
    while(1){
        
        //Insert states probabilities loop
        while(1){
            printf("Inserts the states probabilities\n");
            for(int i = 0; i < states; i++){
                printf("State %d = ", i);
                scanf("%f", &values[i]);
            }
            printf("Do you want to modify any value?\n");
            printf("Any other key - Yes\n");
            printf("0 - No\n");
            scanf("%d", &option);
            if(option == 0)
                break;
        }
        
        printf("States probabilities ");
        printArray(values, states);
        
        printf("==============================\n");
        getResult(matrix, values, states);
        printf("==============================\n");
        
        printf("Do you want to try again with the same matrix?\n");
        printf("Any other key - Yes\n");
        printf("0 - No\n");
        scanf("%d", &option);
        if(option == 0)
            break;
    }
}

void insertsData(float **matrix, int length){
    int line, column, option;
    
    while(1){
        //Inserts data.
        printf("Inserts matrix coordinates.\n");
        printf("Line = ");
        scanf("%d", &line);
        printf("Column = ");
        scanf("%d", &column);
        printf("Insert a new value = ");
        if(line < length && column < length){
            scanf("%f", &matrix[line][column]);
            
            printf("Quit inputing values?\n");
            printf("0 - Quit\n");
            printf("Other number - Continue\n");
            scanf("%d", &option);
            if(option == 0)
                break;
        } else {
            printf("Your line and column must be lower than %d.\n", length);
        }
    }
}

float **createNewMatrix(int lines, int columns){
    float **matrix = (float **)malloc(lines*sizeof(float));
    for(int i=0;i<lines;i++)
        matrix[i]=(float *)malloc(columns*sizeof(float));
    return matrix;
}

float **clearMatrix(float **matrix, int length){
    for(int i = 0; i < length; i++){
        for(int j = 0; j < length; j ++){
            matrix[i][j] = 0;
        }
    }
    return matrix;
}

float **diagonalAjust(float **matrix, int length){
    float resultado;
    for(int i = 0; i < length; i++){
        resultado = 0;
        for(int j = 0; j < length; j ++){
            resultado += matrix[i][j];
        }
        if(resultado > 0)
            matrix[i][i] = difference(resultado, 0) * (-1);
    }
    return matrix;
}

void printMatrix (float ** matrix, int length){
    for(int line = 0; line < length; line++){
        for(int cont = 0; cont < length; cont++){
            if(cont != (length -1)) printf("-------");
            else {
                printf("-------\n");
                printf("|");
            }
        }
        for(int column = 0; column < length; column++){
            printf(" %.2f |", matrix[line][column]);
        }
        printf("\n");
    }
    for(int cont = 0; cont < length; cont++){
        if(cont != (length -1)) printf("-------");
        else printf("-------\n");
    }
}

void printArray(float array [], int length){
    for(int i = 0; i < length; i++){
        printf("[%d] = %.2f, ", i, array[i]);
    }
    printf("\n");
}

float difference(float x, float y){
    if(x > y) return x - y;
    else return y - x;
}

void getResult (float ** matrix, float array [], int length){
    float result;
    for(int column = 0; column < length; column++){
        result = 0;
        printf("State %d = ", column);
        for(int line = 0; line < length; line++){
            result += array [line] * matrix [line][column];
            printf("(%.2f x %.2f)", array[line], matrix[line][column]);
            
            if(line != (length - 1))
                printf(" + ");
        }
        printf(" = %.2f\n", result);
    }
}

int main(int argc, const char * argv[]) {
    printf("markov chains\n");
    while(1){
        printf("Choose an option\n");
        int option = 0;
        printf("1 - Test a new markov chain (Continuous-time Markov chain)\n");
        printf("0 - Exit\n");
        scanf("%d", &option);
        switch (option) {
            case 1:
                testMarkovChain();
                break;
            case 0:
                printf("Exiting...\n");
                return 0;
        }
    }
    return 0;
}
