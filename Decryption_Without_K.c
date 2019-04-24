#include <stdio.h>
int main()
{
    char message[] = "";
    int key;
    int index;
    int placeholder;
    int indexKey;
    for(index = 0; message[index] != 0; index++)
    {
        if(message[index] == 32)
        {
            int placeholder = message[index];
            index = index + 2;
            if(message[index] == 32)
            {
                index = index - 1;
                message[indexKey] = message[index];
                message[index] = 73;
                key = message[indexKey] - 73;
                goto Decrypt;
            }
        }
    }
    Decrypt:
    {
        for(index = 0; message[index] != 0; index++)
        {
            message[index] =  message[index] - key;
        }
    }
    printf("Message is:", message);
    return 0;
}

