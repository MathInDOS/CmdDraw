# CmdDraw - A portable command line drawing tool


# What is CmdDraw?

CmdDraw is a small program which enables drawing on cmd with Math and some basic algorithums.

# How to use it?

First you need to call cmddraw.exe and then gives it's parameters. After that you need to provide some basic Math's and pointers to draw something on console window.


# 1) Functions

There are some functions about it. Let's see it.

`/dline` - Draw line

This parameter is used to draw line, starting to end and starting to end (ax to ay, bx to by)

`/drec` - Draw Rectangle

To draw rectangle you need to use this function. It is same method like draw line.

`/delip` - Draw Ellipse

To draw ellipse from point 0 you can use this thing. 

`/dcurv` - Draw curve

This type functions some tricky but it is really easy. First we need to provide all pointers from first starting to first ending and vice-versa.

Totally you need to provide 8 points of curve.

Example: cmddraw /dcurv 100 100 200 50 400 10 500 100 /rgb 0 255 0 /pw 5

As you can see that point 100 means where starting the curve. To increase every points you can do that.

Now you shall thought what is /rgb and /pw, with this parameter I will discuss, so don't worry.

`/dccurv` - Draw Close curve

It is some diffecult for first users, you need to provide 14 points here.

Example: cmddraw /dccurv 100.0f 100.0f 200.0f 50.0f 400.0f 10.0f 500.0f 100.0f 600.0f 200.0f 700.0f 400.0f 500.0f 500.0f /rgb 0 255 0 /pw 5

If you follow this line you can thought what is .0f, acctually it's not important that you need to provide .0f, you can do it without it, .0f like OpenGL.

`/dbezr` - Draw beziers

If you want to draw beziers on cmd you can do it by this command, it parameters are almost same as /dccurv but there are some difference of them.

To use it you need to provide 14 points on cmd.

Example: cmddraw /dbezr 100.0f 100.0f 200.0f 50.0f 400.0f 10.0f 500.0f 100.0f 600.0f 200.0f 700.0f 400.0f 500.0f 500.0f /rgb 0 255 0 /pw 5

Note: You can remove .0f for your works.

`/darc` - Draw arc

To draw a arc on console you need to provide 4 points on cmd. It is very easy than curve or beziers but don't forget that arc always have a angle and skipangle.

Example: cmddraw /darc 100 100 100 100 /ag 360 /sp 180 /rgb 0 255 0 /pw 5

Tip: Arc always have skip points you can provide /sp 360 to draw a circle by arc command.

`/dtran` - Draw Traingle

To draw a perfect traingle you can try it! In this command it have 6 points as a traingle needs.

Example: cmddraw /dtran 90 90 200 200 100 205 /rgb 0 255 0 /pw 5

Tip: To make it perfect give it focus point.

`/dcir` - Draw Circle

This function as looks same which we discuss before on Arc but it's lot easy than Arc. Here is 3 points (x, y, radius)

Example: cmddraw /dcir 100 100 50 /rgb 0 255 0 /pw 5

Tip: To draw small circles reduce radius.

`/dpie` - Draw Pie

If you want to draw a pie on console you can try it.

Example: cmddraw /dpie 100 100 100 100 100 100 /rgb 0 255 0 /pw 5

`/dpol` - Draw Polygon

Draw a polygon on console. Here is 10 points to locate your polygon.

Example: cmddraw /dpol 100 100 200 130 150 200 50 200 0 130 /rgb 0 255 0 /pw 5


# Let's discuss some other parameters.

`/rgb` - Red, Green, Blue

Mix RGB colors to get more colors on drawing.

`/pw` - Pointer size

Change pointer size to get more small/big brush.

`/ag` - Angle

To define angle.

`/sp` - Sweepangle

Define how much angle you want to sweep.

`/color` - Change color

To change console color.

`/trans /con` - Change console tranparency.

You can put /trans [window] [percentange] to transparent a window else /trans /con [percentage] to transparent current cmd.


# Show images on cmd

If you want to show images on cmd and finding a tool this is maybe perfect for you, against insertbmp.

InsertBmp only supports .bmp images but usually bmp images are too big. Using CmdDraw you can use bmp, png, jpg, gif (Non-Animated), tiff image formats.

To show images type cmddraw /dimg [image file] /x [X position] /y [Y position]


# Some images of this tool

<a href="https://ibb.co/whkNfrD"><img src="https://i.ibb.co/whkNfrD/Screen-Shot-20201224142957.png" alt="Screen-Shot-20201224142957" border="0"></a>

# About

Merry christmas all of you! :)

Build Date: 24 December 2020

Publish Date: 25 December 2020

License: GNU GPLv3

Copyright (C) 2018-2020 MathInDOS




