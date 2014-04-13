#ifndef COLORNAMES_H

#define COLORNAMES_H
#define COLORNAMES 502

struct RGB {
    char *rgb_value;
    char *color_name;
};

static struct RGB RGB_COLORNAMES[COLORNAMES] = {
    {"#F0F8FF", "Aliceblue"},
    {"#FAEBD7", "Antiquewhite"},
    {"#FFEFDB", "Antiquewhite1"},
    {"#EEDFCC", "Antiquewhite2"},
    {"#CDC0B0", "Antiquewhite3"},
    {"#8B8378", "Antiquewhite4"},
    {"#7FFFD4", "Aquamarine1"},
    {"#76EEC6", "Aquamarine2"},
    {"#66CDAA", "Aquamarine3"},
    {"#458B74", "Aquamarine4"},
    {"#F0FFFF", "Azure1"},
    {"#E0EEEE", "Azure2"},
    {"#C1CDCD", "Azure3"},
    {"#838B8B", "Azure4"},
    {"#F5F5DC", "Beige"},
    {"#FFE4C4", "Bisque1"},
    {"#EED5B7", "Bisque2"},
    {"#CDB79E", "Bisque3"},
    {"#8B7D6B", "Bisque4"},
    {"#FFEBCD", "Blanchedalmond"},
    {"#0000FF", "Blue1"},
    {"#0000EE", "Blue2"},
    {"#0000CD", "Blue3"},
    {"#8A2BE2", "Blueviolet"},
    {"#A52A2A", "Brown"},
    {"#FF4040", "Brown1"},
    {"#EE3B3B", "Brown2"},
    {"#CD3333", "Brown3"},
    {"#8B2323", "Brown4"},
    {"#DEB887", "Burlywood"},
    {"#FFD39B", "Burlywood1"},
    {"#EEC591", "Burlywood2"},
    {"#CDAA7D", "Burlywood3"},
    {"#8B7355", "Burlywood4"},
    {"#5F9EA0", "Cadetblue"},
    {"#98F5FF", "Cadetblue1"},
    {"#8EE5EE", "Cadetblue2"},
    {"#7AC5CD", "Cadetblue3"},
    {"#53868B", "Cadetblue4"},
    {"#7FFF00", "Chartreuse1"},
    {"#76EE00", "Chartreuse2"},
    {"#66CD00", "Chartreuse3"},
    {"#458B00", "Chartreuse4"},
    {"#D2691E", "Chocolate"},
    {"#FF7F24", "Chocolate1"},
    {"#EE7621", "Chocolate2"},
    {"#CD661D", "Chocolate3"},
    {"#8B4513", "Chocolate4"},
    {"#FF7F50", "Coral"},
    {"#FF7256", "Coral1"},
    {"#EE6A50", "Coral2"},
    {"#CD5B45", "Coral3"},
    {"#8B3E2F", "Coral4"},
    {"#6495ED", "Cornflowerblue"},
    {"#FFF8DC", "Cornsilk1"},
    {"#EEE8CD", "Cornsilk2"},
    {"#CDC8B1", "Cornsilk3"},
    {"#8B8878", "Cornsilk4"},
    {"#00FFFF", "Cyan1"},
    {"#00EEEE", "Cyan2"},
    {"#00CDCD", "Cyan3"},
    {"#00008B", "Darkblue"},
    {"#008B8B", "Darkcyan"},
    {"#B8860B", "Darkgoldenrod"},
    {"#FFB90F", "Darkgoldenrod1"},
    {"#EEAD0E", "Darkgoldenrod2"},
    {"#CD950C", "Darkgoldenrod3"},
    {"#8B6508", "Darkgoldenrod4"},
    {"#A9A9A9", "Darkgray"},
    {"#006400", "Darkgreen"},
    {"#BDB76B", "Darkkhaki"},
    {"#8B008B", "Darkmagenta"},
    {"#556B2F", "Darkolivegreen"},
    {"#CAFF70", "Darkolivegreen1"},
    {"#BCEE68", "Darkolivegreen2"},
    {"#A2CD5A", "Darkolivegreen3"},
    {"#6E8B3D", "Darkolivegreen4"},
    {"#FF8C00", "Darkorange"},
    {"#FF7F00", "Darkorange1"},
    {"#EE7600", "Darkorange2"},
    {"#CD6600", "Darkorange3"},
    {"#8B4500", "Darkorange4"},
    {"#9932CC", "Darkorchid"},
    {"#BF3EFF", "Darkorchid1"},
    {"#B23AEE", "Darkorchid2"},
    {"#9A32CD", "Darkorchid3"},
    {"#68228B", "Darkorchid4"},
    {"#8B0000", "Darkred"},
    {"#E9967A", "Darksalmon"},
    {"#8FBC8F", "Darkseagreen"},
    {"#C1FFC1", "Darkseagreen1"},
    {"#B4EEB4", "Darkseagreen2"},
    {"#9BCD9B", "Darkseagreen3"},
    {"#698B69", "Darkseagreen4"},
    {"#483D8B", "Darkslateblue"},
    {"#97FFFF", "Darkslategray1"},
    {"#8DEEEE", "Darkslategray2"},
    {"#79CDCD", "Darkslategray3"},
    {"#528B8B", "Darkslategray4"},
    {"#2F4F4F", "Darkslategrey"},
    {"#00CED1", "Darkturquoise"},
    {"#9400D3", "Darkviolet"},
    {"#FF1493", "Deeppink1"},
    {"#EE1289", "Deeppink2"},
    {"#CD1076", "Deeppink3"},
    {"#8B0A50", "Deeppink4"},
    {"#00BFFF", "Deepskyblue1"},
    {"#00B2EE", "Deepskyblue2"},
    {"#009ACD", "Deepskyblue3"},
    {"#00688B", "Deepskyblue4"},
    {"#1E90FF", "Dodgerblue1"},
    {"#1C86EE", "Dodgerblue2"},
    {"#1874CD", "Dodgerblue3"},
    {"#104E8B", "Dodgerblue4"},
    {"#B22222", "Firebrick"},
    {"#FF3030", "Firebrick1"},
    {"#EE2C2C", "Firebrick2"},
    {"#CD2626", "Firebrick3"},
    {"#8B1A1A", "Firebrick4"},
    {"#FFFAF0", "Floralwhite"},
    {"#228B22", "Forestgreen"},
    {"#DCDCDC", "Gainsboro"},
    {"#F8F8FF", "Ghostwhite"},
    {"#FFD700", "Gold1"},
    {"#EEC900", "Gold2"},
    {"#CDAD00", "Gold3"},
    {"#8B7500", "Gold4"},
    {"#DAA520", "Goldenrod"},
    {"#FFC125", "Goldenrod1"},
    {"#EEB422", "Goldenrod2"},
    {"#CD9B1D", "Goldenrod3"},
    {"#8B6914", "Goldenrod4"},
    {"#00FF00", "Green1"},
    {"#00EE00", "Green2"},
    {"#00CD00", "Green3"},
    {"#008B00", "Green4"},
    {"#ADFF2F", "Greenyellow"},
    {"#BEBEBE", "Grey"},
    {"#000000", "Grey0"},
    {"#030303", "Grey1"},
    {"#1A1A1A", "Grey10"},
    {"#FFFFFF", "Grey100"},
    {"#1C1C1C", "Grey11"},
    {"#1F1F1F", "Grey12"},
    {"#212121", "Grey13"},
    {"#242424", "Grey14"},
    {"#262626", "Grey15"},
    {"#292929", "Grey16"},
    {"#2B2B2B", "Grey17"},
    {"#2E2E2E", "Grey18"},
    {"#303030", "Grey19"},
    {"#050505", "Grey2"},
    {"#333333", "Grey20"},
    {"#363636", "Grey21"},
    {"#383838", "Grey22"},
    {"#3B3B3B", "Grey23"},
    {"#3D3D3D", "Grey24"},
    {"#404040", "Grey25"},
    {"#424242", "Grey26"},
    {"#454545", "Grey27"},
    {"#474747", "Grey28"},
    {"#4A4A4A", "Grey29"},
    {"#080808", "Grey3"},
    {"#4D4D4D", "Grey30"},
    {"#4F4F4F", "Grey31"},
    {"#525252", "Grey32"},
    {"#545454", "Grey33"},
    {"#575757", "Grey34"},
    {"#595959", "Grey35"},
    {"#5C5C5C", "Grey36"},
    {"#5E5E5E", "Grey37"},
    {"#616161", "Grey38"},
    {"#636363", "Grey39"},
    {"#0A0A0A", "Grey4"},
    {"#666666", "Grey40"},
    {"#696969", "Grey41"},
    {"#6B6B6B", "Grey42"},
    {"#6E6E6E", "Grey43"},
    {"#707070", "Grey44"},
    {"#737373", "Grey45"},
    {"#757575", "Grey46"},
    {"#787878", "Grey47"},
    {"#7A7A7A", "Grey48"},
    {"#7D7D7D", "Grey49"},
    {"#0D0D0D", "Grey5"},
    {"#7F7F7F", "Grey50"},
    {"#828282", "Grey51"},
    {"#858585", "Grey52"},
    {"#878787", "Grey53"},
    {"#8A8A8A", "Grey54"},
    {"#8C8C8C", "Grey55"},
    {"#8F8F8F", "Grey56"},
    {"#919191", "Grey57"},
    {"#949494", "Grey58"},
    {"#969696", "Grey59"},
    {"#0F0F0F", "Grey6"},
    {"#999999", "Grey60"},
    {"#9C9C9C", "Grey61"},
    {"#9E9E9E", "Grey62"},
    {"#A1A1A1", "Grey63"},
    {"#A3A3A3", "Grey64"},
    {"#A6A6A6", "Grey65"},
    {"#A8A8A8", "Grey66"},
    {"#ABABAB", "Grey67"},
    {"#ADADAD", "Grey68"},
    {"#B0B0B0", "Grey69"},
    {"#121212", "Grey7"},
    {"#B3B3B3", "Grey70"},
    {"#B5B5B5", "Grey71"},
    {"#B8B8B8", "Grey72"},
    {"#BABABA", "Grey73"},
    {"#BDBDBD", "Grey74"},
    {"#BFBFBF", "Grey75"},
    {"#C2C2C2", "Grey76"},
    {"#C4C4C4", "Grey77"},
    {"#C7C7C7", "Grey78"},
    {"#C9C9C9", "Grey79"},
    {"#141414", "Grey8"},
    {"#CCCCCC", "Grey80"},
    {"#CFCFCF", "Grey81"},
    {"#D1D1D1", "Grey82"},
    {"#D4D4D4", "Grey83"},
    {"#D6D6D6", "Grey84"},
    {"#D9D9D9", "Grey85"},
    {"#DBDBDB", "Grey86"},
    {"#DEDEDE", "Grey87"},
    {"#E0E0E0", "Grey88"},
    {"#E3E3E3", "Grey89"},
    {"#171717", "Grey9"},
    {"#E5E5E5", "Grey90"},
    {"#E8E8E8", "Grey91"},
    {"#EBEBEB", "Grey92"},
    {"#EDEDED", "Grey93"},
    {"#F0F0F0", "Grey94"},
    {"#F2F2F2", "Grey95"},
    {"#F5F5F5", "Grey96"},
    {"#F7F7F7", "Grey97"},
    {"#FAFAFA", "Grey98"},
    {"#FCFCFC", "Grey99"},
    {"#F0FFF0", "Honeydew1"},
    {"#E0EEE0", "Honeydew2"},
    {"#C1CDC1", "Honeydew3"},
    {"#838B83", "Honeydew4"},
    {"#FF69B4", "Hotpink"},
    {"#FF6EB4", "Hotpink1"},
    {"#EE6AA7", "Hotpink2"},
    {"#CD6090", "Hotpink3"},
    {"#8B3A62", "Hotpink4"},
    {"#CD5C5C", "Indianred"},
    {"#FF6A6A", "Indianred1"},
    {"#EE6363", "Indianred2"},
    {"#CD5555", "Indianred3"},
    {"#8B3A3A", "Indianred4"},
    {"#FFFFF0", "Ivory1"},
    {"#EEEEE0", "Ivory2"},
    {"#CDCDC1", "Ivory3"},
    {"#8B8B83", "Ivory4"},
    {"#F0E68C", "Khaki"},
    {"#FFF68F", "Khaki1"},
    {"#EEE685", "Khaki2"},
    {"#CDC673", "Khaki3"},
    {"#8B864E", "Khaki4"},
    {"#E6E6FA", "Lavender"},
    {"#FFF0F5", "Lavenderblush1"},
    {"#EEE0E5", "Lavenderblush2"},
    {"#CDC1C5", "Lavenderblush3"},
    {"#8B8386", "Lavenderblush4"},
    {"#7CFC00", "Lawngreen"},
    {"#FFFACD", "Lemonchiffon1"},
    {"#EEE9BF", "Lemonchiffon2"},
    {"#CDC9A5", "Lemonchiffon3"},
    {"#8B8970", "Lemonchiffon4"},
    {"#ADD8E6", "Lightblue"},
    {"#BFEFFF", "Lightblue1"},
    {"#B2DFEE", "Lightblue2"},
    {"#9AC0CD", "Lightblue3"},
    {"#68838B", "Lightblue4"},
    {"#F08080", "Lightcoral"},
    {"#E0FFFF", "Lightcyan1"},
    {"#D1EEEE", "Lightcyan2"},
    {"#B4CDCD", "Lightcyan3"},
    {"#7A8B8B", "Lightcyan4"},
    {"#EEDD82", "Lightgoldenrod"},
    {"#FFEC8B", "Lightgoldenrod1"},
    {"#EEDC82", "Lightgoldenrod2"},
    {"#CDBE70", "Lightgoldenrod3"},
    {"#8B814C", "Lightgoldenrod4"},
    {"#FAFAD2", "Lightgoldenrodyellow"},
    {"#D3D3D3", "Lightgray"},
    {"#90EE90", "Lightgreen"},
    {"#FFB6C1", "Lightpink"},
    {"#FFAEB9", "Lightpink1"},
    {"#EEA2AD", "Lightpink2"},
    {"#CD8C95", "Lightpink3"},
    {"#8B5F65", "Lightpink4"},
    {"#FFA07A", "Lightsalmon1"},
    {"#EE9572", "Lightsalmon2"},
    {"#CD8162", "Lightsalmon3"},
    {"#8B5742", "Lightsalmon4"},
    {"#20B2AA", "Lightseagreen"},
    {"#87CEFA", "Lightskyblue"},
    {"#B0E2FF", "Lightskyblue1"},
    {"#A4D3EE", "Lightskyblue2"},
    {"#8DB6CD", "Lightskyblue3"},
    {"#607B8B", "Lightskyblue4"},
    {"#8470FF", "Lightslateblue"},
    {"#778899", "Lightslategrey"},
    {"#B0C4DE", "Lightsteelblue"},
    {"#CAE1FF", "Lightsteelblue1"},
    {"#BCD2EE", "Lightsteelblue2"},
    {"#A2B5CD", "Lightsteelblue3"},
    {"#6E7B8B", "Lightsteelblue4"},
    {"#FFFFE0", "Lightyellow1"},
    {"#EEEED1", "Lightyellow2"},
    {"#CDCDB4", "Lightyellow3"},
    {"#8B8B7A", "Lightyellow4"},
    {"#32CD32", "Limegreen"},
    {"#FAF0E6", "Linen"},
    {"#FF00FF", "Magenta1"},
    {"#EE00EE", "Magenta2"},
    {"#CD00CD", "Magenta3"},
    {"#B03060", "Maroon"},
    {"#FF34B3", "Maroon1"},
    {"#EE30A7", "Maroon2"},
    {"#CD2990", "Maroon3"},
    {"#8B1C62", "Maroon4"},
    {"#BA55D3", "Mediumorchid"},
    {"#E066FF", "Mediumorchid1"},
    {"#D15FEE", "Mediumorchid2"},
    {"#B452CD", "Mediumorchid3"},
    {"#7A378B", "Mediumorchid4"},
    {"#9370DB", "Mediumpurple"},
    {"#AB82FF", "Mediumpurple1"},
    {"#9F79EE", "Mediumpurple2"},
    {"#8968CD", "Mediumpurple3"},
    {"#5D478B", "Mediumpurple4"},
    {"#3CB371", "Mediumseagreen"},
    {"#7B68EE", "Mediumslateblue"},
    {"#00FA9A", "Mediumspringgreen"},
    {"#48D1CC", "Mediumturquoise"},
    {"#C71585", "Mediumvioletred"},
    {"#191970", "Midnightblue"},
    {"#F5FFFA", "Mintcream"},
    {"#FFE4E1", "Mistyrose1"},
    {"#EED5D2", "Mistyrose2"},
    {"#CDB7B5", "Mistyrose3"},
    {"#8B7D7B", "Mistyrose4"},
    {"#FFE4B5", "Moccasin"},
    {"#FFDEAD", "Navajowhite1"},
    {"#EECFA1", "Navajowhite2"},
    {"#CDB38B", "Navajowhite3"},
    {"#8B795E", "Navajowhite4"},
    {"#000080", "Navyblue"},
    {"#FDF5E6", "Oldlace"},
    {"#6B8E23", "Olivedrab"},
    {"#C0FF3E", "Olivedrab1"},
    {"#B3EE3A", "Olivedrab2"},
    {"#9ACD32", "Olivedrab3"},
    {"#698B22", "Olivedrab4"},
    {"#FFA500", "Orange1"},
    {"#EE9A00", "Orange2"},
    {"#CD8500", "Orange3"},
    {"#8B5A00", "Orange4"},
    {"#FF4500", "Orangered1"},
    {"#EE4000", "Orangered2"},
    {"#CD3700", "Orangered3"},
    {"#8B2500", "Orangered4"},
    {"#DA70D6", "Orchid"},
    {"#FF83FA", "Orchid1"},
    {"#EE7AE9", "Orchid2"},
    {"#CD69C9", "Orchid3"},
    {"#8B4789", "Orchid4"},
    {"#EEE8AA", "Palegoldenrod"},
    {"#98FB98", "Palegreen"},
    {"#9AFF9A", "Palegreen1"},
    {"#7CCD7C", "Palegreen3"},
    {"#548B54", "Palegreen4"},
    {"#AFEEEE", "Paleturquoise"},
    {"#BBFFFF", "Paleturquoise1"},
    {"#AEEEEE", "Paleturquoise2"},
    {"#96CDCD", "Paleturquoise3"},
    {"#668B8B", "Paleturquoise4"},
    {"#DB7093", "Palevioletred"},
    {"#FF82AB", "Palevioletred1"},
    {"#EE799F", "Palevioletred2"},
    {"#CD6889", "Palevioletred3"},
    {"#8B475D", "Palevioletred4"},
    {"#FFEFD5", "Papayawhip"},
    {"#FFDAB9", "Peachpuff1"},
    {"#EECBAD", "Peachpuff2"},
    {"#CDAF95", "Peachpuff3"},
    {"#8B7765", "Peachpuff4"},
    {"#FFC0CB", "Pink"},
    {"#FFB5C5", "Pink1"},
    {"#EEA9B8", "Pink2"},
    {"#CD919E", "Pink3"},
    {"#8B636C", "Pink4"},
    {"#DDA0DD", "Plum"},
    {"#FFBBFF", "Plum1"},
    {"#EEAEEE", "Plum2"},
    {"#CD96CD", "Plum3"},
    {"#8B668B", "Plum4"},
    {"#B0E0E6", "Powderblue"},
    {"#A020F0", "Purple"},
    {"#9B30FF", "Purple1"},
    {"#912CEE", "Purple2"},
    {"#7D26CD", "Purple3"},
    {"#551A8B", "Purple4"},
    {"#FF0000", "Red1"},
    {"#EE0000", "Red2"},
    {"#CD0000", "Red3"},
    {"#BC8F8F", "Rosybrown"},
    {"#FFC1C1", "Rosybrown1"},
    {"#EEB4B4", "Rosybrown2"},
    {"#CD9B9B", "Rosybrown3"},
    {"#8B6969", "Rosybrown4"},
    {"#4169E1", "Royalblue"},
    {"#4876FF", "Royalblue1"},
    {"#436EEE", "Royalblue2"},
    {"#3A5FCD", "Royalblue3"},
    {"#27408B", "Royalblue4"},
    {"#FA8072", "Salmon"},
    {"#FF8C69", "Salmon1"},
    {"#EE8262", "Salmon2"},
    {"#CD7054", "Salmon3"},
    {"#8B4C39", "Salmon4"},
    {"#F4A460", "Sandybrown"},
    {"#54FF9F", "Seagreen1"},
    {"#4EEE94", "Seagreen2"},
    {"#43CD80", "Seagreen3"},
    {"#2E8B57", "Seagreen4"},
    {"#FFF5EE", "Seashell1"},
    {"#EEE5DE", "Seashell2"},
    {"#CDC5BF", "Seashell3"},
    {"#8B8682", "Seashell4"},
    {"#A0522D", "Sienna"},
    {"#FF8247", "Sienna1"},
    {"#EE7942", "Sienna2"},
    {"#CD6839", "Sienna3"},
    {"#8B4726", "Sienna4"},
    {"#87CEEB", "Skyblue"},
    {"#87CEFF", "Skyblue1"},
    {"#7EC0EE", "Skyblue2"},
    {"#6CA6CD", "Skyblue3"},
    {"#4A708B", "Skyblue4"},
    {"#6A5ACD", "Slateblue"},
    {"#836FFF", "Slateblue1"},
    {"#7A67EE", "Slateblue2"},
    {"#6959CD", "Slateblue3"},
    {"#473C8B", "Slateblue4"},
    {"#C6E2FF", "Slategray1"},
    {"#B9D3EE", "Slategray2"},
    {"#9FB6CD", "Slategray3"},
    {"#6C7B8B", "Slategray4"},
    {"#708090", "Slategrey"},
    {"#FFFAFA", "Snow1"},
    {"#EEE9E9", "Snow2"},
    {"#CDC9C9", "Snow3"},
    {"#8B8989", "Snow4"},
    {"#00FF7F", "Springgreen1"},
    {"#00EE76", "Springgreen2"},
    {"#00CD66", "Springgreen3"},
    {"#008B45", "Springgreen4"},
    {"#4682B4", "Steelblue"},
    {"#63B8FF", "Steelblue1"},
    {"#5CACEE", "Steelblue2"},
    {"#4F94CD", "Steelblue3"},
    {"#36648B", "Steelblue4"},
    {"#D2B48C", "Tan"},
    {"#FFA54F", "Tan1"},
    {"#EE9A49", "Tan2"},
    {"#CD853F", "Tan3"},
    {"#8B5A2B", "Tan4"},
    {"#D8BFD8", "Thistle"},
    {"#FFE1FF", "Thistle1"},
    {"#EED2EE", "Thistle2"},
    {"#CDB5CD", "Thistle3"},
    {"#8B7B8B", "Thistle4"},
    {"#FF6347", "Tomato1"},
    {"#EE5C42", "Tomato2"},
    {"#CD4F39", "Tomato3"},
    {"#8B3626", "Tomato4"},
    {"#40E0D0", "Turquoise"},
    {"#00F5FF", "Turquoise1"},
    {"#00E5EE", "Turquoise2"},
    {"#00C5CD", "Turquoise3"},
    {"#00868B", "Turquoise4"},
    {"#EE82EE", "Violet"},
    {"#D02090", "Violetred"},
    {"#FF3E96", "Violetred1"},
    {"#EE3A8C", "Violetred2"},
    {"#CD3278", "Violetred3"},
    {"#8B2252", "Violetred4"},
    {"#F5DEB3", "Wheat"},
    {"#FFE7BA", "Wheat1"},
    {"#EED8AE", "Wheat2"},
    {"#CDBA96", "Wheat3"},
    {"#8B7E66", "Wheat4"},
    {"#FFFF00", "Yellow1"},
    {"#EEEE00", "Yellow2"},
    {"#CDCD00", "Yellow3"},
    {"#8B8B00", "Yellow4"}
};

#endif
