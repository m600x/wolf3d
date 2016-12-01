/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   immersion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:20:45 by alao              #+#    #+#             */
/*   Updated: 2016/11/30 11:21:15 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** DORA : Ambient sound.
*/

void				wolf_sound(t_wolf *w)
{
	(w->e.aud_fst) ? system(AUD_FS1) : system(AUD_FS2);
	w->e.aud_fst = w->e.aud_fst ? 0 : 1;
	w->e.aud_fsi = 0;
}
