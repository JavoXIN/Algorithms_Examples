import sys
input = sys.stdin.readline

N, row, col = list(map(int, input().split()))      
data = [[-1] * N for _ in range(N)]     
globals()['threshold'] = 2      
globals()['num'] = 0
data[row][col] = num      
num += 1

globals()['tile_dict'] = {1 : ((-1, 0), (0, 0), (0, -1)),       
                          2 : ((-1, -1), (0, 0), (0, -1)),     
                          3 : ((-1, -1), (0, 0), (-1, 0)),      
                          4 : ((-1, -1), (-1, 0), (0, -1))}     




def input_tile(data, n):
    # 타일을 넣는 함수
    for i in range(n):
        for j in range(n):
            if data[i][j] == -1:        # 타일, 구멍이 없음
                data[i][j] = globals()['num']       # 순서에 맞춰서 넣음
    globals()['num'] += 1       # num 1증가


def find_hole(data, n):
    # 구멍의 위치를 파악함, n은 항상 2보다 큼
    m = n // 2
    row, col = [[row, col] for row in range(n) for col in range(n) if data[row][col] != -1][0]      # 구멍의 위치를 찾음
    if row < m and col < m:     # row, col 위치에 따라 구멍의 사분면을 리턴함
        return 1
    elif row < m and col >= m:
        return 2
    elif row >= m and col < m:
        return 3
    else:
        return 4


def input_center_tile(data, m ,hole_pos):      # tile_dict(m 기준으로 움직임)
    # 중앙에 타일을 놓는 함수, hole_pos 반대 방향으로, 이미 tile_dict에 모두 선언 해놓았음
    for row, col in globals()['tile_dict'][hole_pos]:
        data[m + row][m + col] = globals()['num']
    globals()['num'] += 1


def split(data, s_r, s_c, m):
    # data를 4등분하는 함수
    s_data = [[0] * m for _ in range(m)]        # 2차원 리스트 선언
    for row in range(s_r, s_r + m):     # 범위 지정
        for col in range(s_c, s_c + m):
            s_data[row - s_r][col - s_c] = data[row][col]       

    return s_data


def combine(m, data, d1, d2, d3, d4):
    
    for i in range(m):      # 순서에 맞게 집어넣기
        for j in range(m):
            data[i][j] = d1[i][j]
            data[i][j + m] = d2[i][j]
            data[i + m][j] = d3[i][j]
            data[i + m][j + m] = d4[i][j]


def func(data, n):
    # 타일을 divid and conquer하는 함수
    if n <= globals()['threshold']:     # 2*2 보다 작아지면 빈 공간에 타일 넣으면 됨
        input_tile(data, n)
    else:       # 2*2 퍼즐보다 클 때
        m = n // 2      # m은 분할을 위해 사용
        
        hole_pos = find_hole(data, n)
        # 구멍의 위치를 찾았으니 반대 방향에 넣으면 됨. N // 2를 이용하자, 딕셔너리도 -> input_center_tile
        input_center_tile(data, m, hole_pos)
        

        # data를 4개로 쪼개는 함수를 만들자 -> split
        d1 = split(data, 0, 0, m)       # 분할함
        d2 = split(data, 0, m, m)
        d3 = split(data, m, 0, m)
        d4 = split(data, m, m, m)

        list(map(lambda x : func(x, m), [d1, d2, d3, d4]))      # 재귀

        # 이제 합병하는 함수를 만들면 됨
        combine(m, data, d1, d2, d3, d4)       # 합병


func(data, N)
for i in range(N):
    print(*data[i])