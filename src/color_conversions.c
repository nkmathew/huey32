#include <stdio.h>
#include <string.h>
#include <math.h>
#include "color_conversions.h"

double normalize(int number) {
  double result = (double)number / MAX_BYTE;
  if (result < 0.0) {
    return 0.0;
  } else if (result > 1.0) {
    return 1.0;
  } else {
    return result;
  }
}

int discretize(double number) {
  int result = number * MAX_BYTE;
  if (result < 0) {
    return 0;
  } else if (result > MAX_BYTE) {
    return MAX_BYTE;
  } else {
    return result;
  }
}

struct rgb_color hex_to_rgb(char *hex_number) {
  unsigned int d1, d2, d3, d4, d5, d6;
  char format[20] = "#%1x%1x%1x%1x%1x%1x";
  if (hex_number[0] != '#') {
    strcpy(format, "%1x%1x%1x%1x%1x%1x");
  }
  sscanf(hex_number, format, &d1, &d2, &d3, &d4, &d5, &d6);
  d1 = d1 > 15 ? 15 : d1;
  d2 = d2 > 15 ? 15 : d2;
  d3 = d3 > 15 ? 15 : d3;
  d4 = d4 > 15 ? 15 : d4;
  d5 = d5 > 15 ? 15 : d5;
  d6 = d6 > 15 ? 15 : d6;
  struct rgb_color rgb;
  rgb.red = d1 * 16 + d2;
  rgb.green = d3 * 16 + d4;
  rgb.blue = d5 * 16 + d6;
  return rgb;
}


// r,g,b values are from 0 to 1
// h = [0,360], s = [0,1], v = [0,1]
//      if s == 0, then h = -1 (undefined)

// http://www.cs.rit.edu/~ncs/color/t_convert.html
struct hsv_color RGB_to_HSV(double red, double green, double blue) {
  double min, max, delta;
  struct hsv_color hsv;

  min = MIN(red, green, blue);
  max = MAX(red, green, blue);
  hsv.value = max;

  delta = max - min;

  if (max != 0) {
    hsv.saturation = delta / max;
  } else {
    // red = green = blue = 0
    // s = 0, v is undefined
    hsv.saturation = 0;
    hsv.hue = -1;
    return hsv;
  }

  if (red == max) {
    // between yellow & magenta
    hsv.hue = (green - blue) / delta;
  } else if (green == max) {
    // between cyan & yellow
    hsv.hue = 2 + (blue - red) / delta;
  } else {
    // between magenta & cyan
    hsv.hue = 4 + (red - green) / delta;
  }

  hsv.hue *= 60;  // degrees
  if (hsv.hue < 0) {
    hsv.hue += 360;
  }
  return hsv;
}

struct rgb_color HSV_to_RGB(double hue, double saturation, double value) {
  int i;
  double f, p, q, t;

  struct rgb_color rgb;
  if (saturation == 0) {
    // achromatic (grey)
    rgb.red = rgb.green = rgb.blue = value;
    return rgb;
  }

  hue /= 60; // sector 0 to 5
  i = floor(hue);
  f = hue - i; // factorial part of h
  p = value * (1 - saturation);
  q = value * (1 - saturation * f);
  t = value * (1 - saturation * (1 - f));

  switch (i) {
    case 0:
      rgb.red = value;
      rgb.green = t;
      rgb.blue = p;
      break;
    case 1:
      rgb.red = q;
      rgb.green = value;
      rgb.blue = p;
      break;
    case 2:
      rgb.red = p;
      rgb.green = value;
      rgb.blue = t;
      break;
    case 3:
      rgb.red = p;
      rgb.green = q;
      rgb.blue = value;
      break;
    case 4:
      rgb.red = t;
      rgb.green = p;
      rgb.blue = value;
      break;
    default:
      rgb.red = value;
      rgb.green = p;
      rgb.blue = q;
      break;
  }
  return rgb;
}

struct rgb_color CMY_to_RGB(double cyan, double magenta, double yellow) {
  //CMY values from 0 to 1
  //RGB results from 0 to MAX_BYTE
  struct rgb_color rgb;
  rgb.red = discretize(1 - cyan);
  rgb.green = discretize(1 - magenta);
  rgb.blue = discretize(1 - yellow);
  return rgb;
}

struct cmy_color RGB_to_CMY(double red, double green, double blue) {
  //RGB values from 0 to MAX_BYTE
  //CMY results from 0 to 1
  struct cmy_color cmy;
  cmy.cyan = 1 - normalize(red);
  cmy.magenta = 1 - normalize(green);
  cmy.yellow = 1 - normalize(blue);
  return cmy;
}


