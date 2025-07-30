#ifndef lcddraw_included
#define lcddraw_included

// Draw single pixel at col, row 
void drawPixel(u_char col, u_char row, u_int colorBGR);

// Fill rectangle
void fillRectangle(u_char colMin, u_char rowMin, u_char width, u_char height, u_int colorBGR);

// Clear screen (fill with color)
void clearScreen(u_int colorBGR);

// Draw string at col,row
void drawString5x7(u_char col, u_char row, char *string, 
		   u_int fgColorBGR, u_int bgColorBGR);

// 5x7 font - this function draws background pixels
void drawChar5x7(u_char col, u_char row, char c, 
		 u_int fgColorBGR, u_int bgColorBGR);

// Draw rectangle outline
void drawRectOutline(u_char colMin, u_char rowMin, u_char width, u_char height,
		     u_int colorBGR);
#endif // included
