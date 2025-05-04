# import itertools

# # Set the length of the strings
# n = 3  # You can change this value as needed

# # Generate all possible strings of length n
# characters = 'abcdefghijklmnopqrstuvwxyz'
# all_strings = itertools.product(characters, repeat=n)

# # Write the strings to a file
# output_file = 'generated_strings.txt'
# with open(output_file, 'w') as file:
#     for string_tuple in all_strings:
#         file.write(''.join(string_tuple) + '\n')

# print(f"All possible strings of length {n} have been written to {output_file}.")


# Compare two text files line by line
file1 = 'out1'
file2 = 'out2'

with open(file1, 'r') as f1, open(file2, 'r') as f2:
    lines1 = f1.readlines()
    lines2 = f2.readlines()

differences = []
for i, (line1, line2) in enumerate(zip(lines1, lines2), start=1):
    if line1 != line2:
        differences.append((i, line1.strip(), line2.strip()))

if differences:
    print("Differences found:")
    for diff in differences:
        print(f"Line {diff[0]}: File1 -> '{diff[1]}', File2 -> '{diff[2]}'")
else:
    print("The files are identical.")

# Check if one file has extra lines
if len(lines1) > len(lines2):
    print(f"File1 has extra lines starting from line {len(lines2) + 1}.")
elif len(lines2) > len(lines1):
    print(f"File2 has extra lines starting from line {len(lines1) + 1}.")