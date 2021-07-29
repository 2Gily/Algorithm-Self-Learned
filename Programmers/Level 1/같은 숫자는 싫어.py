def solution(arr):
    answer = [arr[0]]
    a=0
    
    for i in range(1,len(arr)):
        if arr[i] != answer[a]:
            answer.append(arr[i])
            a+=1

    return answer
