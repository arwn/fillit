# fillit
The goal of this project is to arrange every Tetriminos with each others in 
order to make the smallest possible square. But in some cases, this square 
should contains holes when some given pieces won’t fit in perfectly with 
others. Even if they are embedded in a 4x4 square, each Tetrimino is defined by 
its minimal boundaries (their ’#’). The 12 remaining empty characters will be 
ignored for the Tetriminos assemble process.

## build
`make fclean && make`
