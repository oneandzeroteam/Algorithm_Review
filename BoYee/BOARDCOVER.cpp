#include <cstdlib>
#include <iostream>

using namespace std;

void debugging(bool *board, int w, int h, int *available, int *remain)
{
     printf("-------------\nava: %d  ramain: %d\n",*available, *remain);
     
     for(int i =0; i<w;i++)
             {
              for(int j=0; j< h;j++)
                   {
                           printfa("%d ",board[i*h+j]);
                   }     
                   printf("\n");
              }
     printf("-------------\n");
}

void find(bool *board, int w, int h,int k, int m, int *available, int *remain)
{
    if(*remain == 0)
   {(*available)++; printf("i find !!$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n"); return; }
   // printf("remain: %d\n",*remain);
    
    for(int i = k; i<w-1; i++)
    {
            for(int j =m; j<h-1; j++)
            {     //   printf("i == %d j == %d\n",i,j);
                     if(*remain == 3){
                     debugging(board,w,h,available,remain);
                     printf("i: %d j: %d\n",i,j);
                                                           }
                      bool f1=false,f2=false,f3=false,f4=false;
                      
                     // find(board, w, h, i,j,available,remain);                
                      
                      if(board[i*h+j] && board[(i+1)*h+j] && board[(i+1)*h+(j+1)])
                       {
                        f1 = true;
                      //  printf("f1 go\n");
                        if(*remain == 3){printf("f1\n");
                         debugging(board,w,h,available,remain);}
                        board[i*h+j]=0; board[(i+1)*h+j]=0; board[(i+1)*h+(j+1)] =0;
                        *remain-=3;
                        find(board, w, h, i,j,available,remain);
                        if(j+2<h)
                                 find(board, w, h, i,j+1,available,remain);
                        board[i*h+j]=1; board[(i+1)*h+j]=1; board[(i+1)*h+(j+1)] =1;
                        *remain+=3;
                    //    printf("f1 out\n");
                       }
                       
                       if(board[(i+1)*h+j] && board[(i+1)*h+(j+1)] && board[i*h+(j+1)])
                       {
                     //   printf("f2 go\n");                   
                        f2 = true;
                        if(*remain == 3){printf("f2\n");
                         debugging(board,w,h,available,remain);}
                        board[(i+1)*h+j]=0; board[(i+1)*h+(j+1)] =0; board[i*h+(j+1)] = 0;
                        *remain-=3;
                        find(board, w, h,i,j, available,remain);
                        if(j+2<h)
                                 find(board, w, h, i,j+1,available,remain);
                        board[(i+1)*h+j]=1; board[(i+1)*h+(j+1)] =1; board[i*h+(j+1)] = 1;
                        *remain+=3;
                     //   printf("f2 out\n");
                       }
                       
                       if(board[i*h+j] && board[(i+1)*h+(j+1)] && board[i*h+(j+1)])
                       {
                    //   printf("f3 go\n");                
                         if(*remain == 3){printf("f3\n");
                         debugging(board,w,h,available,remain);}
                        f3 = true;
                        board[i*h+j]=0; board[(i+1)*h+(j+1)]=0; board[i*h+(j+1)] =0;
                       *remain-=3;
                       find(board, w, h, i,j,available,remain);
                       if(j+2<h)
                                 find(board, w, h, i,j+1,available,remain);
                        board[i*h+j]=1; board[(i+1)*h+(j+1)]=1; board[i*h+(j+1)] =1;
                        *remain+=3;
                    //    printf("f3 out\n");
                       }
                       
                       if(board[i*h+j] && board[(i+1)*h+j] && board[i*h+(j+1)])
                       {
                    //    printf("f4 go\n");
                       if(*remain == 3){ printf("f4\n");
                         debugging(board,w,h,available,remain);}
                        f4 = true;
                        board[i*h+j]=0; board[(i+1)*h+j]=0; board[i*h+(j+1)] =0;
                        *remain-=3;
                       find(board, w, h,i,j, available,remain);
                       if(j+2<h)
                                 find(board, w, h, i,j+1,available,remain);
                        board[i*h+j]=1; board[(i+1)*h+j]=1; board[i*h+(j+1)] =1;
                        *remain+=3;
                   //    printf("f4 out\n");
                       }
                       
                       
            }
    }
    
}




int main(int argc, char *argv[])
{ 
    int testcase;
    int remain;
    scanf("%d",&testcase);
    printf("test casse #:%d\n",testcase);
    for(int i =0;i<testcase;i++)
    {
            remain =0;
            // Put testcase into board.
            int w, h;
            scanf("%d %d",&w,&h);
            printf("w:%d h:%d\n",w,h);
            fflush(stdin);
            char *board_box = (char *)malloc(sizeof(char)*w*h);
            bool *board = (bool *)malloc(sizeof(bool)*w*h);
            for(int j = 0; j<w;j++)
                     gets(&board_box[j*h]);
             
             // test.
             for(int j=0 ;j<w ;j++){
             for(int k=0 ;k<h ;k++){
                     if(board_box[j*h+k] == '#')
                         board[j*h+k] = false;
                     else
                       { remain++; board[j*h+k] = true;}
                   
               }
             //      printf("\n");
            }    
                           
             int available =0;
             
             find(board, w, h,0,0, &available, &remain);
             
             printf("available: %d \n",available);        
            // end testcase   
            free(board);     
            free(board_box);                           
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
