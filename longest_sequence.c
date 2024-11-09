/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eebert <eebert@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:47:54 by eebert            #+#    #+#             */
/*   Updated: 2024/11/09 14:52:46 by eebert           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	init_arrays(int *dp, int *prev, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length)
	{
		dp[i] = 1;
		prev[i] = -1;
		i++;
	}
}

static void	update_dp(const int *array, int *dp, int *prev, size_t length)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < length)
	{
		j = 0;
		while (j < i)
		{
			if (array[j] < array[i] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

static int	find_max_index(int *dp, size_t length, size_t *max_length)
{
	size_t	i;
	int		max_index;

	i = 0;
	max_index = 0;
	*max_length = dp[0];
	while (i < length)
	{
		if (dp[i] > (int)*max_length)
		{
			*max_length = dp[i];
			max_index = i;
		}
		i++;
	}
	return (max_index);
}

static int	*build_result(int *array, int *prev, int max_index, size_t max_len)
{
	int		*result;
	size_t	i;

	result = (int *)malloc(sizeof(int) * max_len);
	if (!result)
		return (NULL);
	i = max_len;
	while (i > 0)
	{
		i--;
		result[i] = array[max_index];
		max_index = prev[max_index];
	}
	return (result);
}

int	*get_longest_sequence(int *array, size_t length, size_t *seq_length)
{
	int	*dp;
	int	*prev;
	int	*result;
	int	max_index;

	dp = (int *)malloc(sizeof(int) * length);
	prev = (int *)malloc(sizeof(int) * length);
	if (!dp || !prev)
	{
		free(dp);
		free(prev);
		return (NULL);
	}
	init_arrays(dp, prev, length);
	update_dp(array, dp, prev, length);
	max_index = find_max_index(dp, length, seq_length);
	result = build_result(array, prev, max_index, *seq_length);
	free(dp);
	free(prev);
	return (result);
}
