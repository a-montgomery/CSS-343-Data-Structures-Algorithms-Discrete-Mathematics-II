# Project Description
The Problem: Solving Sudoku Puzzles
Sudoku (Links to an external site.) is a type of puzzle that originated in Japan and attracted a worldwide following, appearing in newspapers, books, and web sites around the world. It is very simple: a 9-by-9 arrangement of squares, subdivided into 3-by-3 groups. A particular puzzle comes with a subset of the squares filled in with numbers from 1 through 9. To solve the puzzle, one must only fill in all the blank squares with numbers from 1 through 9 so that no row, column, or 3-by-3 block in the puzzle has the same number twice. That's all there is to it!

Deterministic Algorithms to Solve Sudoku
There are a variety of techniques that can be used to solve sudoku puzzles. One of the simplest involves the use of what are called pencil marks. In this approach, each unsolved square in the puzzle is first initialized with a list of all possible values: the numbers one through nine. Initialization continues: for each unsolved square, its row, column, and block are scanned. Each time a square that initially has a number assigned to it is found, that square's number is eliminated from the unsolved square's pencil marks. Once this process is done, each unsolved square's initialized pencil marks now contain only those numbers that are still possible solutions.

Solving the puzzle can now commence by finding squares with only single pencil marks: these squares must have that value. Setting that value for a square may change the pencil marks for other squares in its row, column, or block, hopefully producing more squares with singleton marks. This continues until either the puzzle is solved or there are no more squares with such forced values. Unfortunately, only the simplest sudoku puzzles can be solved in this manner; more sophisticated techniques are necessary for harder puzzles.

Genetic Algorithms
In this assignment, we will be using a type of randomized algorithm called genetic programming (Links to an external site.) (GA) to solve sudoku puzzles. Randomized algorithms use a non-deterministic approach to search for problem solutions, coupling randomness with a means for quickly eliminating possibilities that are likely to be inferior. This may not be the most efficient strategy to solve sudoku puzzles, but it is illustrative of the power of such algorithms, in that just about all it requires is a way to evaluate the quality of a partially solved puzzle to achieve a solution (eventually). It will be interesting to see how well GA works for this problem.

GA is also an example of a general algorithm that can be implemented independently of the type of data operated on. You are already familiar with a simple approach to this, using templates. In this assignment, you will use more sophisticated OO design patterns to produce abstract descriptions of the basic operations needed for GA and then develop concrete subclasses of those abstractions.

Genetic Programming as Simplified Evolution
It is difficult for some people to understand how a process like evolution, which is primarily viewed as being driven by an underlying random process (mutation), can produce complex organisms that work so well. However, from a computational point of view, this is not surprising at all. In fact, the area of randomized algorithms is a hot topic — these algorithms have been used successfully to solve many problems for which no deterministic solution exists. From a computational point of view, evolution is a randomized algorithm.

The basic idea behind any type of problem solving is to generate possible solutions, evaluate how good they are, and then use that information to generate what are hopefully better possible solutions. This optimization process is repeated until either a perfect solution is found, a solution that is "good enough" is found, or you give up. This is what you do when you try to find a word in a dictionary. Problems like finding a word in a dictionary are easy to solve because the error in the possible solution at each step tells you how to change the solution for the next step. So, we can generate a deterministic algorithm that solves it.

If we think of the dictionary as a landscape that we're exploring, then it is like a smooth slope, and all we need to do is go downhill (like a rolling marble) until we reach the bottom — the word we're looking for. If we overshoot the word, we've rolled up the hill on the other side, and we just roll back the way we came. Simple problems have this sort of landscape.

Unfortunately, not all problems are simple. Many have rugged landscapes with many little "valleys". We don't want to get stuck in a little valley high in the mountains — we want to reach the lowest valley there is. Clearly, if the terrain is rough, then we can't use the slope of the terrain as our guide. Instead, we need to jump around a bit. And this is what randomization does for us: it allows us to explore the landscape, and it gives us the ability to "mix" the degree of jumping (how far we jump, how jumps are related to starting point, how "jumpy" we are at any point in time) and rolling.

So, evolution is a randomized algorithm in the sense that mutation and recombination change algorithms ("recipes" for organisms) in a random manner and the resultant solutions are "evaluated" by everyday life, with only the best (or, at least, "good enough") solutions able to reproduce (be modified for the next round of optimization).

GA is one way to use an evolution-like process to find optimal algorithms. GA may in general work on representations of algorithms, but in the context of this assignment it will work on a representation of a possible sudoku puzzle solution. A potential sudoku puzzle can simply be a 9-by-9 array of integers, with all values filled in. Clearly, if you fill in all squares in a puzzle randomly, it's unlikely you'll have a valid puzzle solution. But this is merely a starting point.

What makes this approach "genetic" is that a GA program is used that generates an initial, random population of solutions. In each generation, each of the members of the population have their fitness evaluated, and some fraction of the best solutions are selected for reproduction. These reproducing solutions may have their underlying representations randomly altered and may have parts of their representations swapped with other solutions. The result is a new generation of solutions based on the best of the previous generation. This process is repeated until the solution reaches some quality threshold or a maximum number of generations is exceeded.

# Major Deliverables
-- Entity and Relationship Diagrams\
-- SQL statements\
-- Table queries and operations\
-- Discussion of normalization for each table\
-- Project evaluation
