# C++ Mini-Antivirus (Static Scanner)

# Overview
- A lightweight C++ tool designed to scan files for malicious byte signatures. It uses C++ File Streams ('<fstream>') to analyze the raw binary data of files on the hard drive.
1. Memory Allocation: The program opens a target file and loads its contents byte-by-byte into a dynamically resizing Heap array ('std::vector<char>').
2. Data Normalization: To prevent attackers from bypassing the scanner using uppercase/lowercase obfuscation ( e.g., hiding the virus as 'eViL' instead of 'evil'), the scanner uses '<cctype>' to normalize all bytes to lowercase during the inspection.
3. Sliding Window: It uses a bounded 'for' loop to slide a "window" across the memory array, checking for specific hexadecimal malware signatures.
4. Memory Safety: The loop's limit is strictly bound '(size -3)' to prevent an Segmentation Faults.

# How to run it
1. Create a dummy file in the same folder as the program, and hide the word "EVIL" inside it. Or just use the dummy file I provided ('malware.txt').
2. Compile the scanner: Use the 'build.sh' file.
3. Execute the scan: './scanner malware.txt'. Or replace 'malware.txt' whith the file you created.
