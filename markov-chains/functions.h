//
//  Header.h
//  markov-chains
//
//  Created by Henrique Borges on 31/03/18.
//  Copyright © 2018 Henrique Borges. All rights reserved.
//

#ifndef Header_h
#define Header_h

void testMarkovChain(void);
float ** createNewMatrix(int, int);
float ** clearMatrix(float **, int);
void insertsData (float **, int);
void printMatrix (float **, int);
void printArray (float [], int);
float ** diagonalAjust(float **, int);
void getResult (float **, float [], int);
float difference (float, float);
void test (void);
#endif /* Header_h */
