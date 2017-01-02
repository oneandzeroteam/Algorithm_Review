#include <cstdlib>
#include <iostream>
#include <conio.h>
using namespace std;

typedef struct quadtree
{
      quadtree *child[4];
      char fill;
} quadtree;

quadtree *build(char fill)
{
         
         if(fill == 'w')
         {       
                 quadtree *new_quad = (quadtree *)calloc(sizeof(quadtree),sizeof(quadtree));
                 new_quad->fill = 'w';
                 return new_quad;
         }
         
         if(fill == 'b')
         {       
                 quadtree *new_quad = (quadtree *)calloc(sizeof(quadtree),sizeof(quadtree));
                 new_quad->fill = 'b';
                 return new_quad;
         }
         
         if(fill == 'x')
         {       
                 quadtree *new_quad = (quadtree *)calloc(sizeof(quadtree),sizeof(quadtree));
                 new_quad->fill = 'x';
                 new_quad->child[0] = build(getch());
                 new_quad->child[1] = build(getch());
                 new_quad->child[2] = build(getch());
                 new_quad->child[3] = build(getch());
                 return new_quad;
         }
         
}

void quad_post_order(quadtree *head)
{
     printf("%c",head->fill);
     if(head->child[0] != 0)
                       quad_post_order(head->child[0]);
     if(head->child[1] != 0)
                       quad_post_order(head->child[1]);
     if(head->child[2] != 0)
                       quad_post_order(head->child[2]);
     if(head->child[3] != 0)
                       quad_post_order(head->child[3]);
}

void quad_reverse(quadtree *head)
{
     
     if(head->fill == 'x')
     {
                   quadtree *quad_temp1 =head->child[2];
                   quadtree *quad_temp2 =head->child[3];
                   head->child[2] = head->child[0];
                   head->child[3] = head->child[1];
                   head->child[0] = quad_temp1;
                   head->child[1] = quad_temp2;
                   quad_reverse(head->child[0]);
                   quad_reverse(head->child[1]); 
                   quad_reverse(head->child[2]); 
                   quad_reverse(head->child[3]);                    
     }
    
}

int main(void)
{

    char c;
    quadtree *head = (quadtree *)calloc(sizeof(quadtree),sizeof(quadtree));
    //quadtree *go = head;
    head->fill = 'x';
    head->child[0] = build(getch());
    head->child[1] = build(getch());
    head->child[2] = build(getch());
    head->child[3] = build(getch());

    quad_post_order(head);
    printf("\n");
    quad_reverse(head);
  
    quad_post_order(head);
    printf("\n");
    
    system("PAUSE");
    return 0;
}
