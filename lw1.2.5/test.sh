#!/bin/bash

script_dir=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
executable="$script_dir/build/main"
tf_dir="$script_dir/test_files"

test="Test 1: minimal value"
expected="0"
output=$($executable 0)
if [[ "$output" == $expected ]]; then
    echo "$test - Passed"
else
    echo "$test - Failed"
    echo "Expected '$expected', got '$output'"
fi

test="Test 2: maximum value"
expected="255"
output=$($executable 255)
if [[ "$output" == $expected ]]; then
    echo "$test - Passed"
else
    echo "$test - Failed"
    echo "Expected '$expected', got '$output'"
fi

test="Test 3: regular value"
expected="96"
output=$($executable 6)
if [[ "$output" == $expected ]]; then
    echo "$test - Passed"
else
    echo "$test - Failed"
    echo "Expected '$expected', got '$output'"
fi

test="Test 4: out of bounds up value"
expected="Error: Invalid value"
output=$($executable 256)
if [[ "$output" == $expected ]]; then
    echo "$test - Passed"
else
    echo "$test - Failed"
    echo "Expected '$expected', got '$output'"
fi

test="Test 5: out of bounds down value"
expected="Error: Invalid value"
output=$($executable -1)
if [[ "$output" == $expected ]]; then
    echo "$test - Passed"
else
    echo "$test - Failed"
    echo "Expected '$expected', got '$output'"
fi

test="Test 6: no arguments"
expected="Usage: $executable <input byte>"
output=$($executable)
if [[ "$output" == $expected ]]; then
    echo "$test - Passed"
else
    echo "$test - Failed"
    echo "Expected '$expected', got '$output'"
fi

test="Test 7: two arguments"
expected="Usage: $executable <input byte>"
output=$($executable 1 1)
if [[ "$output" == $expected ]]; then
    echo "$test - Passed"
else
    echo "$test - Failed"
    echo "Expected '$expected', got '$output'"
fi

test="Test 8: wrong argument type"
expected="Error: Invalid value"
output=$($executable text)
if [[ "$output" == $expected ]]; then
    echo "$test - Passed"
else
    echo "$test - Failed"
    echo "Expected '$expected', got '$output'"
fi
