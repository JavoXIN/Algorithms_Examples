import sys
input = sys.stdin.readline
def quick_sort(li):
    if len(li)<=1:
        return li
    pivot=li[len(li)//2][2]
    less_li, same_li, more_li=[], [], []
    for i in li:
        if pivot>i[2]:
            less_li.append(i)
        elif pivot<i[2]:
            more_li.append(i)
        else:
            same_li.append(i)
    return quick_sort(less_li)+same_li+quick_sort(more_li)
def find(x):
    if x!=V_root[x]:
        V_root[x] = find(V_root[x])
    return V_root[x]
if __name__== "__main__":
    V, E = map(int, input().split())
    V_root = [i for i in range(V + 1)]
    E_list = []
    for _ in range(E):
        E_list.append(list(map(int, input().split())))
        
    E_list=quick_sort(E_list) 
    
    answer = 0
    for s, e, w in E_list:
        s_Root = find(s)
        
        e_Root = find(e)
        if s_Root != e_Root:
            V_root[s_Root] = e_Root
            answer += w
    print(answer)