#ifndef CONVERSIONS_H
#define CONVERSIONS_H

#define MAX_BYTE 255

#define MIN(x,y,z)  ((y) <= (z) ? \
                     ((x) <= (y) ? (x) : (y)) \
                       : \
                       ((x) <= (z) ? (x) : (z)))

#define MAX(x,y,z)  ((y) >= (z) ? \
                     ((x) >= (y) ? (x) : (y)) \
                       : \
                       ((x) >= (z) ? (x) : (z)))

enum ColorModel {
  HSV_MODEL,
  RGB_MODEL,
  CMY_MODEL
};

struct rgb_color {
  double red, green, blue;
};

struct cmy_color {
  double cyan, magenta, yellow;
};

struct hsv_color {
  double hue, saturation, value;
};

double normalize(int value);
int discretize(double value);

struct rgb_color hex_to_rgb(char *hex_number);

struct hsv_color RGB_to_HSV(double red, double green, double blue);
struct rgb_color HSV_to_RGB(double hue, double saturation, double value);
struct cmy_color RGB_to_CMY(double red, double green, double blue);
struct rgb_color CMY_to_RGB(double cyan, double magenta, double yellow);

#endif

