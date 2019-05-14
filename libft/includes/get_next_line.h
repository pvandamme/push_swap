/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmerien <rmerien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:52:02 by rmerien           #+#    #+#             */
/*   Updated: 2018/11/19 09:32:34 by rmerien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 42
# define ENDL '\n'
# define SLIM 4864

# include "libft.h"
# include <unistd.h>

int get_next_line(int const fd, char **line);

#endif
