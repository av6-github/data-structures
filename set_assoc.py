MM = [1,2,3,4,5,6,7,8,9,10]
CACHE_SIZE = 6
WAYS = 2
NUM_SETS = CACHE_SIZE // WAYS
CACHE = [[None for _ in range(WAYS)] for _ in range(NUM_SETS)]
FRONT = [0] * NUM_SETS
HIT_COUNT = 0
TOTAL_COUNT = 0

def cache_mapping(block):
    global HIT_COUNT
    global TOTAL_COUNT
    set_no = block % NUM_SETS
    if block not in MM:
        print("Number not in Main Memory")
        return

    if block in CACHE[set_no]:
        print("Cache Hit")
        HIT_COUNT += 1
    else:
        print("Cache Miss")
        CACHE[set_no][FRONT[set_no]] = block
        FRONT[set_no] = (FRONT[set_no] + 1) % WAYS

    TOTAL_COUNT += 1
    print(f"Set {set_no}: {CACHE[set_no]}")
    print()

while True:
    num = int(input("Which block to fetch? (0 to exit): "))
    if num == 0:
        break
    cache_mapping(num)
    print(f"Total Count: {TOTAL_COUNT}")
    print(f"Hit Count: {HIT_COUNT}")
    if TOTAL_COUNT > 0:
        print(f"Hit Ratio: {HIT_COUNT/TOTAL_COUNT}")
    print()
