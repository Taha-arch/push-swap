#!/bin/bash
# test_push_swap.sh

echo "=== Testing Push Swap ==="

# Test small cases
echo "Test 1: 2 elements"
./a.out 2 1 | ./checker_linux 2 1
echo "Moves: $(./a.out 2 1 | wc -l)"

echo -e "\nTest 2: 3 elements"
./a.out 3 2 1 | ./checker_linux 3 2 1
echo "Moves: $(./a.out 3 2 1 | wc -l)"

echo -e "\nTest 3: 5 elements"
./a.out 5 4 3 2 1 | ./checker_linux 5 4 3 2 1
echo "Moves: $(./a.out 5 4 3 2 1 | wc -l)"

# Test 100 elements - 10 times
echo -e "\n=== Testing 100 elements ==="
pass=0
fail=0
for i in {1..10000}; do
    ARG=$(seq 1 100 | shuf)
    RESULT=$(./a.out $ARG | ./checker_linux $ARG)
    MOVES=$(./a.out $ARG | wc -l)
    
    if [ "$RESULT" = "OK" ] && [ $MOVES -lt 700 ]; then
        echo "✅ Test $i: OK - Moves: $MOVES"
        ((pass++))
    else
        echo "❌ Test $i: $RESULT - Moves: $MOVES"
        ((fail++))
    fi
done
echo "100 elements: $pass/10 passed"

# Test 500 elements - 10 times
echo -e "\n=== Testing 500 elements ==="
pass=0
fail=0
for i in {1..1000}; do
    ARG=$(seq 1 500 | shuf)
    RESULT=$(./a.out $ARG | ./checker_linux $ARG)
    MOVES=$(./a.out $ARG | wc -l)
    
    if [ "$RESULT" = "OK" ] && [ $MOVES -lt 5500 ]; then
        echo "✅ Test $i: OK - Moves: $MOVES"
        ((pass++))
    else
        echo "❌ Test $i: $RESULT - Moves: $MOVES"
        ((fail++))
    fi
done
echo "500 elements: $pass/10 passed"

echo -e "\n🎉 Testing Complete!"
