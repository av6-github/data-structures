def twos_complement(bin_str):
    n = len(bin_str)
    inv = ''.join('1' if b == '0' else '0' for b in bin_str) # invert bits
    add_one = bin(int(inv, 2) + 1)[2:].zfill(n)
    return add_one[-n:] # keep n bits


def add_binary(a, b):
    n = len(a)
    result = ''
    carry = 0
    for i in range(n-1, -1, -1):
        total = carry + (1 if a[i]=='1' else 0) + (1 if b[i]=='1' else 0)
        result = ('1' if total % 2 == 1 else '0') + result
        carry = total // 2
    return result[-n:] # keep n bits


def arithmetic_right_shift(A, Q, Qn_1):
    combined = A + Q + Qn_1
    msb = combined[0] # preserve sign bit
    shifted = msb + combined[:-1]
    return shifted[:len(A)], shifted[len(A):-1], shifted[-1]


def booths_algorithm(multiplicand, multiplier):
    n = max(len(multiplicand), len(multiplier))
    A = '0' * n
    Q = multiplier.zfill(n)
    Qn_1 = '0'
    M = multiplicand.zfill(n)
    negM = twos_complement(M)

    print(f"\nInitial values:")
    print(f"A = {A}, Q = {Q}, Q-1 = {Qn_1}, M = {M}, -M = {negM}")

    for i in range(n):
        print(f"\nStep {i+1}:")
        if Q[-1] == '1' and Qn_1 == '0': # 10 → subtract M
            A = add_binary(A, negM)
            print(" Action: A = A - M")
        elif Q[-1] == '0' and Qn_1 == '1': # 01 → add M
            A = add_binary(A, M)
            print(" Action: A = A + M")
        else:
            print(" Action: No operation")

        print(f" Before shift: A={A}, Q={Q}, Q-1={Qn_1}")
        A, Q, Qn_1 = arithmetic_right_shift(A, Q, Qn_1)
        print(f" After shift : A={A}, Q={Q}, Q-1={Qn_1}")

    result = A + Q
    print(f"\nFinal Product = {result}")
    return result


multiplicand = input("Enter multiplicand (binary): ")
multiplier = input("Enter multiplier (binary): ")

booths_algorithm(multiplicand, multiplier)