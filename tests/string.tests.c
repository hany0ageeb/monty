#include <stdio.h>
#include "../string.h"

int main(void)
{
	printf("%s is_integer %d\n", "17", is_integer("17"));
	printf("%s is_integer %d\n", "17.0", is_integer("17.0"));
	printf("%s is integer %d\n", "-17", is_integer("-17"));
	printf("%s is_integer %d\n", "50.55", is_integer("50.55"));
	printf("%s is_integer %d\n", "5P", is_integer("5P"));
	printf("%s is_integer %d\n", "P56", is_integer("P56"));
	printf("%s is_integer %d\n", "XYZ", is_integer("XYZ"));
	return (0);
}
