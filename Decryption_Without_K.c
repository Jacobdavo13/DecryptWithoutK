
#include <stdio.h>
int main()
{
    //char message[] = "IFZ HVZT J EFDJEFE UP USZ UIJT PVU"; //only works for I
    char message[] = "SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB"; //should only printf for A
    //char message2[] = "IFZ HVZT J EFDJEFE UP USZ UIJT PVU"; //only works for I
    char message2[] = "SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB"; //should only printf for A
    int key;
    int index;
    int Newindex;
    int Keyindex;
    for(index = 0; message[index] != 0; index++)
    {
        
        if(message[index] == 32)
        {
            Newindex = index + 2;
            Keyindex = index + 1;
            if(message[Newindex] == 32)
            {
                key = message[Keyindex] - 65;
                goto decrypt;
            }
        }
    }
    decrypt:
    {
     for(index = 0; message[index] !=0; index++) //for loop 
    {
        if(( message[index] < 65) || (message[index] > 90 && message[index] < 97) || (message[index] > 122)) //these inequalities are for punctuation and symbols and ensure that they are not changed
        {
            //do nothing to any punctuation  
        }
        else //if the characters are upper case letters this occurs
        {
            message[index] = ((message[index] - 65) - key + 26) % 26 + 65;   
        }
    }
printf("%s\n", message);
 for(index = 0; message[index] != 0; index++)
 {
     Newindex = index + 2;
     Keyindex = index + 1;
     if(message[index] == 32)
     {
     if(message[Newindex] == 32)
     {
     if(message[Keyindex] == 65)
     {
         //do nothing
     }
     else if(message[Keyindex] == 73)
     {
         
     }
     else
     {
      goto ReDecrypt;   
     }
 }

     }

 }
    }
goto PrintForA;
ReDecrypt:
{
    for(index = 0; message2[index] != 0; index++)
    {
        if(message2[index] == 32)
        {
            Newindex = index + 2;
            Keyindex = index + 1;
            if(message2[Newindex] == 32)
            {
                key = message2[Keyindex] - 73;
                goto decrypt2;
            }
        }
    }
}
    decrypt2:
    {
     for(index = 0; message2[index] !=0; index++) //for loop 
    {
        if(( message2[index] < 65) || (message2[index] > 90 && message2[index] < 97) || (message2[index] > 122)) //these inequalities are for punctuation and symbols and ensure that they are not changed
        {
            //do nothing to any punctuation  
        }
        else //if the characters are upper case letters this occurs
        {
            message2[index] = ((message2[index] - 65) - key + 26) % 26 + 65;   
        }
    }
   printf("Decrypted using I: %s\n", message2);
   
}
goto final;
PrintForA:
{
    printf("decrypted using A: %s\n", message);
    
}
final:
{
//nothing    
}
}

