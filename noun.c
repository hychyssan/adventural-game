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
        //��ұ��ˡ��ǵģ���Ҳ��һ���ɼ������塣
        obj == player->location ||
        //��ҵĵ�ǰλ�á�
        obj->location == player ||
        //��ҳ��е���Ʒ
        obj->location == player->location ||
        //��ҵ�ǰλ�õ�����
        obj->location == NULL ||
        //��ҿ���ȥ������λ�ã����������ں���
        obj->location->location == player ||
        //��ҳ��е���һ�������ڵ�����
        obj->location->location == player->location))
        //��ǰλ�ô��ڵ���һ�������ڲ��Ķ���
    {
        printf("You don't see any %s here.\n", noun);
        obj = NULL;
    }
    return obj;
    //���ܵ�ע���ж�ΰ���˰�
}