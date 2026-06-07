from PIL import Image
import numpy as np
import os

def spiral_seq(n):  # ~4*n length, <5000 for n=500
    seq = ''
    for k in range((n+1)//2):
        len_side = n - 2*k
        seq += 'R'*(len_side-1) + 'D'*(len_side-1) + 'L'*(len_side) + 'U'*(len_side-2)
    return seq[:5000]

for i in range(1,9):
    img = Image.open(f"{i:02d}.png").convert('L')
    n = img.size[0]  # assume square
    seq = spiral_seq(n)
    with open(f"{i:02d}.out", 'w') as f: f.write(seq)