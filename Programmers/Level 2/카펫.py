def solution(brown, red) :
    x = (brown + 4 + ((brown + 4) ** 2 - 16 * (brown + red)) ** 0.5) / 4
    y = (brown + red) // x
    return [max(x, y), min(x, y)]
