# Skyscraper Solver

This is a program for solving skyscraper puzzles. See subject specifications for full details on the puzzle.

A skyscraper puzzle is a constraint satisfaction problem where a 2d grid must be filled with values ("skyscrapers") that meet the constraint of the number of "visible" skyscrapers from each boundary edge.

Successful output is printed to stdio.

In case of error or if no solution found, "Error" is printed to stdio (per specifications).

----------
## Usage

    ./skyscraper_solver "<constraint string>"

----------

## Constraints

Designed to handle puzzles from 1x1 to 9x9. Constraint string must be a valid string representing the constraints (see below).

A string is expected to be passed in as the argument to the program representing the constraints.

This program expects the full border of constraints. It is not designed to handle situations where there are "missing" constraints around the border.

----------

## Further Details

Skyscraper puzzles are an example of a constraint satisfaction problem. They are a similar puzzle type to a classic sudoku but with different somewhat different validation rules.

A full explanation of how the game is played can be found elsewhere, but simply speaking, the board exists as a 2d grid of cells. These cells are empty and the player is to fill the cells with skyscrapers of a certain height such that the correct number can be "visible" from each vantage point along all the sides.

Initially a brute force solver was written. However, the search space was too large and this was not able to solve anything other than trivially small puzzles in sensible time.

A faster algorithm was implemented with backtracking to early prune unfruitful trees to improve search time. This algorithm is what is demonstrated in this program.

<br>

### Backtracking algorithm

The backtracking algorithm was written following this pseudocode skeleton.

With six base procedural parameters.

    1. root(P): return the partial candidate at the root of the search tree.
    2. reject(P,c): return true only if the partial candidate c is not worth completing.
    3. accept(P,c): return true if c is a solution of P, and false otherwise.
    4. first(P,c): generate the first extension of candidate c.
    5. next(P,s): generate the next alternative extension of a candidate, after the extension s.
    6. output(P,c): use the solution c of P, as appropriate to the application.

The backtracking algorithm itself is a recursive procedure where.

    procedure backtrack(c) is
        if reject(P, c) then return
        if accept(P, c) then output(P, c)
        s ??? first(P, c)
        while s ??? NULL do
            backtrack(s)
            s ??? next(P, s)

The first call to backtrack is called with the root node.

    backtrack (root(P))

A cleaner implementation would be to have entirely functional base procedural parameters and return objects representing the entire puzzle. However to accommodate the current provided limits in allowed c functions (And to avoid structs/malloc given time limits) this has been slightly modified so that all the functions are performed in-place in a pre initialised shared grid.

<br>

### Design

Constraint string order is expected to be in the following order per the project specifications: top, bottom, left, right. Top and bottom are in book read order (left to right). Left and right are in top to bottom order.

Ie: top-1, top-2, top-3, top-4, bottom-1, ... bottom-4, ... left-1, ... left-4, ... right-1, ... right-4

    "4 3 2 1  1 2 2 2  4 3 2 1  1 2 2 2" represents:

       top-<col#>--- 4 3 2 1
           <col#>---|1|2|3|4|
         left-1 - 4 |x x x x| 1 - right-1
         left-2 - 3 |x x x x| 2 - right-2
         left-3 - 2 |x x x x| 2 - right-3
         left-4 - 1 |x x x x| 2 - right-4
           <col#>---|1|2|3|4|
    bottom-<col#>--- 1 2 2 2

Grid is represented within the program as a 1d array. The grid is unwrapped in book read order. The (row, col) position is removed out from the grid mathematically (using integer division and remainder divison) to calculate where it lies in the grid.

    grid: [cell 0, cell 1, cell 2, cell 3, cell 4, ...]
    
    2d representation:
    -------------------------------------
    | cell 0 | cell 1 | cell 2 | cell 3 |
    | cell 4 | cell 5 | cell 6 | cell 7 |
    ...
    | cell 10| cell 11| cell 12| cell 13|
    -------------------------------------