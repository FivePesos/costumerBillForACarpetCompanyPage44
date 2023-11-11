#include <stdio.h>
#include <math.h>

//Defined Contants
#define TAX_RATE 0.085
#define LABOR_COST 0.35

//print functions
void printMeasurement(int length, int width);
void printCharges(int area, double carpetCost, int discountValue);

//calculations functions
int calculateArea(int length, int width);
double calculateCarpetCost(int area, double squareFootCost);
double calculateLaborCost(int area);
double calculateInstalledPrice(double carpetCharge, double laborCharge);
double calculateDiscount(int costumerDiscount, double installedPriceCharge);
double calculateSubtotal(int costumerDiscount, double installedPriceCharge);
double calculateTax(double subtotalCharge);
double calculateTotal(double subtotalCharge, double taxCharge);

int main()
{
    //Local Declaration
    int area;
    int lengthFeet;
    int widthFeet;
    int costumerDiscount;
    double squareFootCost;

    //UserInput
    printf("Length of room (feet)?\t\t\t");
    scanf("%d", &lengthFeet);
    printf("Width of room (feet)?\t\t\t");
    scanf("%d", &widthFeet);
    printf("Customer discount (percent)?\t\t");
    scanf("%d", &costumerDiscount);
    printf("Cost per square foot (xxx.xx)?\t\t");
    scanf("%lf", &squareFootCost);

    //Calls the calculateArea whereas the locally decalared variable (area) is the receiver of the return value of the function
    area = calculateArea(lengthFeet, widthFeet);

    //Calls the printMeasurement and printCharges to print the output
    printMeasurement(lengthFeet, widthFeet);
    printCharges(area,squareFootCost, costumerDiscount);


    return 0;
}

//Void with paramenter whereas the function accepts two integer paremeter called lenght and width
void printMeasurement(int length, int width){
    //Prints the Measurement format can be seen in the book
    printf("\n\n\t\t\t\tMeasurement\n\n");
    printf("\tLenght  \t\t\t\t    %d ft\n", length);
    printf("\tWidth   \t\t\t\t    %d ft\n", width);
    //calls the calculateArea function to measure the Area
    printf("\tArea    \t\t\t\t    %d square ft", calculateArea(length, width));
}

//Void with paramenter whereas the function accepts three paremeter called area, carpetCost, discountValue
void printCharges(int area,double carpetCost, int discountValue){
    //Local Declarations
    double laborCharge;
    double carpetCharge;
    double installedPriceCharge;
    double discountCharge;
    double subtotalCharge;
    double taxCharge;
    double totalCharge;

    //Assigning the variables to the Calculation Functions to recieve the return values of each function
    laborCharge = calculateLaborCost(area);
    carpetCharge = calculateCarpetCost(area, carpetCost);
    installedPriceCharge = calculateInstalledPrice(laborCharge, carpetCharge);
    discountCharge = calculateDiscount(discountValue, installedPriceCharge);
    subtotalCharge = calculateSubtotal(installedPriceCharge, discountCharge);
    taxCharge = calculateTax(subtotalCharge);
    totalCharge = calculateTotal(subtotalCharge, taxCharge);

    //Prints the charges format can be seen in the book
    printf("\n\n\t\t\t\tCharges\n\n");
    printf("\tDescription\t\tCost/SQ.FT.\t\tCharge \n");
    printf("\t-----------\t\t-----------\t\t-------\n");

    printf("\tCarpet\t\t\t%6.2lf\t\t\t$%.2lf\n",carpetCost,carpetCharge);
    printf("\tLabor\t\t\t%6.2f\t\t\t %.2lf\n",LABOR_COST, laborCharge);
    printf("\t\t\t\t\t\t\t-------\n");

    printf("\tINTALLED PRICE\t\t\t\t\t$%.2lf\n", installedPriceCharge);
    printf("\tDiscount\t\t%3d%%\t\t\t %.2lf\n",discountValue, discountCharge);
    printf("\t\t\t\t\t\t\t-------\n");

    printf("\tSUBTOTAL\t\t\t\t\t$%.2lf\n", subtotalCharge);
    printf("\tTax\t\t\t\t\t\t$%.2lf\n",taxCharge);
    printf("\tTotal\t\t\t\t\t\t$%.2lf\n", totalCharge);
}

//Calculation function are all non - void with parameters whereas they all have a return statement
int calculateArea(int length, int width){
    int area;
    area = length * width;
    return area;
}//Calculates the area by multiplying the length and width
double calculateCarpetCost(int area, double squareFootCost){
    double total;
    total = area * squareFootCost;
    return total;
}//Calculates the carpet cost by multiplying the area and the square foot cost
double calculateLaborCost(int area){
    int total;
    total = area * LABOR_COST;
    return total;
}//Calculates the labor cost by multiplying the area and the defined constant LABOR_COST
double calculateInstalledPrice(double carpetCharge, double laborCharge){
    double total;
    total = carpetCharge + laborCharge;
    return total;
}//Calculates the installed price by adding carpet charge and the labor charge
double calculateDiscount(int costumerDiscount, double installedPriceCharge ){
    double total;
    double discountValue;

    discountValue = (double) costumerDiscount / 100.0;
    total = installedPriceCharge * discountValue;

    return total;
}//Calculating the discount by converting the costumer discount in to a decimal point and then multiplying it to te installed price charge
double calculateSubtotal(int costumerDiscount, double installedPriceCharge){
    double total;
    total = costumerDiscount - installedPriceCharge;
    return total;
}//Calculating the subtotal by subtracting the costumer discount and installed price charge
double calculateTax(double subtotalCharge){
    double total;
    total = subtotalCharge * TAX_RATE;
    return total;
}//Calculating the tax by Multiplying the subtotal charge and the defined constant TAX_RATE
double calculateTotal(double subtotalCharge, double taxCharge){
    double total;
    total = subtotalCharge + taxCharge;
    return total;
}//Calculating the Total by adding the subtotal charge and tax charge
