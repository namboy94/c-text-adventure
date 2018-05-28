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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void hkcalculatorv23(){

printf("Welcome to the HK Calculator!\n\n");
printf("Do you want to use the normal calculator or the special function calculator?\n");
char mode[256];
int lope = 0;
while(lope==0){
    scanf("%s", mode);
    int j = 0;
    while(mode[j]){
        mode[j] = toupper(mode[j]);
        j++;
    }
    if((strncmp(mode,"NORMAL",6)==0)||(strncmp(mode,"SPECIAL",6)==0)){
        lope = 1;
    }
    else{
        printf("The command could not be understood. Please answer \"normal\" or \"special\"\n");
    }
}
int lop = 0;
while (lop==0){

if(strncmp(mode,"NORMAL",6)==0){
    int loop = 0;
    while(loop==0){
        double initial, operant, answer, degrad;
        degrad = M_PI/180;
        char operate[256];
        printf("\nCALCULATOR MODE: NORMAL\n\nPlease enter your starting value\n");
        scanf("%lf", &initial);
        printf("\nPlease enter your operator type\n   Currently supported: +, -, *, /, ^, sin, cos, tan, sqrt\n");
        scanf("%s", operate);
        int i = 0;
            while(operate[i]){
                operate[i] = toupper(operate[i]);
                i++;
            }

        if((strncmp(operate,"+", 2)==0)||(strncmp(operate,"-", 2)==0)||(strncmp(operate,"*", 2)==0)||(strncmp(operate,"/", 2)==0)||(strncmp(operate,"^", 3)==0)){
            printf("\nPlease enter your operating value\n");
            scanf("%lf", &operant);
        }

        if(strncmp(operate,"+", 1)==0){
            answer = initial+operant;
            printf("\nYou have calculated %lf %s %lf\n\nThe answer is %lf", initial, operate, operant, answer);
        }
        else{if(strncmp(operate,"-", 1)==0){
                answer = initial-operant;
                printf("\nYou have calculated %lf %s %lf\n\nThe answer is %lf", initial, operate, operant, answer);
            }
            else{if(strncmp(operate,"*", 1)==0){
                    answer = initial*operant;
                    printf("\nYou have calculated %lf %s %lf\n\nThe answer is %lf", initial, operate, operant, answer);
                }
                else{if(strncmp(operate,"/", 1)==0){
                        answer = initial/operant;
                        if(operant==0){
                            int joke = 0;
                            while(joke==0){
                                printf("No!");
                            }
                            //printf("You can't divide by 0!");
                        }
                        else{
                        printf("\nYou have calculated %lf %s %lf\n\nThe answer is %lf", initial, operate, operant, answer);
                        }
                    }
                    else{if(strncmp(operate,"SIN", 3)==0){
                            answer = sin(initial*degrad);
                            printf("\nYou have calculated %s %lf\n\nThe answer is %lf", operate, initial, answer);
                        }
                        else{if(strncmp(operate,"COS", 3)==0){
                                answer = cos(initial*degrad);
                                printf("\nYou have calculated %s %lf\n\nThe answer is %lf", operate, initial, answer);
                            }
                            else{if(strncmp(operate,"TAN", 3)==0){
                                    answer = tan(initial*degrad);
                                    printf("\nYou have calculated %s %lf\n\nThe answer is %lf", operate, initial, answer);
                                }
                                else{if(strncmp(operate,"^", 1)==0){
                                        answer = pow(initial,operant);
                                        printf("\nYou have calculated %lf %s %lf\n\nThe answer is %lf", initial, operate, operant, answer);
                                    }
                                    else{if(strncmp(operate,"SQRT", 4)==0){
                                            answer = sqrt(initial);
                                            if(initial<0){
                                                printf("The normal calculator does not support complex numbers, sorry!");
                                            }
                                            else{
                                                printf("\nYou have calculated %s ( %lf )\n\nThe answer is %lf", operate, initial, answer);
                                            }
                                        }
                                        else{
                                            printf("\nYour input is invalid");
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        printf("\n\nDo you want to do another calculation or change the calculator type?\n");
        int loopy = 0;
        while(loopy==0){
            char answer[256];
            scanf("%s", answer);
            int l = 0;
            while(answer[l]){
                answer[l] = toupper(answer[l]);
                l++;
            }
            if(strncmp(answer,"YES",3)==0){
                    loopy = 1;
                    loop = 0;
                }
            else{if(strncmp(answer,"NO", 2)==0){
                printf("\nThank you for using the HK calculator!");
                loopy = 1;
                loop = 1;
                lop = 1;
                }
                else{if(strncmp(answer,"CHANGE", 6)==0){
                        loopy = 1;
                        loop = 1;
                        lop = 0;
                        printf("Change to which mode?\n");
                        int lope2 = 0;
                        while(lope2==0){
                            scanf("%s", mode);
                            int ji = 0;
                            while(mode[ji]){
                                mode[ji] = toupper(mode[ji]);
                                ji++;
                            }
                            if((strncmp(mode,"NORMAL",6)==0)||(strncmp(mode,"SPECIAL",6)==0)){
                                lope2 = 1;
                            }
                            else{
                            printf("The command could not be understood. Please answer \"normal\" or \"special\"\n");
                            }
                        }
                    }
                    else{
                        printf("The command could not be understood. Please answer \"yes\", \"no\" or \"change\"\n");
                        loopy = 0;
                        loop = 0;
                        lop = 0;
                    }
                }
            }
        }
    }
    }


else{
        char functiontype[256];
        printf("\nCALCULATOR MODE: SPECIAL FUNCTIONS\n\n");
        printf("Which function do you want to use?\n\nCurrently supported:\tQuadratic equation solver(quadracalc)\n\t\t\tPythagoras Equation(pyth)\n\t\t\tDegrees to Radians Converter(degtorad)\n\t\t\tRadians to Degrees Converter(radtodeg)\n\n");
        int loopydoo = 0;
        while(loopydoo==0){
            scanf("%s", functiontype);
            int y = 0;
            while(functiontype[y]){
                functiontype[y] = toupper(functiontype[y]);
                y++;
            }

            int function;
            if(strncmp(functiontype,"QUADRACALC",8)==0){
                function = 1;
            }
            else{if(strncmp(functiontype,"PYTH",4)==0){
                    function = 2;
                }
                else{if(strncmp(functiontype,"DEGTORAD",8)==0){
                        function = 3;
                    }
                    else{if(strncmp(functiontype,"RADTODEG",8)==0){
                            function = 4;
                        }
                        else{
                            function = 0;
                        }
                    }
                }
            }

            switch (function){

                case 1:

                    printf("\nWelcome to the automatic quadratic equation solver!");
                    int schleif = 0;
                    while(schleif==0){
                        double a,b,c,x1,x2,end,check;
                        printf("\nPlease enter your \"a\" value\n");
                        scanf("%lf", &a);
                        printf("Please enter your \"b\" value\n");
                        scanf("%lf", &b);
                        printf("Please enter your \"c\" value\n");
                        scanf("%lf", &c);
                        printf("\nYour formula is: %lfx^2 + %lfx + %lf = 0\n\n", a, b, c);
                        check = b*b-4*a*c;

                        if(check>=0){
                        x1 = (-b+sqrt(b*b - 4*a*c))/(2*a);
                        x2 = (-b-sqrt(b*b - 4*a*c))/(2*a);
                        printf("The Calculation is complete!\nThe solutions are:\n\n\tx1 = %lf\n\tx2 = %lf\n\nDo you want to do another quadratic equation calculation?\n", x1, x2);
                        scanf("%lf", &end);
                        }
                        else{
                        printf("Your input values do not result in a real number.\nDo you want to do another quadratic equation calculation?\n");
                        scanf("%lf", &end);
                        }
                        int schleife = 0;
                        while(schleife==0){
                            char answer[256];
                            scanf("%s", answer);
                            int i = 0;
                            while(answer[i]){
                                answer[i] = toupper(answer[i]);
                                i++;
                            }
                        if(strncmp(answer,"YES",3)==0){
                            schleife = 1;
                            schleif = 0;
                        }
                        else{if(strncmp(answer,"NO", 2)==0){
                                printf("\nThank you for using the HK quadratic equation calculator!");
                                schleife = 1;
                                schleif = 1;
                            }
                            else{
                                printf("\nThe command could not be understood. Please answer \"yes\" or \"no\"\n");
                                schleife = 0;
                                schleif = 0;
                                }
                            }
                        }
                    }

                    loopydoo = 1;
                    break;

                case 2:

                    printf("\nWelcome to the Pythagoras equation solver!");
                    int pitloop1 = 0;
                    while(pitloop1==0){

                    char cathyp[256];
                    printf("\n\nAre you looking for either:\n\nthe length of the long side of a right-angled triangle\nor\nthe length of one of the short sides of a right-angled triangle?\n");
                    int pytloop2 = 0;
                    while(pytloop2==0){
                        scanf("%s", cathyp);
                        int up = 0;
                        while(cathyp[up]){
                            cathyp[up] = toupper(cathyp[up]);
                            up++;
                        }
                        if((strncmp(cathyp,"LONG",4)==0)||(strncmp(cathyp,"SHORT",5)==0)){
                           pytloop2 = 1;
                           }
                        else{
                            printf("Your input is invalid. Please enter either \"long\" or \"short\".\n");
                        }
                    }
                    double a,b,c,a2,b2,c2,ab,ca,area,winkelsin,winkelsindeg,alpha,beta,gamma,roundlength,killrad;
                    killrad = 180/M_PI;

                    if(strncmp(cathyp,"LONG",4)==0){
                        printf("\nPlease enter the length values for the two short sides of the triangle\n\n1.:\t");
                        scanf("%lf", &a);
                        printf("\n2.:\t");
                        scanf("%lf", &b);
                        printf("\n\n");
                        a2 = a*a;
                        b2 = b*b;
                        ab = a2+b2;
                        c = sqrt(ab);
                        gamma = 90;
                        winkelsin = a/c;
                        winkelsindeg = asin(winkelsin);
                        alpha = winkelsindeg*killrad;
                        beta = 90-alpha;
                        roundlength = a+b+c;
                        area = 0.5*a*b;

                        printf("You have entered the following lengths:\ta:\t\t%lf\n\t\t\t\t\tb:\t\t%lf\n\n",a,b);
                        printf("This results in the following values:\tc:\t\t%lf\n\t\t\t\t\talpha:\t\t%lf\n\t\t\t\t\tbeta:\t\t%lf\n\t\t\t\t\tgamma:\t\t%lf",c,alpha,beta,gamma);
                        printf("\n\t\t\t\t\tcircumference:\t%lf\n\t\t\t\t\tarea:\t\t%lf\n",roundlength,area);
                    }
                    else{
                        printf("\nPlease enter the length values for the two known sides of the triangle\n\nlong side:\t");
                        scanf("%lf", &c);
                        printf("\nshort side:\t");
                        scanf("%lf", &a);
                        printf("\n\n");
                        c2 = c*c;
                        a2 = a*a;
                        ca = c2-a2;
                        b = sqrt(ca);
                        gamma = 90;
                        winkelsin = a/c;
                        winkelsindeg = asin(winkelsin);
                        alpha = winkelsindeg*killrad;
                        beta = 90-alpha;
                        roundlength = a+b+c;
                        area = 0.5*a*b;

                        printf("You have entered the following lengths:\tc:\t\t%lf\n\t\t\t\t\ta:\t\t%lf\n\n",c,a);
                        printf("This results in the following values:\tb:\t\t%lf\n\t\t\t\t\talpha:\t\t%lf\n\t\t\t\t\tbeta:\t\t%lf\n\t\t\t\t\tgamma:\t\t%lf",b,alpha,beta,gamma);
                        printf("\n\t\t\t\t\tcircumference:\t%lf\n\t\t\t\t\tarea:\t\t%lf\n",roundlength,area);
                    }
                    char continuepyth[256];
                    printf("\nDo you want to calculate another triangle using Pythagoras?\n");
                    scanf("%s", continuepyth);
                    int upp = 0;
                    while(continuepyth[upp]){
                        continuepyth[upp] = toupper(continuepyth[upp]);
                        upp++;
                    }
                    if(strncmp(continuepyth,"YES",3)==0){
                        pitloop1 = 0;
                    }
                    else{if(strncmp(continuepyth,"NO",2)==0){
                            printf("Thank you for using the HK Pythagoras Calculator!");
                            pitloop1 = 1;
                        }
                        else{
                            printf("\nThe command could not be understood. Please answer \"yes\" or \"no\"\n");
                        }
                    }
                    }

                    loopydoo = 1;
                    break;

                case 3:

                    printf("\nWelcome to the HK Degrees to Radians Converter!\n");
                    int degtoradloop = 0;
                    while(degtoradloop==0){
                        double degtoradconverter,multipi;
                        degtoradconverter = M_PI/180;
                        printf("\nEnter the value you want to convert from Degrees to Radians\n\n");
                        double degtoradin,degtoradout;
                        scanf("%lf",&degtoradin);
                        degtoradout = degtoradin*degtoradconverter;
                        multipi = degtoradout/M_PI;
                        printf("\nYou have converted %lf degrees to %lf radians (%lf * Pi)\nDo you want to convert another value?\n",degtoradin,degtoradout,multipi);
                        char degtoradcontinue[256];
                        int degtoradloop2 = 0;
                        while(degtoradloop2==0){
                            scanf("%s", degtoradcontinue);
                            int degtoradupper = 0;
                            while(degtoradcontinue[degtoradupper]){
                                degtoradcontinue[degtoradupper] = toupper(degtoradcontinue[degtoradupper]);
                                degtoradupper++;
                            }
                            if(strncmp(degtoradcontinue,"YES",3)==0){
                                degtoradloop2 = 1;
                            }
                            else{if(strncmp(degtoradcontinue,"NO",2)==0){
                                    printf("\nThank you for using the HK Degrees to Radians Converter!");
                                    degtoradloop2 = 1;
                                    degtoradloop = 1;
                                }
                                else{
                                    printf("\nThe command could not be understood. Please answer \"yes\" or \"no\"\n");
                                }
                            }
                        }
                    }
                    loopydoo = 1;
                    break;

                case 4:

                    printf("\nWelcome to the HK Radians to Degrees Converter!\n");
                    int radtodegloop = 0;
                    while(radtodegloop==0){
                        double radtodegconverter;
                        radtodegconverter = 180/M_PI;
                        printf("Would you like to enter the radian value in multiples of Pi?\n");
                        char multipiask[256];
                        scanf("%s", multipiask);
                        int uppi = 0;
                        while(multipiask[uppi]){
                            multipiask[uppi] = toupper(multipiask[uppi]);
                            uppi++;
                        }
                        if(strncmp(multipiask,"YES",3)==0){
                            printf("\nEnter the value you want to convert from Radians to Degrees\n\n");
                            double radtodegin1,radtodegin2,radtodegout;
                            scanf("%lf",&radtodegin1);
                            radtodegin2 = radtodegin1*M_PI;
                            radtodegout = radtodegin2*radtodegconverter;
                            printf("\nYou have converted %lf radians (%lf * Pi) to %lf degrees\nDo you want to convert another value?\n",radtodegin2, radtodegin1, radtodegout);
                            char radtodegcontinue[256];
                            int radtodegloop2 = 0;
                            while(radtodegloop2==0){
                                scanf("%s", radtodegcontinue);
                                int radtodegupper = 0;
                                while(radtodegcontinue[radtodegupper]){
                                    radtodegcontinue[radtodegupper] = toupper(radtodegcontinue[radtodegupper]);
                                    radtodegupper++;
                                }
                                if(strncmp(radtodegcontinue,"YES",3)==0){
                                    radtodegloop2 = 1;
                                }
                                else{if(strncmp(radtodegcontinue,"NO",2)==0){
                                        printf("\nThank you for using the HK Radians to Degrees Converter!");
                                        radtodegloop2 = 1;
                                        radtodegloop = 1;
                                    }
                                    else{
                                        printf("\nThe command could not be understood. Please answer \"yes\" or \"no\"\n");
                                    }
                                }
                            }
                        }
                        else{
                        printf("\nEnter the value you want to convert from Radians to Degrees\n\n");
                        double radtodegin,radtodegout,radinpi;
                        scanf("%lf",&radtodegin);
                        radinpi = radtodegin/M_PI;
                        radtodegout = radtodegin*radtodegconverter;
                        printf("\nYou have converted %lf radians (%lf * Pi)to %lf degrees\nDo you want to convert another value?\n",radtodegin, radinpi, radtodegout);
                        char radtodegcontinue[256];
                        int radtodegloop2 = 0;
                        while(radtodegloop2==0){
                            scanf("%s", radtodegcontinue);
                            int radtodegupper = 0;
                            while(radtodegcontinue[radtodegupper]){
                                radtodegcontinue[radtodegupper] = toupper(radtodegcontinue[radtodegupper]);
                                radtodegupper++;
                            }
                            if(strncmp(radtodegcontinue,"YES",3)==0){
                                radtodegloop2 = 1;
                            }
                            else{if(strncmp(radtodegcontinue,"NO",2)==0){
                                    printf("\nThank you for using the HK Radians to Degrees Converter!");
                                    radtodegloop2 = 1;
                                    radtodegloop = 1;
                                }
                                else{
                                    printf("\nThe command could not be understood. Please answer \"yes\" or \"no\"\n");
                                }
                            }
                        }
                        }
                    }
                    loopydoo = 1;
                    break;

                default:
                    printf("The command could not be understood. Please enter one of the following commands:\nquadracalc\n\n");
            }
        }
        printf("\n\nDo you want to use another special function or change the calculator type?\n");
        int loopy = 0;
        while(loopy==0){
            char answer[256];
            scanf("%s", answer);
            int l = 0;
            while(answer[l]){
                answer[l] = toupper(answer[l]);
                l++;
            }
            if(strncmp(answer,"YES",3)==0){
                    loopy = 1;
                }
            else{if(strncmp(answer,"NO", 2)==0){
                printf("\nThank you for using the HK calculator!");
                loopy = 1;
                lop = 1;
                }
                else{if(strncmp(answer,"CHANGE", 6)==0){
                        loopy = 1;
                        lop = 0;
                        printf("Change to which mode?\n");
                        int lope2 = 0;
                        while(lope2==0){
                            scanf("%s", mode);
                            int ji = 0;
                            while(mode[ji]){
                                mode[ji] = toupper(mode[ji]);
                                ji++;
                            }
                            if((strncmp(mode,"NORMAL",6)==0)||(strncmp(mode,"SPECIAL",6)==0)){
                                lope2 = 1;
                            }
                            else{
                            printf("The command could not be understood. Please answer \"normal\" or \"special\"\n");
                            }
                        }
                    }
                    else{
                        printf("The command could not be understood. Please answer \"yes\", \"no\" or \"change\"\n");
                        loopy = 0;
                        lop = 0;
                    }
                }
            }
        }
}           //end of else loop
}           //end of lop loop
}  //end of main
