#!/bin/sh
set -e

HERE=$(dirname "$0")
PROJECT_ROOT=$(cd "$HERE/.." && pwd)
cd "$PROJECT_ROOT"

make

# Test 1: replace 'World' with 'Earth'
cp tests/input.txt tests/tmp_input.txt
./replace tests/tmp_input.txt World Earth
if [ ! -f "tests/tmp_input.txt.replace" ]; then
  echo "Output file not created"; exit 1
fi
cmp -s tests/tmp_input.txt.replace tests/expected.txt || { echo "Test 1 failed"; exit 1; }
echo "Test 1 passed"

# Test 2: overlapping occurrences (aaaa -> replace 'aa' with 'b' => 'bb')
cp tests/input_overlap.txt tests/tmp_overlap.txt
./replace tests/tmp_overlap.txt aa b
cmp -s tests/tmp_overlap.txt.replace tests/expected_overlap.txt || { echo "Test 2 failed"; exit 1; }
echo "Test 2 passed"

# Test 3: s1 empty should fail
if ./replace tests/input.txt "" x >/dev/null 2>&1; then
  echo "Test 3 failed: program should exit with error when s1 is empty"; exit 1
fi
echo "Test 3 passed (s1 empty handled)"

# Test 4: remove occurrences (replace 'abc' with empty string)
cp tests/input_remove.txt tests/tmp_remove.txt
./replace tests/tmp_remove.txt abc ""
cmp -s tests/tmp_remove.txt.replace tests/expected_remove.txt || { echo "Test 4 failed"; exit 1; }
echo "Test 4 passed"

# Cleanup
rm -f tests/tmp_input.txt tests/tmp_input.txt.replace tests/tmp_overlap.txt tests/tmp_overlap.txt.replace tests/tmp_remove.txt tests/tmp_remove.txt.replace replace

