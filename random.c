/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpireyre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 10:43:49 by cpireyre          #+#    #+#             */
/*   Updated: 2019/09/29 10:43:52 by cpireyre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define LIST_SIZE 32

unsigned int		ft_random_get(void)
{
	static unsigned int	nums[LIST_SIZE];
	static unsigned int	curr = 0;
	int					fd;

	if (curr % LIST_SIZE == 0)
	{
		curr = 0;
		fd = open("/dev/random", O_RDONLY);
		read(fd, nums, sizeof(unsigned int) * LIST_SIZE);
		close(fd);
	}
	return (nums[curr++]);
}

unsigned int		ft_random_range(unsigned int min, unsigned int max)
{
	return (min + (ft_random_get() % max));
}

