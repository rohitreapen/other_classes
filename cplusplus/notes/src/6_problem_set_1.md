# Practice problem set 1

1. Write a C++ program to accept the numbers in a sudoku board and check if the numbers are valid as per rules. Give the input:

    ```latex
        5 3 0  0 7 0  0 0 0
        6 0 0  1 9 5  0 0 0
        0 9 8  0 0 0  0 6 0

        8 0 0  0 6 0  0 0 3
        4 0 0  8 0 3  0 0 1
        7 0 0  0 2 0  0 0 6
        
        0 6 0  0 0 0  2 8 0
        0 0 0  4 1 9  0 0 5
        0 0 0  0 8 0  0 7 9
    ```

2. Given a crossword, and a list of stored words, search for and locate if the words are in the crossword (horizontally or vertically located). At the end of the program, print each word and word location in the form

   start_row start_col -> end_row end_col

3. Consider a Battleship board with 10x10 spaces. Let the player board be populated with:
   - 1 battleship (size 4x2)
   - 2 cruisers (size 3x1)
   - 3 destroyers (size 2x1)
   - 4 submarines (size 1x1)

   The rules are:
   - Ships must be straight (horizontally or vertically)
   - Ships must not touch each other, even diagonally
   - if the board is valid, print "valid", else describe the first violation.
