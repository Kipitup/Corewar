# Corewar

*The Corewar project is the final exercice from the Algorithm branch at 42.
Core War is a programming game in which several programs battle for domination in a virtual computer using a limited set of instructions.
Students must build the arena, develop a champion and an interpreter to convert it into a binary.
This project is relatively straight-forward but requires a complete reading of the documentation and a precise implementation.*


Subject: [English](https://cdn.intra.42.fr/pdf/pdf/6250/corewar.fr.pdf)

#### Objectives:
- Compilation   
- Simplistic virtual machine  
- Simplistic assembly type language - Lexer / Parser
- Visual render in C via SDL2

#### Skills:
- Reverse engineering
- Organization and team work
- Algorithms & AI

#### Developed for Linux type distributions.  

## How to use

#### Pre required: Make, GCC. Optionally SDL2 for the visual.

We provided a shell script to install the SDL depencies.
```
sh virtual_machine/visualizator/sdl2_dependencies.sh
```

First of all, open a terminal, go into the project and build it:   
```  
make -j8
```

### Input

To start a game you need at least a compiled champion file (.cor), you can create one from a redcode assembly file (.s) with the compiler:
```  
./asm champion.s
```
Valid exemples .s files are given into the exemples_s folder.  

Once you have your champion, you can make him play alone or compete with a maximum of 3 other champions (maximum number of players along many other variables can be changed inside op.h).
```  
./corewar champion.cor other_champion.cor
```
You can also use a few options:

• -n followed by a number to set the number of the next player. 
This number impacts the turn order (biggest to smallest):
```  
./corewar a.cor -n 3 b.cor c.cor
```
Here 'a' will be set to 1, 'b' to 3 and 'c' to 2, 'b' will play first then 'c', then 'b' (consult the subject for more informations).  

• -dump32 or -dump64 followed by a number to stop the game at the beginning of the given cycle and print out the memory in hexadecimal (0 being the first cycle).
The suffix 32 or 64 is just for the number of character display on each line
```  
./corewar champion.cor -dump64 42
```
• -visu to activate the visualizer:
```  
./corewar champion.cor -visu
```

### Output

Hard to understand what happened without the visualizer or the dump option, here are how they render:

#### Visualizer (-visu):


#### Dump option (-dump64):

