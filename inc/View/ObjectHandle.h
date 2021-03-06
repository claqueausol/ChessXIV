#ifndef OBJECT_HANDLE_H
#define OBJECT_HANDLE_H

#include "View.h"

ObjectHandle * ObjectHandle_Initialize(ObjectType type, ObjectTagEnum TagIn, int x, int y, int width, int height);
void ObjectHandle_Render(ViewHandle * MainHandle, ObjectHandle * Handle);
ObjectHandle * ObjectHandle_Free(ObjectHandle * Handle);

ObjectHandle * GetObjectByTag(ViewHandle * MainHandle, ObjectTagEnum Tag);
ObjectHandleList * GetObjectByCoordinate(ViewHandle * MainHandle, int x, int y);
ObjectHandle * GetGUICoordinate(ViewHandle * MainHandle, int x, int y);

Event GetSDLEvent(ViewHandle *);


#endif
