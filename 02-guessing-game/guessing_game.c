#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*hint function to give user hint if they are closer or further from the computer guessed number*/ 
void hint(int user_num, int comp_num, int tries)
{
    
    if (user_num > comp_num){
        printf("Too high. %d tries left.\n", tries);
    }
    else{
        printf("Too low. %d tries left.\n", tries);
    }
}

int main(){
    // variable to store user's choice, 
    int user_choice;

    //bool variable for the program to be running in the while looop
    bool is_game_on = true;

    // to check if we get valid difficulty string
    bool got_valid_diff = false;

    // re_prompt incase user inputs wrong string during difficulty selection 
    int re_prompt =0;
    
    //store amount of tries
    int no_of_tries;
    //variable to store the choice
    char difficulty [10];
    
    printf("Welcome To The Guessing Game\n");
    while (! got_valid_diff){
        
        //user enters difficulty
        printf("Enter a Difficulty (easy, meduim, hard): ");
        // store string in difficulty 
        scanf("%s", difficulty);
        
        // comparing the string user inputed with required string and assign the no of tries for the difficulty selected
        if (strcmp(difficulty, "easy")== 0){
                no_of_tries =10;
                got_valid_diff =true;
        }
        else if (strcmp(difficulty ,"meduim") == 0){
                no_of_tries =5;
                got_valid_diff =true;
        }
        else if(strcmp (difficulty ,"hard") == 0){
                no_of_tries =3;
                got_valid_diff =true;
        }
        else{
            // to reprompt user if wrong inputs in entering difficulty
            re_prompt ++;
            // if the repromopt times is equal to 3 then we set to default mode which is meduim
            if (re_prompt == 3){
                no_of_tries =5;
                got_valid_diff = true;
                printf("\nDifficulty set to Default...\n");
                break;
            }
            printf("\nWrong Difficulty level entered...\n");
        }
    }
    
    printf ("You have %d tries\n",no_of_tries);

    //prompt for user to guess a number
    printf("Guess a number between 1 to 100: ");

    //starts the random number generator with a different starting value every time the program runs.
    srand(time(NULL));
    //get random number from range 1 and 100 using the rand() function
    int computer_choice = rand() % 100 + 1;

    while(is_game_on){

        // incase the user inputs a abaijd then we info the user and also clear the buffer. 
        if (scanf("%d", &user_choice) != 1)
        {
            printf("\nPlease enter a valid Number: ");   
            while(getchar() != '\n');
            continue;
        }
        

        // check if the user_choice is equal to computer_choice 
        if (user_choice == computer_choice ){
            printf("You won...\n");
            // if they are both the same we break out of the loop
            is_game_on = false;
        }
        else{
            no_of_tries --;
            if (no_of_tries == 0){
                printf("You have run out of tries\n");
                is_game_on = false;
            }
            else{
                hint(user_choice,computer_choice,no_of_tries);
                printf("Enter a number: ");
            }
        }
            
    }

    return 0;
}
