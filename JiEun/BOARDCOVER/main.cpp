#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int game[20][21];
int h, w, test, ch;

int Lshape[4][3][2] = { //L자 모양의 경우의 수
    { { 0, 0 }, { 0, 1 }, { 1, 1 } }, // case 1 : (i, j), (i, j+1), (i+1, j+1) // ㄱ 모양
    { { 0, 0 }, { 0, 1 }, { 1, 0 } }, // case 2 : (i, j), (i, j+1), (i+1, j)   // 좌우반전 ㄱ 모양
    { { 0, 0 }, { 1, 0 }, { 1, 1 } }, // case 3 : (i, j), (i+1, j), (i+1, j+1) // ㄴ 모양
    { { 0, 0 }, { 1, 0 }, { 1, -1 }}  // case 4 : (i, j), (i+1, j-1), (i+1, j) //  좌우반전 ㄴ 모양
};

bool put(int type, int x, int y) { //입력받은 좌표에 격자 넣을 수 있는 지 확인.

    int px, py; //좌표용
    bool isPut = true;
    for(int i = 0; i < 3; i++) {
        px = x + Lshape[type][i][1];
        py = y + Lshape[type][i][0];
        if (px < 0 || py < 0 || px >= w || py >= h)
            isPut = false;
    }
    return isPut;
}

int cover()
{   int num = 0; // 흰 칸을 덮는 방법의 수
    int cover_x = -1;
    int cover_y = -1;
    for (int i = 0; i < h; i++)  {
        for (int j = 0; j < w; j++) {
            if (game[i][j] == 0) { //흰칸이라면 지금 위치는 cx,cy에 저장하고 break
                cover_x = j;
                cover_y = i;
                goto Continued;
            }
        }
    }
    Continued:
    for(int type = 0; type < 4; type++) { //L 블럭의 각 4가지 모양에 대해 게임판에 넣을 수 있는지 알아본다.
        if(put(type,cover_x, cover_y) == true)
            num += cover();
        put(type,cover_x, cover_y);
    }
    return num;
}

int main()
{
    scanf("%d", &test); //테스트케이스 입력.
    while(test--) {
        scanf("%d %d", &h, &w); // H X W 입력
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                scanf("%c", &ch);   // 게임판의 모양(# . ) 입력
                if (ch == '.')
                    game[i][j] = 0; //흰칸
                else if (ch == '#')
                    game[i][j] = 1; //검은칸
            }
        }
        printf("%d \n", cover()); // L블럭이 흰 칸을 모두 덮는 방법의 수 출력
    }
}
