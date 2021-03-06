#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ChessStructures.h"

ChessMove * ChessMove_Initialize(void);
Boolean ChessMove_IsTransformation(ChessMove *);
ChessMove * ChessMove_Free(ChessMove *);
#endif