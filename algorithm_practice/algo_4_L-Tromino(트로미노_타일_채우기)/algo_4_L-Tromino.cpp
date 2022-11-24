
#include <stdio.h>
#define MAX 33

int cnt;
int MAP[MAX] [MAX];

int find_hole(int x, int y, int len){
    for(int i = x; i < x+len; i++){
        for(int j = y; j < y+len; j++){
            if(MAP[i][j] != 0){
                return 0;
            }
        }
    }
    return 1;
}

void tile_board_DC(int x, int y, int len) {
    ++cnt;
    int halfLen = len / 2;
    if (find_hole(x, y, halfLen)) MAP[x + halfLen - 1][y + halfLen - 1] = cnt;
    if (find_hole(x + halfLen, y, halfLen)) MAP[x + halfLen] [y + halfLen - 1] = cnt;
    if (find_hole(x + halfLen, y + halfLen, halfLen)) MAP[x + halfLen][y + halfLen] = cnt;
    if (find_hole(x, y + halfLen, halfLen)) MAP[x + halfLen - 1] [y + halfLen] = cnt;
    if (len == 2) return;
    
    tile_board_DC(x, y, halfLen);
    tile_board_DC(x, y + halfLen, halfLen);
    tile_board_DC(x + halfLen, y + halfLen, halfLen);
    tile_board_DC(x + halfLen, y, halfLen);
}

int main(){
    int k,x,y=0;
    scanf("%d%d%d",&k,&x,&y);
    MAP[y-1] [x-1] = -1;
    tile_board_DC(0, 0, (1<<k));
    for (int i = 0; i < 1 << k; i++) {
        for (int j = 0; j < (1 << k); j++) {
            printf("%d ", MAP[i][j]);
        }
        printf("\n");
    }
    return 0;
}



