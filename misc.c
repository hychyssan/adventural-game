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
            //�ų��������ҵ�λ�����ִ�����
        {
            if (count++ == 0)
                //������Ҫ��֤�ҵ�һ������֮ǰ�������ӡ you see
            {
                printf("You see:\n");
            }
            printf("%s\n", obj->description);
        }
    }
    return count;
    //���ص�����Ŀ����������һ�¶Դ����������
}