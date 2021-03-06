#include "ChessBoard.h"


ChessBoard * ChessBoard_Initialize(void){
	
	/*malloc the board*/
	ChessBoard * ChessBoardToReturn = (ChessBoard *) malloc(sizeof(ChessBoard));
	assert(ChessBoardToReturn);
  
	/*malloc two players*/
	ChessBoardToReturn->WhitePlayer = (ChessPlayer *) malloc(sizeof(ChessPlayer));
	ChessBoardToReturn->BlackPlayer = (ChessPlayer *) malloc(sizeof(ChessPlayer));
	assert(ChessBoardToReturn->WhitePlayer && ChessBoardToReturn->BlackPlayer);
	ChessBoardToReturn->WhitePlayer->PlayerColor = White;
	ChessBoardToReturn->BlackPlayer->PlayerColor = Black;
	ChessBoardToReturn->WhitePlayer->OtherPlayer = ChessBoardToReturn->BlackPlayer;
	ChessBoardToReturn->BlackPlayer->OtherPlayer = ChessBoardToReturn->WhitePlayer;
	ChessBoardToReturn->WhitePlayer->ElapsedTime = 0;
	ChessBoardToReturn->BlackPlayer->ElapsedTime = 0;
	
	/*malloc all coordinate on the board*/
	int i,j;
	for (i = 0; i < CHESS_BOARD_MAX_ROW; i++){
		for (j = 0; j < CHESS_BOARD_MAX_COL; j++){
			ChessBoardToReturn->Board[i][j]	= (ChessCoordinate *) malloc(sizeof(ChessCoordinate));
			assert(ChessBoardToReturn->Board[i][j]);
			ChessBoardToReturn->Board[i][j]->Piece = NULL;
			ChessBoardToReturn->Board[i][j]->Rank = i;
			ChessBoardToReturn->Board[i][j]->File = j;
			ChessBoardToReturn->Board[i][j]->MainBoard = ChessBoardToReturn;
		}
	}
	
	/*malloc each piece and assign all double links*/
	/*White first*/
	/*Pawns x 8*/
	ChessPiece * CurrPiece;
	int CurrPieceIdx = 0;
	for (i = 0; i < 8; i++){
		CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
		assert(CurrPiece);
		CurrPiece->Type = Pawn;
		CurrPiece->Index = i;
		CurrPiece->PieceValue = 1; /*for ai*/
		CurrPiece->Player = ChessBoardToReturn->WhitePlayer;
		CurrPiece->Coordinate = ChessBoardToReturn->Board[1][i];
		CurrPiece->AliveFlag = True;
		CurrPiece->MoveFirstFlag = 0;
		ChessBoardToReturn->WhitePlayer->Pieces[CurrPieceIdx++] = CurrPiece;
		ChessBoardToReturn->Board[1][i]->Piece = CurrPiece;
	}
	
	/*Rook x 2*/
	for (i = 0; i < 2; i++){
		CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
		assert(CurrPiece);
		CurrPiece->Type = Rook;
		CurrPiece->Index = i;
		CurrPiece->PieceValue = 5; /* for ai */
		CurrPiece->Player = ChessBoardToReturn->WhitePlayer;
		CurrPiece->Coordinate = ChessBoardToReturn->Board[0][7*i];
		CurrPiece->AliveFlag = True;
		CurrPiece->MoveFirstFlag = 0;
		ChessBoardToReturn->WhitePlayer->Pieces[CurrPieceIdx++] = CurrPiece;
		ChessBoardToReturn->Board[0][7*i]->Piece = CurrPiece;
	}
	
	/*Knight x 2*/
	for (i = 0; i < 2; i++){
		CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
		assert(CurrPiece);
		CurrPiece->Type = Knight;
		CurrPiece->Index = i;
		CurrPiece->PieceValue = 3; /* for ai */
		CurrPiece->Player = ChessBoardToReturn->WhitePlayer;
		CurrPiece->Coordinate = ChessBoardToReturn->Board[0][1+5*i];
		CurrPiece->AliveFlag = True;
		CurrPiece->MoveFirstFlag = 0;
		ChessBoardToReturn->WhitePlayer->Pieces[CurrPieceIdx++] = CurrPiece;
		ChessBoardToReturn->Board[0][1+5*i]->Piece = CurrPiece;
	}
	
	/*Bishop x 2*/
	for (i = 0; i < 2; i++){
		CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
		assert(CurrPiece);
		CurrPiece->Type = Bishop;
		CurrPiece->Index = i;
		CurrPiece->PieceValue = 3; /* for ai */
		CurrPiece->Player = ChessBoardToReturn->WhitePlayer;
		CurrPiece->Coordinate = ChessBoardToReturn->Board[0][2+3*i];
		CurrPiece->AliveFlag = True;
		CurrPiece->MoveFirstFlag = 0;
		ChessBoardToReturn->WhitePlayer->Pieces[CurrPieceIdx++] = CurrPiece;
		ChessBoardToReturn->Board[0][2+3*i]->Piece = CurrPiece;
	}
	
	/*Queen x 1*/
	CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
	assert(CurrPiece);
	CurrPiece->Type = Queen;
	CurrPiece->Index = 0;
	CurrPiece->PieceValue = 9;
	CurrPiece->Player = ChessBoardToReturn->WhitePlayer;
	CurrPiece->Coordinate = ChessBoardToReturn->Board[0][3];
	CurrPiece->AliveFlag = True;
	CurrPiece->MoveFirstFlag = 0;
	ChessBoardToReturn->WhitePlayer->Pieces[CurrPieceIdx++] = CurrPiece;
	ChessBoardToReturn->Board[0][3]->Piece = CurrPiece;
	
	/*King x 1*/
	CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
	assert(CurrPiece);
	CurrPiece->Type = King;
	CurrPiece->Index = 0;
	CurrPiece->Player = ChessBoardToReturn->WhitePlayer;
	CurrPiece->Coordinate = ChessBoardToReturn->Board[0][4];
	CurrPiece->AliveFlag = True;
	CurrPiece->MoveFirstFlag = 0;
	ChessBoardToReturn->WhitePlayer->Pieces[CurrPieceIdx++] = CurrPiece;
	ChessBoardToReturn->Board[0][4]->Piece = CurrPiece;
	
	
	/*Then black*/
	/*Pawns x 8*/
	CurrPieceIdx = 0;
	for (i = 0; i < 8; i++){
		CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
		assert(CurrPiece);
		CurrPiece->Type = Pawn;
		CurrPiece->Index = i;
		CurrPiece->PieceValue = 1;
		CurrPiece->Player = ChessBoardToReturn->BlackPlayer;
		CurrPiece->Coordinate = ChessBoardToReturn->Board[6][i];
		CurrPiece->AliveFlag = True;
		CurrPiece->MoveFirstFlag = 0;
		ChessBoardToReturn->BlackPlayer->Pieces[CurrPieceIdx++] = CurrPiece;
		ChessBoardToReturn->Board[6][i]->Piece = CurrPiece;
	}
	
	/*Rook x 2*/
	for (i = 0; i < 2; i++){
		CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
		assert(CurrPiece);
		CurrPiece->Type = Rook;
		CurrPiece->Index = i;
		CurrPiece->PieceValue = 5; /* for ai */
		CurrPiece->Player = ChessBoardToReturn->BlackPlayer;
		CurrPiece->Coordinate = ChessBoardToReturn->Board[7][7*i];
		CurrPiece->AliveFlag = True;
		CurrPiece->MoveFirstFlag = 0;
		ChessBoardToReturn->BlackPlayer->Pieces[CurrPieceIdx++] = CurrPiece;
		ChessBoardToReturn->Board[7][7*i]->Piece = CurrPiece;
	}
	
	/*Knight x 2*/
	for (i = 0; i < 2; i++){
		CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
		assert(CurrPiece);
		CurrPiece->Type = Knight;
		CurrPiece->Index = i;
		CurrPiece->PieceValue = 3; /* for ai*/
		CurrPiece->Player = ChessBoardToReturn->BlackPlayer;
		CurrPiece->Coordinate = ChessBoardToReturn->Board[7][1+5*i];
		CurrPiece->AliveFlag = True;
		ChessBoardToReturn->BlackPlayer->Pieces[CurrPieceIdx++] = CurrPiece;
		ChessBoardToReturn->Board[7][1+5*i]->Piece = CurrPiece;
	}
	
	/*Bishop x 2*/
	for (i = 0; i < 2; i++){
		CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
		assert(CurrPiece);
		CurrPiece->Type = Bishop;
		CurrPiece->Index = i;
		CurrPiece->PieceValue = 3; /* for ai */
		CurrPiece->Player = ChessBoardToReturn->BlackPlayer;
		CurrPiece->Coordinate = ChessBoardToReturn->Board[7][2+3*i];
		CurrPiece->AliveFlag = True;
		CurrPiece->MoveFirstFlag = 0;
		ChessBoardToReturn->BlackPlayer->Pieces[CurrPieceIdx++] = CurrPiece;
		ChessBoardToReturn->Board[7][2+3*i]->Piece = CurrPiece;
	}
	
	/*Queen x 1*/
	CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
	assert(CurrPiece);
	CurrPiece->Type = Queen;
	CurrPiece->Index = 0;
	CurrPiece->PieceValue = 9; /* for ai */
	CurrPiece->Player = ChessBoardToReturn->BlackPlayer;
	CurrPiece->Coordinate = ChessBoardToReturn->Board[7][3];
	CurrPiece->AliveFlag = True;
	CurrPiece->MoveFirstFlag = 0;
	ChessBoardToReturn->BlackPlayer->Pieces[CurrPieceIdx++] = CurrPiece;
	ChessBoardToReturn->Board[7][3]->Piece = CurrPiece;
	
	/*King x 1*/
	CurrPiece = (ChessPiece *) malloc(sizeof(ChessPiece));
	assert(CurrPiece);
	CurrPiece->Type = King;
	CurrPiece->Index = 0;
	CurrPiece->Player = ChessBoardToReturn->BlackPlayer;
	CurrPiece->Coordinate = ChessBoardToReturn->Board[7][4];
	CurrPiece->AliveFlag = True;
	CurrPiece->MoveFirstFlag = 0;
	ChessBoardToReturn->BlackPlayer->Pieces[CurrPieceIdx++] = CurrPiece;
	ChessBoardToReturn->Board[7][4]->Piece = CurrPiece;
  return ChessBoardToReturn;
}

ChessBoard * ChessBoard_InitializeEmpty(void){
	
	/*malloc the board*/
	ChessBoard * ChessBoardToReturn =  ChessBoard_Initialize();
	
	/*break the link between pieces and coordinates*/
	int i,j;
	for (i = 0; i < 16; i++){
		ChessBoardToReturn->BlackPlayer->Pieces[i]->Coordinate = NULL;
		ChessBoardToReturn->BlackPlayer->Pieces[i]->AliveFlag = False;
		ChessBoardToReturn->WhitePlayer->Pieces[i]->Coordinate = NULL;
		ChessBoardToReturn->WhitePlayer->Pieces[i]->AliveFlag = False;
	}
	
	for (i = 0; i < 8; i++)
		for (j = 0; j < 8; j++)
		ChessBoardToReturn->Board[i][j]->Piece = NULL;
	
	return ChessBoardToReturn;
	
}

void ChessBoard_Free(ChessBoard * CurrBoard){
	int i,j;
	/*free coordinate*/
	for (i = 0; i < CHESS_BOARD_MAX_ROW ; i++){
		for (j = 0; j < CHESS_BOARD_MAX_COL; j++){			
			free(CurrBoard->Board[i][j]);
		}
	}
	
	/*free the pieces*/
	for (i = 0; i < 16; i++) {
		free(CurrBoard->WhitePlayer->Pieces[i]);
		free(CurrBoard->BlackPlayer->Pieces[i]);
	}
	
	/*free the player*/
	free(CurrBoard->WhitePlayer);
	free(CurrBoard->BlackPlayer);
	
	/*free the board*/
	free(CurrBoard);
}


int ChessBoard_CountCapturePiece(ChessBoard * CurrBoard, PlayerColorEnum Color, ChessPieceTypeEnum Type){
	ChessPlayer * CurrentPlayer;
	switch (Color){
		case White:
			CurrentPlayer = CurrBoard->WhitePlayer;
			break;
		case Black:
			CurrentPlayer = CurrBoard->BlackPlayer;
			break;
	}
	
	int i, count = 0;
	for (i = 0; i < 16; i++){
		if (!(CurrentPlayer->Pieces[i]->AliveFlag) && CurrentPlayer->Pieces[i]->Type == Type)
			count++;
		
	}
	return count;
}
