import subprocess
import random
import time
import string

def generate_test_case():
    n = random.randint(1, 10)  # Adjusted to a smaller range for testing
    m = random.randint(1, 10)  # Adjusted to a smaller range for testing
    a = [random.randint(1, 100) for _ in range(n)]
    b = [random.randint(1, 100) for _ in range(m)]
    return f"{n} {m}\n" + ' '.join(map(str, a)) + "\n" + ' '.join(map(str, b))

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
    test_count = 100000
    all_testcases = []
    
    # Collect all test cases
    for i in range(test_count):
        all_testcases.append(generate_test_case())
    
    # Build a single input string in "Codeforces style"
    input_data = f"{test_count}\n" + "\n".join(all_testcases)
    # print(input_data)
    
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
    # print(inp, outp)
    
    a, b = int(inp), int(outp)
    c = a ^ b
    p = 1
    while p < a:
        p *= 2
    if (p == a or p-1 == a) and b == -1:
        return True
    if (p == a or p-1 == a) and b != -1:
        return True
    return (a+b>c and a+c>b and b+c>a)
        
        

def run_sol_checker():
    test_count = 1000000
    all_testcases = []
    
    # Collect all test cases
    for i in range(test_count):
        all_testcases.append(generate_test_case())

    # Build a single input string in "Codeforces style"
    input_data = f"{test_count}\n" + "\n".join(all_testcases)
    # print(input_data)

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
