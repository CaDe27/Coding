First of all, when there're only 2 types of elements appearing in the sequence, the answer would be $𝑛/2+1$.

Otherwise, the conclusion is that we can always reach 𝑛 operations when there are more than 2 types of elements appearing in the sequence.

To prove this, note that there must be three adjacent numbers, all of which are different. If not, by contradiction, there would only be two types of elements. Let this numbers be $x$, $y$, and $z$. While the number of elements is greater than three, we will repeatedly apply the following operation:
    • if the element next to $z$ is different than $y$, remove $z$
    • if the element next to $z$ is equal to $y$, remove $y$, and now the three numbers are $x$, $z$ and $y$. Just rename $z$ to $y$, and $y$ to $z$. 

You can repeat this operations until you are left with a sequence with three different elements. You need three operations to eliminate the three of them.

With each operation we eliminated only one number, so we used n operations. 

So we only need to check the number of different elements that appeared in the sequence of length $n$:
. If the number is 2, the answer will be $\frac{n,2}+1$
. Otherwise, the answer equals $n$

