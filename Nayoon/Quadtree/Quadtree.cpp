//
// Created by 황나윤 on 2016. 10. 14..
//

#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode{
    char data;
    treeNode* left;
    treeNode* right;
    treeNode* mid1;
    treeNode* mid2;
}treeNode;

treeNode* makeRootNode(char data, treeNode* left,treeNode* mid1, treeNode* mid2, treeNode* right){
    treeNode* root= (treeNode*)malloc(sizeof(treeNode));
    root->data=data;
    root->left=left;
    root->right=right;
    root->mid1=mid1;
    root->mid2=mid2;
    if(left->data=='x'){
        makeRootNode('x',)
    }right->data=='x'|mid1->data=='x'|mid2->data=='x')
    return root;
}

int main(){
    int CaseNum;
    int i,j;

    char arr[50][1000];//case는 50개 문자열 1000개까지 입력.

    //케이스 개수 입력
    scanf("%d",&CaseNum);
    //case 개수 만큼 입력받기.

    for(i=0;i<CaseNum;i++) {
        scanf("%s", arr[i]);

    }

    //arr[0][!],arr[1][!]...이 생성.
    for(i=0;i<CaseNum;i++) {
        //하나의 케이스. (각각)
        j=0;
        while(arr[i][j]!='\0') {
            if(arr[i][j]=='x'){
                treeNode* tmp1=makeRootNode(arr[i][j+1],NULL,NULL,NULL,NULL);
                treeNode* tmp2=makeRootNode(arr[i][j+2],NULL,NULL,NULL,NULL);
                treeNode* tmp3=makeRootNode(arr[i][j+3],NULL,NULL,NULL,NULL);
                treeNode* tmp4=makeRootNode(arr[i][j+4],NULL,NULL,NULL,NULL);

                makeRootNode(arr[i][j], tmp1, tmp2, tmp3, tmp4);
                j+=5;
            }
            else{
                makeRootNode(arr[i][j],NULL,NULL,NULL,NULL);
            }


        }
    }

    return 0;
}