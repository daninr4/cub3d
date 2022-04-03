/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_to_bmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:31:35 by jcarrete          #+#    #+#             */
/*   Updated: 2021/05/06 22:03:21 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static unsigned char	*create_header(t_bmp_data *bmp)
{
	int						file_size;
	static unsigned char	header[HEADER_SIZE] = {0};

	file_size = 54 + \
		(((bmp->pixel_bytes_row) + (bmp->padding_bytes_row)) * (bmp->height));
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(file_size);
	header[3] = (unsigned char)(file_size >> 8);
	header[4] = (unsigned char)(file_size >> 16);
	header[5] = (unsigned char)(file_size >> 24);
	header[10] = (unsigned char)(HEADER_SIZE);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(bmp->width);
	header[19] = (unsigned char)((bmp->width) >> 8);
	header[20] = (unsigned char)((bmp->width) >> 16);
	header[21] = (unsigned char)((bmp->width) >> 24);
	header[22] = (unsigned char)(bmp->height);
	header[23] = (unsigned char)((bmp->height) >> 8);
	header[24] = (unsigned char)((bmp->height) >> 16);
	header[25] = (unsigned char)((bmp->height) >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(8 * BPP);
	return (header);
}

static void	init_bmp(t_bmp_data *data, t_mlx_image *img)
{
	data->width = (unsigned int)(img->width);
	data->height = (unsigned int)(img->height);
	data->pixel_bytes_row = (data->width * img->bits_per_pixel) / (BPP * 2);
	data->padding_bytes_row = (BPP - (data->pixel_bytes_row) % BPP) % BPP;
}

int	mlx_image_to_bmp(t_mlx_image *img, const char *name)
{
	t_bmp_data			bmp;
	unsigned char const	zeros[3] = {0, 0, 0};
	unsigned int		row;
	int					w;

	w = 0;
	init_bmp(&bmp, img);
	bmp.fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, \
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (bmp.fd == -1)
		return (-1);
	bmp.file_header = create_header(&bmp);
	w += write(bmp.fd, bmp.file_header, HEADER_SIZE);
	bmp.img = (unsigned char *)(img->addr);
	row = bmp.height;
	while (row > 0)
	{
		w += write(bmp.fd, \
					(bmp.img + (row * img->line_length)), img->line_length);
		w += write(bmp.fd, zeros, bmp.padding_bytes_row);
		row--;
	}
	close(bmp.fd);
	return (0);
}
