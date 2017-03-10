// DES Encryption Assignment
// raf22hack

#define _XOPEN_SOURCE

#include <stdio.h>
#include <cs50.h>
#include <string.h>
// #include <ctype.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    
    char *hash = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int key_lenght = strlen(hash);
    
    // ///////       STEP 1: Let's make sure we got our hash      //////
    
    if (argc < 2)
    {
        printf("Try passing a hash next time.\n");
        return 1;
    } 
    else if (argc > 2)
    {
        printf("You've passed one too many arguments!\n");
        return 1;
    }
    
    // ///////       STEP 2: Let's setup our code               //////
    
    string pass;
    string salt = "50";
    
    char lvl1[2] = {0, '\0'};
    char lvl2[3] = {0, 0, '\0'};
    char lvl3[4] = {0, 0, 0, '\0'};
    char lvl4[5] = {0, 0, 0, 0, '\0'};
    
    ///////          L E V E L    ----     1    ------         ///////
    
    for(int i = 0; i < key_lenght; i++) 
    {
        lvl1[0] = hash[i];
        pass = crypt(lvl1, salt);
        
        // Print the key back to the user.
        if(strcmp(argv[1], pass) == 0) 
        {
            printf("%s\n", lvl1);
            return 0;
        }
    }
    
    ///////          L E V E L    ----     2    ------         ///////
    
    for(int i = 0; i < key_lenght; i++) 
    { 
        lvl2[0] = hash[i];
        for(int j = 0; j < key_lenght; j++) 
        {
            lvl2[1] = hash[j];
            pass = crypt(lvl2, salt);
            
            // Print the key back to the user.
            if(strcmp(argv[1], pass) == 0) 
            {
                printf("%s\n", lvl2);
                return 0;
            }
        }
    }
    
    ///////          L E V E L    ----     3    ------         ///////
    
    for(int x = 0; x < key_lenght; x++) 
    { 
        lvl3[0] = hash[x];
        for(int y = 0; y < key_lenght; y++) 
        {
            lvl3[1] = hash[y];
            for(int z = 0; z < key_lenght; z++) 
            {
                lvl3[2] = hash[z];
                pass = crypt(lvl3, salt);
                
                // Print the key back to the user.
                if(strcmp(argv[1], pass) == 0) 
                {
                    printf("%s\n", lvl3);
                    return 0;
                }
            }
        }
    }
    
    ///////          L E V E L    ----     4    ------         ///////
    
    for(int a = 0; a < key_lenght; a++) 
    { 
        lvl4[0] = hash[a];
        for(int b = 0; b < key_lenght; b++) 
        {
            lvl4[1] = hash[b];
            for(int c = 0; c < key_lenght; c++) 
            {
                lvl4[2] = hash[c];
                for(int d = 0; d < key_lenght; d++) 
                {
                    lvl4[3] = hash[d];
                    pass = crypt(lvl4, salt);
                    
                    // Print the key back to the user.
                    if(strcmp(argv[1], pass) == 0) 
                    {
                        printf("%s\n", lvl4);
                        return 0;
                    }
                }
            }
        }
    }
}