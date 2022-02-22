//Recover JPEG file from a memory card
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover [name of file]\n");
        return 1;
    }

    // Open image and determine scaling factor
    FILE *image = fopen(argv[1], "r");
    if (image == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    
    BYTE block[512];
    char filename[8];
    FILE *newimage = NULL;
    int i = 0;

    ////read 512 bytes into a buffer block until it has enought bytes (the end of the file) 
    while (fread(&block, sizeof(block), 1, image) == 1)
    {
        //check first 4 bytes of JPEG header
        if ((block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff) && ((block[3] & 0xf0) == 0xe0))
        {
            //if not first jpeg image
            if (i != 0)
            {
                fclose(newimage);
            }
                
            sprintf(filename, "%03i.jpg", i);
            newimage = fopen(filename, "w");
            i++;
        }    
        //if there is opened newimage, write into it
        if (i != 0)
        {
            fwrite(&block, sizeof(block), 1, newimage);
        }
   
    }

    fclose(newimage);
    fclose(image); 
}