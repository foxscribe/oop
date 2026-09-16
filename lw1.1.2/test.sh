#!/bin/bash

script_dir=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
executable="$script_dir/build/main"
tf_dir="$script_dir/test_files"

# Test 1: Identical files
output=$($executable $tf_dir/1.txt $tf_dir/2.txt)
exit_code=$?
if [[ "$output" == "Files are equal" ]] && [[ "$exit_code" -eq 0 ]]; then
    echo "Test 1 Passed: Equal files"
else
    echo "Test 1 Failed: Expected 'Files are equal' and 0, got '$output' and $exit_code"
fi

# Test 2: Slightly different files
output=$($executable $tf_dir/1.txt $tf_dir/3.txt)
exit_code=$?
if [[ "$output" == "Files are different. Line number is 5" ]] && [[ "$exit_code" -eq 1 ]]; then
    echo "Test 2 Passed: Slightly different files"
else
    echo "Test 2 Failed: Expected 'Files are different. Line number is 5' and 1, got '$output' and $exit_code"
fi

# Test 3: Completely different files
output=$($executable $tf_dir/1.txt $tf_dir/4.txt)
exit_code=$?
if [[ "$output" == "Files are different. Line number is 8" ]] && [[ "$exit_code" -eq 1 ]]; then
    echo "Test 3 Passed: Completely different files"
else
    echo "Test 3 Failed: Expected 'Files are different. Line number is 8' and 1, got '$output' and $exit_code"
fi

# Test 4: No files
expected="Error: Not enough or too much arguments. Usage: $executable <file1> <file2>"
output=$($executable)
exit_code=$?
if [[ "$output" == $expected ]] && [[ "$exit_code" -eq 2 ]]; then
    echo "Test 4 Passed: No files"
else
    echo "Test 4 Failed: Expected '$expected' and 2, got '$output' and $exit_code"
fi

# Test 5: One file
expected="Error: Not enough or too much arguments. Usage: $executable <file1> <file2>"
output=$($executable $tf_dir/1.txt)
exit_code=$?
if [[ "$output" == $expected ]] && [[ "$exit_code" -eq 2 ]]; then
    echo "Test 5 Passed: One file"
else
    echo "Test 5 Failed: Expected '$expected' and 2, got '$output' and $exit_code"
fi

# Test 6: Three files
expected="Error: Not enough or too much arguments. Usage: $executable <file1> <file2>"
output=$($executable $tf_dir/1.txt $tf_dir/2.txt $tf_dir/3.txt)
exit_code=$?
if [[ "$output" == $expected ]] && [[ "$exit_code" -eq 2 ]]; then
    echo "Test 6 Passed: Three files"
else
    echo "Test 6 Failed: Expected '$expected' and 2, got '$output' and $exit_code"
fi

# Test 7: First non-existent file
expected="Error: File nonexistent.txt does not exist"
output=$($executable nonexistent.txt $tf_dir/2.txt)
exit_code=$?
if [[ "$output" == $expected ]] && [[ "$exit_code" -eq 3 ]]; then
    echo "Test 7 Passed: First non-existent file"
else
    echo "Test 7 Failed: Expected '$expected' and 3, got '$output' and $exit_code"
fi

# Test 8: Second non-existent file
expected="Error: File nonexistent.txt does not exist"
output=$($executable $tf_dir/2.txt nonexistent.txt)
exit_code=$?
if [[ "$output" == $expected ]] && [[ "$exit_code" -eq 3 ]]; then
    echo "Test 8 Passed: Second non-existent file"
else
    echo "Test 8 Failed: Expected '$expected' and 3, got '$output' and $exit_code"
fi

# Test 9: Both non-existent files
expected="Error: File nonexistent1.txt does not exist"
output=$($executable nonexistent1.txt nonexistent2.txt)
exit_code=$?
if [[ "$output" == $expected ]] && [[ "$exit_code" -eq 3 ]]; then
    echo "Test 9 Passed: Both non-existent files"
else
    echo "Test 9 Failed: Expected '$expected' and 3, got '$output' and $exit_code"
fi

# Test 10: Same file
expected="Error: Given the same file twice"
output=$($executable $tf_dir/2.txt $tf_dir/2.txt)
exit_code=$?
if [[ "$output" == $expected ]] && [[ "$exit_code" -eq 4 ]]; then
    echo "Test 10 Passed: Same file"
else
    echo "Test 10 Failed: Expected '$expected' and 4, got '$output' and $exit_code"
fi
