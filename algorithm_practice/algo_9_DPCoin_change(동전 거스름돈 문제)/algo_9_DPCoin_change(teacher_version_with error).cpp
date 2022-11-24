#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int coin_change(int coins[], int coin_idx, int M) {
    int C[100001];
    for (int k = 1; k <= 100000; k++) {
        C[k] = 100000;
    // 각 과정에서 드는 코인의 갯수를 엄청 크게 저장하여, 갱신될 수 있도록 함
    }
    C[0]= 0;
    int i, j;
    for (j = 1; j <= M; j++) { // M보다 작은 모든 액수에 대해 최적의 해를 구할 수 있도록 한다
        for (i = coin_idx - 1; i >= 0; i--) {
            if (coins[i] <= j && C[j - coins[i]] + 1 < C[j]) { // 현재 액수에서 모든 코인의 액수를 한 번씩 빼보고,
                C[j] = C[j - coins[i]] + 1; // 그 중에서 가장 작은 갯수의 액수에 + 1하여 현재의 갯수를 정함
            }
        }
    }
    return C[M];
}
int main() {
    char input[10000]; // 입력을 처리하는 버퍼
    char temp[100]; // 입력에서 코인의 액수를 하나씩 저장할 버퍼
    int coinValue[10];  // temp로부터 추출한 코인의 액수를 정수로 저장 할 버퍼
    
    int M;  // 거슬러줄 돈
    scanf("%s", input);  // 입력받음
    
    
    // 스페이스바가 나오면 아무 것도 안함, 숫자가 나오면 temp에 저장, ","나 엔터가 나오면 저장한 temp의 숫자를 정수의 형태로 반환
    int coin_idx = 0;
    for (int idx = 0, ;; idx++) {  //for (int idx = 0, ;; idx++) is it with error
        if (input[idx] == '\0') {
            coinValue[coin_idx] = stoi(temp); //but is it atoi ?// stoi는 c언어에 없고, c++에만 있음
            coin_idx++;
            break;
        } else if (input[idx] == ',') {
            coinValue[coin_idx] = stoi(temp); //but is it atoi ?
            coin_idx++;
            for (int i = 0; i < 100; i++)
                temp[i] = 0;
        }else if (input[idx] == ' '){}
        else temp[idx]= input[idx];
    }
    printf("%d", coin_change(coinValue, coin_idx, M));
    return 0;
}
