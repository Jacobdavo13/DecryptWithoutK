
#include <stdio.h>
void DecMinusK(char message[]); //Function DecMinusK (Decryption for Rotation Without the Key)
int main()
{
    char message[] = "EJE ZPV FWFS IFBS UIF USBHFEZ PG EBSUI QMBHVFJT UIF XJTF? J UIPVHIU OPU. JU'T OPU B TUPSZ UIF KFEJ XPVME UFMM ZPV. JU'T B TJUI MFHFOE. EBSUI QMBHVFJT XBT B EBSL MPSE PG UIF TJUI, TP QPXFSGVM BOE TP XJTF IF DPVME VTF UIF GPSDF UP JOGMVFODF UIF NJEJDIMPSJBOT UP DSFBUF MJGF… IF IBE TVDI B LOPXMFEHF PG UIF EBSL TJEF UIBU IF DPVME FWFO LFFQ UIF POFT IF DBSFE BCPVU GSPN EZJOH. UIF EBSL TJEF PG UIF GPSDF JT B QBUIXBZ UP NBOZ BCJMJUJFT TPNF DPOTJEFS UP CF VOOBUVSBM. IF CFDBNF TP QPXFSGVM… UIF POMZ UIJOH IF XBT BGSBJE PG XBT MPTJOH IJT QPXFS, XIJDI FWFOUVBMMZ, PG DPVSTF, IF EJE. VOGPSUVOBUFMZ, IF UBVHIU IJT BQQSFOUJDF FWFSZUIJOH IF LOFX, UIFO IJT BQQSFOUJDF LJMMFE IJN JO IJT TMFFQ. JSPOJD. IF DPVME TBWF PUIFST GSPN EFBUI, CVU OPU IJNTFMG."; //only works for I
    //char message[] = "TVU TVAOTH : AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU."; // inputted message
    DecMinusK(message);
}

void DecMinusK(char message[])
{
    char message2[1028]; //message2 used if original decryption is incorrect. It saves the original encrypted message so it can be decrypted a second time
    int key; //interger used to determine the key of the rotation
    int index; //pointer
    int Newindex;
    int Keyindex;
    for(index = 0; message[index] !=0; index++)//sets up loop that runs through every element of the array
    {
        message2[index] = message[index]; //sets every element of message2 to the same as message 
    }
    for(index = 0; message[index] != 0; index++) //loops through message
    {
        if(message[index] == 32) //if message[index] is a space character(ASCII value for *space* is 32)
        {
            Newindex = index + 2; //an index that is two places ahead of the present index
            Keyindex = index + 1; //index one place ahead of present index   
            if(message[Newindex] == 32) //if the element 2 spaces ahead of the present index is also a space this means it is a one letter word (either A or I)
            {
                if((message[Keyindex] < 65) || (message[Keyindex] > 90 && message[Keyindex] < 97) || (message[Keyindex] > 122)) //if the one letter is not a letter but a symbol it is not decrypted 
                {
                    //do nothing for symbols
                }
                else //if the lone character is a letter
                {
                    key = message[Keyindex] - 65; //uses this one letter word -65 to determine the places that the letter has been rotated from A (if this letter is found to be I it is corrected later)
                    goto decrypt; //moves to the function decrypt and exits loop 
                }
            }
        }
    }
    decrypt: 
    {
        for(index = 0; message[index] !=0; index++) //for loop that rotates through the message again
        {
            if(( message[index] < 65) || (message[index] > 90 && message[index] < 97) || (message[index] > 122)) //these inequalities are for punctuation and symbols and ensure that they are not changed
            {
                //do nothing to any punctuation  
            }
            else //if the characters are upper case letters this occurs
            {
                message[index] = ((message[index] - 65) - key + 26) % 26 + 65;  //decrypts all letters for the new key and turns them back into their original letters (only if first single letter word detected was A) 
            }
        }
        
        for(index = 0; message[index] != 0; index++)
        {
            Newindex = index + 2; 
            Keyindex = index + 1;
            if(message[index] == 32 && message[Newindex] == 32) //if the present index and the index 2 ahead are spaces then it is a one letter word
            {
                if((message[Keyindex] < 65) || (message[Keyindex] > 90 && message[Keyindex] < 97) || (message[Keyindex] > 122)) //if the one letter is not a letter but a symbol it is not further decrypted 
                {
                    //do nothing
                }
                
                else if(message[Keyindex] == 65 || message[Keyindex] == 73) 
                {
                    // do nothing
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
            Newindex = index + 2;
            Keyindex = index + 1;
            if(message2[index] == 32 && message2[Newindex] == 32)
            {
                key = message2[Keyindex] - 73;
                goto decrypt2;
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

