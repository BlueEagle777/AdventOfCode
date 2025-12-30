.SILENT:

_COMPILER=clang++

part1: part1.cpp
	echo "=============================="
	echo "BUILDING PART 1"
	echo "=============================="
	$(_COMPILER) -o part1 part1.cpp

part2: part2.cpp
	echo "=============================="
	echo "BUILDING PART 2"
	echo "=============================="
	$(_COMPILER) -o part2 part2.cpp

.PHONY: runpart1
runpart1: part1
	echo "=============================="
	echo "RUNNING PART 1"
	echo "=============================="
	./part1

.PHONY: runpart2
runpart2: part2
	echo "=============================="
	echo "RUNNING PART 2"
	echo "=============================="
	./part2
