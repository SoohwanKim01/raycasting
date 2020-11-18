/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 00:19:45 by marvin            #+#    #+#             */
/*   Updated: 2020/11/16 21:59:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libbmp.h"

static t_bmp	*encode(char *img, int width, int height)
{
	t_bmp	*bmp;

	if (!(bmp = init_bmp(height)))
		return (NULL);
	fill_headers(bmp, width, height);
	if (!(fill_imagedata(bmp, img, width, height)))
		return (NULL);
	return (bmp);
}

int				export_bmp(char *path, char *img, int width, int height)
{
	t_bmp	*bmp;

	if (width >= 8001 || height >= 8001)
		return (0);
	if (!(bmp = encode(img, width, height)))
		return (0);
	bmp->fd = open(path, O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (bmp->fd == -1)
		return (-1);
	write_headers(bmp);
	if (!(write_rgb(bmp)))
		return (0);
	close(bmp->fd);
	destroy_bmp(bmp);
	return (1);
}
