#ifndef MODEL_H
#define MODEL_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


/*include headers inside Model directory*/
#include "ChessStructures.h"
#include "ChessBoard.h"
#include "ChessPlayer.h"
#include "ChessCoordinateList.h"
#include "ChessMoveList.h"
#include "ChessMove.h"
#include "ChessCoordinate.h"
#include "ArtificialIntelligence.h"

ChessBoard * Model_Initialize(void);

Boolean Model_CheckLegalMove(ChessBoard *, ChessMove *, ChessMoveList*);

ChessCoordinateList * Model_GetLegalCoordinates(ChessBoard *, ChessPiece *, ChessPlayer *, ChessMoveList *);

ChessCoordinateList * Model_GetAllLegalCoordinate( ChessBoard * board, ChessPlayer * player, ChessPlayer * PlayerInTurn, ChessMoveList *);

/* done, actually move the pieces to its destination */
ChessBoard * Model_PerformMove(ChessBoard *, ChessMoveList *, ChessMove *);

/*done,  undo a move */
ChessBoard * Model_UndoLastMove(ChessBoard *, ChessMoveList *);

/* undo exactly 1 move for ai purposes */
void Model_Undo1Move(ChessBoard * board, ChessMoveList * moveList);

/* check type of move */
ChessMoveTypeEnum Model_GetMoveType(ChessBoard * board, ChessMove *move);

/*check for stalemate position*/
Boolean Model_CheckStalemate(ChessBoard * board, ChessPlayer * player, ChessMoveList *);

/* almost done, If this chess player is checkmakte, return True*/
Boolean Model_CheckCheckmate(ChessBoard *, ChessPlayer *, ChessMoveList *);

/* done, If this chess player is in checked position and must get out, return True*/
Boolean Model_CheckCheckedPosition(ChessBoard *, ChessPlayer *, ChessMoveList *);

/* almost done */
Boolean Model_Stalemate(ChessBoard *, ChessPlayer *);

ChessMove * Model_GetBestMove(ChessBoard *, ChessPlayer *, ChessMoveList *);

ChessBoard * Model_duplicateChessBoard(ChessBoard *, ChessBoard *);

/* done, log file */
int writeToLogFile(char fname[100], ChessMoveList *);

void Model_CleanUp(ChessBoard *, ChessMoveList *);

void ModelSpeak(void);

#endif
