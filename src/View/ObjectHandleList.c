
#include "ObjectHandleList.h"

ObjectHandleList * ObjectHandleList_Initialize(void){
	ObjectHandleList * ReturnPt = malloc(sizeof(ObjectHandleList));
	ReturnPt->FirstNode = NULL;
	ReturnPt->LastNode = NULL;
	return ReturnPt;
}

ObjectHandleList * ObjectHandleList_AppendObject(ObjectHandleList * List, ObjectHandle * Object){
	ObjectHandleNode * NewNode = malloc(sizeof(ObjectHandleNode));
	assert(NewNode);
	NewNode->Object = Object;
	NewNode->NextNode = NULL;
	/*NewNode->List = List;*/
	if (List->FirstNode){		
		List->LastNode->NextNode = NewNode;
		NewNode->PrevNode = List->LastNode;
		List->LastNode = NewNode;
	} else {
		/*empty list*/
		List->FirstNode = NewNode;
		List->LastNode = NewNode;
		NewNode->PrevNode = NULL;
		
	}
	return List;
#if 0
	ObjectHandleNode * NewNode = malloc(sizeof(ObjectHandleNode));
	assert(NewNode);
	NewNode->Object = Object;
	NewNode->NextNode = NULL;
	if (!List->FirstNode){
		List->FirstNode = NewNode;
		List->LastNode = NewNode;
		NewNode->PrevNode = NULL;		
	} else {
		List->LastNode->NextNode = NewNode;
		NewNode->PrevNode = List->LastNode;
		List->LastNode = NewNode;
	}
	return List;
#endif
}