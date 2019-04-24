#include <stdio.h>
int main()
{
    char message[] = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU. ";
    //char message2[] = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU.";
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
    
 
        }
        printf("Message is: %s\n", message);
        return 0;
  

}
/* void DecK(char message[], int key) 
{
    printf("Inputted message was: %s\n", message);
    if(key>26) //used if key is too large which will create ASCII charaters that are not letters
    //Example if key = 100 and message[index] = 65 (equation below), 65 - 65 = 0, 0 - 100 + 26 = -74, -74 % 26 = -22, -22 + 65 = 43 which is not an upper case ASCII charater 
    {
        key = key % 26; //key by %26 makes sure the value of key is changed to the remainder of key/26 which is between 0 to 25.
    }
    int index; //declares a pointer to be used later
    for(index = 0; message[index] != 0; index++) //sets up a for loop to run through every character in the array
    {
        if(message[index] >= 97 && message[index] <= 122) //if statement determines if letters are lower case
        {
            message[index] = message[index] - 32; // if letters are lower case -32 changes them to upper case
        }
    }
    for(index = 0; message[index] !=0; index++) //for loop 
    {
        if(( message[index] < 65) || (message[index] > 90 && message[index] < 97) || (message[index] > 122)) //these inequalities are for punctuation and symbols and ensure that they are not changed
        {
            //do nothing to any punctuation  
        }
        else //if the characters are upper case letters this occurs
        {
            message[index] = ((message[index] - 65) - key + 26) % 26 + 65; //turning the ASCII character to a number between 0 and 25 through -65 and then taking away the key to move the letter back to where it was before it was encrypted
//+26 was done to ensure that when key is taken away from the value it still produces a value that is postive and can be used by the function
//modulus 26 makes produces the remainder of the created value divided by 26 and 65 is added to produce a the decrypted ASCII value
        }
         
    }

*/