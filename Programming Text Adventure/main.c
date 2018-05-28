/*
Copyright 2014 Hermann Krumrey <hermann@krumreyh.com>

This file is part of c-text-adventure.

c-text-adventure is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

c-text-adventure is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with c-text-adventure.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "header/hkcalculatorv23.h"

long room;
long useroutput;
int detailedview = 0;
int roomloop = 0;
char preuserinput[256];
char userinput[256];
int sleep =1;
int spiritfree = 0;

void emptybuffer(){

    int bufferempty = 0;
    while(bufferempty<257){

    userinput[bufferempty] = '\0';
    preuserinput[bufferempty] = '\0';

    bufferempty++;

    }
}

long longinputfunction(long option1,long option2) {

    long userinput;
    int inputloop = 0;
    while(inputloop==0){
            scanf("%ld", &userinput);
            if((userinput>(option1-1))&&(userinput<(option2+1))){
                inputloop = 1;
                return userinput;
                }
            else{
                printf("There was an error in your input. Please enter a number between %ld and %ld",option1,option2);
            }
    }
    return userinput;
}

void simplestringinputfunction(char option1[256],char option2[256]) {

    int inputloop = 0;
    while(inputloop==0){

            fgets(preuserinput, sizeof userinput, stdin);
            strncpy(userinput, preuserinput, strlen(preuserinput)-1);
            int up = 0;
            while(userinput[up]){
                userinput[up] = toupper(userinput[up]);
                up++;
            }
            up = 0;
            char option1up[256];
            strncpy(option1up, option1, 256);
            while(option1up[up]){
                option1up[up] = toupper(option1up[up]);
                up++;
            }
            up = 0;
            char option2up[256];
            strncpy(option2up,option2, 256);
            while(option2up[up]){
                option2up[up] = toupper(option2up[up]);
                up++;
            }

            if((strncmp(userinput,option1up,256)==0)){
                inputloop = 1;
                useroutput = 1;
                emptybuffer();
                }
            else{if(strncmp(userinput,option2up,256)==0){
                    inputloop = 1;
                    useroutput = 2;
                    emptybuffer();
                }
                else{
                    printf("You have not entered a valid command. Pleas enter %s or %s.\n",option1,option2);
                    emptybuffer();
                }
            }
    }
}

void stringinputfunction(char option1[256],char option2[256]) {

    int loopcorrector = 0;
    int inputloop = 0;
    while(inputloop==0){

            fgets(preuserinput, sizeof userinput, stdin);
            strncpy(userinput, preuserinput, strlen(preuserinput)-1);

            int up = 0;
            while(userinput[up]){
                userinput[up] = toupper(userinput[up]);
                up++;
            }
            up = 0;
            char option1up[256];
            strncpy(option1up, option1, 256);
            while(option1up[up]){
                option1up[up] = toupper(option1up[up]);
                up++;
            }
            up = 0;
            char option2up[256];
            strncpy(option2up,option2, 256);
            while(option2up[up]){
                option2up[up] = toupper(option2up[up]);
                up++;
            }

            if((strncmp(userinput,option1up,256)==0)){
                inputloop = 1;
                useroutput = 1;
                emptybuffer();
                }
            else{if(strncmp(userinput,option2up,256)==0){
                    inputloop = 1;
                    useroutput = 2;
                    emptybuffer();
                }
                else{if(strncmp(userinput,"INSPECT AREA",256)==0){
                        inputloop = 1;
                        useroutput = 3;
                        emptybuffer();
                    }
                    else{if(strncmp(userinput,"HELP",256)==0){
                            printf("List of possible commands:\t%s\n\t\t\t\t%s\n\t\t\t\tInspect Area\n\n",option1,option2);
                            emptybuffer();
                        }
                        else{if(loopcorrector==0){
                            loopcorrector = 1;
                            emptybuffer();
                            }
                            else{
                                printf("You have not entered a valid command. Pleas enter \"Help\" for reference.\n");
                                emptybuffer();
                            }
                        }
                    }
                }
            }
    }
}

void advancedstringinputfunction3(char option1[256],char option2[256], char option3[256]) {

    int inputloop = 0;
    while(inputloop==0){


            fgets(preuserinput, sizeof userinput, stdin);
            strncpy(userinput, preuserinput, strlen(preuserinput)-1);

            int up = 0;
            while(userinput[up]){
                userinput[up] = toupper(userinput[up]);
                up++;
            }
            up = 0;
            char option1up[256];
            strncpy(option1up, option1, 256);
            while(option1up[up]){
                option1up[up] = toupper(option1up[up]);
                up++;
            }
            up = 0;
            char option2up[256];
            strncpy(option2up,option2, 256);
            while(option2up[up]){
                option2up[up] = toupper(option2up[up]);
                up++;
            }
            up = 0;
            char option3up[256];
            strncpy(option3up,option3, 256);
            while(option3up[up]){
                option3up[up] = toupper(option3up[up]);
                up++;
            }

            if((strncmp(userinput,option1up,256)==0)){
                inputloop = 1;
                useroutput = 1;
                emptybuffer();
                }
            else{if(strncmp(userinput,option2up,256)==0){
                    inputloop = 1;
                    useroutput = 2;
                    emptybuffer();
                }
                else{if(strncmp(userinput,option3up,256)==0){
                        inputloop = 1;
                        useroutput = 3;
                        emptybuffer();
                    }
                    else{if(strncmp(userinput,"HELP",256)==0){
                            printf("List of possible commands:\t%s\n\t\t\t\t%s\n\t\t\t\t%s\n\n",option1,option2,option3);
                            emptybuffer();
                        }
                        else{
                            printf("You have not entered a valid command. Pleas enter \"Help\" for reference.\n");
                            emptybuffer();
                        }
                    }
                }
            }
    }
}

void useroutputswitch1(){

    if(detailedview==1){

        switch (useroutput){

        case 1:
            printf("\n\n");
            room = 8;
            roomloop = 1;
            detailedview = 0;
            break;

        case 2:
            printf("\n\n");
            room = 5;
            roomloop = 1;
            detailedview = 0;
            break;

        case 3:
            printf("\nYou take a seat at the desk.\n");
            detailedview = 2;
            break;

        default:
            printf("\0");

        }
    }
    else{if(detailedview==2){

            switch (useroutput){

            case 1:
                printf("\nYou stand back up again\n");
                detailedview = 1;
                break;

            case 2:
                printf("\nYou try turning the lamp on.\nNothing happens, it seems to be broken.\n\n");
                break;

            case 3:
                printf("\nYou boot up the PC. It displays: \"HK Calculator V2.3\"\nDo you want to run the program?\n");
                simplestringinputfunction("yes","no");
                if(useroutput==1){
                    printf("\n");
                    hkcalculatorv23();
                    printf("\n\nAfter ending the program, the PC overheats and switches off on it's own.\n");
                }
                else{
                    printf("\nYou switch off the PC to conserve energy.\n");
                }
                break;

            default:
                printf("\0");
            }
        }
        else{

            switch (useroutput){

            case 1:
                printf("\n\n");
                room = 8;
                roomloop = 1;
                break;

            case 2:
                printf("\n\n");
                room = 5;
                roomloop = 1;
                break;

            case 3:
                detailedview = 1;
                break;

            default:
                printf("\0");
            }
        }
    }
}

void useroutputswitch2(){

    if(detailedview==1){

        switch (useroutput){

        case 1:
            printf("\n\n");
            room = 8;
            roomloop = 1;
            detailedview = 0;
            break;

        case 2:
            printf("\n\n");
            room = 6;
            roomloop = 1;
            detailedview = 0;
            break;

        case 3:
            printf("\nYou examine the frying pan. It looks really disgusting\n");
            detailedview = 2;
            break;

        default:
            printf("\0");

        }
    }
    else{if(detailedview==2){

            switch (useroutput){

            case 1:
                printf("\nYou leave the frying pan in disgust\n");
                detailedview = 1;
                break;

            case 2:
                printf("\nYou try some of the grease residing in the frying pan.\nYou vomit immediately after tasting the slimy residue.\n\n");
                break;

            case 3:

                if(spiritfree==1){
                    printf("\nThe note doesn't say anything.\n");
                }
                else{
                    printf("\nYou read the note. It says: \n\n\t\t\tI am a spirit, locked away in this piece of paper.\n\t\t\tWould you mind releasing me from my cruel fate?\n\nDo you want to free the spirit?\n");
                    simplestringinputfunction("yes","no");
                    if(useroutput==1){
                        printf("\n");
                        spiritfree = 1;
                        printf("\n\nThe spirit cries out in laughter and disappears into the ceiling\n");
                    }
                    else{
                        printf("\nYou put the note containing the spirit back into the greasy frying pan.\nYou monster.\n");
                    }
                }
                break;

            default:
                printf("\0");
            }
        }
        else{

            switch (useroutput){

            case 1:
                printf("\n\n");
                room = 6;
                roomloop = 1;
                break;

            case 2:
                printf("\n\n");
                room = 5;
                roomloop = 1;
                break;

            case 3:
                detailedview = 1;
                break;

            default:
                printf("\0");
            }
        }
    }
}

void room0(){

    system("COLOR F0");
    printf("Welcome to the Programming Text Adventure!\n\nYou are standing in a small room with four doors.\nThese four doors are numbered with the numbers 1 to 4.\nThrough which door do you want to go through?\n");
    room = longinputfunction(1,4);
    printf("Everything around you fades to black and you fall into a deep slumber.\n\nYou wake up in ");
    sleep = 0;
}

void room1(){

    system("COLOR 1E");
    if(sleep==0){
        printf("a small, dark room, covered in Dust.\nThere are two doors, one to the South and another to the East.\nWhat do you want to do?\n(Enter help for a list of commands)\n");
    }
    else{
        printf("You enter a small, dark room, covered in Dust.\nThere are two doors, one to the South and another to the East.\nWhat do you want to do?\n(Enter help for a list of commands)\n");
    }
    stringinputfunction("Go South","Go East");
    useroutputswitch1();
    if(detailedview==1){
        printf("\nYou examine the room. You see an old desk and a chair.\nOn top of the table is a rather old PC and a table lamp.\n");
    }
    while(roomloop==0){

        switch(detailedview){

            case 0:

                break;

            case 1:

                printf("What do you want to do?\n(Enter help for a list of commands)\n");
                advancedstringinputfunction3("Go South","Go East","Sit at desk");
                useroutputswitch1();
                break;

            case 2:

                printf("What do you want to do?\n(Enter help for a list of commands)\n");
                advancedstringinputfunction3("Stand up","Turn on Lamp","Use PC");
                useroutputswitch1();

            default:
                printf("\0");

        }
    }
}

void room2(){

    system("COLOR A2");
    if(sleep==0){
        printf("a kitchen. You catch a smell that almost causes you to vomit.\nThere are two doors, one to the South and another to the West.\nWhat do you want to do?\n(Enter help for a list of commands)\n");
    }
    else{
        printf("You enter a kitchen. You catch a smell that almost causes you to vomit.\nThere are two doors, one to the South and another to the West.\nWhat do you want to do?\n(Enter help for a list of commands)\n");
    }
    stringinputfunction("Go South","Go West");
    useroutputswitch2();
    if(detailedview==1){
        printf("\nYou examine the room.\nYou see a frying pan covered in slimy grease resting on the stove.\nThere is a note inside the frying pan.\n");
    }
    while(roomloop==0){

        switch(detailedview){

            case 0:

                break;

            case 1:

                printf("What do you want to do?\n(Enter help for a list of commands)\n");
                advancedstringinputfunction3("Go South","Go West","Examine frying pan");
                useroutputswitch2();
                break;

            case 2:

                printf("What do you want to do?\n(Enter help for a list of commands)\n");
                advancedstringinputfunction3("leave frying pan alone","taste grease","read note");
                useroutputswitch2();

            default:
                printf("\0");

        }
    }
}

int main()
{
    int mainloop = 0;

    while(mainloop==0){

    switch (room){

        case 0:

            room0();
            break;

        case 1:

            room1();
            break;

        case 2:

            room2();
            break;

        /*case 3:

            room3();
            break;

        case 4:

            room4();
            break;

        case 5:

            room5();
            break;

        case 6:

            room6();
            break;

        case 7:

            room7();
            break;

        case 8:

            room8();
            break;

        case 9:

            room9();
            break;

        case 10:

            room10();
            break;

        case 11:

            room11();
            break;*/

        default:

            printf("\0");
    }
    }
    return 0;
}
