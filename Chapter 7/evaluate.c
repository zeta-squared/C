#include <stdio.h>

int main(void)
{
	float val, eval;
	char ch;

	printf("Enter an expression: ");
	scanf("%f", &eval);
	while ((ch = getchar()) != '\n') {
		scanf("%f", &val);
		switch (ch) {
			case '+':
				eval += val;
				break;
			case '-':
				eval -= val;
				break;
			case '*':
				eval *= val;
				break;
			case '/':
				eval /= val;
				break;
			default:
				break;
		}
	}
	printf("Value of the expression: %.2f\n", eval);

	return 0;
}
