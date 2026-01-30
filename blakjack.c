#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int setRan;
int cardsRan;
int numbers[] = {1,2,3,4,5,6,7,8,9};
char *letters = "JQKA";

void game(int *yourPoints, int *tablePoints){
    while(true){
    int choose;
    printf("1 - Hit\n");
    printf("2 - Stop\n");
    scanf("%d", &choose);
    printf("===================================================================\n");

    if(choose == 1){
            setRan = rand() % 2;
            if (setRan == 0){
                cardsRan = rand() % 8;
                *yourPoints += numbers[cardsRan];
            } else if (setRan == 1){
                cardsRan = rand() % 3;
                if (cardsRan != letters[3]){
                    *yourPoints += 10;
                } else if (cardsRan == letters[3] && *yourPoints < 10){
                    *yourPoints += 1;
                } else if (cardsRan == letters[3] && *yourPoints == 10){
                    *yourPoints += 11;
                }
            }
        } else if(choose ==2){
            setRan = rand() % 2;
            if (setRan == 0){
                cardsRan = rand() % 8;
                *tablePoints += numbers[cardsRan];
            } else if (setRan == 1){
                cardsRan = rand() % 3;
                if (cardsRan != letters[3]){
                    *tablePoints += 10;
                } else if (cardsRan == letters[3] && *tablePoints < 10){
                    *tablePoints += 1;
                } else if (cardsRan == letters[3] && *tablePoints == 10){
                    *tablePoints += 11;
                }
            }
        }

        printf("Table points: %d\n", *tablePoints);
        printf("Player points: %d\n", *yourPoints);

        if (*yourPoints == 21){
            printf("You won\n\n");
            break;
        } else if (*yourPoints > 21){
            printf("You Lost\n\n");
            break;
        } else if (*tablePoints == 21){
            printf("You Lost\n\n");
            break;
        } else if (*tablePoints > 21){
            printf("You won\n\n");
            break;
        }
    }
}

void player(int *table){
    int points = 0;
    for(int i = 0; i < 2; i++){
        setRan = rand() % 2;
        if (setRan == 0){
            cardsRan = rand() % 8;
            points += numbers[cardsRan];
        } else if (setRan == 1){
            cardsRan = rand() % 3;
            if (cardsRan != letters[3]){
                points += 10;
            } else if (cardsRan == letters[3] && points < 10){
                points += 1;
            } else if (cardsRan == letters[3] && points == 10){
                points += 11;
            }
        }
    }
        printf("Player points: %d\n\n", points);
        if(points == 21){
            printf("Player Won\n\n");
        } else if (points >= 21){
            printf("Player Lost\n\n");
        } else {
            game(&points, table);
        }
    }


void table(){
    int TableSum = 0;
        printf("Table's turn!\n");
            for (int i = 0; i < 2; i++){
                setRan = rand() % 2;
                if (setRan == 0){
                    cardsRan = rand() % 8;
                    TableSum += numbers[cardsRan];
                } else if (setRan == 1){
                    cardsRan = rand() % 3;
                    if (cardsRan != letters[3]){
                        TableSum += 10;
                    } else if (cardsRan == letters[3] && TableSum < 10){
                        TableSum += 1;
                    } else if (cardsRan == letters[3] && TableSum == 10){
                        TableSum += 11;
                    }
                }
            }

            printf("Table: %d\n\n", TableSum);
                if(TableSum == 21){
                    printf("The table has won\n");
                }else if(TableSum > 21){
                        printf("The table has lost\n");
                }else if(TableSum < 21){
                            printf("Player's time\n");
                            player(&TableSum);
                        }
}
void menu(){
    while(true){
        srand(time(NULL));
        int i;
        printf("Enter 1 to play\n");
        printf("Enter 2 to exit\n\n");
        scanf("%d", &i);
        if(i == 1){
            table();
        }
        else if(i == 2){
            break;
        }
        else{
            printf("Invalid entry, please try again\n\n");
            continue;
        }
    }
}

void main(){
    menu();
}
