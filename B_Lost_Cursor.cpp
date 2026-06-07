from PIL import Image
import numpy as np
import zipfile
import os

def generate_spiral_seq(n, max_len=5000):
    seq = ''
    dirs = [('R', n-1), ('D', n-1), ('L', n), ('U', n-2)]  # Adjust for layers
    layer = 0
    while len(seq) < max_len:
        for d, steps in dirs:
            for _ in range(min(steps - 2*layer, n - 2*layer)):
                seq += d
        layer += 1
        if layer * 8 > n: break
    return seq[:max_len]

def verify(grid, seq):  # Optional: simulate all whites
    # Implement multi-start sim; return True if all hit black
    pass

# Process
for i in range(1,9):
    img = Image.open(f"{i:02d}.png").convert('L')  # Assume unzipped PNGs
    n = img.size[0]
    white = np.array(img) < 128
    seq = generate_spiral_seq(n)
    with open(f"{i:02d}.out", 'w') as f:
        f.write(seq)
    print(f"{i:02d}.out: len={len(seq)}")