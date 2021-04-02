# [Examples](https://en.wikipedia.org/wiki/Admissible_heuristic)

Two different examples of admissible heuristics apply to the fifteen puzzle problem:

    Hamming distance
    Manhattan distance

The Hamming distance is the total number of misplaced tiles. It is clear that this heuristic is admissible since the total number of moves to order the tiles correctly is at least the number of misplaced tiles (each tile not in place must be moved at least once). The cost (number of moves) to the goal (an ordered puzzle) is at least the Hamming distance of the puzzle.

The Manhattan distance of a puzzle is defined as:

    h ( n ) = ∑ all tiles d i s t a n c e ( tile, correct position ) {\displaystyle h(n)=\sum _{\text{all tiles}}{\mathit {distance}}({\text{tile, correct position}})} {\displaystyle h(n)=\sum _{\text{all tiles}}{\mathit {distance}}({\text{tile, correct position}})}

Consider the puzzle below in which the player wishes to move each tile such that the numbers are ordered. The Manhattan distance is an admissible heuristic in this case because every tile will have to be moved at least the number of spots in between itself and its correct position.[2]
4-3 	6-1 	3-0 	8-1
7-2 	12-3    9-3 	14-4
15-3    13-2    1-4 	5-4
2-4 	10-1 	11-1

The subscripts show the Manhattan distance for each tile. The total Manhattan distance for the shown puzzle is:

    h ( n ) = 3 + 1 + 0 + 1 + 2 + 3 + 3 + 4 + 3 + 2 + 4 + 4 + 4 + 1 + 1 = 36 {\displaystyle h(n)=3+1+0+1+2+3+3+4+3+2+4+4+4+1+1=36} h(n)=3+1+0+1+2+3+3+4+3+2+4+4+4+1+1=36