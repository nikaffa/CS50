#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image [i][j].rgbtRed + image [i][j].rgbtGreen + image [i][j].rgbtBlue) / 3.0;
            image [i][j].rgbtRed =  round(average);
            image [i][j].rgbtGreen = round(average);
            image [i][j].rgbtBlue = round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float sepiaRed = .393 * image [i][j].rgbtRed + .769 * image [i][j].rgbtGreen + .189 * image [i][j].rgbtBlue;
            float sepiaGreen = .349 * image [i][j].rgbtRed + .686 * image [i][j].rgbtGreen + .168 * image [i][j].rgbtBlue;
            float sepiaBlue = .272 * image [i][j].rgbtRed + .534 * image [i][j].rgbtGreen + .131 * image [i][j].rgbtBlue;

            int x = round(sepiaRed);
            int y = round(sepiaGreen);
            int z = round(sepiaBlue);

            if (x > 255)
            {
                x = 255;
            }
            if (y > 255)
            {
                y = 255;
            }
            if (z > 255)
            {
                z = 255;
            }

            image [i][j].rgbtRed =  x;
            image [i][j].rgbtGreen = y;
            image [i][j].rgbtBlue = z;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE swap;
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0, n = width / 2; j < n; j++)
            {
                swap = image [i][j];
                int x = (width - 1) - j;
                image [i][j] = image [i][x];
                image [i][x] = swap;
            }
        }
        else if (width % 2 == 1)
        {
            for (int j = 0, n = width / 2 - 1; j <= n; j++)
            {
                swap = image [i][j];
                int x = (width - 1) - j;
                image [i][j] = image [i][x];
                image [i][x] = swap;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE cimage [height][width];
    //create a new image, a copy of image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cimage [i][j].rgbtRed = image [i][j].rgbtRed;
            cimage [i][j].rgbtGreen = image [i][j].rgbtGreen;
            cimage [i][j].rgbtBlue = image [i][j].rgbtBlue;
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float averageRed = 0.0, averageGreen = 0.0, averageBlue = 0.0, k = 0.0;
            
            // create 3x3 box and calculate average if a pixel exists
            for (int x = -1; x < 2; x++)
            {   
                for (int y = -1; y < 2; y++)
                {
                    if ((i + x >= 0 && i + x < height) && (j + y >= 0 && j + y < width))
                    {
                        averageRed += cimage [i + x][j + y].rgbtRed;
                        averageGreen += cimage [i + x][j + y].rgbtGreen;
                        averageBlue += cimage [i + x][j + y].rgbtBlue;
                        k++;
                    }
                }
            }
            averageRed /= k;
            averageGreen /= k;
            averageBlue /= k;
            
            image [i][j].rgbtRed =  round(averageRed);
            image [i][j].rgbtGreen = round(averageGreen);
            image [i][j].rgbtBlue = round(averageBlue);
            
        }
    }

    return;
}
