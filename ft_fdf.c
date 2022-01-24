/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lebackor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:12:00 by lebackor          #+#    #+#             */
/*   Updated: 2022/01/17 16:12:09 by lebackor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"



int	get_len_file(char *av)
{
	int i;
	s_data fd;
	char *str;

	i = 0;
	fd.fd = open(av, O_RDONLY);
	while ((str = get_next_line(fd.fd)) != NULL)
	{
		i++;
	//	printf("%s", str);
	}
	//close(fd);
	free(str);
	return (i);
}
/*
char **get_width(int fd)
{
	int i;
	char *str;
	char **s1;
	i = 0;
	//printf("%s", str);
	str = get_next_line(fd);
	s1 = ft_split(str, ' ');
	while (s1[i])
	 {
		//printf("[%s]", s1[i]);
		i++;
	 }
	return (s1);
}
*/

int		ft_count_tab(char **str)
{
	int i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return (i);
}
char	***get_total_width(char *av)
{
	int i;
	int k;
	int j = 0;
	char ***str;
	s_data tab;

	i = 1;
	k = get_len_file(av);
	tab.fd = open(av, O_RDONLY);
	//printf("%d\n", k);
	str = malloc(sizeof(char **) * (k + 1));
	//printf("[%s]", **str);
	str[0] = ft_split(get_next_line(tab.fd), ' ');
	//printf("len %d", ft_count_tab(str[0]));
	while (i < k)
	{
		str[i] = ft_split(get_next_line(tab.fd), ' ');
		if (ft_count_tab(str[0]) != ft_count_tab(str[i]))
			return (NULL);
		//printf("%s", *str[i]);
		j = 0;
		while (str[i][j])
		{
		//	printf("[%s]", str[i][j]);
			j++;
		}
	//	printf("\n");
		i++;
	}
	close(tab.fd);
	return (str);
}

int	get_fd(char *av)
{
	char	***str;

	//fd = open(av, O_RDONLY);
	str = get_total_width(av);
	if(!str)
	{
		printf("WRONG MAP\n");
		return (0);
	}
	return (1);
}
/*
char *arg(char **av)
{
	char *str;

	int i;
	i = 0;
	
	str = malloc(sizeof(char) * ft_strlen(av[1]) + 1);
	while (av[1][i])
	{
		str[i] = av[1][i];
		//write(1, &str[i], 1);
		i++;
	}
	return (str);
}*/

int main(int ac, char **av)
{
	s_data data;
	//int fd;
	if (ac != 2)
		return (0);
	data.x = get_fd(av[1]);
	printf("%d", data.len);
	//close(fd);

}













/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
    int i;

	i = 0;
    mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FDF");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
    while (i < 500)
    {
        my_mlx_pixel_put(&img, 500 + i, 500, 0x00FF0000);
        i++;
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/