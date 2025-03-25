#include "minirt.h"

int	encode_rgb(t_color *c)
{
    return (c->r << 16 | c->g << 8 | c->b);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp -8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp /8));
	while (i >= 0)
	{
		if (img->endian)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	render(t_minirt *data)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (!data->win_ptr)
		return (EXIT_SUCCESS);
	while (++i <= WIN_WIDTH)
	{
		j = -1;
		while( ++j <= WIN_HEIGHT)
		{
			if (i <= 100 && j <= 100)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0xFF00FF);
			else if (i <= 100 && j >= WIN_HEIGHT - 100)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0xFFFF00);
			else if (i >= WIN_WIDTH - 100 && j <= 100)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0x00FFFF);
			else if (i >= WIN_WIDTH - 100 && j >= WIN_HEIGHT - 100)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0xFFFFFF);
			else if (i >= (WIN_WIDTH - 100) / 2 && i <= (WIN_WIDTH + 100) / 2
				&& j >= (WIN_HEIGHT - 100) / 2 && j < (WIN_HEIGHT + 100) / 2)	
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0xFF0000);
			else if ( i == j || WIN_WIDTH - i == WIN_HEIGHT - j
				|| i  == WIN_HEIGHT - j || j == WIN_WIDTH - i)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0x00FF00);
			else
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, 0x0000FF);
		}
	}
	return (EXIT_SUCCESS);
}