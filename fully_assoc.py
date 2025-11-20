MM = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
CM = []
CACHE_SIZE = 5
HIT_COUNT = 0
TOTAL_COUNT = 0

def cache_mapping(value):
    global HIT_COUNT
    global TOTAL_COUNT
    if value not in MM:
        print('Number is not in Main Memory')
        return
    
    if value in CM:
        print('Cache Hit')
        HIT_COUNT+=1
    else:
        print('Cache Miss')
        if len(CM)<CACHE_SIZE:
            CM.append(value)
        else:
            removed = CM.pop(0)
            print(f'Cache Full - Removing the oldest elemet : {removed}')
            CM.append(value)
    TOTAL_COUNT+=1

while True:
    number = int(input('Which block to fetch? (0 to exit): '))
    if number == 0:
        break
    cache_mapping(number)
    print(f'Current Cache Memory {CM}')
    print(f'Total Count: {TOTAL_COUNT}')
    print(f'Hit Count: {HIT_COUNT}')
    HIT_RATIO = HIT_COUNT/TOTAL_COUNT
    print(f'Hit Ratio: {HIT_RATIO}')