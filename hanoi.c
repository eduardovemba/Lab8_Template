#include "hanoi.h"
#include "disk.h"
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#define NUMBER_DISKS 3

typedef struct {
    PtStack towers[3];
    int num_disks;
} HanoiGame;

typedef HanoiGame *PtHanoiGame;


HanoiGame hanoiInit() {
   HanoiGame game;

   int num_Disks = NUMBER_DISKS;

    // Inicializa o número total de discos no jogo
    game.num_disks = NUMBER_DISKS;

    // Aloca memória para as torres
    game.towers = (StackElem **)malloc(3 * sizeof(StackElem *));
    if (game.towers == NULL) {
        exit(EXIT_FAILURE); // Saída se a alocação falhar
    }

    // Cria uma nova pilha para representar cada torre
    for (int i = 0; i < 3; i++) {
        game.towers[i] = createStack(); // Cria uma nova pilha para a torre i
        if (game.towers[i] == NULL) {
            // Se a criação da pilha falhar, libera a memória alocada anteriormente e sai
            for (int j = 0; j < i; j++) {
                destroyStack(game.towers[j]);
            }
            free(game.towers);
            exit(EXIT_FAILURE);
        }
    }

    // Coloca todos os discos na primeira torre (game.towers[0])
    for (int i = NUMBER_DISKS; i > 0; i--) {
        Disk *new_disk = (Disk *)malloc(sizeof(Disk)); // Aloca memória para um novo disco
        if (new_disk == NULL) {
            // Se a alocação falhar, libera a memória alocada anteriormente e sai
            for (int j = 0; j < 3; j++) {
                destroyStack(game.towers[j]);
            }
            free(game.towers);
            exit(EXIT_FAILURE);
        }
        new_disk->size = i; // Define o tamanho do disco
        push(game.towers[0], *new_disk); // Empilha o novo disco na primeira torre
        free(new_disk); // Libera a memória alocada para o disco após empilhá-lo
    }

    return game;
}

void hanoiCleanup(PtHanoiGame game) {
      for (int i = 0; i < 3; i++) {
        stackDestroy(&(game->towers[i]));
    }
    // Liberar a memória alocada para o array de ponteiros de pilhas
    free(game->towers);
}

void hanoiPrint(PtHanoiGame game) {
    printf("### GAME STATE ###\n");

    // Print all tower's contents
    for(int i=0; i<3; i++) {
        printf("\n🗼 Tower %d: \n", (i+1));
        stackPrint(game->towers[i]);
    }

    printf("\n##################\n");
}

bool hanoiMakeMove(PtHanoiGame game, int towerFrom, int towerTo) {
    if (towerFrom < 1 || towerFrom > 3 || towerTo < 1 || towerTo > 3) {
        printf("As torres especificadas estão fora dos limites válidos.\n");
        return false;
    }
    towerFrom--;
    towerTo--;

    if (stackIsEmpty(game->towers[towerFrom])) {
        printf("A torre de origem está vazia.\n");
        return false;
    }

    Disk top_disk;
    if (stackPeek(game->towers[towerFrom], &top_disk) != STACK_OK) {
        printf("Erro ao obter o disco do topo da torre de origem.\n");
        return false;
    }

    if (!stackIsEmpty(game->towers[towerTo]) && top_disk.size > stackPeekSize(game->towers[towerTo])) {
        printf("Um disco não pode ser colocado em cima de um disco menor.\n");
        return false;
    }

    if (stackPop(game->towers[towerFrom], NULL) != STACK_OK) {
        printf("Erro ao remover o disco do topo da torre de origem.\n");
        return false;
    }

    if (stackPush(game->towers[towerTo], NULL) != STACK_OK) {
        printf("Erro ao empilhar o disco na torre de destino.\n");
       
        stackPush(game->towers[towerFrom], top_disk);
        return false;
    }

    printf("Disco movido da torre %d para a torre %d.\n", towerFrom + 1, towerTo + 1);

    return true;
}

bool hanoiSolved(HanoiGame game) {
    int num_discs_on_third_tower = size(game.towers[2]); // Supondo que a terceira torre seja game.towers[2]
    return num_discs_on_third_tower == game.num_disks;
    return false;
}