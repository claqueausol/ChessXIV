#include "Model.h"

#define TEST_COORDINATE_LIST  
/*#define TEST_MOVE_LIST*/

int main(void){
	ChessBoard * MainBoard = ChessBoard_InitializeEmpty();
	int i;
#ifdef TEST_COORDINATE_LIST  
	ChessCoordinateList * MainList = ChessCoordinateList_Initialize();
	ChessCoordinateList * SupportList = ChessCoordinateList_Initialize();
	
	
	
	for (i = 0; i < 8; i++){
		MainList = ChessCoordinateList_AppendCoord(MainList, MainBoard->Board[i][7-i]);
	}
	
	for (i = 0; i < 8; i++){
		SupportList = ChessCoordinateList_AppendCoord(SupportList, MainBoard->Board[i][i]);
	}
	
	MainList = ChessCoordinateList_AppendNoRedundancy(MainList, SupportList);
	
	for (i = 0; i < 5; i++) ChessCoordinateList_RemoveAtNode(MainList, MainList->FirstNode->NextNode);
	while (MainList->LastNode) ChessCoordinateList_RemoveAtNode(MainList, MainList->FirstNode);
	
	ChessCoordinateList_Free(MainList);
	
#endif

#ifdef TEST_MOVE_LIST
	ChessMoveList * MoveList = ChessMoveList_Initialize();
	ChessMove * NewMove;
	/*append*/
	for (i = 0; i < 8; i++){
		NewMove = malloc(sizeof(ChessMove));
		NewMove->MovePiece = MainBoard->BlackPlayer->Pieces[15-i];
		NewMove->StartPosition = MainBoard->Board[i][7-i];
		NewMove->NextPosition = MainBoard->Board[7-i][i];
		ChessMoveList_AppendMove(MoveList, NewMove);		
	}
	
	/*pop*/
	for (i = 0; i < 5; i++){
		ChessMoveList_PopLastMove(MoveList);
	}
	
	ChessMoveNode * MoveNode = MoveList->FirstNode;
	
	
	ChessMoveList_Free(MoveList);
#endif
	ChessBoard_Free(MainBoard);
  return 0;
}