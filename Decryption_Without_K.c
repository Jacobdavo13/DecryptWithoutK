
#include <stdio.h>
void DecMinusK(char message[]); //Function DecMinusK (Decryption for Rotation Without the Key)
int main()
{
    char message[] = "TVU TVAOTH: AOL KHAH IYVBNOA AV BZ IF AOL IVAOHU ZWPLZ WPUWVPUAZ AOL LEHJA SVJHAPVU VM AOL LTWLYVY'Z ULD IHAASL ZAHAPVU. DL HSZV RUVD AOHA AOL DLHWVU ZFZALTZ VM AOPZ KLHAO ZAHY HYL UVA FLA VWLYHAPVUHS. DPAO AOL PTWLYPHS MSLLA ZWYLHK AOYVBNOVBA AOL NHSHEF PU H CHPU LMMVYA AV LUNHNL BZ, PA PZ YLSHAPCLSF BUWYVALJALK. IBA TVZA PTWVYAHUA VM HSS, DL'CL SLHYULK AOHA AOL LTWLYVY OPTZLSM PZ WLYZVUHSSF VCLYZLLPUN AOL MPUHS ZAHNLZ VM AOL JVUZAYBJAPVU VM AOPZ KLHAO ZAHY. THUF IVAOHUZ KPLK AV IYPUN BZ AOPZ PUMVYTHAPVU.";
    //char message[] ="SJSFMPCRM WG O USBWIG. PIH WT MCI XIRUS O TWGV PM WHG OPWZWHM HC QZWAP O HFSS, WH KWZZ ZWJS WHG KVCZS ZWTS PSZWSJWBU HVOH WH WG GHIDWR. - OZPSFH SWBGHSWB";
    //char message[] = "FKF AQW GXGT JGCT VJG VTCIGFA QH FCTVJ RNCIWGKU VJG YKUG? K VJQWIJV PQV. KV'U PQV C UVQTA VJG LGFK YQWNF VGNN AQW. KV'U C UKVJ NGIGPF. FCTVJ RNCIWGKU YCU C FCTM NQTF QH VJG UKVJ, UQ RQYGTHWN CPF UQ YKUG JG EQWNF WUG VJG HQTEG VQ KPHNWGPEG VJG OKFKEJNQTKCPU VQ ETGCVG NKHG… JG JCF UWEJ C MPQYNGFIG QH VJG FCTM UKFG VJCV JG EQWNF GXGP MGGR VJG QPGU JG ECTGF CDQWV HTQO FAKPI. VJG FCTM UKFG QH VJG HQTEG KU C RCVJYCA VQ OCPA CDKNKVKGU UQOG EQPUKFGT VQ DG WPPCVWTCN. JG DGECOG UQ RQYGTHWN… VJG QPNA VJKPI JG YCU CHTCKF QH YCU NQUKPI JKU RQYGT, YJKEJ GXGPVWCNNA, QH EQWTUG, JG FKF. WPHQTVWPCVGNA, JG VCWIJV JKU CRRTGPVKEG GXGTAVJKPI JG MPGY, VJGP JKU CRRTGPVKEG MKNNGF JKO KP JKU UNGGR. KTQPKE. JG EQWNF UCXG QVJGTU HTQO FGCVJ, DWV PQV JKOUGNH."; 
 DecMinusK(message);
}

void DecMinusK(char message[])
{
    char message2[1028]; //message2 used if original decryption is incorrect. It saves the original encrypted message so it can be decrypted a second time
    int key; //interger used to determine the key of the rotation
    int index; //pointer
    int Newindex; //index that is used to determine the character two spaces ahead of the index
    int Keyindex; //index that is used to determine the character one space ahead of the index
    for(index = 0; message[index] != 0; index++) //starts a for loop that declares index as 0 and if message[index] does not equal 0 it will continue to loop
    //When it reaches the end of the loop it repeats and increases the index. This will stop once the index reaches the end of the array.
    {
        if(message[index] >= 97 && message[index] <= 122) //checks to see if any characters used are lower case letters.
        {
            message[index] = message[index] - 32; //if they are lower case letters -32 turns them into upper case (as seen on ASCII table)
        }
    }
    for(index = 0; message[index] !=0; index++)//sets up loop that runs through every element of the array
    {
        message2[index] = message[index]; //sets every element of message2 to the same as message inputted
    }
    for(index = 0; message[index] != 0; index++) //loops through message
    {
        if(message[index] == 32) //if message[index] is a space character(ASCII value for *space* is 32)
        {
            Newindex = index + 2; //an index that is two places ahead of the present index
            Keyindex = index + 1; //index one place ahead of present index   
            if(message[Newindex] == 32) //if the element 2 spaces ahead of the present index is also a space this means it is a one letter word (either A or I)
            {
                if((message[Keyindex] < 65) || (message[Keyindex] > 90 && message[Keyindex] < 97) || (message[Keyindex] > 122)) //if the one letter is not a letter but a symbol the key is not determined from this 
                {
                    //do nothing for symbols
                }
                else //if the lone character is a letter
                {
                    key = message[Keyindex] - 65; //uses this one letter word minus 65 to determine the places that the letter has been rotated from A (if this letter is found to be I it is corrected later)
                    goto decrypt; //jumps to the decrypt statement and thus exits loop 
                }
            }
        }
    }
    decrypt: //placeholder that the goto statment jumps to
    {
        for(index = 0; message[index] !=0; index++) //for loop that rotates through the message
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
        
        for(index = 0; message[index] != 0; index++) //this is another for loop cycling through the message to detect if decryption has happened correctly, if it decrypted correctly every single letter word will be either A or I
        {
            Newindex = index + 2; 
            Keyindex = index + 1;
            if(message[index] == 32 && message[Newindex] == 32) //if the present index and the index 2 ahead are spaces then it is a one letter word
            {
                if((message[Keyindex] < 65) || (message[Keyindex] > 90 && message[Keyindex] < 97) || (message[Keyindex] > 122)) //if the one letter is not a letter but a symbol it is not further decrypted 
                {
                    //do nothing
                }
                
                else if(message[Keyindex] == 65 || message[Keyindex] == 73) //if the one letter word is either A(65) or I(73) than it does not need to be corrected as decryption was sucessful
                {
                    // do nothing
                }
                else //if the one letter word was not A or I then the fist detected one letter word was not A but I and the message will be decrypted again correctly instead
                {
                    goto ReDecrypt; //goes to the statement that will redecrypt using I to find the key instead of A
                }
            }

        } //end of for loop
    } //end of decrypt section
    goto PrintForA; //if the message was correctly decrypted, this occurs. This moves to a position such that the code below this does not occur to redecrypt for I and rather it prints the decrypted message
    ReDecrypt: //redecrypt that occurs if decryption using A failed
    {
        for(index = 0; message2[index] != 0; index++) //loops through message
        {
            if(message2[index] == 32) //if message[index] is a space character(ASCII value for *space* is 32)
            {
                Newindex = index + 2; //an index that is two places ahead of the present index
                Keyindex = index + 1; //index one place ahead of present index   
                if(message2[Newindex] == 32) //if the element 2 spaces ahead of the present index is also a space this means it is a one letter word (either A or I)
                {
                    if((message2[Keyindex] < 65) || (message2[Keyindex] > 90 && message2[Keyindex] < 97) || (message2[Keyindex] > 122)) //if the one letter is not a letter but a symbol the key is not determined from this 
                    {
                        //do nothing for symbols
                    }
                    else //if the lone character is a letter
                    {
                        key = message2[Keyindex] - 73; //uses this one letter word minus 73 to determine the places that the letter has been rotated from I and not A
                        goto decrypt2; //jumps to the decrypt2 statement and thus exits loop 
                    }
                }
            }
        }
    } //end of redecrypt 
    decrypt2: //placeholder used to jump out of for and if loops and decrypt for I
    {
        for(index = 0; message2[index] !=0; index++) //for loop cycles through message2 (which is the original message)
        {
            if(( message2[index] < 65) || (message2[index] > 90 && message2[index] < 97) || (message2[index] > 122)) //these inequalities are for punctuation and symbols and ensure that they are not changed
            {
                //do nothing to any punctuation  
            }
            else //if the characters are upper case letters this occurs
            {
                message2[index] = ((message2[index] - 65) - key + 26) % 26 + 65; //decrypts using the determined key and changes every letter back to its original value 
            }
        }
        printf("Decrypted using I: %s\n", message2); //occurs if redecrypted for I. Message2 gets printed
    }
    goto final; //skips over the PrintForA statement as it was incorrect decryption. Jumps over it to the end so that it does not occur
    PrintForA: //occurs if decryption for A was correct and prints the decrypted message
    {
        printf("decrypted using A: %s\n", message); //prints decrypted message
    }
    final: //used to skip over PrintForA if decryption using A was incorrect. Does nothing
    {
        //nothing    
    }
}