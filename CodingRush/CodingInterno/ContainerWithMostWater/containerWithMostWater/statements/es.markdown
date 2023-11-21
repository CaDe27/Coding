# Description
You are given an integer array $height$ of length $n$. There are $n$ vertical lines drawn such that the two endpoints of the $i^{th}$ line are ($i$, $0$) and ($i$, $height[i]$).

Find two lines that together with the $x$-axis form a container, such that the container contains the most water.

The amount of water a container contains is given by lines $i$ and $j$ is $min(height[i], height[j])*|j-i|$

Notice that you may not slant the container.

Return the maximum amount of water a container can store.

# Input
The first line contains an integer $n$, the size of the array. 

The second line contains $n$ integers, the heights of the vertical lines. 

# Output
A single integer, the maximum amount of water a container can store. 

# Example
||input
9
1 8 6 2 5 4 8 3 7
||output
49
||description
See the image below to illustrate the container with the maximum capacity. 
||input
2 
1 1
||output
1
||description

||end

Image of example input 1:
![Texto alternativo](exampleInput1.jpg)

# Constraints
* $2 \leq n \leq 10^5$
* $0 \leq height[i] \leq 10^4$
