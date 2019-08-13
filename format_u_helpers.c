/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mqian <mqian@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 14:53:50 by mqian             #+#    #+#             */
/*   Updated: 2019/08/12 16:17:24 by mqian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     format_u_left(int flags[], uintmax_t argument, int len)
{
    int count;

    count = 0;
    if (len >= flags[5] && len >= flags[7])
    {
        if (flags[5] == 0 && flags[6] == 1 && flags[7] == 0 && argument == 0)
            count += 0;
        else if (flags[7] == 0 && flags[6] == 1)
            count += (argument > 0) ? print_uint_max(argument, 1, 0) : write_and_increment(' ');
        else
            count += (argument > 0) ? print_uint_max(argument, 1, 0) : write_and_increment('0');
    }
    else if (flags[7] >= flags[5] && flags[7] >= len)
        count += format_u_left_helper_1(flags, argument, len);
    else if (flags[5] >= len && flags[5] >= flags[7])
    {
        if (len >= flags[7])
            count += format_u_left_helper_2(flags, argument, len);
        else // minw >= precision > len
            count += format_u_left_helper_3(flags, argument, len);
    }
    return (count);
}

int     format_u_left_helper_1(int flags[], uintmax_t argument, int len)
{
    int count;

    count = 0;
    while (count < flags[7] - len)
        count += write_and_increment('0');
    count += (argument > 0) ? print_uint_max(argument, 1, 0) : write_and_increment('0');
    return (count);
}

int     format_u_left_helper_2(int flags[], uintmax_t argument, int len)
{
    int count;

    count = 0;
    if (flags[7] == 0 && flags[6] == 1)
        count += (argument > 0) ? print_uint_max(argument, 1, 0) : write_and_increment(' ');
    else
        count += (argument > 0) ? print_uint_max(argument, 1, 0) : write_and_increment('0');
    while (count < flags[5])
        count += write_and_increment(' ');
    return (count);
}

int     format_u_left_helper_3(int flags[], uintmax_t argument, int len)
{
    int count;

    count = 0;
    while (count < flags[7] - len)
        count += write_and_increment('0');
    count += (argument > 0) ? print_uint_max(argument, 1, 0) : write_and_increment('0');
    while (count < flags[5])
        count += write_and_increment(' ');
    return (count);
}