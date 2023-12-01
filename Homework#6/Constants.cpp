#include <stdio.h>
#define PI 3.14159
 
int main()
{
    float radius, area;
    radius = 12;
    area = PI * radius * radius;
 
    printf("Area = %f", area);
 
    return 0;
}


/*
As far as I understand, the difference between these two ways of defining a variable is that 
defining a variable as constant via "const" is a more reliable way to make sure that this variable will remain constant 
throughout the program, resulting in an error each time you try to modify that value 
while defining a constant variable via preprocessor directive "#define" will replace all instances of the same variable 
with this value during the preprocessing stage. 
It means no errors will occur in the code if you try to redefine the constant value after this variable was defined via "#define". 
However, all the values would be replaced by the value defined in the preprocessor.

Open sources also provide information that the "#define" method was more often used in the past; 
therefore, a lot of legacy code contains such a way of definition, while "const" is considered to be 
a more modern and safer pattern of defining constants in the code.
*/