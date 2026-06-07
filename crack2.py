from argon2.low_level import hash_secret_raw, Type
import base64, itertools, string

salt = base64.b64decode("i/eOmAF+Qg40JHQAt4J/2A" + "==")
expected = base64.b64decode("sSPcLIMzrICGjBh3G5IcYZ" + "==")

for combo in itertools.product(string.ascii_uppercase + string.digits, repeat=4):
    pw = ''.join(combo)
    if hash_secret_raw(pw.encode(), salt, time_cost=3, memory_cost=65536,
                       parallelism=4, hash_len=16, type=Type.ID) == expected:
        print(f"Password: {pw}")
        break
