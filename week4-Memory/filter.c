
#include "helpers.h"
#include <stdio.h>
#include <math.h>

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
                image[i][j].rgbtBlue = round(totalB/count);
                image[i][j].rgbtRed =  round(totalR/count);
                image[i][j].rgbtGreen = round(totalG/count);
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    //sqrt(gx^2 + gx^2)
    int aGx[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int aGy[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};
    //printf("%i",aGx[0][0]);
    for (int i = 0,h = 5; i < h; i++)
    {
        for (int j = 0, w = 5; j < w; j++)
        {   
            int count = 0;
            double gxR = 0;
            double gxB = 0;
            double gxG = 0;
            double gyR = 0;
            double gyB = 0;
            double gyG = 0;
          
            
            if(i-1 >= 0 && i+1 < h && j-1 >= 0 && j+1 < w)
            {
                for(int tx = 0, x = i -1; x <= i+1; x++,tx++)
                {
                    printf("%i\n",tx);
                    for(int ty=0, y = j-1; y <= j+1; y++,ty++)
                    {
                        printf("%f",gxB);
                        printf("%-----i",image[x][y].rgbtRed);
                        gxR += aGx[tx][ty] * image[x][y].rgbtRed;
                        //  gxB += aGx[tx][ty] * image[x][y].rgbtBlue;
                        //  gxG += aGx[tx][ty] * image[x][y].rgbtGreen;
                        //  gyR += aGy[tx][ty] * image[x][y].rgbtRed;
                        //  gyB += aGy[tx][ty] * image[x][y].rgbtBlue;
                        //  gyG += aGy[tx][ty] * image[x][y].rgbtGreen;
                        
                        // totalR += image[x][y].rgbtRed;
                        // totalB += image[x][y].rgbtBlue;
                        // totalG += image[x][y].rgbtGreen;
                        // count++;
                    }
        
                }
                printf("%f\n",gxB);
                // image[i][j].rgbtBlue = round(totalB/count);
                // image[i][j].rgbtRed =  round(totalR/count);
                // image[i][j].rgbtGreen = round(totalG/count);
            }
            
            
        }
    }  
    return;
}
