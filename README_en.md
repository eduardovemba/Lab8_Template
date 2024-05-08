# Algorithms and Abstract Data Types

## Lab 8 \| Exercises + Template

🇬🇧 [English version](README_en.md)

This repository was created from:

- <https://github.com/estsetubal-atad/CProgram_Template>

Consult the README if you have questions about its use.

------------------------------------------------------------------------

Goals:

- Using the ADT Stack to develop a game.

References:

- “Abstract Data Types – Language C. Bruno Silva”, available on Moodle.

------------------------------------------------------------------------

### Towers of Hanoi

![](hanoiGame.png)

The [Torres de Hanoi](https://en.wikipedia.org/wiki/Tower_of_Hanoi) game is a simple puzzle consisting of three towers and a certain number of disks of various diameters. The game starts with all the disks stacked, in descending order of size, in the first tower and the objective is to move the entire pile of disks to the third tower, obeying the <u> following rules </u> :

- Only one disk can be moved at a time;

- Each move consists of moving the disk on top of a tower and placing it on an empty tower or another tower;

- No disk may be placed on top of a smaller diameter disk.

The number of discs used determines the difficulty of the game.

### Level 1 (Estimated duration: 15min)

1.  Inspect the `disk` and `hanoi` modules; pay attention to the definition of types `Disk` and `HanoiGame` that define how the game will be represented;

2.  Each tower is represented by an instance of the ADT Stack. To that end, parameterize `StackElem` to be of type `Disk` ;

3.  Finalize the implementation of function `hanoiInit` .

    - You will not be able to test the program yet.

### Level 2 (Estimated duration: 15min)

4.  Implement function `hanoiSolved` , knowing that the game ends when all disks are on the 3rd tower.

    - Don't worry about the ascending order of the disks, the level 4 operation should guarantee it.

5.  Compile and test the program, verifying that initially the game state is the intended one, eg, the 1st tower contains all the disks and the rest are empty.

### Level 3 (Estimated duration: 15min)

6.  Implement function `hanoiCleanup` - this should release the memory of the three stacks referring to the towers.

7.  Compile and test the program, entering `0` to give up. Use valgring to verify correct dynamic memory management.

### Level 4 (Estimated duration: 30min)

8.  Implement function `hanoiMakeMove` . Its operation must obey the rules of the game.

9.  Test the program, verifying that it can win the game, using only valid moves.

### Level 5 (Estimated duration: 15min)

10. The intention is to initially ask (at `main` ) the user the difficulty of the game (at runtime), this to the detriment of the `NUMBER_DISKS` constant used so far (at compile time);

    - It remains to remove the `NUMBER_DISKS` constant and add this field to the `HanoiGame` structure, and change the definition of the `hanoiInit` function:

    ``` cpp
    typedef struct hanoiGame {
        PtStack towers[3];
        int numberDisks;
    } HanoiGame;
    ```

    ``` cpp
    HanoiGame hanoiInit(int numberDisks);
    ```

    Make the necessary modifications to get a working program. You can test the game with 2 and 5 disks.

------------------------------------------------------------------------

``` markdown
@bruno.silva
(EOF)
```

\[Disclaimer: This document was automatically translated, some original formatting may have been lost.\]
