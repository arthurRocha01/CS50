#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE result[height][width];

    // cópia e operação do pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray_value = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            gray_value = gray_value > 255 ? 255 : gray_value;
            result[i][j].rgbtRed = gray_value;
            result[i][j].rgbtGreen = gray_value;
            result[i][j].rgbtBlue = gray_value;
        }
    }

    // passa os novos valores
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = result[i][j];
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE result[height][width];

    // cópia e operação do pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double sepia_red = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            double sepia_green = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            double sepia_blue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            sepia_red = sepia_red > 255 ? 255 : sepia_red;
            sepia_green = sepia_green > 255 ? 255 : sepia_green;
            sepia_blue = sepia_blue > 255 ? 255 : sepia_blue;

            result[i][j].rgbtRed = round(sepia_red);
            result[i][j].rgbtGreen = round(sepia_green);
            result[i][j].rgbtBlue = round(sepia_blue);
        }
    }

    // passa os novos valores
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = result[i][j];
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE result[height][width];

    // cópia e operação do pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            result[i][j] = image[i][width - 1 - j];
        }
    }

    // passa os novos valores
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = result[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE result[height][width];

    // cópia e operação do pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int total_red = 0, total_green = 0, total_blue = 0;

            int pixel_count = 0;
            for (int x = i-1; x <= i+1; x++)
            {
                for (int y = j-1; y <= j+1; y++)
                {
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        total_red += image[x][y].rgbtRed;
                        total_blue += image[x][y].rgbtBlue;
                        total_green += image[x][y].rgbtGreen;
                        pixel_count++;
                    }
                }
            }

            result[i][j].rgbtRed = round((float) total_red / pixel_count);
            result[i][j].rgbtGreen = round((float) total_green / pixel_count);
            result[i][j].rgbtBlue = round((float) total_blue / pixel_count);
        }
    }

    // passa os novos valores
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = result[i][j];
        }
    }
    return;
}
