#include <stdio.h>

int main()
{
    int score = 2; 
    while (score != 1 && score != 0 && score > 0){    
        printf("Enter 0 or 1 to STOP \n");
        printf("Enter the NFL score:  ");
        scanf("%d", &score);
        
        
        
        for (int TDep = 0; TDep <= (score/8); TDep++) {   //cycles through all possible ways to score points starting at the lowest
            for (int TDfg = 0; TDfg <= (score / 7); TDfg++) {
                for (int TDnone = 0; TDnone <= (score/6); TDnone++) {
                    for (int fg = 0; fg <= (score / 3); fg++) {
                        for (int safety = 0; safety <= (score / 2); safety++) {
    
                            int total = (8 * TDep) +(7 *TDfg)+(6 * TDnone) +(3*fg)+(2 * safety);
    
                            if (total == score) {
                                printf("TD + 2pt: %d, TD + FG: %d, TD: %d, FG: %d, Safety: %d\n",TDep, TDfg, TDnone, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}
