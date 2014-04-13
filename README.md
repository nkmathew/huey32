###huey32: A color and font selection tool


**huey32** is a port of the [Tkinter](http://wiki.python.org/moin/Tkinter) program found [here.](
infohost.nmt.edu/tcc/help/lang/python/examples/huey/)

It's a test bed for all the [WinAPI](http://msdn.microsoft.com/en-us/library/ff818516.aspx) concepts I've been meaning to put to practice.

You can build it using either of these two commands:

    :: The first one will simply do what the second does and run the program for you.
    cd huey32 && build
    cd huey32\src && make && cd ..


#### Drawbacks
Some of the program's shortcomings:

+ It's reliance on `SetBkMode(hDC, TRANSPARENT)` causes the text in the edit box to *'bleed'* when you
  try to enter something.
+ Moving the sliders causes the edit box to flicker sometimes possibly because it's not being drawn
  fast enough.

The upside is, it has more functionality than its counterpart and a bit of eyecandy.



#### Screengrabs
![A screenshot of WinAPI huey32](http://i.imgur.com/zq1a3pF.png)

![A screenshot of Tkinter huey](http://imgur.com/EXGvpU9.png)

