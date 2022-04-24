#include<stdio.h>

#define QUOTIENT (4.0f/3.0f)
#define PI 3.14f

int main(void)
{
	float volume; 
	float radius;

	printf("Enter a radius: ");
	scanf("%f", &radius);

	volume = QUOTIENT * PI * radius * radius * radius;
	printf("%f\n\a", volume);

	return 0;
}
