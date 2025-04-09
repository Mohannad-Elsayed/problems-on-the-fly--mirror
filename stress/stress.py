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
    n = random.randint(2, 100)  # adjust for demo
    m = random.randint(1, min(n * (n - 1) // 2, n//2))  # limit edges to avoid excessive density
    edges = set()
    nodes = list(range(1, n + 1))
    random.shuffle(nodes)  # Randomize node order to ensure acyclic graph generation

    for i in range(len(nodes)):
        for j in range(i + 1, len(nodes)):
            if len(edges) >= m:
                break
            edges.add((nodes[i], nodes[j]))  # Ensure directed edge from lower to higher index

    lines = [f"{n} {len(edges)}"]
    for (v, u) in edges:
        lines.append(f"{v} {u}")
    # print("\n".join(lines))
    return "\n".join(lines)

#! run two solutions
def run_two_solutions():
    test_count = 1
    all_testcases = []
    
    # Collect all test cases
    for i in range(test_count):
        all_testcases.append(generate_test_case())
    
    # Build a single input string in "Codeforces style"
    # input_data = f"{test_count}\n" + "\n".join(all_testcases)
    input_data = "\n".join(all_testcases)
    print(input_data)
    
    # Run each program once
    brute_output = run_program("b.exe", input_data).splitlines()
    optimized_output = run_program("o.exe", input_data).splitlines()
    
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
    brute_output = run_program("b.exe", input_data).splitlines()
    optimized_output = run_program("o.exe", input_data).splitlines()
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
        
        
#! solution checker
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
    # run_two_solutions_with_check()
    # run_sol_checker()

if __name__ == "__main__":
    main()
