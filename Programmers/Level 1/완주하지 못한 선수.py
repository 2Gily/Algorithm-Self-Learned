def solution(participant, completion):
    answer = ''
    
    for i in range(len(participant)):
        if participant[i] not in completion:
            return participant[i]
        else :
            participant.sort()
            completion.sort()
            for j in range(len(completion)):
                if participant[j] != completion[j]:
                    return participant[j]완주
