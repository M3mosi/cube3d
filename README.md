# 42'S CUB3D SUBJECT

<h2>MANDATORY PART</h2>
<br>

  **Program name** | <samp>cub3d</samp> 
  -----------------|----------
  **Turn in files** | All your files
  **Makefile** | <samp>all, clean, fclean, re, bonus</samp>
  **Arguments** | a map in format <samp>*.cub</samp>
  **External functs.** | * <code>open</code>, <code>close</code>, <code>read</code>, <code>write</code>, <code>printf</code>, <code>malloc</code>, <code>free</code>, <code>perror</code>, <code>strerror</code>, <code>exit</code><br>* All functions of the math library (<samp>-lm man man 3 math</samp>)<br>* All functions of the <samp>MinilibX</samp>
  **Libft authorized** | Yes
  **Description** | You must create a “realistic” 3D graphical representation of the inside of a maze from a first person perspective. You have to create this representation using the Ray-Casting principles mentioned earlier.
  
<br> 

The constraints are as follows:

- You must use the <samp>minilibX</samp>. Either the version that is available on the operating system, or from its sources.
- The management of your window must remain smooth: changing to another win- dow, minimizing, etc.
- Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West).
- Your program must be able to display an item (sprite) instead of a wall.
- Your program must be able to set the floor and ceilling colors to two different ones.
- In case the <samp>Deepthought</samp> has eyes one day to evaluate your project, your program must save the first rendered image in <samp>bmp</samp> format when its second argument is "<samp>––save</samp>".
- If no second argument is supllied, the program displays the image in a window and respects the following rules:
  - The left and right arrow keys of the keyboard must allow you to look left and right in the maze.
  - The W, A, S and D keys must allow you to move the point of view through the maze.
  - Pressing <samp>ESC</samp> must close the window and quit the program cleanly.
  - Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.
  - If the declared screen size in the map is greater than the display resolution, the window size will be set depending to the current display resolution.
  - The use of <samp>images</samp> of the <samp>minilibX</samp> is strongly recommended.
- Your program must take as a first argument a scene description file with the .cub
extension.
  - The map must be composed of only 4 possible characters: <code>0</code> for an empty space, <code>1</code> for a wall, <code>2</code> for an item and <code>N</code>,<code>S</code>,<code>E</code> or <code>W</code> for the player’s start position and spawning orientation. This is a simple valid map:
  <pre>
  <code>
  1111111
  1001001
  1020001
  1100N01
  1111111
  </code>
  </pre>
  - The map must be closed/surrounded by walls, if not the program must return an error.
  - Except for the map content, each type of element can be separated by one or more empty line(s).
  - Except for the map content which always has to be the last, each type of element can be set in any order in the file.
  - Except for the map, each type of information from an element can be separated by one or more space(s).
  - The map must be parsed as it looks like in the file. Spaces are a valid part of the map, and is up to you to handle. You must be able to parse any kind of map, as long as it respects the maps rules.
  - Each element (except the map) firsts information is the type identifier (com- posed by one or two character(s)), followed by all specific informations for each object in a strict order such as :
    - Resolution: <code>R 1920 1080</code>
      - identifier: <code>R</code>
      - x render size
      - y render size
    - North texture: <code>NO ./path_to_the_north_texture</code>
      - identifier: <code>NO</code>
      - path to the north texture
    - South texture: <code>SO ./path_to_the_north_texture</code>
      - identifier: <code>SO</code>
      - path to the south texture
    - West texture: <code>WE ./path_to_the_north_texture</code>
      - identifier: <code>WE</code>
      - path to the west texture
    - East texture: <code>EA ./path_to_the_north_texture</code>
      - identifier: <code>Ea</code>
      - path to the east texture
    - Sprite texture: <code>S ./path_to_the_north_texture</code>
      - identifier: <code>S</code>
      - path to the south texture
    - Floor color: <code>F 220, 100, 0</code>
      - identifier: <code>F</code>
      - R,G,B colors in range [0,255]: 0, 255, 255
    - Ceilling color: <code>C 225, 30, 0</code>
      - identifier: <code>C</code>
      - R,G,B colors in range [0,255]: 0, 255, 255
  - Example of the mandatory part with a minimalist <samp>.cub</samp> scene:
    <pre>
    <code>
    R 1920 1080
    NO ./path_to_the_north_texture
    SO ./path_to_the_south_texture
    WE ./path_to_the_west_texture
    EA ./path_to_the_east_texture
    S ./path_to_the_sprite_texture
    F 220,100,0
    C 225,30,0
    1111111111111111111111111
    1000000000110000000000001
    1011000001110000002000001
    1001000000000000000000001
    111111111011000001110000000000001
    100000000011000001110111111111111
    11110111111111011100000010001
    11110111111111011101010010001
    11000000110101011100000010001
    10002000000000001100000010001
    10000000000000001101010010001
    11000001110101011111011110N0111
    11110111 1110101 101111010001
    11111111 1111111 111111111111
    </code>
    </pre>
  - If any misconfiguration of any kind is encountered in the file, the program must exit properly and return "<spam>Error\n</spam>" followed by an explicit error message of your choice.
  
<br>
<h2>BONUS PART</h2>
<br>

Bonus list:
- Wall collisions.
- A skybox.
- Floor and/or ceiling texture.
- An HUD.
- Ability to look up and down.
- Jump or crouch.
- A distance related shadow effect.
- Life bar.
- More items in the maze.
- Object collisions.
- Earning points and/or losing life by picking up objects/traps.
- Doors which can open and close.
- Secret doors.
- Animations of a gun shot or animated sprite.
- Several levels.
- Sounds and music.
- Rotate the point of view with the mouse.
- Weapons and bad guys to fight!

<br>

<samp><b>NOTE</b>: To earn all bonus points you need to validate at least 14 of them, so choose wisely but be careful to not waste your time!</samp>

<samp><b>NOTE</b>: You are allowed to use other functions to complete the bonus part as long as their use is justified during your evaluation.  You are also allowed to modify the expected scene file format to fit your needs. Be smart!</samp>
