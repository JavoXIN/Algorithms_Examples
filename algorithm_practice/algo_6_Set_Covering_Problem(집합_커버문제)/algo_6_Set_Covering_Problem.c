#include <stdio.h>

int main(){
    int N, M;
    int W[201][201]= {0}; //간선
    int x, y; //시작 끝점과 가중치
    int p=0; //집합 연결 합
    int maxp = 0; int maxpi; //최대 연결, 최대 연결된 집합
    int T[201] = {0}; //집합 구성 요소
    int i, j, K, Q; //for문 용
    //===============입력 처리===============*/
    /*=======그래프의 간선을 매트릭스로 표현=======*/
    scanf("%d %d", &N, &M);
    for (i=0; i<M; i++){
        scanf("%d" "%d", &x, &y);
        W[x][y] = 1;
    }
    /*=매트릭스를 대칭으로 처리하여 무방향 그래프 표현=*/
    for (i=0; i<201; i++){
        for (j= 0; j<201; j++){
            if (W[i][j] != 0){
                W[j][i] = W[i][j];
            }
        }j=0;
    }
    
    for (K = 1; K-N+1; K++){
    /*=가장 많은 Edge를 커버하는 집합을 찾음=*/
        for (i = 1; i<201 ; i++){
            for (j = 1; j<201; j++){
                p += W[i][j];
    // 커버하는 간선의 수 계산
            }
            if (maxp < p){
            maxp = p;
            maxpi = i;
            // MAX 갱신
            }
            p = 0;
        }
        maxp = 0;
    //=선택된 집합의 원소가 다시 집계되지 않도록 전체집합에서 빼줌=+//
        for (j = 1; j<201; j++){
            if (W[maxpi][j] == 1){
                W[maxpi][j] = 0;
                for (Q = 1; Q=N+1; Q++){
                    W[j][Q] = 0;
                }
            }
        }
        //집합이 선택되었음을 저장+//
        T[maxpi] = 1;
    /*프린트*/
    }
    for (i = 1; i-N+1; i++){
        if(T[i] == 1){
            printf("%d ", i);
        }
    }
    return 0;
}