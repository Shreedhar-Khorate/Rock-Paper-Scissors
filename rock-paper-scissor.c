#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int userScore=0,computerScore=0;
void gameResult()
{
    //this function use to show result who won the game
    if (userScore>computerScore)
    {
        printf("\nCongrat's! You won the game\n\n");
    }
    else if(computerScore>userScore)
    {
        printf("\nComputer Won the game\n\n");
    }
    else if(userScore==computerScore)
    {
        printf("\nGame is draw!\n\n");
    }           
}
int getScore(int userChoose,int computerChoose)
{
    //getScore functino use to give point to players
    if (userChoose==1&&computerChoose==2)//When user chose rock and computer chose scissor
    {
        userScore+=1; //user got 1 point
        return 2;
    }
    else if(userChoose==2&&computerChoose==0)//When user choe paper and computer choose rock
    {
        userScore+=1;  //user got 1 point
        return 2;
    }
    else if (userChoose==3&&computerChoose==1)//When user chose scissor and computer chose paper
    {
        userScore+=1; //user got 1 point
        return 2;        
    }
    else if (computerChoose==0&&userChoose==3)//When computer chose rock and user chose scissor
    {
        computerScore+=1; //computer got 1 pint
        return 1;
    }
    else if(computerChoose==1&&userChoose==1)//When computer chose paper and user chose rock
    {
        computerScore+=1; //computer got 1 pint
        return 1;
    }
    else if (computerChoose==2&&userChoose==2)//When computer chose scissor and user chose paper
    {
        computerScore+=1; //computer got 1 pint
        return 1;        
    }else
    {
        //When both chose same sign
        //both got 1 points
        userScore+=1;
        computerScore+=1;
        return 3;
    }              
}
void playGame()
{
    //playGame function use to play game
    int userChoose,computerChoose,check;
    printf("\n----------------------------------------------------\n");
    printf("\nEnter 1 for Rock,2 for Paper and 3 for Scissor\n");
    repeate:
    printf("Your turn: ");
    scanf("%d",&userChoose);
    switch (userChoose)
    {
    case 1:
        printf("You chose: Rock\n");
        break;
    case 2:
        printf("You chose: Paper\n");
        break;
    case 3:
        printf("You chose: Scissor\n");
        break;
    default:
        printf("Invalid number try again\n");
        goto repeate;
        break;
    }
    printf("\nYour score: %d\nComputer score: %d\n",userScore,computerScore);
    printf("\n----------------------------------------------------\n");
    printf("\nEnter 1 for Rock,2 for Paper and 3 for Scissor\n");
    printf("Computer's turn:\n");
    srand(time(NULL));
    computerChoose=rand()%3;//generating number randomly
    switch (computerChoose)
    {
    case 0:
        printf("computer chose: Rock\n");
        break;
    case 1:
        printf("computer chose: Paper\n");
        break;
    case 2:
        printf("computer chose: Scissor\n");
        break;
    }
    check=getScore(userChoose,computerChoose);
    if (check==2)
    {
        printf("You got 1 points\n");
    }
    else if(check==1)
    {
        printf("Computer got 1 points\n");
    }else
    {
        printf("Both got 1 points\n");
    }        
    printf("\nYour score: %d\nComputer score: %d\n",userScore,computerScore);
}
int main()
{
    int i;
    printf("\n*Welcome To Rock Paper Scissor Game*\n");
    printf("Here are few rules of this game\n");
    printf("1.This game is being paly between you and computer\n");
    printf("2.The game is being play three times\n");
    printf("3.If your score is high then you won the game\n");
    printf("4.Rock defeate Scissor,Scissor defeate Paper and Paper defeate Rock\n");
    printf("5.If you defeate computer then you get 1 score\n");
    printf("6.If computer defeate you then computer get 1 score\n");
    for ( i = 0; i < 3; i++)
    {
        playGame();
    } 
    gameResult();   
}