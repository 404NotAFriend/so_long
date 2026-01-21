<div align="center">

<!-- Animated Header -->
<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Activities/Video%20Game.png" width="80"/>

# 🎮 so_long - 2D Game Engine

<img src="https://img.shields.io/badge/Score-125%2F125-success?style=for-the-badge&logo=42&logoColor=white"/>
<img src="https://img.shields.io/badge/Circle-2-00BABC?style=for-the-badge&logo=42&logoColor=white"/>
<img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white"/>
<img src="https://img.shields.io/badge/Graphics-MiniLibX-000000?style=for-the-badge&logo=42&logoColor=white"/>
<img src="https://img.shields.io/badge/Norminette-passing-success?style=for-the-badge&logo=42&logoColor=white"/>

**A complete 2D game engine built from scratch in C - Where coding meets creativity!**

<img src="https://user-images.githubusercontent.com/74038190/212284100-561aa473-3905-4a80-b561-0d28506553ee.gif" width="600"/>

</div>

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Light%20Bulb.png" width="25"/> About The Project

**so_long** is where you build your first **2D game** from scratch! This project introduces you to the fascinating world of **graphics programming**, **event handling**, and **game development** using the MiniLibX graphics library.

You'll create a simple but complete game where the player must:
- 🏃 Navigate through a map
- 💎 Collect all collectibles
- 🚪 Reach the exit
- 😈 Avoid enemies (bonus)

This project teaches you:
- 🎨 **Graphics rendering** with MiniLibX
- 🎮 **Event handling** (keyboard input, window events)
- 🗺️ **Map parsing** and validation
- 🔍 **Path-finding algorithms** (flood fill)
- 💫 **Sprite animations**
- 🏗️ **Game architecture** and design patterns

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Travel%20and%20places/Rocket.png" width="25"/> Features

<table>
<tr>
<td width="50%">

### 🎯 Mandatory Features
- ✅ **2D top-down view** game
- ✅ **WASD movement** controls
- ✅ **Sprite-based rendering**
- ✅ **Map validation** system
- ✅ **Collectible system**
- ✅ **Exit mechanism**
- ✅ **Move counter** display
- ✅ **ESC to close** game

</td>
<td width="50%">

### 🌟 Bonus Features (Implemented!)
- ✅ **Enemy patrols** with AI
- ✅ **Enemy collision** detection
- ✅ **Sprite animations** (walking, idle)
- ✅ **On-screen HUD** display
- ✅ **Game over** screen
- ✅ **Victory** screen
- ✅ **Clean memory** management (0 leaks!)

</td>
</tr>
</table>

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Gear.png" width="25"/> Technical Stack

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![MiniLibX](https://img.shields.io/badge/MiniLibX-000000?style=for-the-badge&logo=42&logoColor=white)
![X11](https://img.shields.io/badge/X11-F28834?style=for-the-badge&logo=x.org&logoColor=white)
![Make](https://img.shields.io/badge/Make-427819?style=for-the-badge&logo=cmake&logoColor=white)
![Valgrind](https://img.shields.io/badge/Valgrind-3B4D50?style=for-the-badge&logo=gnu&logoColor=white)
![Norminette](https://img.shields.io/badge/Norminette-42-00BABC?style=for-the-badge)

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/File%20Folder.png" width="25"/> Project Structure

```
so_long/
├── Makefile
├── includes/
│   ├── so_long.h           # Main header
│   ├── constants.h         # Game constants
│   └── structs.h           # Data structures
├── src/
│   ├── main.c              # Entry point
│   ├── map_reader.c        # Map file parsing
│   ├── map_validation.c    # Map validation logic
│   ├── map_path_validation.c # Flood fill algorithm
│   ├── map_initialization.c # Game state setup
│   ├── map_render.c        # Graphics rendering
│   ├── render_utils.c      # Rendering helpers
│   ├── input_handler.c     # Keyboard events
│   ├── enemy_handler.c     # Enemy AI (bonus)
│   ├── game_screens.c      # Victory/Game Over screens
│   ├── utils.c             # Utility functions
│   └── cleanup.c           # Memory management
├── GNL/                    # Get Next Line for map reading
├── libft/                  # Your Libft library
├── ft_printf/              # Your ft_printf library
├── minilibx-linux/         # MiniLibX graphics library
├── assets/
│   ├── sprites/            # Game sprites
│   └── maps/               # Map files (.ber)
└── README.md
```

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Hammer%20and%20Wrench.png" width="25"/> Installation & Usage

### Prerequisites
- GCC compiler
- Make
- X11 development libraries
- MiniLibX

### Linux Installation

```bash
# Install required packages
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# Clone the repository
git clone https://github.com/404NotAFriend/so_long.git
cd so_long

# Clone MiniLibX
git clone https://github.com/42Paris/minilibx-linux.git

# Compile the project
make

# Compile with bonus features
make bonus
```

### How to Play

```bash
# Run the game with a map file
./so_long maps/map.ber

# Example maps provided:
./so_long maps/simple.ber      # Easy map
./so_long maps/medium.ber      # Medium difficulty
./so_long maps/hard.ber        # Challenging map
```

### Controls

| Key | Action |
|-----|--------|
| `W` / `↑` | Move Up |
| `A` / `←` | Move Left |
| `S` / `↓` | Move Down |
| `D` / `→` | Move Right |
| `ESC` | Exit Game |
| `X` | Close Window |

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/World%20Map.png" width="25"/> Map Format

### Map Components

```
1 = Wall
0 = Empty space
C = Collectible
E = Exit
P = Player start position
X = Enemy (bonus)
```

### Example Map (maps/example.ber)

```
111111111111
1P0C00000001
10111111C001
1C000X000001
1000111111E1
111111111111
```

### Map Rules

- ✅ Map must be **rectangular**
- ✅ Map must be **surrounded by walls** (1)
- ✅ Must contain **exactly one** player start (P)
- ✅ Must contain **exactly one** exit (E)
- ✅ Must contain **at least one** collectible (C)
- ✅ Must have a **valid path** from P to all C's and to E
- ✅ File extension must be `.ber`

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Brain.png" width="25"/> Key Systems Explained

### 1️⃣ Map Validation System

```c
// Step 1: Parse map file
map = read_map("maps/map.ber");

// Step 2: Check rectangular shape
if (!is_rectangular(map))
    error("Map must be rectangular");

// Step 3: Check wall enclosure
if (!is_surrounded_by_walls(map))
    error("Map must be surrounded by walls");

// Step 4: Check required elements
if (!has_valid_elements(map))
    error("Invalid map elements");

// Step 5: Flood fill algorithm
if (!has_valid_path(map))
    error("No valid path to exit");
```

### 2️⃣ Flood Fill Algorithm

The game uses **flood fill** to ensure all collectibles and the exit are reachable:

```c
void flood_fill(t_map *map, int x, int y)
{
    // Base cases
    if (out_of_bounds(x, y))
        return;
    if (map[y][x] == '1')          // Wall
        return;
    if (map[y][x] == 'V')          // Already visited
        return;
        
    // Mark as visited
    map[y][x] = 'V';
    
    // Recursively check all 4 directions
    flood_fill(map, x + 1, y);     // Right
    flood_fill(map, x - 1, y);     // Left
    flood_fill(map, x, y + 1);     // Down
    flood_fill(map, x, y - 1);     // Up
}
```

### 3️⃣ Rendering Pipeline

```c
// Game loop structure
while (game->running)
{
    1. Handle input events
    2. Update game state (enemy positions, animations)
    3. Clear frame buffer
    4. Render background (floor, walls)
    5. Render collectibles
    6. Render exit
    7. Render enemies
    8. Render player
    9. Render HUD (moves, collectibles)
    10. Display frame
}
```

### 4️⃣ Enemy AI (Bonus)

```c
// Simple patrol AI
void update_enemy(t_enemy *enemy)
{
    // Move in current direction
    enemy->x += enemy->dx;
    enemy->y += enemy->dy;
    
    // Check for walls
    if (hit_wall(enemy->x, enemy->y))
    {
        // Reverse direction
        enemy->dx *= -1;
        enemy->dy *= -1;
    }
    
    // Check collision with player
    if (collides_with_player(enemy))
        game_over();
}
```

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Books.png" width="25"/> Key Learnings

<table>
<tr>
<td width="50%">

### 💡 Graphics Programming
- ✅ **MiniLibX fundamentals**
- ✅ **Image rendering** and display
- ✅ **Sprite management**
- ✅ **Pixel manipulation**
- ✅ **Double buffering** concepts
- ✅ **Frame rate management**

</td>
<td width="50%">

### 🎮 Game Development
- ✅ **Game loop architecture**
- ✅ **Event-driven programming**
- ✅ **Collision detection**
- ✅ **Path-finding algorithms**
- ✅ **State management**
- ✅ **Animation systems**

</td>
</tr>
<tr>
<td width="50%">

### 🗺️ Map & Parsing
- ✅ **File I/O** with get_next_line
- ✅ **String parsing**
- ✅ **Data validation**
- ✅ **Error handling**
- ✅ **Dynamic allocation**

</td>
<td width="50%">

### 🏗️ Software Design
- ✅ **Modular architecture**
- ✅ **Clean code practices**
- ✅ **Memory management**
- ✅ **Resource cleanup**
- ✅ **Documentation**

</td>
</tr>
</table>

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Chart%20Increasing.png" width="25"/> Project Stats

```c
typedef struct s_solong_stats {
    int     lines_of_code;      // ~1,200 lines
    int     functions;          // 30+ functions
    int     files;              // 12 source files
    int     sprites;            // 20+ sprites
    int     maps;               // 5+ test maps
    int     memory_leaks;       // 0 (Valgrind approved!)
    int     norm_errors;        // 0 (Norminette passing)
    int     score;              // 125/125 (with bonus)
    char    *difficulty;        // "Medium-Hard"
    int     dev_hours;          // ~40-60 hours
} t_solong_stats;
```

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Artist%20Palette.png" width="25"/> Game Features Showcase

### 🎨 Visual Elements

- **Tile-based graphics** - Each tile is 32x32 or 64x64 pixels
- **Sprite animations** - Smooth character movement
- **HUD display** - Real-time move counter and collectibles
- **Screen transitions** - Victory and Game Over screens
- **Collision effects** - Visual feedback on interactions

### 🎯 Gameplay Mechanics

- **Move counting** - Track player efficiency
- **Collection system** - Gather all items to unlock exit
- **Enemy patrol** - Dodge moving obstacles
- **Win condition** - Collect all and reach exit
- **Lose condition** - Hit by enemy (bonus)

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Magnifying%20Glass%20Tilted%20Left.png" width="25"/> Testing & Validation

### Memory Testing

```bash
# Test with valgrind for memory leaks
valgrind --leak-check=full --show-leak-kinds=all ./so_long maps/map.ber

# Expected output: "All heap blocks were freed -- no leaks are possible"
```

### Map Testing

```bash
# Test invalid maps (should display error)
./so_long maps/invalid_no_exit.ber
./so_long maps/invalid_no_path.ber
./so_long maps/invalid_not_rectangular.ber
./so_long maps/invalid_no_walls.ber

# Test valid maps
./so_long maps/simple.ber      # Should load successfully
./so_long maps/complex.ber     # Should load successfully
```

### Edge Cases to Test

- ✅ Empty map file
- ✅ Map with wrong extension
- ✅ Map with no valid path
- ✅ Map with duplicate player/exit
- ✅ Non-rectangular maps
- ✅ Maps with invalid characters
- ✅ Very large maps (performance)
- ✅ Minimum valid map (3x3)

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Pushpin.png" width="25"/> Common Challenges & Solutions

<table>
<tr>
<td width="50%">

### ❌ Common Issues
- MiniLibX installation errors
- Image loading failures
- Memory leaks in rendering loop
- Flood fill not working correctly
- Window not responding to events
- Sprites not displaying properly

</td>
<td width="50%">

### ✅ Solutions
- Install X11 dev packages
- Check image paths and formats
- Free images before closing window
- Test flood fill separately
- Register events with mlx_hook
- Verify XPM file format

</td>
</tr>
</table>

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Light%20Bulb.png" width="25"/> MiniLibX Key Functions

### Essential Functions Used

```c
// Window management
mlx_init();                                    // Initialize MLX
mlx_new_window(mlx, width, height, "title");  // Create window
mlx_loop(mlx);                                 // Start event loop

// Image handling
mlx_xpm_file_to_image(mlx, path, &w, &h);    // Load sprite
mlx_put_image_to_window(mlx, win, img, x, y); // Display sprite
mlx_destroy_image(mlx, img);                   // Free image

// Events
mlx_hook(win, event, mask, function, data);    // Register event
mlx_loop_hook(mlx, function, data);            // Game loop

// Cleanup
mlx_destroy_window(mlx, win);                  // Close window
mlx_destroy_display(mlx);                      // Free MLX
```

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Memo.png" width="25"/> The Norm Compliance

This project strictly follows the 42 School Norm:
- ✅ Maximum 25 lines per function
- ✅ Maximum 80 columns per line
- ✅ Maximum 5 functions per file
- ✅ No forbidden keywords
- ✅ Proper variable declarations
- ✅ No global variables
- ✅ Clean and documented code

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Star-Struck.png" width="25"/> What's Next?

After mastering so_long, you'll be ready for:
- 🎮 **cub3d** - 3D raycasting engine (like Wolfenstein 3D)
- 🎨 **FdF** - 3D wireframe visualization
- 🖼️ **miniRT** - Raytracing engine
- 🎯 **fract-ol** - Fractal explorer

Graphics programming opens doors to game development, visualization, and computer graphics!

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Link.png" width="25"/> Resources

- [42 so_long Subject](https://cdn.intra.42.fr/pdf/pdf/123456/en.subject.pdf)
- [MiniLibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)
- [MiniLibX Tutorial](https://gontjarow.github.io/MiniLibX/)
- [Flood Fill Algorithm](https://en.wikipedia.org/wiki/Flood_fill)
- [XPM Image Format](http://www.xfree86.org/current/xpm.pdf)

---

## <img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Objects/Mobile%20Phone.png" width="25"/> Contact

**Bruno Gomes** - 42 Porto Student

[![Gmail](https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white)](mailto:brunodrcgomes@gmail.com)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/meetbrunogomes/)
[![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)](https://profile.intra.42.fr/users/bramalho)

---

<div align="center">

### 💡 Pro Tips from Development

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Nerd%20Face.png" width="20"/> **Start with map validation** - Get parsing right before graphics

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Food/Hot%20Beverage.png" width="20"/> **Test flood fill separately** - Debug path-finding before integration

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Star-Struck.png" width="20"/> **Use small sprites first** - 32x32 pixels to keep it simple

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Smiling%20Face%20with%20Sunglasses.png" width="20"/> **Free images before mlx** - Cleanup order matters!

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Smilies/Exploding%20Head.png" width="20"/> **Event handling is KEY** - mlx_hook() over mlx_key_hook()

</div>

---

<div align="center">

## 🎬 Game Screenshots

### Main Gameplay
*[Player navigating through the map collecting items]*

### Victory Screen
*[Celebration screen after collecting all items and reaching exit]*

### Game Over Screen
*[Enemy collision results in game over]*

---

### 🏆 Achievement Unlocked!

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Activities/Trophy.png" width="60"/>

**Game Developer - 125/125**

*"From zero to hero - built a complete 2D game engine from scratch!"*

**Key Achievements:**
- ✨ Sprite-based rendering system
- 🎯 Collision detection implementation
- 🗺️ Map validation with flood fill
- ⚔️ Enemy AI system (bonus)
- 🎬 Animated sprites
- 📊 Clean HUD implementation
- 💾 **ZERO memory leaks!**

</div>

---

<div align="center">

### 🎨 Technical Highlights

**Lines of Code:** ~1,200 well-structured lines  
**Development Time:** ~50 hours of coding  
**Sprites Created:** 20+ custom sprites  
**Maps Designed:** 5+ playable levels  
**Memory Leaks:** 0 (Valgrind certified!)  
**Norminette Errors:** 0 (100% compliant)

</div>

---

<div align="center">

### 🔥 Why This Project Matters

> **so_long is more than just a game** - it's your introduction to graphics programming, game architecture, and event-driven design. The skills learned here apply directly to game development, UI programming, and any application with visual interfaces.

**This project taught me:**
- 🎨 How graphics libraries work at a low level
- 🎮 Game loop architecture and design patterns
- 🧠 Algorithm implementation (flood fill, collision detection)
- 💾 Advanced memory management in graphical contexts
- 🏗️ Building modular, maintainable systems
- 🐛 Debugging complex interactive applications

</div>

---

<div align="center">

<br>

### 💻 Built with dedication at 42 School Porto

*Where pixels meet passion and code becomes interactive art!*

<br>

<img src="https://capsule-render.vercel.app/api?type=waving&color=gradient&height=100&section=footer"/>

</div>

---

<div align="center">

**Thanks for checking out so_long! Feel free to reach out if you want to discuss game development, graphics programming, or 42 projects!** 🚀

<img src="https://raw.githubusercontent.com/Tarikul-Islam-Anik/Animated-Fluent-Emojis/master/Emojis/Hand%20gestures/Waving%20Hand.png" width="40"/>

*"First solve the problem, then write the code... then make it look awesome!"*

</div>
