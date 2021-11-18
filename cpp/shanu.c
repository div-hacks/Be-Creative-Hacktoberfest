#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void main()
{
label:
    system("cls");
    int g, c;
    int count = 0;
    int count2 = 0;

    srand(time(0));
    c = rand() % 100 + 1;
    printf("Player 1 turn\n");
    do
    {
        printf("\nGuess the number:\n");
        scanf("%d", &g);
        if (c > g)
        {
            printf("You guessed smaller number\n");
        }
        else if (c < g)
        {
            printf("You guessed larger number\n");
        }
        else
        {
            printf("player 1 guessed right number in ");
        }
        count++;

    } while (c != g);
    printf("%d turns", count);
    getch();

    srand(time(0));
    c = rand() % 100 + 1;
    printf("\n\n\n\nPlayer 2 turn\n");
    do
    {
        printf("\nGuess the number:\n");
        scanf("%d", &g);
        if (c > g)
        {
            printf("You guessed smaller number\n");
        }
        else if (c < g)
        {
            printf("You guessed larger number\n");
        }
        else
        {
            printf("player 2 guessed right number in ");
        }
        count2++;

    } while (c != g);
    printf("%d turns\n\n", count2);
    if (count < count2)
    {
        printf("player 1 win");
    }
    else if (count > count2)
    {
        printf("player 2 win");
    }
    else
    {
        printf("Draw,both players guessed in equal number of turns");
    }

    getch();
    goto label;
}