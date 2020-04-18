#include <iostream>
#include <conio.h>

#include "field.h"
#include "snake.h"
#include "bonus.h"
#include "constants.h"

using namespace std;

int main(int argc, char *argv[])
{
    Field field;
    /*
    int i = clock()/CLK_TCK;
    int curDir = UP;
    while(1000){               //кол-во циклов в секунде
        if ((clock()/CLK_TCK)%1==0){
            if(i!=(clock()/CLK_TCK)){
                ////////////////////////////////////////////////
                system("cls");
                field.output();
                if(kbhit()){
                    
                    switch(getch()){
                            case 72: //вверх
                                curDir = UP;
                                break;
                            case 80: //вниз
                                curDir = DOWN;
                                break;
                            case 75: //влево 
                                curDir = LEFT;
                                break;
                            case 77: //вправо
                                curDir = RIGHT;
                                break;
                            case 27:
                                return 0;
                        }
                } 
                field.update(curDir);                
                ////////////////////////////////////////////////
                i = clock()/CLK_TCK;
            }
        }
    }
    */
    
   int curDir = UP;
    for(;;){       
        ////////////////////////////////////////////////
        system("cls");
        field.output();
        if(kbhit()){               
            switch(getch()){
                case 72: //вверх
                    curDir = UP;
                    break;
                case 80: //вниз
                    curDir = DOWN;
                    break;
                case 75: //влево 
                    curDir = LEFT;
                    break;
                case 77: //вправо
                    curDir = RIGHT;
                    break;
                case 27:
                    return 0;
            }
        }
        field.update(curDir);                
        ////////////////////////////////////////////////
        Sleep(500);
    }
    


    return 0;
}