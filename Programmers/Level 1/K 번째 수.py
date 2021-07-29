def solution(array, commands):
    answer = []
    print(len(commands))
    for i in range(len(commands)):
        start = commands[i][0]-1
        end = commands[i][1]
        pick = commands[i][2]-1
        new = array[start:end]
        new.sort()
        number = new[pick]
        answer.append(number)
    return answer
