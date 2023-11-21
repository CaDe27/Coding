# Description
Define a cyclic sequence of size $n$ as an array $𝑠$ of length $𝑛$, in which $𝑠_𝑛$ is adjacent to $𝑠_1$.

Muxii has a ring represented by a cyclic sequence $𝑎$ of size $𝑛$.

However, the ring itself hates equal adjacent elements. So if two adjacent elements in the sequence are equal at any time, one of them will be erased immediately. The sequence doesn't contain equal adjacent elements initially.

Muxii can perform the following operation until the sequence becomes empty:

Choose an element in 𝑎 and erase it. For example, if ring is [1,2,4,2,3,2], and Muxii erases element 4, then ring would erase one of the elements equal to 2, and the ring will become [1,2,3,2].

Muxii wants to find the maximum number of operations he could perform.

Note that in a ring of size 1, its only element isn't considered adjacent to itself (so it's not immediately erased).

# Input
The first line of each test case contains a single integer $𝑛$ ($1≤𝑛≤100000$) — the size of the cyclic sequence.

The second line of each test case contains $𝑛$ integers $a_1$, $a_2$, ..., $a_n$ ($1 \leq a_i \leq n$) - the sequence itself. 

It is guaranteed that no two adjacent elements are equal in the initial subsequence. That is:

• It's guaranteed that $a_i \neq a_{i+1}$ for $1 \leq 𝑖 < n$.

• It's guaranteed that $a_n \neq a_1$ when $𝑛>1$.

# Output
Output a single integer — the maximum number of operations Muxii can perform.

# Example
||input
4
1 2 1 2
||output
3
||description

||input
4
1 2 3 2
||output
4
||description

||end

