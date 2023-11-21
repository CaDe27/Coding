# Description
Pogelio is having a party tomorrow and is going to give pizza for dinner. Pogelio is a very righteous person, so he wants everyone to receive the same amount of pizza slices. He ordered $n$ pizzas from a company, but there was an accident and not all of them are complete. As you are good with problems, he asked you to help him. He wants to know the maximum amount of his friends he can invite. 

# Input
In the first line, two integers, $n$ and $k$, the number of pizzas he received and the number of friends he has. 

In the second line, $n$ integers, the slices that each box contains. 

# Output
A single integer, the maximum amount of friends he can invite, so that Pogelio and his friends eat the same amount of slices. 

# Example
||input
2 3
6 3

||output
2

||description
There are 9 slices in total, so he cannot invite three friends, as they would be four people. He can invite two people, as everyone would receive three slices. 

||input
2 1
2 2
||output
1
||description
Pogelio can invite his only friend as he they can each have two slices of pizza. 
||end

# Constraints
* $1 \leq n \leq 10^5$;
* $1 \leq k \leq 100$;
* $1 \leq s_i \leq 100$ where $s_i$ is the slices of the $i$-pizza, ($1 \leq i \leq n$).
