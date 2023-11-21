# Description
A binary string is a string that consists of characters 0 and 1.

Let MEX of a binary string be the smallest digit among 0, 1, or 2 that does not occur in the string. For example, MEX of 001011 is 2, because 0 and 1 occur in the string at least once, MEX of 1111 is 0, because 0 and 2 do not occur in the string and $0<2$.

A binary string $𝑠$ is given. You should cut it into any number of substrings such that each character is in exactly one substring. It is possible to cut the string into a single substring — the whole string.

A string $𝑎$ is a substring of a string $𝑏$ if $𝑎$ can be obtained from 𝑏 by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.

What is the minimal sum of MEX of all substrings pieces can be?

# Input
A single binary string $𝑠$ ($1 \leq |𝑠| \leq 10^5$).

# Output

Print a single integer — the minimal sum of MEX of all substrings that it is possible to get by cutting $𝑠$ optimally.

# Example
||input
010101
||output
2
||description

||input
11111
||output
0
||description

||end

# Constraints
* $1 \leq n \leq 10^5$
