def optimal_page_replacement(refs, frames):
    frame = []
    faults = 0
    n = len(refs)
    for i, r in enumerate(refs):
        if r not in frame:
            faults += 1
            if len(frame) < frames:
                frame.append(r)
            else:
                future_use = {p: (refs[i+1:].index(p) if p in refs[i+1:] else float("inf")) for p in frame}
                victim = max(frame, key=lambda p: future_use[p])
                frame[frame.index(victim)] = r
        print(frame)
    print("Total Page Faults:", faults)
    print("Hit Ratio:", (len(refs) - faults) / len(refs))

refs = list(map(int, input("Enter reference string (space-separated): ").split()))
frames = int(input("Enter number of frames: "))
optimal_page_replacement(refs, frames)
