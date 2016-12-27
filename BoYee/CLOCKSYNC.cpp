#include <cstdlib>
#include <iostream>

using namespace std;

static bool sync_info[][16] = {
             {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0},
             {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1},
             {1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0},
             {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
             {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
             {0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
             {0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
             {0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0}
         };

int isComplete(int *clock)
{
    for(int i =0;i<16;i++)
    {
            if(clock[i] !=0)
                        return 0;
                         
    }
    return 1;
}

void gogo(int *clock, int type)
{
     for(int i =0;i<16;i++)
             {
                           if(sync_info[i])
                           {               
                                           clock[i]++;
                                           if(clock[i] == 4)
                                           clock[i] = 0;
                                           }
                           }             
}

void sync(int *clock)
{
     
}

int main(int argc, char *argv[])
{ 
    
         
         int clock[16] = {0,0,0,1,0,0,1,0,0,0,2,0,3,0,0,0};
         
         sync(clock);
         
         system("PAUSE");
         return EXIT_SUCCESS;         
}
