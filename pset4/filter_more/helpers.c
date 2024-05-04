#include "helpers.h"
#include <math.h>

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int grayscale_rgb = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            if (grayscale_rgb > 255)
            {
                grayscale_rgb = 255;
            }

            image[i][j].rgbtRed = grayscale_rgb;
            image[i][j].rgbtGreen = grayscale_rgb;
            image[i][j].rgbtBlue = grayscale_rgb;
        }
    }
    return;
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int index = 1;
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - index];
            image[i][width - index] = temp;
            index++;
        }
    }
    return;
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE result[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            float count = 0;

            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        sumRed += image[x][y].rgbtRed;
                        sumGreen += image[x][y].rgbtGreen;
                        sumBlue += image[x][y].rgbtBlue;
                        count++;
                    }
                }
            }
            result[i][j].rgbtRed = round((float) sumRed / count);
            result[i][j].rgbtGreen = round((float) sumGreen / count);
            result[i][j].rgbtBlue = round((float) sumBlue / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = result[i][j];
        }
    }
    return;
}

void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    int GX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int GY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRedX = 0, sumGreenX = 0, sumBlueX = 0;
            int sumRedY = 0, sumGreenY = 0, sumBlueY = 0;

            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    if (i+x >= 0 && i+x < height && j+y >= 0 && j+y < width)
                    {
                        sumRedX += GX[x + 1][y + 1] * copy[i + x][j + y].rgbtRed;
                        sumGreenX += GX[x + 1][y + 1] * copy[i + x][j + y].rgbtGreen;
                        sumBlueX += GX[x + 1][y + 1] * copy[i + x][j + y].rgbtBlue;

                        sumRedY += GY[x + 1][y + 1] * copy[i + x][j + y].rgbtRed;
                        sumGreenY += GY[x + 1][y + 1] * copy[i + x][j + y].rgbtGreen;
                        sumBlueY += GY[x + 1][y + 1] * copy[i + x][j + y].rgbtBlue;
                    }
                }
            }

            int finalRed = round(sqrt((double)(sumRedX * sumRedX + sumRedY * sumRedY)));
            int finalGreen = round(sqrt((double)(sumGreenX * sumGreenX + sumGreenY * sumGreenY)));
            int finalBlue = round(sqrt((double)(sumBlueX * sumBlueX + sumBlueY * sumBlueY)));


            image[i][j].rgbtRed = finalRed > 255 ? 255 : finalRed;
            image[i][j].rgbtGreen = finalGreen > 255 ? 255 : finalGreen;
            image[i][j].rgbtBlue = finalBlue > 255 ? 255 : finalBlue;
        }
    }
    return;
}
