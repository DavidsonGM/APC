#include "netpbm.h"
#include <stdio.h> /* input, output */
#include <stdlib.h> /* malloc, calloc, atoi */
#include <math.h>

#define VERBOSE 0


/****************
 * Function to load an image from disk in ASCII PGM or PPM format: */


int allocate_img(Image *img, unsigned int channels, unsigned int rows, unsigned int cols, unsigned char max){
  unsigned int chn, row;
  
  img->chns = channels;
  img->rows = rows;
  img->cols = cols;
  img->max = max;
  img->data = malloc(img->chns * sizeof(unsigned char **));
  for(chn=0; chn<channels; chn++){
    img->data[chn] = malloc(img->rows * sizeof(unsigned char *));
    for(row=0; row < img->rows; row++)
      img->data[chn][row] = calloc(img->cols, sizeof(unsigned char));
  }
  return(1);
}


int load_img(Image *img){
  unsigned int magic_number, channels, rows, cols, chn, row, col;
  unsigned char max;
  char line[256];

  FILE *fp = fopen(img->filename, "r");
  if(!fp){
    printf("Couldn't open %s\n", img->filename);
    return(0);
  }

  do{ /* Ignore comment lines. */
    fgets(line, 256, fp);
    printf("line: %s\n", line);
  }while (line[0]=='#'); 
  sscanf(line, "P%u", &magic_number);
  if(magic_number==2) /* Grey image */
    channels = 1;
  else
    if(magic_number==3) /* Colour image */
      channels = 3;
  printf("magic_number: %d\n", magic_number);
  
  do{ /* Ignore comment lines. */
    fgets(line, 256, fp);
    printf("line: %s\n", line);
  }while (line[0]=='#'); 
  sscanf(line, "%u%u", &cols, &rows);  
  printf("cols: %u\nrows: %u\n", cols, rows);
  fscanf(fp, "%hhu", &max);
  printf("img->max: %u\n", max);

  allocate_img(img, channels, rows, cols, max);
  
  for(row=0; row < img->rows; row++){
    for(col=0; col < img->cols; col++){
      for(chn=0; chn < img->chns; chn++){
	fscanf(fp, "%hhu", &img->data[chn][row][col]);
      }
    }
  }
  fclose(fp);
  return 1;
}



/****************
 * Function to save an image to disk in ASCII PGM or PPM format: */
int save_img(Image img){
  unsigned int row, col, chn;
  
  FILE *fp = fopen(img.filename, "w");
  if(!fp){
    printf("Couldn't open %s\n", img.filename);
    return(0);
  }
  if(img.chns==1) /* Grey image. */
    fprintf(fp, "P2\n");
  else
    if(img.chns==3) /* Colour image. */
      fprintf(fp, "P3\n");

  fprintf(fp, "# Created by NetPBM library of Teo de Campos, Universidade de Brasilia.\n");
  fprintf(fp, "%u %u\n%u\n", img.cols, img.rows, img.max);
  for(row=0; row < img.rows; row++){
    for(col=0; col < img.cols; col++){
      for(chn=0; chn < img.chns; chn++){
	fprintf(fp, "%hhu ", img.data[chn][row][col]);
      }
      if(col < img.cols-1)
	fprintf(fp, " ");
      else
	fprintf(fp, "\n");    
    }
  }
  fclose(fp);
  return 1;
}

