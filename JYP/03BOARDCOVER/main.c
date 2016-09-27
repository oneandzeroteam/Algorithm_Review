//
//  main.c
//  EDGEIsTrash
//
//  Created by 박재영 on 2016. 9. 7..
//  Copyright © 2016년 박재영. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void Num_CoverCase(char**, int, int, int*);
int Validate_and_Fill(int type, int num_H, int num_W, int h, int w, char** arr_Board, char filler);
void print_map(char** arr_Board, int num_H, int num_W);

int main(int argc, const char * argv[]) {
    
    int num_quiz;
    int num_H, num_W;
    char** arr_Board;

    int* count = (int*)malloc(sizeof(int));
    
    //input
    scanf("%d", &num_quiz);
    
    for(int k1 = 0; k1 < num_quiz; k1++) {
        scanf("%d %d", &num_H, &num_W);
        
        arr_Board = (char**)malloc(sizeof(char*) * (num_H));
        for(int k2 = 0; k2 < num_H; k2++) {
            arr_Board[k2] = (char*)malloc(sizeof(char) * (num_W));
            scanf("%s", arr_Board[k2]);
            //printf("%s\n", arr_Board[k2]);
        }

        (*count) = 0;
        Num_CoverCase(arr_Board, num_H, num_W, count);
        printf("%d\n", (*count));
    }

    return 0;
}

void Num_CoverCase(char** arr_Board, int num_H, int num_W, int* count) {
    for (int k1 = 0; k1 < num_H; k1++) {
        for (int k2 = 0; k2 < num_W; k2++) {
            if (arr_Board[k1][k2] == '.') {
                for (int type = 1; type <= 4; type++) {
                    if (Validate_and_Fill(type, num_H, num_W, k1, k2, arr_Board, '#')) {
                        Num_CoverCase(arr_Board, num_H, num_W, count);
                        Validate_and_Fill(type, num_H, num_W, k1, k2, arr_Board, '.');
                    }
                }

                return; // 3번 type검사 끝 -> 이번경우의수 검사끝
            } else if (arr_Board[k1][k2] == '#') {
                if(k1 == num_H-1 && k2 == num_W-1)
                    (*count)++;
            }
        }
    }
}

int Validate_and_Fill(int type, int num_H, int num_W, int h, int w, char** arr_Board, char filler) {
    int row1, row2, col1, col2;
    switch(type) {
        case 1:
            row1 = h;   col1 = w+1;
            row2 = h+1; col2 = w;
            if( col1 < num_W) {
                if(row2 < num_H) {
                    if(arr_Board[h][w] != filler
                       && arr_Board[row1][col1] != filler
                       && arr_Board[row2][col2] != filler) {

                        arr_Board[h][w] = filler;
                        arr_Board[row1][col1] = filler;
                        arr_Board[row2][col2] = filler;

                        //print_map(arr_Board, num_H, num_W);
                        return TRUE;
                    }
                }
            }
            break;
        case 2:
            row1 = h;   col1 = w+1;
            row2 = h+1; col2 = w+1;
            if(col1 < num_W) {
                if(row2 < num_H && col2 < num_W) {
                    if(arr_Board[h][w] != filler
                       && arr_Board[row1][col1] != filler
                       && arr_Board[row2][col2] != filler) {

                        arr_Board[h][w] = filler;
                        arr_Board[row1][col1] = filler;
                        arr_Board[row2][col2] = filler;

                        //print_map(arr_Board, num_H, num_W);
                        return TRUE;
                    }
                }
            }
            break;
        case 3:
            row1 = h+1; col1 = w;
            row2 = h+1; col2 = w+1;
            if(row1 < num_H) {
                if(row2 < num_H && col2 < num_W) {
                    if(arr_Board[h][w] != filler
                       && arr_Board[row1][col1] != filler
                       && arr_Board[row2][col2] != filler) {

                        arr_Board[h][w] = filler;
                        arr_Board[row1][col1] = filler;
                        arr_Board[row2][col2] = filler;

                        //print_map(arr_Board, num_H, num_W);
                        return TRUE;
                    }
                }
            }
            break;

        case 4:
            row1 = h+1; col1 = w;
            row2 = h+1; col2 = w-1;
            if(row1 < num_H) {
                if(row2 < num_H && col2 > 0) {
                    if(arr_Board[h][w] != filler
                       && arr_Board[row1][col1] != filler
                       && arr_Board[row2][col2] != filler) {

                        arr_Board[h][w] = filler;
                        arr_Board[row1][col1] = filler;
                        arr_Board[row2][col2] = filler;

                        //print_map(arr_Board, num_H, num_W);
                        return TRUE;
                    }
                }
            }
            break;
    }
    return FALSE;
}

void print_map(char** arr_Board, int num_H, int num_W) {
    for(int k1=0; k1<num_H; k1++) {
        printf("%s\n", arr_Board[k1]);
    }
    printf("\n");
}