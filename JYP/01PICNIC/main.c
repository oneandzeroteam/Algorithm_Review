//
//  main.c
//  EDGEIsTrash
//
//  Created by 박재영 on 2016. 9. 7..
//  Copyright © 2016년 박재영. All rights reserved.
//

#include <stdio.h>

#define swap(a,b); {int temp = b; b = a; a = temp; }

int NumOfPair(int, int, int, int*);
void SearchArr(int*, int, int*, int, int**);

int main(int argc, const char * argv[]) {
    
    int num_quiz;
    int num_stu;
    int num_pair;
    
    // input
    scanf("%d", &num_quiz);
    
    for(int k1 = 0; k1 < num_quiz; k1++) {
        scanf("%d %d", &num_stu, &num_pair);
        
        int* pairs = (int*)malloc(sizeof(int) * (num_pair*2));
        
        for(int k2 = 0; k2 < num_pair; k2++) {
            scanf("%d %d ", &pairs[k2*2], &pairs[k2*2+1]);
        }
        
        printf("%d ", NumOfPair(num_quiz, num_stu, num_pair, pairs));
    }
    
    return 0;
}

int NumOfPair(int num_quiz, int num_stu, int num_pair, int* pairs){
    //1. Data table
    int pair_table[num_stu][num_stu];
    
    for(int k2 = 0; k2 < num_stu; k2++) {
        for(int k3 = 0; k3 < num_stu; k3++) {
            pair_table[k2][k3] = 0;
        }
    }
    
    for(int k2 = 0; k2 < num_pair; k2++){
        int pairA = pairs[k2*2];
        int pairB = pairs[k2*2+1];
        
        if (pairA > pairB){
            swap(pairA, pairB);
        }
        
        pair_table[pairA][pairB] = 1;
    }
    
    
    //2. Search
    int arr[num_stu];
    int count = 0;
    int prefix = 0;
    
    SearchArr(arr, prefix, &count, num_stu, pair_table);
    
    return count;
}

void SearchArr(int* arr, int prefix, int* count, int arrsize, int** pair_table) {
    if (prefix%2) { // odd
        int min_val = arr[prefix-1] + 1;
        for (int k1 = min_val; k1 < arrsize; k1++) {
            int dup_flag = 0;
            for (int k2 = 1; k2 < (int)(prefix); k2+=2) {
                if (arr[k2] == k1) {
                    dup_flag = 1; // 중복검사
                }
            }
            
            if(!dup_flag) {
                if(pair_table[arr[prefix-1]][k1]) { // pair with prefix-1?
                    arr[prefix] = k1;
                    
                    if(prefix + 1 == arrsize) {
                        (*count)++;
                    }
                    else {
                        SearchArr(arr, prefix+1, count, arrsize, pair_table);
                    }
                }
            }
        }
    }
    else { // even
        int min_val = arr[prefix-2] + 1;
        
        for(int k1 = min_val; k1 < arrsize; k1++) {
            int dup_flag = 0;
            
            for(int k2 = 1; k1 < (prefix); k2+=2) {
                if (arr[k2] == k1) {
                    dup_flag = 1;
                }
            }
            
            if (!dup_flag) {
                arr[prefix] = k1;
                SearchArr(arr, prefix+1, count, arrsize, pair_table);
                break;
            }
        }
    }
}
