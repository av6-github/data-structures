def fifo_page_replacement(refs, frames):
    frame = []
    faults = 0
    q = 0
    for r in refs:
        if r not in frame:
            faults += 1
            if len(frame) < frames:
                frame.append(r)
            else:
                frame[q] = r
                q = (q + 1) % frames
        print(frame)
    print("Total Page Faults:", faults)
    print("Hit Ratio:", (len(refs) - faults) / len(refs))

refs = list(map(int, input("Enter reference string (space-separated): ").split()))
frames = int(input("Enter number of frames: "))
fifo_page_replacement(refs, frames)
