#include <stdio.h>
int main()
{
    int speed = 0, gapSpeed = 0, numLines = 0, layers = 0; 
    
    float poreSize = 0, z = 0, zFactor = 0.2, e = 0, eFactor = 0.002;   
    printf(";Enter pore size: "); 
    scanf("%f", &poreSize); 
    printf("\n;Enter numLines:  "); 
    scanf("%d", &numLines); 
    printf("\n;Enter print speed:  "); 
    scanf("%d", &speed);  
     printf("\n;Enter gap speed:  "); 
    scanf("%d", &gapSpeed);  
    printf("\n;Enter num layers:  "); 
    scanf("%d", &layers); 
    
    

    
    printf(";Gcode generated by Ryan Wang Grid Gcode Generator\n");
    printf("T1\n");
    printf("M82\n");
    printf("M107\n");
    printf("G92 E0\n");
    printf("G21\n");
    printf("G90\n");
    printf("M82\n"); 
    printf("G92 E0\n");
    printf(";LAYER_COUNT:%d\n", layers);
    for(int l = 1; l <= layers; l++){
        printf(";LAYER:%d\n", l-1); 
        printf("M107\n");  
        printf("G0 F%d X%.2f Y%.2f Z%f\n", gapSpeed, 0.00, 0.00, z+= 0.2); 
        printf("TYPE:WALL-OUTER\n"); 
    
        if(l == 1 || (l - 1) % 4 ==  0) {
            for(int i = 1; i <= numLines+1; i++){
                if(i == 1){
                    printf("G1 F%d X%.2f Y%.2f E%f\n", speed, 0.00, 0.00, e += eFactor); 
                    printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 1)), (poreSize * numLines),  e += eFactor); 
                } 
                else if(i % 2 == 0){
                    printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 1)), (poreSize * numLines),  e += eFactor); 
                    printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 1)), 0.00,  e += eFactor);
                }
                else {
                    printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 1)), 0.00,  e += eFactor); 
                    printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 1)), (poreSize * numLines),  e += eFactor);  
                }
            }  
        } 
        else if(l % 2 == 0 && l % 4 != 0){
            for(int i = 1; i <= numLines+1; i++){
                if(i == 1){
                    printf("G1 F%d X%.2f Y%.2f E%f\n", speed, 0.00, 0.00, e += eFactor); 
                    printf("G1 X%.2f Y%.2f E%f\n", (poreSize * numLines), (poreSize * (i - 1)),  e += eFactor); 
                } 
                else if(i % 2 == 0){
                    printf("G1 X%.2f Y%.2f E%f\n", (poreSize * numLines), (poreSize * (i - 1)),  e += eFactor); 
                    printf("G1 X%.2f Y%.2f E%f\n", 0.00, (poreSize * (i - 1)),  e += eFactor); 
                }
                else {
                    printf("G1 X%.2f Y%.2f E%f\n", 0.00, (poreSize * (i - 1)),  e += eFactor); 
                    printf("G1 X%.2f Y%.2f E%f\n", (poreSize * numLines), (poreSize * (i - 1)),  e += eFactor); 
                }
            }  
        } 
        else if((l - 1) % 2 == 0){
            for(int i = 1; i <= numLines+2; i++){
                if(i == 1){
                    printf("G1 F%d X%.2f Y%.2f E%f\n", speed, 0.00, 0.00, e += eFactor); 
                    printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 1)), (poreSize * numLines),  e += eFactor); 
                } 
                else if(i % 2 == 0){
                    if(i == numLines+2){
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 2)), (poreSize * numLines),  e += eFactor); 
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 2)), 0.00,  e += eFactor);     
                    }
                    else{           
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 1)) - (poreSize/2), (poreSize * numLines),  e += eFactor); 
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 1)) - (poreSize/2), 0.00,  e += eFactor); 
                    }
                }
                else { 
                    if(i == numLines+2){
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 2)), 0.00,  e += eFactor); 
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 2)), (poreSize * numLines),  e += eFactor);     
                    } 
                    else {
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 1)) - (poreSize/2), 0.00,  e += eFactor); 
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * (i - 1)) - (poreSize/2), (poreSize * numLines),  e += eFactor);  
                    }       
                }
            }  
        } 
        else{
            for(int i = 1; i <= numLines+2; i++){
                if(i == 1){
                    printf("G1 F%d X%.2f Y%.2f E%f\n", speed, 0.00, 0.00, e += eFactor); 
                    printf("G1 X%.2f Y%.2f E%f\n", (poreSize * numLines), (poreSize * (i - 1)),  e += eFactor); 
                } 
                else if(i % 2 == 0){
                    if(i == numLines + 2){ 
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * numLines), (poreSize * (i - 2)),  e += eFactor); 
                        printf("G1 X%.2f Y%.2f E%f\n", 0.00, (poreSize * (i - 2)),  e += eFactor);  
                    }
                    else { 
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * numLines), (poreSize * (i - 1)) - (poreSize / 2),  e += eFactor); 
                        printf("G1 X%.2f Y%.2f E%f\n", 0.00, (poreSize * (i - 1)) - (poreSize / 2),  e += eFactor); 
                    }
                }
                else {
                    if(i == numLines + 2){
                        printf("G1 X%.2f Y%.2f E%f\n", 0.00, (poreSize * (i - 2)) ,  e += eFactor); 
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * numLines), (poreSize * (i - 2)) ,  e += eFactor); 
                    }
                    else{ 
                        printf("G1 X%.2f Y%.2f E%f\n", 0.00, (poreSize * (i - 1)) - (poreSize / 2),  e += eFactor); 
                        printf("G1 X%.2f Y%.2f E%f\n", (poreSize * numLines), (poreSize * (i - 1)) - (poreSize / 2),  e += eFactor); 
                    }
                }
            }   
        }
        e = 0; 
    } 
    printf("G92 E0\n");
    printf("M84\n");
    printf("M82\n");
    return 0;
}
