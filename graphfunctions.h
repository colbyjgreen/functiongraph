//
// Created by Colby Green on 9/11/25.
//

#ifndef FUNCTIONGRAPH_GRAPHFUNCTIONS_H
#define FUNCTIONGRAPH_GRAPHFUNCTIONS_H
#include "graphvalues.h"
#include <iomanip>
#include <iostream>

void userinput();
void graphinit(graphvalues quadratic, int y[], bool tripledigit);
void quadraticfunction(graphvalues quadratic);
void quadraticsize(graphvalues quadratic, int y[]);
void valueprint(int y[]);
void graphlogic(graphvalues quadratic,int y[],bool tripledigit, char graphval[25][25]);
void graphprint(int y[],char graphval[25][25], bool tripledigit);
#endif //FUNCTIONGRAPH_GRAPHFUNCTIONS_H