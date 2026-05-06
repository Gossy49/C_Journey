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

int computer_rand(){

    //get random number from range 1 and 100 using the rand() function
    int com_choice = rand() % 100 + 1;
    return com_choice;
}

int main(){
    //starts the random number generator with a different starting value every time the program runs.
    srand(time(NULL));
    //computer choice variable. 
    int computer_choice = computer_rand();
    
    // variable to store user's choice, 
    int user_choice;

    //bool variable for the program to be running in the while looop
    bool is_game_on = true;
    bool game_round =true;

    // to check if we get valid difficulty string
    bool got_valid_diff = false;

    // re_prompt incase user inputs wrong string during difficulty selection 
    int re_prompt =0;
    
    //store amount of tries
    int no_of_tries;
    //variable to store the choice
    char difficulty [10];
   
    
    printf("Welcome To The Guessing Game\n");
    while (is_game_on){
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



        //variable for new game
        char new_game = 'n';

        while(game_round){

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
                game_round = false;
            }
            else{
                no_of_tries --;
                if (no_of_tries == 0){
                    printf("Game Over! You have run out of tries & Computer choice was: %d\n",computer_choice); 
                    game_round =false;
                                
                }
                else{
                    hint(user_choice,computer_choice,no_of_tries);
                    printf("Enter a number: ");
                }
            

            }


            }
        printf("\nDo you want to play again?(y/n):  ");
        if (scanf(" %c", &new_game) != 1)
            {
                printf("\nPlease enter a valid character (y/n): ");   
                while(getchar() != '\n');
             continue;
            }

        if (new_game =='y'){
                computer_choice = computer_rand();
                got_valid_diff = false;
                re_prompt =0;
                game_round = true;
            }
        else{
                is_game_on = false;
            }

            
    }
    return 0;
}
