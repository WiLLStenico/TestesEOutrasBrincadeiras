typedef struct tagBITMAPFILEHEADER {
	unsigned int  bfType;                   // "BM" or 0x4D42
	unsigned long bfSize;                   // Size of file in bytes
	unsigned int  bfReserved1;              // Set to 0
	unsigned int  bfReserved2;              // Set to 0
	unsigned long bfOffBits;                // Offset in file where
														 // the bits begin
} BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER {
	unsigned long biSize;                   // Size of the structure
	unsigned long biWidth;                  // Width in pixels
	unsigned long biHeight;                 // Height in pixels
	unsigned int  biPlanes;                 // # of color Planes: Set to 1
	unsigned int  biBitCount;               // Color bits per pixel
	unsigned long biCompression;            // Compression Scheme
	unsigned long biSizeImage;              // Number of bitmap bytes
	unsigned long biXPelsPerMeter;          // Horizontal Resolution
	unsigned long biYPelsPerMeter;          // Vertical Resolution
	unsigned long biClrUsed;                // Number of colors used
	unsigned long biClrImportant;           // Important colors
} BITMAPINFOHEADER;

typedef struct elep{
	unsigned char decdia;
	unsigned char dechr;
	unsigned char decmin;
	unsigned char decseg;
} TEMPODECORRIDO;

typedef struct inip{
	unsigned char inihr;
	unsigned char inimin;
	unsigned char iniseg;
	unsigned char inidia;
	unsigned char inimes;
	unsigned char iniano;
} INICIOPROCESSO;

void ProcessBMP(char *BMPFile, int x1, int y1);

