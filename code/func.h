//returns cartisian point based on one variable
float circlePoint(bool topHalf, float point, float rad) {

	if(topHalf)

		return sqrt(pow(rad, 2) - pow(point, 2));

	else

		return -sqrt(pow(rad, 2) - pow(point, 2));

}

//prints gcode line based on x y position 
void printLine(float X, float Y, float E) {

	printf("G1 X%.2f Y%.2f E%f\n", X, Y, E);

	return;
}
