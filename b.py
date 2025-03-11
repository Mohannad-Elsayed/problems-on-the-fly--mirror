def ensure_alternating_sum(lst):
    """
    Ensures that the first element of the list equals the alternating sum of the rest of the list.
    Alternating sum: a2 - a3 + a4 - a5 + ...

    Parameters:
    - lst: List of integers

    Returns:
    - Modified list where the first element equals the alternating sum of the rest.
    """
    s = 0
    for i in range(1, len(lst)):
        if i % 2 == 1:
            s += lst[i]
        else: s -= lst[i]
    return lst[0] == s


# def generate_sequence(n):
#     """
#     Generates a sequence of 2*n+1 positive integers such that
#     the sum of numbers at odd positions (1-based) equals the sum at even positions.
    
#     The method:
#     - For the first 2*n numbers, set:
#         index 0: 1
#         index 1: 2
#         all other indices (2 to 2*n-1): 1
#     - Then, calculate the difference between the sums of the even-indexed group (1-based even positions)
#       and odd-indexed group (1-based odd positions) among these first 2*n numbers.
#     - Append that difference as the last number.
#     """
#     # Create the list for first 2*n numbers.
#     seq = []
#     for i in range(2 * n):
#         if i == 1:
#             seq.append(2)
#         else:
#             seq.append(1)
    
#     # Calculate sums based on 1-based indexing:
#     # 1-based odd positions correspond to 0-based even indices.
#     odd_sum = sum(seq[i] for i in range(0, 2 * n, 2))
#     # 1-based even positions correspond to 0-based odd indices.
#     even_sum = sum(seq[i] for i in range(1, 2 * n, 2))
    
#     # Determine the number to add so that the odd-position sum equals the even-position sum.
#     diff = even_sum - odd_sum
#     # diff is guaranteed to be positive by our construction.
    
#     # Append the diff to complete the sequence.
#     seq.append(diff)
    
#     return seq

# def main():
#     try:
#         n = int(input("Enter a positive integer n: "))
#         if n < 1:
#             print("n must be at least 1.")
#             return
#         sequence = generate_sequence(n)
#         print("Generated sequence:")
#         print(sequence)
        
#         # Verify the condition: sum at 1-based odd indices equals sum at 1-based even indices.
#         odd_positions_sum = sum(sequence[i] for i in range(0, len(sequence), 2))
#         even_positions_sum = sum(sequence[i] for i in range(1, len(sequence), 2))
#         print("\nVerification:")
#         print("Sum at odd positions (1-based):", odd_positions_sum)
#         print("Sum at even positions (1-based):", even_positions_sum)
#     except ValueError:
#         print("Please enter a valid integer.")

# if __name__ == "__main__":
#     main()

import random

def generate_sequence(n, min_val=1, max_val=30):
    """
    Generates a sequence of 2*n+1 positive integers with some randomization such that:
    The sum of numbers at odd positions (1-based) equals the sum at even positions.

    Parameters:
    - n: integer, number of pairs (the sequence length will be 2*n+1)
    - min_val, max_val: range for generating random integers

    Returns:
    - List of integers meeting the condition.
    """
    # Generate 2*n random numbers.
    seq = [random.randint(min_val, max_val) for _ in range(2 * n)]
    
    # Calculate sums for 1-based odd (indices 0,2,4,...) and even positions (indices 1,3,5,...)
    odd_sum = sum(seq[i] for i in range(0, 2 * n, 2))
    even_sum = sum(seq[i] for i in range(1, 2 * n, 2))
    
    # Ensure the even positions' sum is greater than the odd positions' sum.
    # If not, adjust the first even-index element by adding the necessary amount.
    if even_sum <= odd_sum:
        adjustment = (odd_sum - even_sum + 1)
        seq[1] += adjustment
        even_sum += adjustment
    
    # Compute the difference which will be appended to the odd positions group.
    diff = even_sum - odd_sum
    # diff is now guaranteed to be a positive integer.
    seq.append(diff)
    
    return seq

def main():
    try:
        n = int(input("Enter a positive integer n: "))
        if n < 1:
            print("n must be at least 1.")
            return
        
        sequence = generate_sequence(n)
        print("\nGenerated sequence:")
        for x in sequence:
            print(x, end=" ")
        print()
        print(ensure_alternating_sum(sequence))
        # Verification: Sum at odd positions (1-based) equals sum at even positions.
        odd_positions_sum = sum(sequence[i] for i in range(0, len(sequence), 2))
        even_positions_sum = sum(sequence[i] for i in range(1, len(sequence), 2))
        print("\nVerification:")
        print("Sum at odd positions (1-based):", odd_positions_sum)
        print("Sum at even positions (1-based):", even_positions_sum)
        
    except ValueError:
        print("Please enter a valid integer.")

    exit()
if __name__ == "__main__":
    # main()
    lst = list(map(int, input().split()))
    print(ensure_alternating_sum(lst))

