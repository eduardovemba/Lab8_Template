/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief Towers of Hanoi game in C.
 * @version 0.1
 * @date 2022-05-03
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "hanoi.h"
#include "input.h"

int main() {
    printf("### Welcome to Towers of Hanoi. Enjoy the game 🙂 ###\n\n");

    int num_discs;

    // Solicitar ao usuário o número de discos
    do {
        printf("Please enter the number of discs for the game (between 1 and 10): ");
        scanf("%d", &num_discs);

        if (num_discs < 1 || num_discs > 10) {
            printf("Invalid number of discs. Please try again.\n\n");
        }
    } while (num_discs < 1 || num_discs > 10);

    // Inicializar o jogo com o número de discos escolhido pelo usuário
    HanoiGame game = hanoiInit(num_discs);

    while (!hanoiSolved(&game)) {
        hanoiPrint(&game);

        int from, to;
        printf("What's your next move? Enter 0 to quit.\n");

        printf("From [1-3]: ");
        scanf("%d", &from);
        if (from == 0) break;

        printf("To [1-3]: ");
        scanf("%d", &to);
        if (to == 0) break;

        bool valid = hanoiMakeMove(&game, from, to);
        if (!valid) {
            printf("\n🛑 The requested move is invalid! Please try again.\n");
        }
    }

    if (hanoiSolved(&game)) {
        printf("You won! 🥳 Congratulations! \n");
    }

    printf("\n\nThanks for playing. Bye!\n");
    hanoiCleanup(&game);

    return EXIT_SUCCESS;
}