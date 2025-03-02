import subprocess
import random
import time

def generate_test_case(n):
    """Generate a random string with size up to 10."""
    size = random.randint(1, 50)
    random_string = ''.join(random.choices('abc', k=size))
    test = f"{size}\n{random_string}\n"
    # print(test)
    return test

def run_program(program, input_data):
    """Runs a compiled C++ program with input_data and returns output."""
    process = subprocess.run(
        [f"./{program}"], 
        input=input_data, 
        text=True, 
        capture_output=True
    )
    return process.stdout.strip()

def main():
    test_count = 10000
    all_testcases = []
    
    # Collect all test cases
    for i in range(test_count):
        all_testcases.append(generate_test_case(i))
    
    # Build a single input string in "Codeforces style"
    input_data = f"{test_count}\n" + "".join(all_testcases)
    
    # Run each program once
    brute_output = run_program("b.exe", input_data).splitlines()
    optimized_output = run_program("o.exe", input_data).splitlines()
    
    # Compare the outputs line by line
    for i in range(test_count):
        if i >= len(brute_output) or i >= len(optimized_output):
            print(f"Output mismatch in length at test #{i+1}")
            break
        if brute_output[i] != optimized_output[i]:
            print(f"Test #{i+1} Failed!")
            print(f"Input:\n{all_testcases[i].strip()}")
            print(f"Brute-force: {brute_output[i]}")
            print(f"Optimized: {optimized_output[i]}")
            break
    else:
        print("All test cases passed!")

if __name__ == "__main__":
    main()
