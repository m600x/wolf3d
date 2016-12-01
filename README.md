#Wolf3D
OSX Status: ![OSX Status](https://travis-ci.com/m600x/wolf3d.svg?token=NqkvpdueTsHVQsHR9xAp)

Wolf3D is a graphical project that aim to teach us the Raycasting method by reproducing a barebone version of Wolf3D (just the rendering part). The project use mlx but it wasn't mandatory as long as the library used (like SDL) is only limited to the same function as the one present in mlx. To avoid temptation, I just stick to mlx.

<p align="center"><img src=http://reho.st/self/1b402d0710f99beb67008432fb3419f9b58c861a.png></p>

Mandatory functionality:
 - ESC key should quit the program.
 - The red cross should also quit the program.
 - Movement of the character.
 - Color of the wall should be different depending of the orientation.

Bonus currently supported:
 - Clipping (can't go into the wall).
 - Wall texture.
 - Skybox texture.
 - Ground texture.
 - Object in the map.
 - Object that can be picked up.
 - Alteration of the character with the item.
 - 5 different maze with auto loading between them.
 - Time of the game.
 - Sound and music.

<p align="center">Key mapping</p>
Key|Function|Comment
:-:|:-:|:--
<kbd>W</kbd><br><kbd>S</kbd>|Movement<br>Movement|Forward.<br>Backward.
<kbd>A</kbd><kbd>D</kbd>|Movement<br>Movement|Strafe left.<br>Strafe right.
<kbd>Q</kbd><kbd>E</kbd>|Rotation<br>Rotation|Rotate left.<br>Rotation right.
<kbd>Space</kbd>|Item|Use item (4x speed).
<kbd>T</kbd>|Option|Untextured version.
