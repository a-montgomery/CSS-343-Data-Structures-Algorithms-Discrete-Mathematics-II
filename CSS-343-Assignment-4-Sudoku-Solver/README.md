# Project Description
Assignment 4 - Sudoku Solver was an individual project created for CSS 343. Sudoku Solver was the final project for the course and required the use of object oriented programming techniques to be sucessfully completed.

For the Sudoku Solver project, I designed and implement a set of classes that define the abstractions necessary to solve puzzles of any kind using genetic algorithms. I then produced concrete subclasses that implemented these interfaces for solving sudoku puzzles.

The interfaces and subclasses necessary for completing the project are:\
-- Population and SudokuPopulation Classes\
-- PuzzleFactory and SudokuFactory Classes\
-- Fitness and SudokuFitness Classes\
-- Reproduction and SudokuOffspring Classes

The program:\
Sudoku Solver takes two command line arguments: the size of the population and the maximum number of generations.  It then reads the sudoku puzzle from cin and generates the first generation (i.e. randomly fill in the squares that are not fixed to produce a population of the specified size with that many different puzzles). The program then begings the genetic algorithm iterations. In each iteration, the program completes the following steps:

1.) Ask the Population for the bestFitness, halting iterations if a solution has been found or if the maximum number of generations limit has been reached\
2.) Command the Population to cull 90\% of its Puzzles\
3.) Command the Population to reproduce a newGeneration\

At the end, the program outputs the best puzzle found, with its fitness value.


# Major Deliverables

-- All relevant C++ Source and Header files\
-- Analysis of the programs output\

