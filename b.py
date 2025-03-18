import os

# Set the folder where your videos are located
video_folder = "C:\\Users\\moha\\Downloads\\Week-4-upsolve-l1\\mp4"  # Change this to your actual folder path (Use \\ on Windows)
output_file = "list.txt"

# Get all MP4 files and sort them alphabetically
videos = sorted([f for f in os.listdir(video_folder) if f.endswith(".mp4")])

# Write to list.txt in FFmpeg format
with open(os.path.join(video_folder, output_file), "w") as f:
    for video in videos:
        f.write(f"file '{video}'\n")

print("✅ list.txt has been created!")
