import subprocess
import random
import time

def generate_test_case(n):
    return str(random.randint(1, 1**18))

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
    test_count = 100
    all_testcases = []
    
    # Collect all test cases
    for i in range(test_count):
        all_testcases.append(generate_test_case(i))
    
    # Build a single input string in "Codeforces style"
    input_data = f"{test_count}\n" + "\n".join(all_testcases)
    print(input_data)
    
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

def check_solution(inp, outp):
    """Check the solution output for correctness."""
    # Parse input
    lines = inp.strip().split('\n')
    n = int(lines[0])
    array = list(map(int, lines[1].split()))
    
    # Parse output
    output_array = list(map(int, outp.split()))
    
    # Verify the output format
    if len(output_array) != n:
        print(f"Output length mismatch: expected {n}, got {len(output_array)}")
        return False
    
    # Verify all numbers in output are in the range 1 to 10^9
    if any(x < 1 or x > 10**9 for x in output_array):
        print(f"Invalid number in output: all numbers must be between 1 and 10^9")
        return False
    
    # Verify every pair of adjacent numbers in output
    for i in range(n - 1):
        if not (output_array[i] % output_array[i + 1] == 0 or output_array[i + 1] % output_array[i] == 0):
            print(f"Invalid adjacent pair: {output_array[i]} and {output_array[i + 1]}")
            return False
    
    # Verify the summation constraint
    sum_diff = sum(abs(array[i] - output_array[i]) for i in range(n))
    if 2 * sum_diff > sum(array):
        print(f"Summation constraint violated: 2 * {sum_diff} > {sum(array)}")
        return False
    
    return True

def run_sol_checker():
    test_count = 100000
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
        if not check_solution(all_testcases[i].strip(), optimized_output[i]):
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
