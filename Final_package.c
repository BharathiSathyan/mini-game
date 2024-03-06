#include<stdio.h>
#include<string.h>
//NUMBER SWAP GAME
//FUNCTION TO PRINT THE RULES OF NUMBER SWAP GAME
char print()
{
     char choice;
     system("cls");
     printf(" -> The game board has blocks with numbers in it. Also there is a '0' that can be used for moving the blocks.\n");
     printf(" -> The objective of the game is to order the numbers using the '0' for temporary movement.\n");
     printf(" -> Move blocks in a row or column by entering the respective block numbers. A block can be moved only if it is in the same row or column as the '0'\n");
     printf("********************************************************************ENTER 'y 'TO START*************************************************************** \n");
     choice=getch();
     if(choice=='y'||choice=='Y');
        system("cls");
     return choice;
}
//FUNCTION TO SWAP DIGITS
void swap(char direction,int (*b)[3],int (*o)[3],int *a)
{
    int t;
            switch(direction)
            {
                    case 'a':
                    case 'A':t=*(*(b+*(a+2))+*(a+1));
                             *(*(b+*(a+2))+*(a+1))=*(*(b+*(a+2))+*(a+1)-1);
                             *(*(b+*(a+2))+*(a+1)-1)=t;
                             *(a+1)=*(a+1)-1;
                             *(a+0)=check(b,o);
                             break;
                    case 'd':
                    case 'D':t=*(*(b+*(a+2))+*(a+1));
                             *(*(b+*(a+2))+*(a+1))=*(*(b+*(a+2))+*(a+1)+1);
                             *(*(b+*(a+2))+*(a+1)+1)=t;
                             *(a+1)=*(a+1)+1;
                             *(a+0)=check(b,o);
                             break;
                    case 'w':
                    case 'W':t=*(*(b+*(a+2))+*(a+1));
                             *(*(b+*(a+2))+*(a+1))=*(*(b+*(a+2)-1)+*(a+1));
                             *(*(b+*(a+2)-1)+*(a+1))=t;
                             *(a+2)=*(a+2)-1;
                             *(a+0)=check(b,o);
                            break;
                    case 's':
                    case 'S':t=*(*(b+*(a+2))+*(a+1));
                             *(*(b+*(a+2))+*(a+1))=*(*(b+*(a+2)+1)+*(a+1));
                             *(*(b+*(a+2)+1)+*(a+1))=t;
                             *(a+2)=*(a+2)+1;
                             *(a+0)=check(b,o);
                            break;
            }
}
//FUNCTION TO CHECK IF THE FINAL OUTPUT IS RIGHT
int check(int (*b)[3],int (*o)[3])
{
    int i,j,count; count=0;
            for(i=0;i<3;i++)
            {
                    for(j=0;j<3;j++)
                    {
                            if(*(*(b+i)+j)==*(*(o+i)+j))
                            {
                                count++;
                            }
                            else
                            {
                                count=0;
                                goto stop;
                            }
                    }
            }
    stop:
    return count;
}
//FUNCTION TO GET THE INPUT FROM USER
char get()
{
    char direction;
    printf("a-LEFT\n");
    printf("d-right\n");
    printf("w-up\n");
    printf("s-down\n");
    printf("enter the side to move the 'o'");
    direction=getch();
    system("cls");
    return direction;
}
//THE FUNCTION TO WHICH CONTROLS THE NUMBER SWAP GAME
int number_game()
{
    char choice,direction;
    choice=print();
    if(choice=='y'||choice=='Y')
    {
    int i,j,a[3];
    a[0]=0;
    a[1]=2;
    a[2]=2;
    int box[3][3]={{8,2,4},{5,1,3},{6,7,0}};
    int order[3][3]={{1,2,3},{4,5,6},{7,8,0}};
    int (*b)[3],(*o)[3];
    b=box;
    o=order;
    repeat:
    printf("\tGAME\n\n");
    for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("\t%d",box[i][j]);
            }
            printf("\n");
        }
    direction=get();
    swap(direction,b,o,a);
    if(*(a+0)==9)
    {
        printf("*****YOU WON*****");
        printf("\n");
        goto end;
    }
    else
    {
        goto repeat;
    }
    end:
    for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                printf("\t%d",box[i][j]);
            }
            printf("\n");
        }
    return 0;
    }
    else
    {
    printf("Quited");
    return 0;
    }
}
//MORSE CODE GAME
//TO DISPLAY MORSE CODE
void disp(char **p,int *q,int n)
{
    printf("\t\t\tMORSE CODE\n\n");
    printf("\tALPHABET\t\t\tMORSE\n");
    for(int i=0;i<n;i++)
    {
        printf("\t   %c\t\t\t\t%s\n",*(q+i),p[i]);
        printf("\n");
    }
}
//FUNCTION FOR MORSE CODE JUMBLED GAME(EASY)
int easy(char **p,int *q,int rep)
{
    int score=0,T;
    char guess[15];
    char clue;
    char *wrd[5]={"CAMEL","EMOTION","OPINION","RELATE","STRESSFUL"};
    char *jum[5]={"MALEC","NOMEONTI","OIOINNP","TLEERA","FRSUTSLSE"};
    //display the jumbled lettered word in morse code
    int time;
    time=rep%5;
    switch(time)
    {
    case 1:
        {
            for(int i=0;i<strlen(jum[0]);i++)
            {
                int val,ind;
                val=jum[0][i];
                for(int j=0;j<26;j++)
                {
                    if(val==*(q+j))
                        ind=j;
                }
                printf("%s  ",p[ind]);
            }
        }break;
    case 2:
        {
            for(int i=0;i<strlen(jum[1]);i++)
            {
                int val,ind;
                val=jum[1][i];
                for(int j=0;j<26;j++)
                {
                    if(val==*(q+j))
                        ind=j;
                }
                printf("%s  ",p[ind]);
            }
        }break;
    case 3:
        {
            for(int i=0;i<strlen(jum[2]);i++)
            {
                int val,ind;
                val=jum[2][i];
                for(int j=0;j<26;j++)
                {
                    if(val==*(q+j))
                        ind=j;
                }
                printf("%s  ",p[ind]);
            }
        }break;
    case 4:
        {
            for(int i=0;i<strlen(jum[3]);i++)
            {
                int val,ind;
                val=jum[3][i];
                for(int j=0;j<26;j++)
                {
                    if(val==*(q+j))
                        ind=j;
                }
                printf("%s  ",p[ind]);
            }
        }break;
    case 5:
        {
            for(int i=0;i<strlen(jum[4]);i++)
            {
                int val,ind;
                val=jum[4][i];
                for(int j=0;j<26;j++)
                {
                    if(val==*(q+j))
                        ind=j;
                }
                printf("%s  ",p[ind]);
            }
        }break;
    }
    int chance=1;
    int clue_flag=1;
    NEXTCHANCE:
    while(chance<6)
    {
        if(chance>2&&clue_flag==1&&chance<5)
        {
            printf("\nDO YOU WANT A CLUE?(y-yes and n-no)\n");
            clue=getch();
            if(clue=='y'||clue=='Y')
            {
                clue_flag=0;
                switch(time)
                {
                case 1:
                    {
                        for(int k=0;k<strlen(jum[0])-1;k++)
                        {
                            printf("_ ");
                        }
                        printf("%c",wrd[0][strlen(jum[0])-1]);
                    }break;
                case 2:
                    {
                        for(int k=0;k<strlen(jum[1])-1;k++)
                        {
                            printf("_ ");
                        }
                        printf("%c",wrd[1][strlen(jum[1])-1]);
                    }break;
                case 3:
                    {
                        for(int k=0;k<strlen(jum[2])-1;k++)
                        {
                            printf("_ ");
                        }
                        printf("%c",wrd[2][strlen(jum[2])-1]);
                    }break;
                case 4:
                    {
                        for(int k=0;k<strlen(jum[3])-1;k++)
                        {
                            printf("_ ");
                        }
                        printf("%c",wrd[3][strlen(jum[3])-1]);
                    }break;
                case 5:
                    {
                        for(int k=0;k<strlen(jum[4])-1;k++)
                        {
                            printf("_ ");
                        }
                        printf("%c",wrd[4][strlen(jum[4])-1]);
                    }break;
                }
            }
        }
        printf("\nGuess the word:");
        scanf("\n%s",guess);
        switch(time)
        {
        case 1:
            {
                if(strcmp(guess,wrd[0])==0)
                {
                    switch(chance)
                    {
                        case 1:score=10;break;
                        case 2:score=8;break;
                        case 3:
                            {
                                if(clue_flag!=0)
                                    score=6;
                                else
                                    score=5;
                            }break;
                        case 4:
                            {
                                if(clue_flag!=0)
                                    score=4;
                                else
                                    score=3;
                            }break;
                       case 5:
                            score=2;break;
                    }
                    T=1;
                }
            }break;
        case 2:
            {
                if(strcmp(guess,wrd[1])==0)
                {
                    switch(chance)
                    {
                        case 1:score=10;break;
                        case 2:score=8;break;
                        case 3:
                            {
                                if(clue_flag!=0)
                                    score=6;
                                else
                                    score=5;
                            }break;
                        case 4:
                            {
                                if(clue_flag!=0)
                                    score=4;
                                else
                                    score=3;
                            }break;
                       case 5:
                            score=2;break;
                    }
                    T=1;
                }
            }
        case 3:
            {
                if(strcmp(guess,wrd[2])==0)
                {
                    switch(chance)
                    {
                        case 1:score=10;break;
                        case 2:score=8;break;
                        case 3:
                            {
                                if(clue_flag!=0)
                                    score=6;
                                else
                                    score=5;
                            }break;
                        case 4:
                            {
                                if(clue_flag!=0)
                                    score=4;
                                else
                                    score=3;
                            }break;
                       case 5:
                            score=2;break;
                    }
                    T=1;
                }
            }break;
        case 4:
            {
                if(strcmp(guess,wrd[3])==0)
                {
                    switch(chance)
                    {
                        case 1:score=10;break;
                        case 2:score=8;break;
                        case 3:
                            {
                                if(clue_flag!=0)
                                    score=6;
                                else
                                    score=5;
                            }break;
                        case 4:
                            {
                                if(clue_flag!=0)
                                    score=4;
                                else
                                    score=3;
                            }break;
                       case 5:
                            score=2;break;
                    }
                    T=1;
                }
            }break;
        case 5:
            {
                if(strcmp(guess,wrd[4])==0)
                {
                    switch(chance)
                    {
                        case 1:score=10;break;
                        case 2:score=8;break;
                        case 3:
                            {
                                if(clue_flag!=0)
                                    score=6;
                                else
                                    score=5;
                            }break;
                        case 4:
                            {
                                if(clue_flag!=0)
                                    score=4;
                                else
                                    score=3;
                            }break;
                       case 5:
                            score=2;break;
                    }
                    T=1;
                }
            }break;
        default:
            T=0;
        }
        if(T==1)
            return score;
        if(T==0)
            {
                printf("\n%d GUESSES LEFT!",(5-chance));
                if((5-chance)==0)
                {
                    return 0;
                }
                chance++;
                goto NEXTCHANCE;
            }
    }
}
//FUNCTION FOR MORSE CODE JUMBLED GAME(HARD)
int hard(char **p,int *q,int rep)
{
    int score=0,T;
    char guess[15];
    char clue;
    char *wrd[5]={"PERSONALITY","FRIGHTENED","INDEPENDENT","REASONABLE","LANGUAGE"};
    char *jum[5]={"YRSPNLOAEIT","EENDHFGIRT","DDTEDIENEPNN","EROALEBNSA","AGAGENLU"};
    //display the jumbled lettered word in morse code
    int time;
    time=rep%5;
    switch(time)
    {
    case 1:
        {
            for(int i=0;i<strlen(jum[0]);i++)
            {
                int val,ind;
                val=jum[0][i];
                for(int j=0;j<26;j++)
                {
                    if(val==*(q+j))
                        ind=j;
                }
                printf("%s  ",p[ind]);
            }
        }break;
    case 2:
        {
            for(int i=0;i<strlen(jum[1]);i++)
            {
                int val,ind;
                val=jum[1][i];
                for(int j=0;j<26;j++)
                {
                    if(val==*(q+j))
                        ind=j;
                }
                printf("%s  ",p[ind]);
            }
        }break;
    case 3:
        {
            for(int i=0;i<strlen(jum[2]);i++)
            {
                int val,ind;
                val=jum[2][i];
                for(int j=0;j<26;j++)
                {
                    if(val==*(q+j))
                        ind=j;
                }
                printf("%s  ",p[ind]);
            }
        }break;
    case 4:
        {
            for(int i=0;i<strlen(jum[3]);i++)
            {
                int val,ind;
                val=jum[3][i];
                for(int j=0;j<26;j++)
                {
                    if(val==*(q+j))
                        ind=j;
                }
                printf("%s  ",p[ind]);
            }
        }break;
    case 5:
        {
            for(int i=0;i<strlen(jum[4]);i++)
            {
                int val,ind;
                val=jum[4][i];
                for(int j=0;j<26;j++)
                {
                    if(val==*(q+j))
                        ind=j;
                }
                printf("%s  ",p[ind]);
            }
        }break;
    }
    int chance=1;
    int clue_flag=1;
    NEXTCHANCE:
    while(chance<6)
    {
        if(chance>2&&clue_flag==1&&chance<5)
        {
            printf("\nDO YOU WANT A CLUE?(y-yes and n-no)\n");
            clue=getch();
            if(clue=='y'||clue=='Y')
            {
                clue_flag=0;
                switch(time)
                {
                case 1:
                    {
                        for(int k=0;k<strlen(jum[0])-1;k++)
                        {
                            printf("_ ");
                        }
                        printf("%c",wrd[0][strlen(jum[0])-1]);
                    }break;
                case 2:
                    {
                        for(int k=0;k<strlen(jum[1])-1;k++)
                        {
                            printf("_ ");
                        }
                        printf("%c",wrd[1][strlen(jum[1])-1]);
                    }break;
                case 3:
                    {
                        for(int k=0;k<strlen(jum[2])-1;k++)
                        {
                            printf("_ ");
                        }
                        printf("%c",wrd[2][strlen(jum[2])-1]);
                    }break;
                case 4:
                    {
                        for(int k=0;k<strlen(jum[3])-1;k++)
                        {
                            printf("_ ");
                        }
                        printf("%c",wrd[3][strlen(jum[3])-1]);
                    }break;
                case 5:
                    {
                        for(int k=0;k<strlen(jum[4])-1;k++)
                        {
                            printf("_ ");
                        }
                        printf("%c",wrd[4][strlen(jum[4])-1]);
                    }break;
                }
            }
        }
        printf("\nGuess the word:");
        scanf("\n%s",guess);
        switch(time)
        {
        case 1:
            {
                if(strcmp(guess,wrd[0])==0)
                {
                    switch(chance)
                    {
                        case 1:score=10;break;
                        case 2:score=8;break;
                        case 3:
                            {
                                if(clue_flag!=0)
                                    score=6;
                                else
                                    score=5;
                            }break;
                        case 4:
                            {
                                if(clue_flag!=0)
                                    score=4;
                                else
                                    score=3;
                            }break;
                       case 5:
                            score=2;break;
                    }
                    T=1;
                }
            }break;
        case 2:
            {
                if(strcmp(guess,wrd[1])==0)
                {
                    switch(chance)
                    {
                        case 1:score=10;break;
                        case 2:score=8;break;
                        case 3:
                            {
                                if(clue_flag!=0)
                                    score=6;
                                else
                                    score=5;
                            }break;
                        case 4:
                            {
                                if(clue_flag!=0)
                                    score=4;
                                else
                                    score=3;
                            }break;
                       case 5:
                            score=2;break;
                    }
                    T=1;
                }
            }
        case 3:
            {
                if(strcmp(guess,wrd[2])==0)
                {
                    switch(chance)
                    {
                        case 1:score=10;break;
                        case 2:score=8;break;
                        case 3:
                            {
                                if(clue_flag!=0)
                                    score=6;
                                else
                                    score=5;
                            }break;
                        case 4:
                            {
                                if(clue_flag!=0)
                                    score=4;
                                else
                                    score=3;
                            }break;
                       case 5:
                            score=2;break;
                    }
                    T=1;
                }
            }break;
        case 4:
            {
                if(strcmp(guess,wrd[3])==0)
                {
                    switch(chance)
                    {
                        case 1:score=10;break;
                        case 2:score=8;break;
                        case 3:
                            {
                                if(clue_flag!=0)
                                    score=6;
                                else
                                    score=5;
                            }break;
                        case 4:
                            {
                                if(clue_flag!=0)
                                    score=4;
                                else
                                    score=3;
                            }break;
                       case 5:
                            score=2;break;
                    }
                    T=1;
                }
            }break;
        case 5:
            {
                if(strcmp(guess,wrd[4])==0)
                {
                    switch(chance)
                    {
                        case 1:score=10;break;
                        case 2:score=8;break;
                        case 3:
                            {
                                if(clue_flag!=0)
                                    score=6;
                                else
                                    score=5;
                            }break;
                        case 4:
                            {
                                if(clue_flag!=0)
                                    score=4;
                                else
                                    score=3;
                            }break;
                       case 5:
                            score=2;break;
                    }
                    T=1;
                }
            }break;
        default:
            T=0;
        }
        if(T==1)
            return score;
        if(T==0)
            {
                printf("\n%d GUESSES LEFT!",(5-chance));
                if((5-chance)==0)
                {
                    return 0;
                }
                chance++;
                goto NEXTCHANCE;
            }
    }
}
//the function to control morse code game
int Morse()
{
    char ch;
    int *p_ALPH,rep=0;
    int diff,score_f=0,score;
    char *morse[26]={"._","_...","_._.","_..",".",".._.","__.","....","..",".___","_._","._..","__","_.","___",".__.","__._","._.","...","_",".._","..._",".__","_.._","_.__","__.."};
    int ALPH[26]={65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
    p_ALPH=ALPH;
    system("cls");
    printf("*************************************************************WECOME TO MORSE CODE GAME***************************************************************");
    printf("\nRULES:\nIN THIS GAME THE ALPHABETS AND THEIR CORRESPONDING MORSE CODES WILL BE DISPLAYED ON THE SCREEN\nCHOOSE YOUR DIFFICULTY LEVEL\nA WORD WITH JUMBLED LETTERS APPEAR ON THE SCREEN IN MORSE CODE\nUSE THE TABLE TO DECODE THE LETTERS AND UNSCRAMBLE TO GIVE A MEANINGFUL WORD\nYOU HAVE 5 CHANCES TO GUESS THE RIGHT WORD AND THE SCORES ARE GIVEN ACCORDINGLY\nYOU HAVE 1 CLUE WHICH CAN BE USED AFTER THE 2nd CHANCE(But points will be reduced)\n***ANWER ONLY IN UPPER CASE**** \nGOOD LUCK!!!!!!");
    REPEAT:
    rep++;
    printf("\nChoose the difficulty level:\n1-EASY\n2-HARD\n");
    scanf("%d",&diff);
    system("cls");
    disp(morse,p_ALPH,26);
    if(diff==1)
        score=easy(morse,p_ALPH,rep);
    if(diff==2)
        score=hard(morse,p_ALPH,rep);
    score_f=score_f+score;
    printf("\nTHE CURRENT SCORE IS %d",score_f);
    printf("\nDo yo want to replay?(Y-yes or N-no)\n");
    ch=getch();
    if(ch=='y'||ch=='Y')
    {
        system("cls");
        goto REPEAT;
    }
    printf("\nTHE FINAL SCORE OF THIS GAME IS %d",score_f);
    return score_f;
}
//MAIN FUNCTION
int main()
{
    int game;
    system("COLOR B0");
    printf("**************************************************************WELCOME TO THE GAME********************************************************************\nWHICH GAME DO YOU WANT TO PLAY?\nNUMBER GAME-1\nMORSE CODE GAME-2\n");
    scanf("%d",&game);
    switch(game)
    {
    case 1:
        number_game();
        break;
    case 2:
        Morse();
    }
    return 0;
}
