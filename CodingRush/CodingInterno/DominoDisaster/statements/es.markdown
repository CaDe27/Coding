# Description
Alice has a grid with $2$ rows and $𝑛$ columns. She fully covers the grid using $𝑛$ dominoes of size $1×2$ — Alice may place them vertically or horizontally, and each cell should be covered by exactly one domino.  

Now, she decided to show one row of the grid to Bob. Help Bob and figure out what the other row of the grid looks like!

# Input
The first line contains an integer $𝑛$ (1≤$𝑛$≤500,000) — the width of the grid.


The second line of each test case contains a string $s$ consisting of $𝑛$ characters, each of which is either L, R, U, or D, representing the left, right, top, or bottom half of a domino, respectively. This string represents one of the rows of the grid. 

The input corresponds to at least one valid tiling.

# Output

Output one string — the other row of the grid, using the same format as the input string. If there are multiple answers, print any.

# Example
||input
6
DDDDDD
||output
UUUUUU
||description
See the notes below. 
||input
5
LRULR
||outputß
LRDLR
||description

||end

# Constraints
* $1 \leq n \leq 500,000$

# Notes
For the first example, the bottom row is shown, which contains the bottom half of the pieces. The other row must contain the upper part of the pieces, hence the output. 

In the second example, the characters LR represent a horizontal domino in the row. The row shown represent a horizontal domino, then the upper part of a domino, and then another horizontal domino. 