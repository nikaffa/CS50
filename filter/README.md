### Filter
Filter is a program that allows users to apply grayscale, sepia, reflection, or blur filters to their images.
The program applies filters to BMPs, a file format that supports “24-bit color” uses 24 bits per pixel (8 bits to signify the amount of red in a pixel’s color, 8 bits to signify the amount of green in a pixel’s color, and 8 bits to signify the amount of blue in a pixel’s color).
The algorithm filters an image by taking the pixels of some original image and modifying each pixel in such a way that a particular effect is apparent in the resulting image.

#### Usage
Try compling by run **`make filter`** 
Filter images from **`images`** directory. 
Original image:

Run the program by specifying the filter prefix:
Use **`grayscale`** filter to turn an image into a black-and-white version:
**`./filter -g images/yard.bmp out.bmp`** 

Use **`sepia`** filter to turn an image into a sepia version:
**`./filter -s images/yard.bmp out.bmp`** 


Use **`reflect`** filter to reflect an image horizontally:
**`./filter -r images/yard.bmp out.bmp`** 


Use **`blur`** filter to turn an image into a box-blurred version:
**`./filter -b images/yard.bmp out.bmp`** 

