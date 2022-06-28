#include "checker.h"

void check_is_sort(t_astek *a_stek)
{
    t_astek *tmp1;

    tmp1 = (a_stek);
    while (tmp1->next != NULL)
    {
        if (!(tmp1->index < tmp1->next->index))
        {
            printf("KO\n");
            break ;
        }
        if (tmp1->next->next == NULL && tmp1->next != NULL)
		{
            printf("OK\n");
            break;
		}
		tmp1 = tmp1->next;
    }
}

int	ft_strlen_ps(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *str_1, char *str_2)
{
	int	i;

	i = 0;
	if (!str_1 || !str_2)
		return (0);
	if (ft_strlen_ps(str_1) == ft_strlen_ps(str_2))
	{
		while (str_1[i] == str_2[i])
			i++;
		i--;
		if (i == ft_strlen_ps(str_1))
			return (1);
	}
	return (0);
}