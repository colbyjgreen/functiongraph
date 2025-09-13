//
// Created by Colby Green on 9/11/25.
//

#include "graphfunctions.h"
#include "graphvalues.h"
void userinput() {
    graphvalues quadratic{0,0,0};
    std::cout << "Enter Quadratic Constants (no variables) \n";
    std::cin >> quadratic.a >> quadratic.b >> quadratic.c;
    quadraticfunction(quadratic);
}

void quadraticfunction(graphvalues quadratic) {
    int y[5];
    //quadratic formula for x=[1,5], named as y since it is the y value
    for (int i = 1; i<=5;i++) {
        y[i-1]=quadratic.a*(i*i)+quadratic.b*i+quadratic.c;
    }
    quadraticsize(quadratic,y);
}

void quadraticsize(graphvalues quadratic, int y[]) {
    bool tripledigit=false;
    //check if values are triple digit at any point
    for (int i=0;i<5;i++) {
        if (y[i]>100) {
            tripledigit = true;
        }
    }
    graphinit(quadratic,y,tripledigit);
}

void graphinit(graphvalues quadratic, int y[], bool tripledigit) {
    //this is to initialize the graph, its later updated with graphlogic
    char graphprint[25][25];
    memset(graphprint,'_',sizeof(graphprint)); //never heard of this before but seems useful

    graphlogic(quadratic,y,tripledigit,graphprint);
    valueprint(y);
}
void graphlogic(graphvalues quadratic, int y[], bool tripledigit, char graphval[25][25]) {

    if (y[0]<5){
        graphval[24][0] = *"x";//got an error, and it told me to do this, dont know what * does
    }
    //specifically for non-triple digit numbers
    if (tripledigit==false) {
        for (int j=0;j<=5;j++) {
            for (int i=25;i>0;i--) {
                if (y[j]<(120-(i-1)*5)&&y[j]>(115-(i-1)*5)&&y[j]>5) { //logic for where to place x (approximated to the nearest 5)
                    graphval[i][(j*5)] = *"x";
                }
            }
        }
    }

    //should probably rewrite this to be easier to read, as we have a lot happening in one function

    if (tripledigit) {
        if (y[0]<50){
            graphval[24][0] = *"x";//got an error, and it told me to do this, dont know what * does
        }
        for (int j=0;j<=5;j++) {
            for (int i=25;i>0;i--) {
                if (y[j]<(1200-(i-1)*50)&&y[j]>(1150-(i-1)*50)&&y[j]>5) { //logic for where to place x (approximated to the nearest 50)
                    graphval[i][(j*5)] = *"x";
                }
            }
        }
    }
    graphprint(y,graphval,tripledigit);
}
void graphprint(int y[], char graphval[25][25], bool tripledigit) {
    //some simple printing stuff
    for (int i=0;i<25;i++) {
        if (tripledigit==false) {
            std::cout<<120 -(i * 5)<<"\t"; //here we print the value of the y axis
        }
        else {
            std::cout<<1200 -(i * 50)<<"\t";
        }
        for (int j=0;j<25;j++) {
            std::cout << graphval[i][j]<< "\t";
        }
        std::cout << "\n";
    }
    std::cout <<"    ";
    for (int i=1;i<=25;i++) {
        if (i%5==0) {
            std::cout<<i / 5<<std::setw(20); //value of the x axis
        }
        else {
        }
    }
    std::cout <<"\n";
}

void valueprint(int y[]) {
    for (int i=0; i<5;i++) {
        std::cout << "x: "<<i+1<<" y: "<<y[i] << "\n"; //prints the actual values not just the approximation
    }
}