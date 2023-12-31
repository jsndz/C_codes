#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int GuessTheNumber(FILE *gamelog){
    int guess, secret, maxattempt = 10, attempts = 0,score;
    int penalty = 10; 
    srand(time(NULL));
    secret = rand() % 100 + 1;
    printf("Welcome to the Exciting Number Guessing Game!\n");
    printf("I have selected a random number between 1 and 100. Try to guess it!\n");
    printf("You have %d attempts. Each incorrect guess will deduct points.\n", maxattempt);
    while (attempts != maxattempt)
    {
        printf("Enter The number: \n ");
        scanf("%d", &guess);
        if (guess == secret)
        {
            printf("Congratulations! You've guessed the correct number in %d attempts\n", attempts + 1);
            score = maxattempt * penalty - attempts * penalty;
            fprintf(gamelog, "Number Guessing Game: %d attempts\n", attempts + 1);
            return score;
        }
        else if (guess < secret)
        {
            printf("The number is Bigger\n");
        }
        else
        {
            printf("The number is Smaller\n");
        }
        attempts++;

        if (attempts == maxattempt)
        {
            printf("Sorry, you've run out of attempts. The correct number was %d.\n", secret);
            printf("Your final score: %d\n", attempts);
            fprintf(gamelog, "Number Guessing Game: Run out of attempts\n");
            
            return 0;
        }
    }
    

}
int main()
{
    FILE *scorecard;
    FILE *gamelog;
    int choice,totalscore,score;
    char username[10];
    printf("Enter The User Name:");
    scanf("%s",username);
    gamelog = fopen("gamelog.txt", "w");
    scorecard = fopen("scorecard.txt", "w");
    if (scorecard == NULL) {
        fprintf(stderr, "Error opening scorecard file.\n");
        exit(1);
    }
    if (gamelog == NULL) {
        fprintf(stderr, "Error opening scorecard file.\n");
        exit(1);
    }
    fprintf(scorecard, "Username: %s\n", username);
    fprintf(gamelog, "Username: %s\n", username);
    while (choice != 2) {
        printf("\nChoose a game to play:\n");
        printf("1. Number Guessing Game\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                score= GuessTheNumber(gamelog);
                totalscore= totalscore+ score;
                break;
            case 2:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } ;

    fprintf(scorecard,"Total Score:%d",totalscore);
    fclose(scorecard);

    return 0;
   
}