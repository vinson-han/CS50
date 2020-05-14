#include "helpers.h"
#include <stdio.h>
#include <math.h>
int check(double x,double y);
int cap255(double n);
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
   
    for (int i = 0,h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < width; j++)
        {
            double total = 0;
            total += image[i][j].rgbtBlue;
            total += image[i][j].rgbtRed;
            total += image[i][j].rgbtGreen;

            int average = round(total/3);
            //printf("%i\n",average);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
        }
    }  
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     
    //RGBTRIPLE temp = image[height-1][width-1];
    // printf("%iheight\n",height);
    // printf("%iwidth/2\n",width/2);
    // printf("%iheight\n",temp.rgbtBlue);
    printf("%iheight\n",image[0][0].rgbtBlue);
    printf("%iheight\n",image[0][0].rgbtGreen);
    printf("%iheight\n",image[0][0].rgbtRed);
    for (int i = 0,h = height; i < h; i++)
    {
        for (int j = 0, w = width; j <= width/2; j++)
        {
            RGBTRIPLE temp = image [i][j];
            image[i][j] = image[i][w-1-j];
            image[i][w-1-j] = temp; 
        }
    }  
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0,h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {   
            int count = 0;
            double totalR = 0;
            double totalB = 0;
            double totalG = 0;
            
            if(i-1 >= 0 && i+1 < h && j-1 >= 0 && j+1 < w)
            {
               
                for(int x = i -1; x <= i+1; x++)
                {
                    for(int y = j-1; y <= j+1; y++)
                    {
                        totalR += image[x][y].rgbtRed;
                        totalB += image[x][y].rgbtBlue;
                        totalG += image[x][y].rgbtGreen;
                        count++;
                    }
                }
                image[i][j].rgbtBlue = ceil(totalB/count);
                image[i][j].rgbtRed =  ceil(totalR/count);
                image[i][j].rgbtGreen = ceil(totalG/count);
            }
            else
            {
              for(int x = i -1; x <= i+1; x++)
                {
                    for(int y = j-1; y <= j+1; y++)
                    { 
                      if ((x>=0 && x<=h-1) && (y>=0 && y<= w-1))
                      {
                            totalR += image[x][y].rgbtRed;
                            totalB += image[x][y].rgbtBlue;
                            totalG += image[x][y].rgbtGreen;
                            count++;
                      }         
                    }

                    if(count> 0)
                    {
                        image[i][j].rgbtBlue = round(totalB/count);
                        image[i][j].rgbtRed =  round(totalR/count);
                        image[i][j].rgbtGreen = round(totalG/count);
                    }
                }
               
            }
            
        }
    }  
}
int check(double x,double y)
{
    double value = sqrt(x * x + y * y);
    int r = (int)round(value);
    if (r > 255)
        return 255;
    return r;
}
// Detect edges
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

    // Main loop to sum up all values for each channel in each pixel relative to Gx and Gy
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float rGx, gGx, bGx, rGy, gGy, bGy;
            rGx = gGx = bGx = rGy = gGy = bGy = 0;

            // Up
            if (i > 0)
            {
                rGy += -2 * copy[i-1][j].rgbtRed;
                gGy += -2 * copy[i-1][j].rgbtGreen;
                bGy += -2 * copy[i-1][j].rgbtBlue;
            }
            // Down
            if (i < height - 1)
            {

                rGy += 2 * copy[i+1][j].rgbtRed;
                gGy += 2 * copy[i+1][j].rgbtGreen;
                bGy += 2 * copy[i+1][j].rgbtBlue;
            }
            // Left
            if (j > 0)
            {
                rGx += -2 * copy[i][j-1].rgbtRed;
                gGx += -2 * copy[i][j-1].rgbtGreen;
                bGx += -2 * copy[i][j-1].rgbtBlue;

            }
            // Right
             if (j < height - 1)
            {
                rGx += 2 * copy[i][j+1].rgbtRed;
                gGx += 2 * copy[i][j+1].rgbtGreen;
                bGx += 2 * copy[i][j+1].rgbtBlue;

            }
            // Up left
            if (i > 0 && j > 0)
            {
                // Note: change sign in Gx values here and the result changes side
                rGx += -1 * copy[i-1][j-1].rgbtRed;
                gGx += -1 * copy[i-1][j-1].rgbtGreen;
                bGx += -1 * copy[i-1][j-1].rgbtBlue;
                rGy += -1 * copy[i-1][j-1].rgbtRed;
                gGy += -1 * copy[i-1][j-1].rgbtGreen;
                bGy += -1 * copy[i-1][j-1].rgbtBlue;
            }
            // Up right
            if (i > 0 && j < width - 1)
            {
                rGx += 1 * copy[i-1][j+1].rgbtRed;
                gGx += 1 * copy[i-1][j+1].rgbtGreen;
                bGx += 1 * copy[i-1][j+1].rgbtBlue;
                rGy += -1 * copy[i-1][j+1].rgbtRed;
                gGy += -1 * copy[i-1][j+1].rgbtGreen;
                bGy += -1 * copy[i-1][j+1].rgbtBlue;
            }
            // Bottom right
            if (i < height - 1  && j < width - 1)
            {
                rGx += 1 * copy[i+1][j+1].rgbtRed;
                gGx += 1 * copy[i+1][j+1].rgbtGreen;
                bGx += 1 * copy[i+1][j+1].rgbtBlue;
                rGy += 1 * copy[i+1][j+1].rgbtRed;
                gGy += 1 * copy[i+1][j+1].rgbtGreen;
                bGy += 1 * copy[i+1][j+1].rgbtBlue;
            }
            // Bottom left
            if (j < height - 1  && j > 0)
            {
                rGx += -1 * copy[i+1][j-1].rgbtRed;
                gGx += -1 * copy[i+1][j-1].rgbtGreen;
                bGx += -1 * copy[i+1][j-1].rgbtBlue;
                rGy += 1 * copy[i+1][j-1].rgbtRed;
                gGy += 1 * copy[i+1][j-1].rgbtGreen;
                bGy += 1 * copy[i+1][j-1].rgbtBlue;
            }

            // Compute result
            image[i][j].rgbtRed = (int) cap255(sqrt((rGx*rGx)+(rGy*rGy)));
            image[i][j].rgbtGreen = (int) cap255(sqrt((gGx*gGx)+(gGy*gGy)));
            image[i][j].rgbtBlue = (int) cap255(sqrt((bGx*bGx)+(bGy*bGy)));
        }
    }
    return;
}
int cap255(double n)
{
    int result = 0;

    if (n >= 255)
    {
        result = 255;
    }
    else if(n < 0)
    {
        result = 0;
    }
    else
    {
        result = (int) round(n);
    }
    return (result);
}
// Function to cap results at 255 maximum



    // //sqrt(gx^2 + gx^2)
    // int aGx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    // int aGy[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};
    // //printf("%i",aGx[0][0]);
    // for (int i = 0,h = height; i < h; i++)
    // {
    //     for (int j = 0, w = width; j < w; j++)
    //     {   
            
    //         double gxR = 0;
    //         double gxB = 0;
    //         double gxG = 0;
    //         double gyR = 0;
    //         double gyB = 0;
    //         double gyG = 0;

    //         if(i-1 >= 0 && i+1 < h && j-1 >= 0 && j+1 < w)
    //         {
    //             //printf("-[%i][%i]\n",i,j);
    //             for(int tx = 0, x = i -1; x <= i+1; x++,tx++)
    //             {
    //                 for(int ty=0, y = j-1; y <= j+1; y++,ty++)
    //                 {
    //                      gxR+= aGx[tx][ty] * image[x][y].rgbtRed;
    //                      gxB+= aGx[tx][ty] * image[x][y].rgbtBlue;
    //                      gxG+= aGx[tx][ty] * image[x][y].rgbtGreen;

    //                      gyR+= aGy[tx][ty] * image[x][y].rgbtRed;
    //                      gyB+= aGy[tx][ty] * image[x][y].rgbtBlue;
    //                      gyG+= aGy[tx][ty] * image[x][y].rgbtGreen;
      
    //                 }
    //             }
    //             //printf("\n");
    //             image[i][j].rgbtRed = check(gxR,gyR);
    //             image[i][j].rgbtBlue = check(gxB,gyB); 
    //             image[i][j].rgbtGreen= check(gxG,gyG);                  
               
    //         }
            
            
    //     }
    // }  
