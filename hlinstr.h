typedef enum{
    MOV,    // Mover robô
    REC,    // Recolher cristal
    DEP,    // Depositar cristal
    VER,    // Checar as vizinhanças
} High_instr;

typedef enum{
    N,  //(i-1,j)
    NE, //(i-1,j+1)
    SE, //(i,j+1)
    S,  //(i+1,j)
    SW, //(i+1,j-1)
    NW, //(i,j-1)
} Dir;