/*
Author: Kevin Elfert
Date: 20 August 2020
Description: a combat calculator
*/
#include <stdio.h>

int main()
{
    const int playerAttack = 12;
    const int goblinAttack = 15;
    int playerMana = 3;
    int playerHealth = 100;
    int goblinHealth = 120;
    int choice;

    printf("a goblin appeared!\n");
    while (playerHealth > 0)
    {
        printf("Player Health: %d\n", playerHealth);
        printf("Player Mana: %d\n", playerMana);
        printf("goblin Health: %d\n", goblinHealth);
        printf("What would you like to do?\n");
        printf("\t1) Sword Attack\n");
        printf("\t2) Charge Mana\n");
        printf("\t3) Destruction Spell\n");
        printf("\t4) Healing Spell\n");
        printf("\t5) Run\n");

        scanf("%d", &choice);

        if(choice == 1)
        {
            goblinHealth-=playerAttack;
        }
        if(choice == 2)
        {
            playerMana+=2;
        }
        if(choice == 3)
        {
            if(playerMana>=2)
            {
                goblinHealth/=2;
                playerMana-=2;
            }
            else
            {
                printf("You do not have enough Mana!\n");
            }  
        }
        if(choice == 4)
        {
            if(playerMana>=2)
            {
                playerHealth+=30;
                playerMana-=2;
            }
            else
            {
                printf("You do not have enough Mana!\n");
            }
        }
        if(choice == 5)
        {
            printf("You Run Away!\n");
            break;
        }
        playerHealth-=goblinAttack;
        if(goblinHealth<=0)
            break;
    }
    if(playerHealth<=0)
    {
        printf("The goblin has defeated you!\n");
        printf("You Lose!\n");
    }
    if(goblinHealth<=0)
    {
        printf("You have defeated the goblin!\n");
        printf("You Win!\n");
    }
    return 0;
}