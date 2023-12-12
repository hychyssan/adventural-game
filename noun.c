#define _CRT_SECURE_NO_WARNINGS

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "object.h"

static bool objectHasTag(OBJECT* obj, const char* noun)
{
    return noun != NULL && *noun != '\0' && strcmp(noun, obj->tag) == 0;
}

static OBJECT* getObject(const char* noun)
{
    OBJECT* obj, * res = NULL;
    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (objectHasTag(obj, noun))
        {
            res = obj;
        }
    }
    return res;
}

OBJECT* getVisible(const char* intention, const char* noun)
{
    OBJECT* obj = getObject(noun);
    if (obj == NULL)
    {
        printf("I don't understand %s.\n", intention);
    }
    else if (!(obj == player ||
        //玩家本人。是的，这也是一个可见的物体。
        obj == player->location ||
        //玩家的当前位置。
        obj->location == player ||
        //玩家持有的物品
        obj->location == player->location ||
        //玩家当前位置的物体
        obj->location == NULL ||
        //玩家可以去的任意位置，具体完善在后面
        obj->location->location == player ||
        //玩家持有的另一个物体内的物体
        obj->location->location == player->location))
        //当前位置存在的另一个对象内部的对象
    {
        printf("You don't see any %s here.\n", noun);
        obj = NULL;
    }
    return obj;
    //感受到注释有多伟大了吧
}