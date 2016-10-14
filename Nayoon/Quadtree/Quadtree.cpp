//
// Created by 황나윤 on 2016. 10. 14..
//

#include<stdio.h>
#include<stdlib.h>

char *ptr;

typedef struct treeNode{
    char data;
    treeNode* left;
    treeNode* right;
    treeNode* mid1;
    treeNode* mid2;
}treeNode;

treeNode* makeRootNode(char* data, treeNode* left,treeNode* mid1, treeNode* mid2, treeNode* right){
    treeNode* root= (treeNode*)malloc(sizeof(treeNode));
    if(*data=='x'){
        treeNode* tmp1=makeRootNode(data+1,NULL,NULL,NULL,NULL);
        treeNode* tmp2=makeRootNode(data+2,NULL,NULL,NULL,NULL);
        treeNode* tmp3=makeRootNode(data+3,NULL,NULL,NULL,NULL);
        treeNode* tmp4=makeRootNode(data+4,NULL,NULL,NULL,NULL);

        root=makeRootNode(data, tmp1, tmp2, tmp3, tmp4);
    }
    else {
        root->data = *data;
        root->left = left;
        root->right = right;
        root->mid1 = mid1;
        root->mid2 = mid2;
    }
    if(left->data=='x'){
        treeNode* tmp1=makeRootNode(*ptr+1,NULL,NULL,NULL,NULL);
        treeNode* tmp2=makeRootNode(*ptr+2,NULL,NULL,NULL,NULL);
        treeNode* tmp3=makeRootNode(*ptr+3,NULL,NULL,NULL,NULL);
        treeNode* tmp4=makeRootNode(*ptr+4,NULL,NULL,NULL,NULL);

        makeRootNode('x', tmp1, tmp2, tmp3, tmp4);
    }
    else if(right->data=='x'){

    }
    else if(mid1->data=='x'){

    }
    else if(mid2->data=='x'){

    }
    else
        return root;
}

int main(){
    int CaseNum;
    int i,j;

    char arr[50][1000];//case는 50개 문자열 1000개까지 입력.

    //케이스 개수 입력
    scanf("%d",&CaseNum);
    //case 개수 만큼 입력받기.

    //각 포인터에 입력받은 배열의 주소가 들어갑니다.

    for(i=0;i<CaseNum;i++) {
        scanf("%s", arr[i]);
    }

    //arr[0][!],arr[1][!]...이 생성.
    for(i=0;i<CaseNum;i++) {
        //하나의 케이스. (각각)
        j=0;
        ptr=arr[i];
        while(*ptr='\0') {
            if(*ptr=='x'){
                treeNode* tmp1=makeRootNode(*(ptr+1),NULL,NULL,NULL,NULL);
                treeNode* tmp2=makeRootNode(*(ptr+2),NULL,NULL,NULL,NULL);
                treeNode* tmp3=makeRootNode(*(ptr+3),NULL,NULL,NULL,NULL);
                treeNode* tmp4=makeRootNode(*(ptr+4),NULL,NULL,NULL,NULL);

                makeRootNode(*ptr, tmp1, tmp2, tmp3, tmp4);
                ptr+=5;
            }
            else{
                makeRootNode(arr[i][j],NULL,NULL,NULL,NULL);
            }


        }
    }

    return 0;
}