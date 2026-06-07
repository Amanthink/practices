from argon2.low_level import hash_secret_raw, Type
import base64, itertools, string, time

salt     = base64.b64decode("i/eOmAF+Qg40JHQAt4J/2A==")
expected = base64.b64decode("sSPcLIMzrICGjBh3G5IcYZ==")

def try_password(pw: str) -> bool:
    h = hash_secret_raw(pw.encode(), salt, time_cost=3, memory_cost=65536,
                        parallelism=4, hash_len=16, type=Type.ID)
    return h == expected

# Benchmark
t0 = time.time()
hash_secret_raw(b"test", salt, time_cost=3, memory_cost=65536,
                parallelism=4, hash_len=16, type=Type.ID)
per_hash = time.time() - t0
print(f"Speed: ~{per_hash:.3f}s per hash\n")

found = False

# ══════════════════════════════════════════════════════════════
# PHASE 1 — Lowercase letters only: aaaa–zzzz  (26^4 = 456,976)
# ══════════════════════════════════════════════════════════════
charset = string.ascii_lowercase
total   = len(charset) ** 4
print(f"{'='*50}")
print(f"PHASE 1: Lowercase a-z  ({total:,} combos)")
print(f"ETA: ~{per_hash * total / 60:.0f} min")
print("=" * 50)
for i, combo in enumerate(itertools.product(charset, repeat=4)):
    pw = "".join(combo)
    if try_password(pw):
        print(f"\n✅ FOUND: {pw}")
        print(f"🚩 Flag: {pw}")
        found = True
        break
    if i % 500 == 0:
        print(f"  [{i:,}/{total:,}] last tried: {pw}")

# ══════════════════════════════════════════════════════════════
# PHASE 2 — Mixed alphanumeric: 0-9 + a-z  (skips pure digits/letters)
# ══════════════════════════════════════════════════════════════
if not found:
    charset = string.digits + string.ascii_lowercase
    total   = len(charset) ** 4
    print(f"\n{'='*50}")
    print(f"PHASE 2: Mixed alphanumeric 0-9+a-z  ({total:,} combos)")
    print(f"ETA: ~{per_hash * total / 60:.0f} min")
    print("=" * 50)
    for i, combo in enumerate(itertools.product(charset, repeat=4)):
        pw = "".join(combo)
        if pw.isdigit() or pw.isalpha():
            continue  # already covered
        if try_password(pw):
            print(f"\n✅ FOUND: {pw}")
            print(f"🚩 Flag: {pw}")
            found = True
            break
        if i % 1000 == 0:
            print(f"  [{i:,}/{total:,}] last tried: {pw}")

# ══════════════════════════════════════════════════════════════
# PHASE 3 — Full alphanumeric: 0-9 + a-z + A-Z
# ══════════════════════════════════════════════════════════════
if not found:
    charset = string.digits + string.ascii_letters
    total   = len(charset) ** 4
    print(f"\n{'='*50}")
    print(f"PHASE 3: Full alphanumeric 0-9+a-z+A-Z  ({total:,} combos)")
    print(f"ETA: ~{per_hash * total / 60:.0f} min")
    print("=" * 50)
    for i, combo in enumerate(itertools.product(charset, repeat=4)):
        pw = "".join(combo)
        if pw.isdigit() or (pw.isalpha() and pw.islower()) or (pw.isalpha() and pw.isupper()):
            continue  # already covered
        if try_password(pw):
            print(f"\n✅ FOUND: {pw}")
            print(f"🚩 Flag: {pw}")
            found = True
            break
        if i % 5000 == 0:
            print(f"  [{i:,}/{total:,}] last tried: {pw}")

if not found:
    print("\n❌ Not found. May contain special characters — let me know!")