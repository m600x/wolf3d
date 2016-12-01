/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 13:28:55 by alao              #+#    #+#             */
/*   Updated: 2016/11/29 21:13:08 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARS_H
# define VARS_H

/*
** MAPS : Coding is as follow:
**            - 0 empty space.
**            - 1 wall.
**            - 2 player.
**            - 3 heroin.
**            - 4 exit;
*/

# define XPM_MAP_1		"maps/m1.wolf"
# define XPM_MAP_2		"maps/m2.wolf"
# define XPM_MAP_3		"maps/m3.wolf"
# define XPM_MAP_4		"maps/m4.wolf"
# define XPM_MAP_5		"maps/m5.wolf"

/*
** IMAGES
*/

# define IMG_TEX_X		256
# define IMG_TEX_Y		256
# define IMG_SPR_X		256
# define IMG_SPR_Y		256
# define SPRITE_TP		"Resources/images/sprites/teleporter.xpm"
# define SPRITE_HEROIN	"Resources/images/sprites/heroin.xpm"

# define LV1_SKY		"Resources/images/level/1_sky.xpm"
# define LV1_WALL		"Resources/images/level/1_wall.xpm"
# define LV1_GND		"Resources/images/level/1_gnd.xpm"

# define LV5_WALL		"Resources/images/level/5_wall.xpm"
# define LV5_SKY		"Resources/images/level/5_sky.xpm"
# define LV5_GND		"Resources/images/level/5_gnd.xpm"

# define IMG_GUI_FOOT	"Resources/images/gui/footer.xpm"
# define IMG_GUI_N0		"Resources/images/gui/numbers/0.xpm"
# define IMG_GUI_N1		"Resources/images/gui/numbers/1.xpm"
# define IMG_GUI_N2		"Resources/images/gui/numbers/2.xpm"
# define IMG_GUI_N3		"Resources/images/gui/numbers/3.xpm"
# define IMG_GUI_N4		"Resources/images/gui/numbers/4.xpm"
# define IMG_GUI_N5		"Resources/images/gui/numbers/5.xpm"
# define IMG_GUI_N6		"Resources/images/gui/numbers/6.xpm"
# define IMG_GUI_N7		"Resources/images/gui/numbers/7.xpm"
# define IMG_GUI_N8		"Resources/images/gui/numbers/8.xpm"
# define IMG_GUI_N9		"Resources/images/gui/numbers/9.xpm"
# define IMG_HEAD_L		"Resources/images/player/headl.xpm"
# define IMG_HEAD_M		"Resources/images/player/headm.xpm"
# define IMG_HEAD_R		"Resources/images/player/headr.xpm"
# define IMG_HEROIN_0	"Resources/images/player/heroin0.xpm"
# define IMG_HEROIN_1	"Resources/images/player/heroin1.xpm"
# define IMG_HEROIN_2	"Resources/images/player/heroin2.xpm"
# define IMG_HEROIN_3	"Resources/images/player/heroin3.xpm"
# define IMG_HEROIN_4	"Resources/images/player/heroin4.xpm"
# define IMG_HEROIN_5	"Resources/images/player/heroin5.xpm"

/*
** SOUNDS
*/

# define AUD_OPN		"afplay Resources/audio/opening.mp3 &>/dev/null &"
# define AUD_FS1		"afplay Resources/audio/fs1.wav &>/dev/null &"
# define AUD_FS2		"afplay Resources/audio/fs2.wav &>/dev/null &"
# define AUD_HERPICK	"afplay Resources/audio/her_pick.wav &>/dev/null &"
# define AUD_HERIN		"afplay Resources/audio/her_pick.wav &>/dev/null &"
# define AUD_LEVEL		"afplay Resources/audio/her_pick.wav &>/dev/null &"
# define AUD_OFF		"killall afplay &>/dev/null"

#endif
