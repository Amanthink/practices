
import re, hashlib

data = open(r'C:\Users\avsin\Downloads\memory.bin', 'rb').read()
text = data.decode('latin-1')

# 'md5sum' is literally in that line - maybe we need to md5 something
# Let's try md5 of various obvious candidates
candidates = [
    b'something_interesting',
    b'memghost',
    b'MemGhost',
    b'leaf',
    b'SecLeaf',
    b'virustotal',
    b'md5sum',
    b'hidden in plain sight',
    b'Glitched',
]
for c in candidates:
    h = hashlib.md5(c).hexdigest()
    print(f'md5({c!r}) = {h}')
    # also check if hash appears in file
    if h in text:
        print('  FOUND IN FILE!')
"
#Output

#md5(b'something_interesting') = b5099a5ea07ef8066af5ab721b127935
#md5(b'memghost') = 291d838adfd9cf250812a89c79bbdffe
#md5(b'MemGhost') = 5b78e1877a3d04e8e7d2b1cb1418f527
#md5(b'leaf') = bab4ff04cc14af66e4d42c85f888cfe6
#md5(b'SecLeaf') = 5c696586bc8b1b4e17f990e9188cbce7
#md5(b'virustotal') = dd5f0eee2e4a99b71a939bded450b246
#md5(b'md5sum') = c8f1ee9a7c5fd4b3c66d7559e99807d0
#md5(b'hidden in plain sight') = 989fdf95adcfd1b0c1afd17937671bc4
#md5(b'Glitched') = 5d1a666f17f219ee8f73cdf196970012
