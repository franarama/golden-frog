# golden-frog

This program was a school assignment loosely based off the "Shuffled Frog Leaping Algorithm". 

The goal is to find what is called "The Golden Frog". First, one large array is created (a population of frogs) with random values between 0 and a max depending on user input. Each of these represent X, Y, and Z (different attributes) for the frogs that will eventually determine their "Fitness Value". The population is split up into 5 different memeplexes (groups), and the fitness values are calculated. (Each row represents a frog and the columns are attributes). The frogs with the lowest fitness values from each of the 5 groups are selected. Of the final five, one last comparison is done to find the golden frog. 

Here's how it works:

1. The program takes 3 integers as user input from the command line that represent the max for X, Y and Z. It then creates an array with 100 rows and 3 columns. It populates the array by generating random numbers from 0 to MAX, where MAX is the user input for each column. (The first integer is for column 1, second is column 2, and third is column 3). 

2. The array is then sorted and printed out. (Each line formatted as: [eg: P001 = 6, 13, 27 up until P100 where 6 is the X value, 13 is the Y value, and 27 is the Z value]).

3. 5 new arrays are created, with 20 rows and 5 columns each. Row by row, the values from all the columns from the array in 1) are copied over into the first 3 columns of the new arrays. The value in the 4th column represents a group id (from 1 to 5) and the value in the last column is the fitness value. The fitnes value is found by the following equation:

```

Fitness Value F = x^2 + 3(y^3) - 2(z^2)

```

4. Each of the 5 memeplexes of frogs are sorted and printed out. Since they are sorted, the frogs with the lowest fitness value can be easily found and placed into a subset (another array) called "The Golden 5". Of the 5, the one with the lowest fitness value is found and the frog's details are printed out.
