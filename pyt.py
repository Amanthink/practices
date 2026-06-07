import zipfile
import sys
import time

def brute_force_zip(zip_path, max_digits=9):
    """
    Attempts to brute-force a ZIP file password using numeric combinations.
    """
    print(f"[*] Opening archive: {zip_path}")
    try:
        z_file = zipfile.ZipFile(zip_path)
    except FileNotFoundError:
        print(f"[-] Error: File '{zip_path}' not found.")
        return
    except zipfile.BadZipFile:
        print("[-] Error: Not a valid ZIP file.")
        return

    start_time = time.time()
    print(f"[*] Starting numeric brute-force (up to {max_digits} digits)...")
    
    # Track progress every 1,000,000 attempts
    checkpoint = 1000000
    
    # We loop through total possible numbers up to the max digit threshold
    # e.g., 9 digits = 1,000,000,000 possibilities
    total_combinations = 10 ** max_digits
    
    for i in range(total_combinations):
        # Convert integer to string, then to bytes (zipfile requires bytes for passwords)
        # We try both raw numbers (e.g., '123') and zero-padded numbers (e.g., '000000123')
        # depending on how the weak numeric pattern is structured.
        password_str = str(i)
        
        # Test 1: Plain string number
        password_bytes = password_str.encode('utf-8')
        try:
            # extractall will throw an exception if the password is wrong
            z_file.extractall(pwd=password_bytes)
            print(f"\n[+] Success! Password found: {password_str}")
            print(f"[+] Total time: {time.time() - start_time:.2f} seconds")
            return
        except (RuntimeError, zipfile.BadZipFile):
            # RuntimeError occurs on bad password; BadZipFile can occur if CRC fails
            pass

        # Test 2: Zero-padded string number (matching the max digits length)
        padded_str = password_str.zfill(max_digits)
        if padded_str != password_str: # Avoid duplicate testing if they are identical
            password_bytes = padded_str.encode('utf-8')
            try:
                z_file.extractall(pwd=password_bytes)
                print(f"\n[+] Success! Password found: {padded_str}")
                print(f"[+] Total time: {time.time() - start_time:.2f} seconds")
                return
            except (RuntimeError, zipfile.BadZipFile):
                pass

        # Console status update
        if i % checkpoint == 0 and i > 0:
            elapsed = time.time() - start_time
            speed = i / elapsed
            print(f"[*] Tried {i} combinations... Speed: {speed:.0f} att/sec", end='\r')

    print("\n[-] Password not found within the numeric limit.")

if __name__ == "__main__":
    # Change 'archive.zip' to the actual name of your intercepted file
    target_zip = r"C:\Users\avsin\Downloads\protected (2).zip"
    
    # Adjust digits based on how deep you want to go 
    # (6 digits is fast, 8-9 digits takes longer in pure Python)
    max_numeric_length = 9
    
    brute_force_zip(target_zip, max_numeric_length)