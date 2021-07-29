def solution(num):
    answer = 0 #작업횟수 초기화

    while True: #수마다 몇회 반복해야 할지 모르므로 무한루프

        if num == 1: #입력받은 수가 1일경우 answer를 리턴
            return answer

        if answer == 500: #작업 횟수가 500이 되면 -1을 리턴
            return -1

        if num % 2 == 0: #입력받은 수가 짝수 일경우 2로 나눈값을 변수에 담는다. 
            num = num / 2

        elif num % 2 == 1: #입력받은 수가 홀수 일경우 3을 곱하고 1을 더해준다.
            num = num * 3 + 1

        answer += 1 #위의 작업을 마치고 작업횟수를 1더해준다
