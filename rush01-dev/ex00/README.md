# Skyscraper Solver

This is a program for solving skyscraper puzzles. See subject specifications
for full details on the puzzle

A skyscraper puzzle is a constraint satisfaction problem where a 2d grid must
be filled with values ("skyscrapers") that meet the constraint of the number
of "visible" skyscrapers from each boundary edge.

Initially brute force solver was written. However, the search space was too
large and was not able to solve anything other than trivially small puzzles
in sensible time.

A faster algorithm was implemented with backtracking to early prune unfritful
trees to improve search time. This algorithm is demonstrated in this program.

Successful output is printed to stdio.

In case of error or if no solution found, "Error" is printed to stdio (per specifications)

----------
## Usage
    ./skyscraper_solver "<constraint string>"

----------

A string is expected to be passed in as the argument to the program
representing the constraints.

Constraint string order is expected to be in the following order per the
project specifications: top, bottom, left, right
Top and bottom are in book read order (left to right)
Left and right are in top to bottom order

ie: top-1, top-2, top-3, top-4, bottom-1, ... bottom-4, ... left-1, ...
left-4, ... right-1, ... right-4

    "4 3 2 1  1 2 2 2  4 3 2 1  1 2 2 2" represents:

       top-<col#>--- 4 3 2 1
           <col#>---|1|2|3|4|
         left-1 - 4 |x x x x| 1 - right-1
         left-2 - 3 |x x x x| 2 - right-2
         left-3 - 2 |x x x x| 2 - right-3
         left-4 - 1 |x x x x| 2 - right-4
           <col#>---|1|2|3|4|
    bottom-<col#>--- 1 2 2 2