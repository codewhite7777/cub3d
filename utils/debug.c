#include "debug.h"

void	debug_print_dptr_toint(const char* msg, char **dptr, int ylen, int xlen)
{
	int	i;
	int	j;

	printf("%s\n", msg);
	i = 0;
	while (i < ylen)
	{
		printf("%d: ", i);
		j = 0;
		while (j < xlen)
		{
			printf("%4d ", dptr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}
