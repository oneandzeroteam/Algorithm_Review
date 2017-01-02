#include <stdio.h>
#include <stdbool.h>
int multiply(bool fan[], bool group[], int fan_num, int group_num)
{
             int count =0;
             bool res[400000];
                         
             for(int i= 0;i<fan_num;i++)
                     for(int j=0;j<group_num;j++)
                     {   
                         if(!res[i+j]){
                                      res[i+j] = (fan[i]&group[j]);           
                         }    
                     }
             
             for(int i = group_num-1; i<fan_num;i++)
             {
                     if(!res[i]) count++;
             }
             return count;
}

int main(int argc, char *argv[])
{
    bool group[200000], fan[200000];
   
   int Tcase;
   scanf("%d",&Tcase);
   fflush(stdin);
   while(Tcase--)
   {
  
    int group_num = 0;
    int fan_num = 0;
    char ch;
   while ((ch = getc(stdin))!= '\n')
    {
            group[group_num] = (ch == 'M') ? true : false;
            group_num++;
    }

    while ((ch = getc(stdin))!= '\n')
    {
           fan[fan_num] = (ch == 'M') ? true : false;
           fan_num++;
          //  printf(fan[fan_num - i -1] ? "T" : "F");
    }
    
    int count = multiply(fan, group,fan_num, group_num);
    printf("%d\n",count);
   // printf("\ncount :%d\n",count);
    }
   // clock_t end = clock();
   // double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  //  printf("time_spent : %f\n",time_spent);
  // while(true);
   return 0;
}
