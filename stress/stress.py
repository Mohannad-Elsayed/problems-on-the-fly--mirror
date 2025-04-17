import subprocess
import random
import time
import string
cnt = 123456789
class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def run_program(program, input_data):
    """Runs a compiled C++ program with input_data and returns output if successful, else returns stderr."""
    process = subprocess.run(
        [f"./{program}"], 
        input=input_data, 
        text=True, 
        capture_output=True
    )
    if process.returncode == 0:
        return process.stdout.strip()
    else:
        return f"Error: {process.stderr.strip()}"

def generate_test_case():
    mx = 100
    while True:
        n = random.randint(2, mx)
        m = random.randint(2, mx)
        k = random.randint(2, n * m)
        
        if (n * m) % k == 0 and 2 <= n * m <= 200000:
            return f"{n} {m} {k}"

#! run two solutions
def run_two_solutions():
    test_count = 10
    all_testcases = []
    
    # Collect all test cases
    for i in range(test_count):
        all_testcases.append(generate_test_case())
    
    # Build a single input string in "Codeforces style"
    input_data = f"{test_count}\n" + "\n".join(all_testcases)
    # input_data = "\n".join(all_testcases)
    # print(input_data)
    
    # Run each program once
    brute_output = run_program("b", input_data).splitlines()
    optimized_output = run_program("o", input_data).splitlines()
    
    # print(brute_output)
    # print(optimized_output)
    
    # Compare the outputs line by line
    for i in range(test_count):
        if i >= len(brute_output) or i >= len(optimized_output):
            print(f"{bcolors.WARNING}Output mismatch in length at test #{i+1}{bcolors.ENDC}")
            break
        if brute_output[i].strip() != optimized_output[i].strip():
            print(f"{bcolors.FAIL}Test #{i+1} Failed!")
            print(f"Input:\n{all_testcases[i].strip()}")
            print(f"Brute-force: {brute_output[i]}")
            print(f"Optimized:   {optimized_output[i]}{bcolors.ENDC}")
            break
    else:
        print(f"{bcolors.OKGREEN}All test cases passed!{bcolors.ENDC}")

#! two solutions with check
def run_two_solutions_with_check():
    test_count = 1
    all_testcases = []
    
    # Collect all test cases
    for i in range(test_count):
        all_testcases.append(generate_test_case())
    
    # Build a single input string in "Codeforces style"
    input_data = f"{test_count}\n" + "\n".join(all_testcases)
    # print(input_data)
    
    # Run each program once
    brute_output = run_program("b", input_data).splitlines()
    optimized_output = run_program("o", input_data).splitlines()
    # print(brute_output)
    # print(optimized_output)
    
    # Compare the outputs line by line
    for i in range(test_count):
        if i >= len(brute_output) or i >= len(optimized_output):
            print(f"Output mismatch in length at test #{i+1}")
            break
        
        brute_result = brute_output[i].split()
        optimized_result = optimized_output[i].split()
        
        # Check if both outputs are valid
        # if len(brute_result) != 2 or len(optimized_result) != 2:
        #     print(f"Test #{i+1} Failed: Invalid output format")
        #     print(f"Input:\n{all_testcases[i].strip()}")
        #     print(f"Brute-force: {brute_output[i]}")
        #     print(f"Optimized: {optimized_output[i]}")
        #     break
        print(brute_result)
        print(optimized_result)
        # Case 1: Brute force outputs "-1 -1"
        if brute_result == ['-1']:
            
            if optimized_result != ['-1']:
                print(f"Test #{i+1} Failed: Brute force indicates no solution but optimized does not")
                print(f"Input:\n{all_testcases[i].strip()}")
                print(f"Brute-force: {brute_output[i]}")
                print(f"Optimized: {optimized_output[i]}")
                break
        if optimized_result == ['-1']:
            print(f"Test #{i+1} Failed: Optimized indicates no solution but brute force does not")
            print(f"Input:\n{all_testcases[i].strip()}")
            print(f"Brute-force: {brute_output[i]}")
            print(f"Optimized: {optimized_output[i]}")
            break
            
        # Case 2: Check sum of range is equal
        else:
            brute_start, brute_end = int(brute_result[0]), int(brute_result[1])
            optimized_start, optimized_end = int(optimized_result[0]), int(optimized_result[1])
            
            brute_sum = sum(range(brute_start, brute_end + 1))
            optimized_sum = sum(range(optimized_start, optimized_end + 1))
            
            if brute_sum != optimized_sum:
                print(f"Test #{i+1} Failed: Range sums don't match")
                print(f"Input:\n{all_testcases[i].strip()}")
                print(f"Brute-force: {brute_output[i]} (sum: {brute_sum})")
                print(f"Optimized: {optimized_output[i]} (sum: {optimized_sum})")
                break
    else:
        print("All test cases passed!")
        

def check_solution(inp, outp):
    """Check the solution output for correctness."""
    # Parse input
    n, m, k = map(int, inp.split())
    
    # Parse output grid
    grid = [list(map(int, row.split())) for row in outp.splitlines()]
    # print("grid ", grid)
    # Check grid dimensions
    if len(grid) != n or any(len(row) != m for row in grid):
        return False
    
    # Check range of integers and count occurrences
    counts = [0] * (k + 1)
    for i in range(n):
        for j in range(m):
            if not (1 <= grid[i][j] <= k):
                return False
            counts[grid[i][j]] += 1
    
    # Check if each integer from 1 to k appears an equal number of times
    expected_count = (n * m) // k
    if any(count != expected_count for count in counts[1:]):
        return False
    
    # Check adjacency constraint
    for i in range(n):
        for j in range(m):
            if i > 0 and grid[i][j] == grid[i - 1][j]:  # Check above
                return False
            if j > 0 and grid[i][j] == grid[i][j - 1]:  # Check left
                return False
    
    return True
        
        
#! solution checker
def run_sol_checker():
    test_count = 2
    all_testcases = []
    
    # Collect all test cases
    for i in range(test_count):
        all_testcases.append(generate_test_case())

    # Build a single input string in "Codeforces style"
    input_data = f"{test_count}\n" + "\n".join(all_testcases)
    # print(input_data)

    # Run the optimized program
    optimized_output = run_program("o", input_data).splitlines()
    print(optimized_output)

    # Check the outputs line by line
    for i in range(test_count):
        if i >= len(optimized_output):
            print(f"Output mismatch in length at test #{i+1}")
            break
        if not check_solution(all_testcases[i].strip(), optimized_output[i]):
            print(f"Test #{i+1} Failed!")
            print(f"Input:\n{all_testcases[i].strip()}")
            print(f"Optimized: {optimized_output[i]}")
            break
    else:
        print("All test cases passed!")

def main():
    # run_two_solutions()
    # run_two_solutions_with_check()
    run_sol_checker()

if __name__ == "__main__":
    main()
