// @Date: 4th July 2014

#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "../res/resource.h"
#include "color_names.h"
#include "font_names.h"
#include "color_conversions.h"

LPSTR PROGRAM_NAME = "huey32 v0.0.1";

LPSTR g_szSliderLabels[3][3] = {
  {"Hue"  , "Saturation" , "Value"},
  {"Red"  , "Green"      , "Blue"},
  {"Cyan" , "Magenta"    , "Yellow"}
};

VOID CALLBACK PopulateFontNamesListBox(HWND hDialog) {
  for (INT i = 0; i < FONT_COUNT; i++) {
    LPSTR fontName = FONT_NAMES[i];
    SendDlgItemMessage(hDialog, ID_FONTNAME_LISTBOX, LB_ADDSTRING, 0, (LPARAM)fontName);
  }
}

VOID CALLBACK ChangeSliderLabel(HWND hDialog, INT iModel) {
  LPSTR szLabel1, szLabel2, szLabel3;
  szLabel1 = g_szSliderLabels[iModel][0];
  szLabel2 = g_szSliderLabels[iModel][1];
  szLabel3 = g_szSliderLabels[iModel][2];
  SendDlgItemMessage(hDialog, ID_SLIDER1_LABEL, WM_SETTEXT, 0, (LPARAM)szLabel1);
  SendDlgItemMessage(hDialog, ID_SLIDER2_LABEL, WM_SETTEXT, 0, (LPARAM)szLabel2);
  SendDlgItemMessage(hDialog, ID_SLIDER3_LABEL, WM_SETTEXT, 0, (LPARAM)szLabel3);
}

VOID CALLBACK CopyTextToClipboard(LPSTR szTextToCopy) {
  OpenClipboard(NULL);
  EmptyClipboard();
  HGLOBAL hGlobal = GlobalAlloc(GHND | GMEM_SHARE, strlen(szTextToCopy) + 1);
  strcpy((LPSTR)GlobalLock(hGlobal), szTextToCopy);
  GlobalUnlock(hGlobal);
  SetClipboardData(CF_TEXT, hGlobal);
  CloseClipboard();
}

VOID CALLBACK PopulateColorNamesListBox(HWND hDialog) {
  for (INT i = 0; i < COLORNAMES; i++) {
    LPSTR colorName = RGB_COLORNAMES[i].color_name;
    SendDlgItemMessage(hDialog, ID_COLORNAME_LISTBOX, LB_ADDSTRING, 0, (LPARAM)colorName);
  }
}

VOID CALLBACK ChangeSliderPos(HWND hDialog, INT iSlider1Pos, INT iSlider2Pos, INT iSlider3Pos) {
  SendDlgItemMessage(hDialog, ID_SLIDER1, TBM_SETPOS, TRUE, iSlider1Pos);
  SendDlgItemMessage(hDialog, ID_SLIDER2, TBM_SETPOS, TRUE, iSlider2Pos);
  SendDlgItemMessage(hDialog, ID_SLIDER3, TBM_SETPOS, TRUE, iSlider3Pos);
  // Change the labels to reflect the new positions.
  SendMessage(hDialog, WM_VSCROLL, 0, 0);
}

VOID CALLBACK ChangeSliderValues(HWND hDialog, INT iSlider1, INT iSlider2, INT iSlider3) {
  SetDlgItemInt(hDialog, ID_SLIDER1_VALUE, iSlider1, FALSE);
  SetDlgItemInt(hDialog, ID_SLIDER2_VALUE, iSlider2, FALSE);
  SetDlgItemInt(hDialog, ID_SLIDER3_VALUE, iSlider3, FALSE);
}

LONG CALLBACK ChangeTextColor(COLORREF crBackground, COLORREF crForeground, WPARAM wParam) {
  HBRUSH hbrBackground = CreateSolidBrush(crBackground);
  HDC hdcEditControl = (HDC)wParam;
  SetTextColor(hdcEditControl, crForeground);
  SetBkMode(hdcEditControl, TRANSPARENT);
  return (LONG)hbrBackground;
}

VOID CALLBACK ChangeSliderValueByOne(HWND hDialog, INT iSlider, INT iSliderLabel, BOOL bIncrease) {
  INT iSliderValue = SendDlgItemMessage(hDialog, iSlider, TBM_GETPOS, 0, 0);
  if (bIncrease) {
    iSliderValue++;
  } else {
    iSliderValue--;
  }
  iSliderValue = iSliderValue > MAX_BYTE ? MAX_BYTE : iSliderValue;
  iSliderValue = iSliderValue < 0 ? 0 : iSliderValue;
  SetDlgItemInt(hDialog, iSliderLabel, iSliderValue, FALSE);
  SendDlgItemMessage(hDialog, iSlider, TBM_SETPOS, TRUE, iSliderValue);
}

BOOL CALLBACK DialogProcedure(HWND hDialog, UINT uMessage, WPARAM wParam, LPARAM lParam) {
  static HWND hEditControl           = NULL;
  static HFONT hfEditBoxFont         = NULL;
  static CHAR szBackgroundColor[10]  = "#FF0000";
  static CHAR szTextColor[10]        = "#000000";
  static BOOL bBoldSelected          = FALSE;
  static BOOL bItalicSelected        = FALSE;
  switch (uMessage) {
    case WM_INITDIALOG: {
      HDC hDC = GetDC(NULL);
      LONG lFontHeight = -MulDiv(14, GetDeviceCaps(hDC, LOGPIXELSY), 72);
      ReleaseDC(NULL, hDC);
      hfEditBoxFont = CreateFont(
                        lFontHeight, 0, 0, 0, FW_DONTCARE, FALSE,
                        TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                        CLIP_DEFAULT_PRECIS, 5, VARIABLE_PITCH, "fixedsys");
      PopulateColorNamesListBox(hDialog);
      PopulateFontNamesListBox(hDialog);

      // Set Huey icon
      HICON programIcon = LoadIcon(GetModuleHandle(NULL), MAKEINTRESOURCE(ID_HUEY_ICON));
      SendMessage(hDialog, WM_SETICON, (WPARAM)ICON_SMALL, (LPARAM)programIcon);

      // Set default values
      SendDlgItemMessage(hDialog, ID_FONTSIZE_EDITBOX, WM_SETTEXT, 0, (LPARAM)"14");
      SendDlgItemMessage(hDialog, ID_BACKGROUNDCOLOR_LABEL, WM_SETTEXT, 0, (LPARAM)szBackgroundColor);
      SendDlgItemMessage(hDialog, ID_TEXTCOLOR_LABEL, WM_SETTEXT, 0, (LPARAM)szTextColor);

      // Set initial focus for radio buttons
      SendDlgItemMessage(hDialog, ID_BACKGROUND_RADIO, BM_SETCHECK, TRUE, 0);
      SendDlgItemMessage(hDialog, ID_HSV_RADIO, BM_SETCHECK, TRUE, 0);

      // Minimum slider value
      SendDlgItemMessage(hDialog, ID_SLIDER1, TBM_SETRANGEMIN, TRUE, 0);
      SendDlgItemMessage(hDialog, ID_SLIDER2, TBM_SETRANGEMIN, TRUE, 0);
      SendDlgItemMessage(hDialog, ID_SLIDER3, TBM_SETRANGEMIN, TRUE, 0);

      // Maximum slider value
      SendDlgItemMessage(hDialog, ID_SLIDER1, TBM_SETRANGEMAX, TRUE, MAX_BYTE);
      SendDlgItemMessage(hDialog, ID_SLIDER2, TBM_SETRANGEMAX, TRUE, MAX_BYTE);
      SendDlgItemMessage(hDialog, ID_SLIDER3, TBM_SETRANGEMAX, TRUE, MAX_BYTE);

      hEditControl = CreateWindowEx(
                       WS_EX_CLIENTEDGE, "EDIT", "",
                       WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | ES_MULTILINE |
                       ES_AUTOVSCROLL | ES_AUTOHSCROLL | ES_WANTRETURN, 545, 10, 500,
                       200, hDialog, (HMENU)107, GetModuleHandle(NULL), NULL);

      SetWindowText(hDialog, PROGRAM_NAME);

      if (hEditControl == NULL) {
        MessageBox(hDialog, "Could not create edit box.", "Error", MB_OK | MB_ICONERROR);
      } else {
        SendMessage(hEditControl, WM_SETTEXT, 0, (LPARAM)QUICK_BROWN_FOX);
      }
    }
    return TRUE;

    case WM_CLOSE: {
      EndDialog(hDialog, 0);
    }
    break;
    case WM_VSCROLL: {
      // Update slider labels everytime the sliders move.
      INT iSlider1 = SendDlgItemMessage(hDialog, ID_SLIDER1, TBM_GETPOS, 0, 0);
      INT iSlider2 = SendDlgItemMessage(hDialog, ID_SLIDER2, TBM_GETPOS, 0, 0);
      INT iSlider3 = SendDlgItemMessage(hDialog, ID_SLIDER3, TBM_GETPOS, 0, 0);

      struct rgb_color rgb;
      char szHexForm[10];
      if (IsDlgButtonChecked(hDialog, ID_HSV_RADIO)) {
        DOUBLE hue = normalize(iSlider1) * 360;
        DOUBLE saturation = normalize(iSlider2);
        DOUBLE value = normalize(iSlider3);
        rgb = HSV_to_RGB(hue, saturation, value);
        INT red, green, blue;
        red = discretize(rgb.red);
        green = discretize(rgb.green);
        blue = discretize(rgb.blue);
        sprintf(szHexForm, "#%02X%02X%02X", red, green, blue);
      } else if (IsDlgButtonChecked(hDialog, ID_CMY_RADIO)) {
        DOUBLE cyan = normalize(iSlider1);
        DOUBLE magenta = normalize(iSlider2);
        DOUBLE yellow = normalize(iSlider3);
        rgb = CMY_to_RGB(cyan, magenta, yellow);
        sprintf(szHexForm, "#%02X%02X%02X", (INT)rgb.red, (INT)rgb.green, (INT)rgb.blue);
      } else {
        sprintf(szHexForm, "#%02X%02X%02X", iSlider1, iSlider2, iSlider3);
      }

      if (IsDlgButtonChecked(hDialog, ID_BACKGROUND_RADIO)) {
        SendDlgItemMessage(hDialog, ID_BACKGROUNDCOLOR_LABEL, WM_SETTEXT, 0, (LPARAM)szHexForm);
        strcpy(szBackgroundColor, szHexForm);
      } else {
        SendDlgItemMessage(hDialog, ID_TEXTCOLOR_LABEL, WM_SETTEXT, 0, (LPARAM)szHexForm);
        strcpy(szTextColor, szHexForm);
      }

      ChangeSliderValues(hDialog, iSlider1, iSlider2, iSlider3);
      SendMessage(hEditControl, WM_SETFONT, (WPARAM)hfEditBoxFont, TRUE);
      SendMessage(hEditControl, WM_CTLCOLOREDIT, TRUE, (LPARAM)hEditControl);
    }
    break;
    case WM_CTLCOLORSTATIC: {
      // Set default font for labels/static controls
      HDC hDC = GetDC(NULL);
      LONG lFontHeight = -MulDiv(10, GetDeviceCaps(hDC, LOGPIXELSY), 72);
      ReleaseDC(NULL, hDC);
      HFONT hfStaticFont = CreateFont(
                             lFontHeight, 0, 0, 0, FW_DONTCARE, FALSE,
                             FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                             CLIP_DEFAULT_PRECIS, 5, VARIABLE_PITCH, "Consolas");
      hDC = (HDC)wParam;
      SelectObject(hDC, hfStaticFont);
      DeleteObject(hfStaticFont);
    }
    break;
    case WM_CTLCOLOREDIT: {
      // Change the main editbox color
      if ((HWND)lParam == hEditControl) {
        TEXTMETRIC tmEditBoxFont;
        GetTextMetrics((HDC)hEditControl, &tmEditBoxFont);
        struct rgb_color rgbText = hex_to_rgb(szTextColor);
        struct rgb_color rgbBack = hex_to_rgb(szBackgroundColor);
        COLORREF crBackColor = RGB(rgbBack.red, rgbBack.green, rgbBack.blue);
        COLORREF crTextColor = RGB(rgbText.red, rgbText.green, rgbText.blue);
        return ChangeTextColor(crBackColor, crTextColor, wParam);
      }
    }
    break;
    case WM_KILLFOCUS: {
      switch (LOWORD(wParam)) {
        case ID_FONTSIZE_EDITBOX: {
          SendMessage(hDialog, WM_COMMAND, (WPARAM)ID_FONTNAME_LISTBOX, 0);
          return 0;
        }
      }
    }
    break;
    case WM_COMMAND: {
      switch (LOWORD(wParam)) {
        case ID_SETSIZE_BUTTON: {
          SendMessage(hDialog, WM_COMMAND, (WPARAM)ID_FONTNAME_LISTBOX, 0);
        }
        break;
        case ID_CLIPBOARD_BUTTON: {
          char szCurrentColors[30];
          sprintf(szCurrentColors, "fore:%s,back:%s", szTextColor, szBackgroundColor);
          CopyTextToClipboard(szCurrentColors);
        }
        break;
        case ID_FONTSIZE_EDITBOX: {
          // Makes the font change in real-time
          SendMessage(hDialog, WM_COMMAND, (WPARAM)ID_FONTNAME_LISTBOX, 0);
        }
        break;
        case ID_SLIDER1_PLUS: {
          ChangeSliderValueByOne(hDialog, ID_SLIDER1, ID_SLIDER1_VALUE, TRUE);
          SendMessage(hDialog, WM_VSCROLL, SB_LINEDOWN, SB_THUMBPOSITION);
        }
        break;
        case ID_SLIDER2_PLUS: {
          ChangeSliderValueByOne(hDialog, ID_SLIDER2, ID_SLIDER2_VALUE, TRUE);
          SendMessage(hDialog, WM_VSCROLL, SB_LINEDOWN, SB_THUMBPOSITION);
        }
        break;
        case ID_SLIDER3_PLUS: {
          ChangeSliderValueByOne(hDialog, ID_SLIDER3, ID_SLIDER3_VALUE, TRUE);
          SendMessage(hDialog, WM_VSCROLL, SB_LINEDOWN, SB_THUMBPOSITION);
        }
        break;
        case ID_SLIDER1_MINUS: {
          ChangeSliderValueByOne(hDialog, ID_SLIDER1, ID_SLIDER1_VALUE, FALSE);
          SendMessage(hDialog, WM_VSCROLL, SB_LINEUP, SB_THUMBPOSITION);
        }
        break;
        case ID_SLIDER2_MINUS: {
          ChangeSliderValueByOne(hDialog, ID_SLIDER2, ID_SLIDER2_VALUE, FALSE);
          SendMessage(hDialog, WM_VSCROLL, SB_LINEUP, SB_THUMBPOSITION);
        }
        break;
        case ID_SLIDER3_MINUS: {
          ChangeSliderValueByOne(hDialog, ID_SLIDER3, ID_SLIDER3_VALUE, FALSE);
          SendMessage(hDialog, WM_VSCROLL, SB_LINEUP, SB_THUMBPOSITION);
        }
        break;
        case ID_COLORNAME_LISTBOX: {
          INT index = SendDlgItemMessage(hDialog, ID_COLORNAME_LISTBOX, LB_GETCURSEL, 0, 0);
          index = index < 0 ? 0 : index; // Helps prevent scanf segfault when there's no selection
          LPSTR rgb_value = RGB_COLORNAMES[index].rgb_value;
          if (IsDlgButtonChecked(hDialog, ID_BACKGROUND_RADIO) == BST_UNCHECKED) {
            strcpy(szTextColor, rgb_value);
            SendDlgItemMessage(hDialog, ID_TEXTCOLOR_LABEL, WM_SETTEXT, 0, (LPARAM)rgb_value);
          } else {
            strcpy(szBackgroundColor, rgb_value);
            SendDlgItemMessage(hDialog, ID_BACKGROUNDCOLOR_LABEL, WM_SETTEXT, 0, (LPARAM)rgb_value);
          }
          SendDlgItemMessage(hDialog, ID_COLORNAME_ENTRYBOX, WM_SETTEXT, 0, (LPARAM)rgb_value);
          SendMessage(hEditControl, WM_SETFONT, (WPARAM)hfEditBoxFont, TRUE);
          SendMessage(hEditControl, WM_CTLCOLOREDIT, TRUE, (LPARAM)hEditControl);
        }
        break;
        case ID_FONTNAME_LISTBOX: {
          LPSTR fontName;
          CHAR szFontSize[5];
          CHAR fontDescription[50] = {0};
          fontName = (LPSTR)GlobalAlloc(GPTR, 35);

          INT index = SendDlgItemMessage(hDialog, ID_FONTNAME_LISTBOX, LB_GETCURSEL, 0, 0);
          SendDlgItemMessage(hDialog, ID_FONTNAME_LISTBOX, LB_GETTEXT, index, (LPARAM)fontName);
          GetDlgItemText(hDialog, ID_FONTSIZE_EDITBOX, szFontSize, 4);

          sprintf(fontDescription, "%s %s", fontName, szFontSize);
          SendDlgItemMessage(hDialog, ID_FONTNAME_STATIC, WM_SETTEXT, 0, (LPARAM)fontDescription);
          INT iFontSize;
          sscanf(szFontSize, "%i", &iFontSize);
          if (strlen(szFontSize) == 0) {
            iFontSize = 1;
          }
          HDC hDC = GetDC(NULL);
          LONG lFontHeight = -MulDiv(iFontSize, GetDeviceCaps(hDC, LOGPIXELSY), 72);
          ReleaseDC(NULL, hDC);

          INT iFontWeight = FW_DONTCARE;
          BOOL bItalic = FALSE;

          if (bBoldSelected) {
            iFontWeight = FW_BOLD;
          }
          if (bItalicSelected) {
            bItalic = TRUE;
          }
          hfEditBoxFont = CreateFont(
                            lFontHeight, 0, 0, 0, iFontWeight, bItalic,
                            FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
                            CLIP_DEFAULT_PRECIS, 5, VARIABLE_PITCH, fontName);
          GlobalFree((HANDLE)fontName);

          SendMessage(hEditControl, WM_SETFONT, (WPARAM)hfEditBoxFont, TRUE);
          SendMessage(hEditControl, WM_CTLCOLOREDIT, TRUE, (LPARAM)hEditControl);
        }
        break;
        case ID_BACKGROUND_RADIO:
          // Intentional fall-through
        case ID_TEXT_RADIO: {
          // Change the slider values according to the selected color model
          if (IsDlgButtonChecked(hDialog, ID_HSV_RADIO)) {
            SendMessage(hDialog, WM_COMMAND, (WPARAM)ID_HSV_RADIO, 0);
          } else if (IsDlgButtonChecked(hDialog, ID_CMY_RADIO)) {
            SendMessage(hDialog, WM_COMMAND, (WPARAM)ID_CMY_RADIO, 0);
          } else {
            SendMessage(hDialog, WM_COMMAND, (WPARAM)ID_RGB_RADIO, 0);
          }
        }
        break;
        case ID_CMY_RADIO: {
          ChangeSliderLabel(hDialog, CMY_MODEL);
          struct rgb_color rgb;
          if (IsDlgButtonChecked(hDialog, ID_BACKGROUND_RADIO)) {
            rgb = hex_to_rgb(szBackgroundColor);
          } else {
            rgb = hex_to_rgb(szTextColor);
          }
          struct cmy_color cmy = RGB_to_CMY(rgb.red, rgb.green, rgb.blue);
          INT cyan = discretize(cmy.cyan);
          INT magenta = discretize(cmy.magenta);
          INT yellow = discretize(cmy.yellow);
          ChangeSliderValues(hDialog, cyan, magenta, yellow);
          ChangeSliderPos(hDialog, cyan, magenta, yellow);
        }
        break;
        case ID_RGB_RADIO: {
          struct rgb_color rgb;
          if (IsDlgButtonChecked(hDialog, ID_BACKGROUND_RADIO)) {
            rgb = hex_to_rgb(szBackgroundColor);
          } else {
            rgb = hex_to_rgb(szTextColor);
          }
          ChangeSliderLabel(hDialog, RGB_MODEL);
          ChangeSliderValues(hDialog, rgb.red, rgb.green, rgb.blue);
          ChangeSliderPos(hDialog, rgb.red, rgb.green, rgb.blue);
        }
        break;
        case ID_HSV_RADIO: {
          ChangeSliderLabel(hDialog, HSV_MODEL);
          struct rgb_color rgb;
          if (IsDlgButtonChecked(hDialog, ID_BACKGROUND_RADIO)) {
            rgb = hex_to_rgb(szBackgroundColor);
          } else {
            rgb = hex_to_rgb(szTextColor);
          }
          struct hsv_color hsv = RGB_to_HSV(normalize(rgb.red), normalize(rgb.green), normalize(rgb.blue));
          INT hue = discretize(hsv.hue / 360);
          INT saturation = discretize(hsv.saturation);
          INT value = discretize(hsv.value);

          ChangeSliderValues(hDialog, hue, saturation, value);
          ChangeSliderPos(hDialog, hue, saturation, value);
        }
        break;
        case ID_BOLD_CHECKBOX: {
          bBoldSelected = IsDlgButtonChecked(hDialog, ID_BOLD_CHECKBOX) == BST_CHECKED;
          // Make sure changes take place on being clicked
          SendMessage(hDialog, WM_COMMAND, (WPARAM)ID_FONTNAME_LISTBOX, 0);
        }
        break;
        case ID_ITALIC_CHECKBOX: {
          bItalicSelected = IsDlgButtonChecked(hDialog, ID_ITALIC_CHECKBOX) == BST_CHECKED;
          // Make sure changes take place on being clicked
          SendMessage(hDialog, WM_COMMAND, (WPARAM)ID_FONTNAME_LISTBOX, 0);
        }
        break;
        case ID_COLORNAME_ENTRYBOX: {
          CHAR szEnteredColor[9] = {0};
          GetDlgItemText(hDialog, ID_COLORNAME_ENTRYBOX, szEnteredColor, 8);
          if (strlen(szEnteredColor) < 7) {
            // Don't do anything if the user has entered less than six hex digits.
            break;
          }
          if (IsDlgButtonChecked(hDialog, ID_BACKGROUND_RADIO)) {
            strcpy(szBackgroundColor, szEnteredColor);
            SendDlgItemMessage(hDialog, ID_BACKGROUNDCOLOR_LABEL, WM_SETTEXT, 0, (LPARAM)szBackgroundColor);
          } else {
            strcpy(szTextColor, szEnteredColor);
            SendDlgItemMessage(hDialog, ID_TEXTCOLOR_LABEL, WM_SETTEXT, 0, (LPARAM)szTextColor);
          }
          SendMessage(hEditControl, WM_SETFONT, (WPARAM)hfEditBoxFont, TRUE);
          SendMessage(hEditControl, WM_CTLCOLOREDIT, TRUE, (LPARAM)hEditControl);
          // Change the slider values according to the selected color model
          if (IsDlgButtonChecked(hDialog, ID_HSV_RADIO)) {
            SendMessage(hDialog, WM_COMMAND, (WPARAM)ID_HSV_RADIO, 0);
          } else if (IsDlgButtonChecked(hDialog, ID_CMY_RADIO)) {
            SendMessage(hDialog, WM_COMMAND, (WPARAM)ID_CMY_RADIO, 0);
          } else {
            SendMessage(hDialog, WM_COMMAND, (WPARAM)ID_RGB_RADIO, 0);
          }
          for (INT i = 0; i < COLORNAMES; i++) {
            // Search for the entered color in the list and scroll to that position if found.
            if (strcmp(szEnteredColor, RGB_COLORNAMES[i].rgb_value) == 0) {
              SendDlgItemMessage(hDialog, ID_COLORNAME_LISTBOX, LB_SETCURSEL, i, TRUE);
              break;
            }
          }
        }
        break;
      }
    }
  }
  return FALSE;
}


INT APIENTRY WinMain(HINSTANCE hCurrInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nShowCmd) {
  HINSTANCE hInst = hCurrInstance;
  InitCommonControls();
  return DialogBox(hInst, MAKEINTRESOURCE(ID_MAIN_DIALOG), NULL, (DLGPROC)DialogProcedure);
}

