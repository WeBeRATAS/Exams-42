/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbuitrag <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:25:50 by rbuitrag          #+#    #+#             */
/*   Updated: 2024/08/29 13:27:16 by rbuitrag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char *av[])
{
    int i;
    
    if (ac == 2)
    {
        i = 0;
        while (av[1][i])
        {
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
            /* we remove the ASCII code of the letter from the ASCII
             * code of the last upper-case letter, then add the ASCII
             * code of the first upper-case letter
             * 90 - 65(A) = 35, 35 + 65 = 90(Z)
             * 90 - 66(B) = 34, 34 + 65 = 89(Y)
             */ 
                av[1][i] = 'Z' - av[1][i] + 'A';
            else if (av[1][i] >= 'a' && av[1][i] <= 'z')
            /* we remove the ASCII code of the letter from the ASCII
             * code of the last lower-case letter, then add the ASCII
             * code of the first lower-case letter
             * 122 - 97(a) = 35, 35 + 97 = 122(z)
             * 122 - 98(b) = 34, 34 + 97 = 121(y)
             */ 
                av[1][i] = 'z' - av[1][i] + 'a';
            /* finally, we can writethe current character to the screen
             */
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
}
