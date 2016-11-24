#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int num;
    int order;
    struct Node* link;
}Node;

//list의 header역할.
typedef struct Node_h{
    Node* head;
}Node_h;

//공백 리스트 생성.(header를 가리키는 포인터를 반환한다.)
Node_h* createList(){
    Node_h* L;
    L=(Node_h*)malloc(sizeof(Node_h));
    L->head=NULL;
    return L;
}

void InsertLastNode(Node_h* list, int x){
    //삽입할 신규 노드 생성
    //1. null을 가진 헤드노드에 삽입하는경우
    //2. 기존 노드를 가진 리스트에 삽입하는 경우
    Node* node_n;
    Node* pointer;

    node_n=(Node*)malloc(sizeof(Node)); //메모리 할당.
    node_n->num = x;
    node_n->link = NULL;

    if(list->head==NULL){
        list->head= node_n;
        return;
    }

    pointer=list->head;

    while(pointer->link!=NULL)pointer=pointer->link;
    pointer->link=node_n;
}

int main(){
    int i,j,N,k,h;
    int kill=1;
    int test_case;
    int survive;

    Node_h* L;
    L = createList();
    Node* node_ptr= L->head;
    Node* kill_ptr= L->head;

    scanf("%d",&test_case);
    scanf("%d %d",&N, &k);

    survive = N;

    for(i=0;i<test_case;i++){
        for(j=0;j<N;j++)
            InsertLastNode(L, j);
        while(survive != 2) {

            node_ptr=L->head->link;
            free(kill_ptr);

            for(h=0;h<k-1;h++)
                node_ptr=node_ptr->link;
            kill_ptr = node_ptr->link;
            free(kill_ptr);

            /*
            while (node_ptr->link-> order != kill + k) node_ptr = node_ptr->link;

            kill = node_ptr->link-> order;
            Node *kill_ptr = node_ptr->link;
            node_ptr->link = node_ptr->link->link;

            while (node_ptr->link!=NULL){
                (node_ptr->order)--;
                node_ptr = node_ptr->link;
            }

            free(kill_ptr);
            //node_ptr->link =
            survive--;*/


        }
    }

}
