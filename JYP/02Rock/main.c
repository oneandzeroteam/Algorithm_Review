//
//  main.c
//  EDGEIsTrash
//
//  Created by 박재영 on 2016. 9. 7..
//  Copyright © 2016년 박재영. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

double MinimumCost(int, int, int*);

int main(int argc, const char * argv[]) {
    
    int num_quiz;
    int num_availableDays;
    int num_casted;
    
    // input
    scanf("%d", &num_quiz);
    
    for(int k1 = 0; k1 < num_quiz; k1++) {
        scanf("%d %d", &num_availableDays, &num_casted);
        
        int* cost = (int*)malloc(sizeof(int) * (num_availableDays));
        
        for(int k2 = 0; k2 < num_availableDays; k2++) {
            scanf("%d", &cost[k2]);
        }
        
        printf("%lf\n", MinimumCost(num_availableDays, num_casted, cost));
    }
    
    return 0;
}

double MinimumCost(int num_availableDays, int num_casted, int* cost) {
    int sum = 0;
    double avg = 0, opt_avg;
    int idx;

    for(idx=0; idx<num_casted; idx++) {
        sum += cost[idx];
    }
    avg = (double)sum / idx;
    opt_avg = avg;

    for(; idx<num_availableDays; idx++) {
        sum += cost[idx];
        if(cost[idx] < opt_avg) {
            avg = (double)sum / (idx+1);
            if (opt_avg > avg) {
                opt_avg = avg;
            }
        }
    }

    return opt_avg;
}