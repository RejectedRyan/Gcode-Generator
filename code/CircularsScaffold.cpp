
#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "func.h"
//includes circlePoint(tophalf, point, rad) and printLine(x, y, e)



int main()
{
	int speed = 0, gapSpeed = 0, layers = 0, numPoints = 11, numLines;

	float radius = 0, poreSize,z = 0, zFactor = 0.2, e = 0, eFactor = 0.002, x = 0;
	printf(";Enter pore size: ");
	scanf("%f", &poreSize);
	printf("\n;Enter number of lines: ");
	scanf("%d", &numLines);
	printf("\n;Enter print speed:  ");
	scanf("%d", &speed);
	printf("\n;Enter num layers:  ");
	scanf("%d", &layers);

	radius = ((numLines + 2) * poreSize) / 2;

	printf(";Gcode generated by Ryan Wang's Grid Gcode Generator\n");
	printf("T1\n");
	printf("M82\n");
	printf("M107\n");
	printf("G92 E0\n");
	printf("G21\n");
	printf("G90\n");
	printf("M82\n");
	printf("G92 E0\n");
	printf(";LAYER_COUNT:%d\n", layers);
	for(int l = 1; l <= layers; l++) {

		x = -radius + poreSize;

		printf(";LAYER:%d\n", l-1);
		printf("M107\n");
		printf("G0 F%d X%.2f Y%.2f Z%f\n", speed, 0.00, 0.00, z+= 0.2);
		printf("TYPE:WALL-OUTER\n");
		printf("G0 F%d X%.2f Y%.2f\n", speed, x, circlePoint(false, x, radius));

		for(int ct = 0; ct < numLines; ct++ ) {
			if(ct % 2 == 0) {
				printLine(x, circlePoint(true, x, radius), e+=eFactor);  //line
				x+=poreSize;
				printLine(x, circlePoint(true, x, radius), e+=eFactor);  //gap? whatever its called
			}
			else {
				printLine(x, circlePoint(false, x, radius), e+=eFactor);
				x+=poreSize;
				printLine(x, circlePoint(false, x, radius), e+=eFactor);
			}
			printLine(x, circlePoint(true, x, radius), e+=eFactor);
		} 
	

	}
	printf("G92 E0\n");
	printf("M84\n");
	printf("M82\n");
	return 0;
}
