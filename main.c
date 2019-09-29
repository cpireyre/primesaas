#include <stdlib.h>
#include "primes.h"

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (ft_miller_rabin(atoi(argv[1]), GOOD_ENOUGH));
	else
		return (127);
}
