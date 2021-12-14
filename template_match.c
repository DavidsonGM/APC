/* Template matching sample code by Teofilo de Campos, 
   University of Brasilia, June 2018.

   Compile with
   gcc netpbm.c template_match.c -Wall -pedantic
*/

#include "netpbm.h" /* My NetPBM library */
#include <stdio.h> 
#include <stdlib.h> /* malloc, calloc, atoi */

int main(int argc, char **argv){
  Image img, template, result;
  double **differences; /* Differences matrix */
  unsigned int row, col, chn; /* Indices of the input image */
  unsigned int row_t, col_t; /* Indices of the template */
  unsigned int rows_d, cols_d; /* Size of the differences matrix */
  unsigned int min_row, min_col; /* Located position */
  double diff, min_diff, max_diff; /* Temporary variables */

  if(argc < 3){
    printf("At least 2 arguments are required: image_file_name template_file_name\n");
    return(1);
  }
  sprintf(img.filename, "%s", argv[1]);
  sprintf(template.filename, "%s", argv[2]);

  /* 1. Load image and template. */
  /** Write missing code here. **/

  /* 2. Compute the size of the differences matrix. */
  rows_d = img.rows - template.rows + 1;
  cols_d = img.cols - template.cols + 1;

  /* 3. Allocate differences matrix. */
  /** Write missing code here. **/

  /* 4. For each channel
           For each row in the image
	     For each column in the image
	       For each row in the template
	         For each column in the demplate
		   Compute the absolute diference between the template and the difference
		   Add the result to the current position of the differences matrix
  */
  /** Write missing code here. **/

  /* 5. Locate the position where the difference is the minimum. 
     Use the difference matrix for that. */
  /** Write missing code here. **/

  printf("\nTemplate found at row=%u, col=%u. Difference=%lf\n", min_row, min_col, min_diff);

  if(argc>3){
    /* 6. Allocate an image to store the differences matrix. */
    /** Write missing code here. **/

    /* 7. The differences matrix can have very high values, but images can only go up to 255. 
          Normalize the differences so that they go from 0 to 255, i.e., 
	  for each pixel, 
            divide its value by the maximum difference and 
	    then multiply the result by 255
	    convert to unsigned char and copy to the differences image.
    */
    /** Write missing code here. **/
    sprintf(result.filename, "%s", argv[3]);
    save_img(result);
  }  

  if(argc>4){
    /* 8. Modif the original image to highlight the located template.
          For that, subtract 128 from the value of all pixels
	  that are NOT in the region where the template was found.
	  Be careful to avoid negative results, if the original
	  value was less then 128, set it to 0.
    */
    /** Write missing code here. **/
 	  
    sprintf(img.filename, "%s", argv[4]);
    save_img(img);
  }
  
  return 0;  
}

