/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 09:58:29 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/08/29 10:52:50 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int main(int ac, char **av)
{
    int i;
    int j;
    
    /* check the number of argument
     */
    if (ac == 2)
    {
        i = 0;
        /* loop over the whole string
         */
        while (av[1][i])
        {
            /* if the character is an upper-case letter
             */
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            {
                j = 0;
                /* loop while the j is smaller than the alphabetical
                 * index of the current character
                 * - 64 is to get the alphabetical index
                 * A in ASCII => 65, so 65 - 64 = 1
                 * Z in ASCII => 90, so 90 - 64 = 26
                 */
                while (j < av[1][i] - 64)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            else if (av[1][i] >= 'a' && av[1][i] <= 'z')
            {
                j = 0;
                /* loop while the j is smaller than the alphabetical
                 * index of the current character
                 * - 96 is to get the alphabetical index
                 * a in ASCII => 97, so 97 - 96 = 1
                 * z in ASCII => 122, so 122 - 96 = 26
                 */
                while (j < av[1][i] - 96)
                {
                    write(1, &av[1][i], 1);
                    j++;
                }
            }
            else
                /* if the current character is not a letter
                 * simply write the character
                 */
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
