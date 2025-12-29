.SILENT:

_COMPILER=clang++
_OUTPUTFILE='part'

buildpart1:
	$(_COMPILER) -o $(_OUTPUTFILE)1 part1.cpp

buildpart2:
	$(_COMPILER) -o $(_OUTPUTFILE)2 part2.cpp

part1: buildpart1
	./$(_OUTPUTFILE)1

part2: buildpart2
	./$(_OUTPUTFILE)2
