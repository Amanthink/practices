from crack2 import PasswordHasher
from argon2.low_level import hash_secret_raw, Type
import base64

salt = base64.b64decode("i/eOmAF+Qg40JHQAt4J/2A==")
target = base64.b64decode("sSPcLIMzrICGjBh3G5IcYZ==")

with open("wordlist.txt") as f:
    for line in f:
        word = line.strip()
        result = hash_secret_raw(
            secret=word.encode(),
            salt=salt,
            time_cost=3,
            memory_cost=65536,
            parallelism=4,
            hash_len=len(target),
            type=Type.ID
        )
        if result == target:
            print(f"[+] PASSWORD FOUND: {word}")
            break