MM = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
CACHE_SIZE = 5
CM = [None] * CACHE_SIZE
HIT_COUNT = 0
TOTAL_COUNT = 0

def cache_mapping(block):
    global HIT_COUNT
    global TOTAL_COUNT
    if block not in MM:
        print("Number not in Main Memory\n")
        return

    index = (block - 1) % CACHE_SIZE

    if CM[index] == block:
        print(f"Cache Hit")
        HIT_COUNT+=1
    else:
        print(f"Cache Miss")
        replaced = CM[index]
        CM[index] = block
        if replaced is not None:
            print(f"Replaced block {replaced} at index {index}")
    TOTAL_COUNT+=1
    print(f"Updated Cache: {CM}\n")

while True:
    num = int(input("Which block to fetch? (0 to exit): "))
    if num == 0:
        break
    cache_mapping(num)
    print(f'Current Cache Memory {CM}')
    print(f'Total Count: {TOTAL_COUNT}')
    print(f'Hit Count: {HIT_COUNT}')
    HIT_RATIO = HIT_COUNT/TOTAL_COUNT
    print(f'Hit Ratio: {HIT_RATIO}')