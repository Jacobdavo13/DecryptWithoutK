
#include <stdio.h>
int main()
{
    char message[] = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU. ";
    char message2[] = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU.";
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

 for(index = 0; message[index] != 0; index++)
 {
     Newindex = index + 2;
     Keyindex = index + 1;
     if(message[index] == 32 && message[Newindex] == 32)
     {
     if(message[Keyindex] == 65 || message[Keyindex] == 73)
     {
      //do nothing   
     }
     else
     {
      goto ReDecrypt;   
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
                key = message2[Keyindex] - 65;
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
   printf("printed %s\n", message2);
   goto final;
}
PrintForA:
{
    printf("decrypted: %s\n", message);
    
}
final:
{
    
}
}