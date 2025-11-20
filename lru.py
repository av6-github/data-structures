def lru_page_replacement(refs, frames):
    frame = []
    faults = 0
    last_used = {}
    for i, r in enumerate(refs):
        if r not in frame:
            faults += 1
            if len(frame) < frames:
                frame.append(r)
            else:
                victim = min(frame, key=lambda x: last_used.get(x, -1))
                frame[frame.index(victim)] = r
        last_used[r] = i
        print(frame)
    print("Total Page Faults:", faults)
    print("Hit Ratio:", (len(refs) - faults) / len(refs))

refs = list(map(int, input("Enter reference string (space-separated): ").split()))
frames = int(input("Enter number of frames: "))
lru_page_replacement(refs, frames)
