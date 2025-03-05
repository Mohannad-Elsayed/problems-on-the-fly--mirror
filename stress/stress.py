import subprocess
import random
import time

def generate_test_case(n):
    """Generate a test case with constraints: 1 ≤ k ≤ n ≤ 50, string s of length n with '.' and '*', at least one '*' in s, distance between any two '*' ≤ k."""
    n = random.randint(1, 50)
    k = random.randint(1, n)
    s = ['.'] * n
    star_positions = sorted(random.sample(range(n), random.randint(1, n // k + 1)))
    for pos in star_positions:
        s[pos] = '*'
    for i in range(1, len(star_positions)):
        if star_positions[i] - star_positions[i - 1] > k:
            s[star_positions[i]] = '.'
            new_pos = star_positions[i - 1] + random.randint(1, k)
            if new_pos < n:
                s[new_pos] = '*'
    s = ''.join(s)
    test = f"{n} {k}\n{s}\n"
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

def run_two_solutions():
    test_count = 10
    all_testcases = []
    
    # Collect all test cases
    for i in range(test_count):
        all_testcases.append(generate_test_case(i))
    
    # Build a single input string in "Codeforces style"
    input_data = f"{test_count}\n" + "".join(all_testcases)
    
    # Run each program once
    brute_output = run_program("b.exe", input_data).splitlines()
    optimized_output = run_program("o.exe", input_data).splitlines()
    
    # print(brute_output)
    # print(optimized_output)
    
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

def check_solution(output):
    """Check the solution output for correctness."""
    # Implement the logic to check the solution output
    # For now, we assume the output is always correct
    return True

def run_sol_checker():
    test_count = 10
    all_testcases = []
    
    # Collect all test cases
    for i in range(test_count):
        all_testcases.append(generate_test_case(i))
    
    # Build a single input string in "Codeforces style"
    input_data = f"{test_count}\n" + "".join(all_testcases)
    
    # Run the optimized program
    optimized_output = run_program("o.exe", input_data).splitlines()
    
    # Check the outputs line by line
    for i in range(test_count):
        if i >= len(optimized_output):
            print(f"Output mismatch in length at test #{i+1}")
            break
        if not check_solution(optimized_output[i]):
            print(f"Test #{i+1} Failed!")
            print(f"Input:\n{all_testcases[i].strip()}")
            print(f"Optimized: {optimized_output[i]}")
            break
    else:
        print("All test cases passed!")

def main():
    run_two_solutions()
    # run_sol_checker()

if __name__ == "__main__":
    main()
