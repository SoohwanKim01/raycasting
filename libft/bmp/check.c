/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:19:43 by marvin            #+#    #+#             */
/*   Updated: 2020/11/16 21:59:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libbmp.h"

int		check_header(t_bmp *bmp)
{
	if (bmp->file_header->signature[0] != 'B' &&
			bmp->file_header->signature[1] != 'M')
		return (0);
	if (bmp->info_header->bm_headersize != 40)
		return (0);
	if (bmp->info_header->bpp != 24)
		return (0);
	return (1);
}
