// Name: Peter Barybin
// KUID: 3057437
// LAB Session: Thursday 4 p.m.
// LAB Assignment: 04
// Description: Program that takes in an integer from the user that represents a football score and outputs all the possible combinations 
// of scoring plays. Program terminates if an integer less than or equal to 1 is entered.

#include <stdio.h>

// combinations function that takes in football score as int
void combinations(int points) {
    int td_and_two;
    int td_and_one;
    int td;
    int fg;
    int safety;
    // iterates through each type of score with for loops to generate all possible combinations less than or equal to user score,
    // and prints them if they are equal to user score (formatted)
    for (td_and_two = 0; (td_and_two)*8 <= points; td_and_two++) {
        for (td_and_one = 0; (td_and_two)*8 + (td_and_one)*7 <= points; td_and_one++) {
            for (td = 0; (td_and_two)*8 + (td_and_one)*7 + (td)*6 <= points; td++) {
                for (fg = 0; (td_and_two)*8 + (td_and_one)*7 + (td)*6 + (fg)*3 <= points; fg++) {
                    for (safety = 0; (td_and_two)*8 + (td_and_one)*7 + (td)*6 + (fg)*3 + (safety)*2 <= points; safety++) {
                        if ((td_and_two)*8 + (td_and_one)*7 + (td)*6 + (fg)*3 + (safety)*2 == points) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td_and_two, td_and_one, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    //continuously prompts user for score until they terminate program by entering score <= 1
    while (1) {
        //get score from user
        int score;
        printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            //terminate
            return 0;
        }

        //print output using combinations function declared above
        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
        combinations(score);

    }
}
