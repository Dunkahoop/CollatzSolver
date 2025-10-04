# Collatz Solver

I wrote this after seeing [Veritasium's video](youtu.be/094y1Z2wpJg) on the problem, and thought it would be a good exercise.

the function caluclated in the program in KaTeX is:

$$f(n) = \begin{cases} \frac{n}{2} &\text{if } n \equiv 0 \pmod{2},\\
\frac{3n+1}{2} & \text{if } n\equiv 1 \pmod{2}. \end{cases}$$

As the result of $3x+1$ will always be even, we also divide it by 2 to speed things up.

If you run this long enough and prove the conjecture wrong, please credit me in whatever paper you write and message me directly via [LinkedIn](linkedin.com/in/duncan-wade919/).

This requires [Boost](boost.org) to work, as it will deal with very large numbers and starts out with the largest number tried on the conjecture.
