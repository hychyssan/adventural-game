#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "object.h"

int listObjectsAtLocation(OBJECT* location)
{
    int count = 0;
    OBJECT* obj;
    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (obj != player && obj->location == location)
            //排除玩家在玩家的位置这种蠢东西
        {
            if (count++ == 0)
                //我们需要保证找到一个东西之前他不会打印 you see
            {
                printf("You see:\n");
            }
            printf("%s\n", obj->description);
        }
    }
    return count;
    //返回的是数目的数量，下一章对此做额外操作
}