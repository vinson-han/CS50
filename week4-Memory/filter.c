#include "helpers.h"
#include <stdio.h>
#include <math.h>
int check(double x,double y);

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
    // printf("%iheight\n",image[0][0].rgbtBlue);
    // printf("%iheight\n",image[0][0].rgbtGreen);
    // printf("%iheight\n",image[0][0].rgbtRed);
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
    
    int r = (int)round(sqrt((x * x) + (y * y)));
    if (r < 0)
        return 0;
    if (r >= 255)
        return 255;
    return r;
}
// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    
    RGBTRIPLE copy[height][width];
    int aGX[3][3] = {{-1,0,1},{-2,0,2},{-1,0,1}};
    int aGY[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};
    // int aGy[3][3] = {{-1,-2,-1},{0,0,0},{1,2,1}};
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
           
        }
    }
    
  
    for (int i = 0,h = height; i < h; i++)
    {
        for (int j = 0, w = width; j < w; j++)
        {   

            double gxR = 0;
            double gxG = 0;
            double gxB = 0;

            double gyR = 0;
            double gyG = 0;
            double gyB = 0;

            // printf("[%i][%i]:\n",i,j);
            // printf("Red,%i:\n",copy[i][j].rgbtRed);
            for(int x = 0, startX = i-1; x < 3; x++,startX++)
            {
                 //printf("%i\n",x);
                for (int y = 0,startY = j-1; y < 3; y++,startY++)
                {
                    
                    if((startX >=0 && startY >= 0) && (startX <= h-1 && startY <= w-1))
                    {
                        //printf("Red,[%i][%i]%i:",startX,startY,aGX[x][y]);
                        //printf("Copy,%i:\n",copy[startX][startY].rgbtRed);
                        gxR += copy[startX][startY].rgbtRed * aGX[x][y];
                        gyR += copy[startX][startY].rgbtRed * aGY[x][y];
                        gxG += copy[startX][startY].rgbtGreen * aGX[x][y];
                        gyG += copy[startX][startY].rgbtGreen * aGY[x][y];
                        gxB += copy[startX][startY].rgbtBlue * aGX[x][y];
                        gyB += copy[startX][startY].rgbtBlue * aGY[x][y];
                        
                    }
        
                }
            }
            image[i][j].rgbtRed = check(gxR,gyR);
            image[i][j].rgbtGreen = check(gxG,gyG);
            image[i][j].rgbtBlue = check(gxB,gyB);
        }
    }

   
    return;
}
