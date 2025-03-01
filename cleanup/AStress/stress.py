import subprocess
import random

def generate_test_case(n):
    """Modify this function to generate appropriate test cases."""
    x = random.randint(1, 100)  # Generate a random number x
    permutation = list(range(1, x + 1))
    random.shuffle(permutation)  # Shuffle the permutation
    return f"{x}\n" + " ".join(map(str, permutation)) + "\n"

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
    for test in range(1000):  # Run 100 test cases
        test_case = generate_test_case(test)
        
        brute_output = run_program("b.exe", test_case)
        optimized_output = run_program("o.exe", test_case)

        if brute_output != optimized_output:
            print(f"Test Case {test + 1} Failed!")
            print(f"Input:\n{test_case}")
            print(f"Brute-force Output:\n{brute_output}")
            print(f"Optimized Output:\n{optimized_output}")
            return  # Stop on first failure

    print("All test cases passed!")

if __name__ == "__main__":
    main()
