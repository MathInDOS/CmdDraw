/*
 CmdDraw - A portable command line drawing tool
 Copyright (C) 2018-2020 MathInDOS
 
 License: GNU GPLv3
 
 To know about GPL License, how it's work, terms and conditions please check out LICENSE file.
 
 Requirements:
 -------------
 
 Starting from Windows XP to Windows 10
 (Only stay for Windows Operating System)
 
 Build Log:
 ----------
 
 CmdDraw Version-1.0 Build Date: 24 December 2020
 Enables you to draw images, geometry, transparency, colors in here.
 + Draw your shapes
 + Easily choose colors by R(Red) G(Green) B(Blue) ratio.
 + Draw with effective shapes.
 
 
 CmdDraw Version-1.2 Build Date: 31 December 2020
 + Added draw star function.
 + Write more effective with select your font and size.
 + Added Font function.
 + Added Hex2RGB program to easily select RGB colors.
 + Fix little bugs.
 + Security fixes.
 
 Bugs:
 -----
 - To draw Ellipse you may faced some Math issues.
 - Sometimes if parameters are wrong or missing then "APPCRASH".
 - If you are using Windows 10 and in cmd if legacy mode isn't enable the this program doesn't working anymore.
 
 Contact:
 --------
 Join our Discord server at: https://discord.gg/E5qYx7WYef
 Or
 E-Mail: mathindossoftwares@yahoo.com
 
*/

#include <windows.h>
#include <gdiplus.h>
#include <string>
#include <iostream>

int wmain(int argc, wchar_t *argv[])
{
	// startup config
	
	if(argv[1]==NULL)return 1;
	HDC hdc = GetDC(GetConsoleWindow());

	Gdiplus::GdiplusStartupInput gsi;
	ULONG_PTR tok;
	Gdiplus::GdiplusStartup(&tok, &gsi, nullptr);
	Gdiplus::Graphics gf(hdc);

	if(!_wcsicmp(argv[1], L"/dimg") && !_wcsicmp(argv[3], L"/x") && !_wcsicmp(argv[5], L"/y"))
	{
		if(argv[2]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[6]==NULL)return 1;
		Gdiplus::Bitmap image(argv[2]);
		float gex = (float)wcstol(argv[4], nullptr, 0);
		float gey = (float)wcstol(argv[6], nullptr, 0);
		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		gf.DrawImage(&image, gex, gey);
	}
	/* draw line */
	else if(!_wcsicmp(argv[1], L"/dline") && !_wcsicmp(argv[6], L"/rgb") && !_wcsicmp(argv[10], L"/pw"))
	{
		if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[5]==NULL)return 1; if(argv[6]==NULL)return 1; if(argv[7]==NULL)return 1; if(argv[8]==NULL)return 1;
		
		int r = (int)wcstol(argv[7], nullptr, 0);
		int g = (int)wcstol(argv[8], nullptr, 0);
		int b = (int)wcstol(argv[9], nullptr, 0);

		if(argv[11]==NULL)return 1;
		int size = (int)wcstol(argv[11], nullptr, 0);
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), size);
		float cx = (float)wcstol(argv[2], nullptr, 0);
		float cy = (float)wcstol(argv[3], nullptr, 0);
		float gx = (float)wcstol(argv[4], nullptr, 0);
		float gy = (float)wcstol(argv[5], nullptr, 0);
		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		gf.DrawLine(&pen, cx, cy, gx, gy);
		// gf.DrawPolygon(&pen,200, );
	}
	/* draw rectangle */
	else if(!_wcsicmp(argv[1], L"/drec") && !_wcsicmp(argv[6], L"/rgb") && !_wcsicmp(argv[10], L"/pw"))
	{
		if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[5]==NULL)return 1;  if(argv[7]==NULL)return 1; if(argv[8]==NULL)return 1; if(argv[9]==NULL)return 1;
		int r = (int)wcstol(argv[7], nullptr, 0);
		int g = (int)wcstol(argv[8], nullptr, 0);
		int b = (int)wcstol(argv[9], nullptr, 0);

		if(argv[11]==NULL)return 1;
		int size = (int)wcstol(argv[11], nullptr, 0);

		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), size);
		float cx = (float)wcstol(argv[2], nullptr, 0);
		float cy = (float)wcstol(argv[3], nullptr, 0);
		float gx = (float)wcstol(argv[4], nullptr, 0);
		float gy = (float)wcstol(argv[5], nullptr, 0);
		Gdiplus::RectF rect(cx, cy, gx, gy);

		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		gf.DrawRectangle(&pen, rect);

		// Fill up
		if(!_wcsicmp(argv[12], L"/fill") && !_wcsicmp(argv[13], L"/rgb"))
		{
			if(argv[14]==NULL)return 1; if(argv[15]==NULL)return 1; if(argv[16]==NULL)return 1;
			int r = (int)wcstol(argv[14], nullptr, 0);
		    int g = (int)wcstol(argv[15], nullptr, 0);
		    int b = (int)wcstol(argv[16], nullptr, 0);
			
			Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
			gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
			gf.FillRectangle(&brush, rect);
		}else{
			return 0;
		}
	}
	/* draw ellipse */
	else if(!_wcsicmp(argv[1], L"/delip") && !_wcsicmp(argv[6], L"/rgb"))
	{
		if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[5]==NULL)return 1; if(argv[7]==NULL)return 1; if(argv[8]==NULL)return 1; if(argv[9]==NULL)return 1;
		int r = (int)wcstol(argv[7], nullptr, 0);
		int g = (int)wcstol(argv[8], nullptr, 0);
		int b = (int)wcstol(argv[9], nullptr, 0);

		Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
		float cx = (float)wcstol(argv[2], nullptr, 0);
		float cy = (float)wcstol(argv[3], nullptr, 0);
		float gx = (float)wcstol(argv[4], nullptr, 0);
		float gy = (float)wcstol(argv[5], nullptr, 0);
		for(UINT i = 0; i < cy; i++)
		{
			gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		    gf.FillEllipse(&brush, cx, i, gx, gy); // x y
	}}
	/* draw curve */
	else if(!_wcsicmp(argv[1], L"/dcurv") && !_wcsicmp(argv[10], L"/rgb") && !_wcsicmp(argv[14], L"/pw"))
	{
		if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[5]==NULL)return 1; if(argv[6]==NULL)return 1; if(argv[7]==NULL)return 1; if(argv[8]==NULL)return 1; if(argv[9]==NULL)return 1;
		float x1 = (float)wcstol(argv[2], nullptr, 0);
		float x2 = (float)wcstol(argv[3], nullptr, 0);
		float x3 = (float)wcstol(argv[4], nullptr, 0);
		float x4 = (float)wcstol(argv[5], nullptr, 0);
		float x5 = (float)wcstol(argv[6], nullptr, 0);
		float x6 = (float)wcstol(argv[7], nullptr, 0);
		float x7 = (float)wcstol(argv[8], nullptr, 0);
		float x8 = (float)wcstol(argv[9], nullptr, 0);

		Gdiplus::Point point1(x1, x2);
		Gdiplus::Point point2(x3, x4);
		Gdiplus::Point point3(x5, x6);
		Gdiplus::Point point4(x7, x8);

		Gdiplus::Point curve[4] = {point1, point2, point3, point4};
		
		if(argv[11]==NULL)return 1; if(argv[12]==NULL)return 1; if(argv[13]==NULL)return 1; if(argv[15]==NULL)return 1;
		int r = (int)wcstol(argv[11], nullptr, 0);
		int g = (int)wcstol(argv[12], nullptr, 0);
		int b = (int)wcstol(argv[13], nullptr, 0);

		int size = (int)wcstol(argv[15], nullptr, 0);
		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), size);
		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		gf.DrawCurve(&pen, curve, 4);

	}
	/* draw closed curve */
	else if(!_wcsicmp(argv[1], L"/dccurv") && !_wcsicmp(argv[16], L"/rgb") && !_wcsicmp(argv[20], L"/pw"))
	{
		if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[5]==NULL)return 1; if(argv[6]==NULL)return 1; if(argv[7]==NULL)return 1; if(argv[8]==NULL)return 1; if(argv[9]==NULL)return 1; if(argv[10]==NULL)return 1; if(argv[11]==NULL)return 1; if(argv[12]==NULL)return 1; if(argv[13]==NULL)return 1; if(argv[14]==NULL)return 1; if(argv[15]==NULL)return 1;
		float x1 = (float)wcstol(argv[2], nullptr, 0);
		float x2 = (float)wcstol(argv[3], nullptr, 0);
		float x3 = (float)wcstol(argv[4], nullptr, 0);
		float x4 = (float)wcstol(argv[5], nullptr, 0);
		float x5 = (float)wcstol(argv[6], nullptr, 0);
		float x6 = (float)wcstol(argv[7], nullptr, 0);
		float x7 = (float)wcstol(argv[8], nullptr, 0);
		float x8 = (float)wcstol(argv[9], nullptr, 0);
		float x9 = (float)wcstol(argv[10], nullptr, 0);
		float x10 = (float)wcstol(argv[11], nullptr, 0);
		float x11 = (float)wcstol(argv[12], nullptr, 0);
		float x12 = (float)wcstol(argv[13], nullptr, 0);
		float x13 = (float)wcstol(argv[14], nullptr, 0);
		float x14 = (float)wcstol(argv[15], nullptr, 0);

		Gdiplus::PointF point1(x1, x2);
		Gdiplus::PointF point2(x3, x4);
		Gdiplus::PointF point3(x5, x6);
		Gdiplus::PointF point4(x7, x8);
		Gdiplus::PointF point5(x9, x10);
		Gdiplus::PointF point6(x11, x12);
		Gdiplus::PointF point7(x13, x14);

		Gdiplus::PointF closecurve[7] = {point1, point2, point3, point4, point5, point6, point7};
		
		if(argv[17]==NULL)return 1; if(argv[18]==NULL)return 1; if(argv[19]==NULL)return 1; if(argv[21]==NULL)return 1;
		int r = (int)wcstol(argv[17], nullptr, 0);
		int g = (int)wcstol(argv[18], nullptr, 0);
		int b = (int)wcstol(argv[19], nullptr, 0);
		int size = (int)wcstol(argv[21], nullptr, 0);

		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), size);
		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		gf.DrawClosedCurve(&pen, closecurve, 7, 1.0);

	}
	/* draw beziers */
	else if(!_wcsicmp(argv[1], L"/dbezr") && !_wcsicmp(argv[16], L"/rgb") && !_wcsicmp(argv[20], L"/pw"))
	{
		if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[5]==NULL)return 1; if(argv[6]==NULL)return 1; if(argv[7]==NULL)return 1; if(argv[8]==NULL)return 1; if(argv[9]==NULL)return 1; if(argv[10]==NULL)return 1; if(argv[11]==NULL)return 1; if(argv[12]==NULL)return 1; if(argv[13]==NULL)return 1; if(argv[14]==NULL)return 1; if(argv[15]==NULL)return 1;
		float x1 = (float)wcstol(argv[2], nullptr, 0);
		float x2 = (float)wcstol(argv[3], nullptr, 0);
		float x3 = (float)wcstol(argv[4], nullptr, 0);
		float x4 = (float)wcstol(argv[5], nullptr, 0);
		float x5 = (float)wcstol(argv[6], nullptr, 0);
		float x6 = (float)wcstol(argv[7], nullptr, 0);
		float x7 = (float)wcstol(argv[8], nullptr, 0);
		float x8 = (float)wcstol(argv[9], nullptr, 0);
		float x9 = (float)wcstol(argv[10], nullptr, 0);
		float x10 = (float)wcstol(argv[11], nullptr, 0);
		float x11 = (float)wcstol(argv[12], nullptr, 0);
		float x12 = (float)wcstol(argv[13], nullptr, 0);
		float x13 = (float)wcstol(argv[14], nullptr, 0);
		float x14 = (float)wcstol(argv[15], nullptr, 0);

		Gdiplus::PointF point1(x1, x2);
		Gdiplus::PointF point2(x3, x4);
		Gdiplus::PointF point3(x5, x6);
		Gdiplus::PointF point4(x7, x8);
		Gdiplus::PointF point5(x9, x10);
		Gdiplus::PointF point6(x11, x12);
		Gdiplus::PointF point7(x13, x14);

		Gdiplus::PointF beziers[7] = {point1, point2, point3, point4, point5, point6, point7};
		
		if(argv[17]==NULL)return 1; if(argv[18]==NULL)return 1; if(argv[19]==NULL)return 1; if(argv[21]==NULL)return 1;
		int r = (int)wcstol(argv[17], nullptr, 0);
		int g = (int)wcstol(argv[18], nullptr, 0);
		int b = (int)wcstol(argv[19], nullptr, 0);
		int size = (int)wcstol(argv[21], nullptr, 0);

		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), size);
		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		gf.DrawBeziers(&pen, beziers, 7);
		
	}
	/* draw arc */
	else if(!_wcsicmp(argv[1], L"/darc") && !_wcsicmp(argv[6], L"/ag") && !_wcsicmp(argv[8], L"/sp") && !_wcsicmp(argv[10], L"/rgb") && !_wcsicmp(argv[14], L"/pw"))
	{
		if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[5]==NULL)return 1; if(argv[6]==NULL)return 1; if(argv[7]==NULL)return 1; if(argv[8]==NULL)return 1; if(argv[9]==NULL)return 1;
		float x1 = (float)wcstol(argv[2], nullptr, 0);
		float x2 = (float)wcstol(argv[3], nullptr, 0);
		float x3 = (float)wcstol(argv[4], nullptr, 0);
		float x4 = (float)wcstol(argv[5], nullptr, 0);
		float x5 = (float)wcstol(argv[7], nullptr, 0);
		float x6 = (float)wcstol(argv[9], nullptr, 0);
		Gdiplus::REAL x = x1;
		Gdiplus::REAL y = x2;
		Gdiplus::REAL width = x3;
		Gdiplus::REAL height = x4;
		Gdiplus::REAL angel = x5;
		Gdiplus::REAL swip = x6;
		
		if(argv[11]==NULL)return 1; if(argv[12]==NULL)return 1; if(argv[13]==NULL)return 1; if(argv[15]==NULL)return 1;
		int r = (int)wcstol(argv[11], nullptr, 0);
		int g = (int)wcstol(argv[12], nullptr, 0);
		int b = (int)wcstol(argv[13], nullptr, 0);
		int size = (int)wcstol(argv[15], nullptr, 0);

		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), size);
		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		gf.DrawArc(&pen, x, y, width, height, angel, swip);
	}
	/* draw traingle */
	else if(!_wcsicmp(argv[1], L"/dtran") && !_wcsicmp(argv[8], L"/rgb") && !_wcsicmp(argv[12], L"/pw"))
	{
		if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[5]==NULL)return 1; if(argv[6]==NULL)return 1; if(argv[7]==NULL)return 1;
		float x1 = (float)wcstol(argv[2], nullptr, 0);
	    float x2 = (float)wcstol(argv[3], nullptr, 0);
		float x3 = (float)wcstol(argv[4], nullptr, 0);
		float x4 = (float)wcstol(argv[5], nullptr, 0);
		float x5 = (float)wcstol(argv[6], nullptr, 0);
		float x6 = (float)wcstol(argv[7], nullptr, 0);

		// 200 100 300 300 100 300
		Gdiplus::Point point1(x1, x2);
		Gdiplus::Point point2(x3, x4);
		Gdiplus::Point point3(x5, x6);
		Gdiplus::Point p[3] = {point1, point2, point3};

		if(argv[9]==NULL)return 1; if(argv[10]==NULL)return 1; if(argv[11]==NULL)return 1; if(argv[13]==NULL)return 1;
		int r = (int)wcstol(argv[9], nullptr, 0);
		int g = (int)wcstol(argv[10], nullptr, 0);
		int b = (int)wcstol(argv[11], nullptr, 0);
		int size = (int)wcstol(argv[13], nullptr, 0);

		Gdiplus::Pen red(Gdiplus::Color(r, g, b), size);
		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		gf.DrawPolygon(&red, p, 3);

		// fill up
		if(!_wcsicmp(argv[14], L"/fill") && !_wcsicmp(argv[15], L"/rgb"))
		{
			if(argv[10]==NULL)return 1; if(argv[11]==NULL)return 1; if(argv[12]==NULL)return 1;

			int r = (int)wcstol(argv[16], nullptr, 0);
		    int g = (int)wcstol(argv[17], nullptr, 0);
		    int b = (int)wcstol(argv[18], nullptr, 0);

			Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
			gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
			gf.FillPolygon(&brush, p, 3);
		}else{
			return 0;
		}
	}
	/* draw  circle */
	else if(!_wcsicmp(argv[1], L"/dcir") && !_wcsicmp(argv[5], L"/rgb") && !_wcsicmp(argv[9], L"/pw"))
	{
		if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1;

		float cx = (float)wcstol(argv[2], nullptr, 0);
		float cy = (float)wcstol(argv[3], nullptr, 0);
		float rad = (float)wcstol(argv[4], nullptr, 0);

		if(argv[6]==NULL)return 1; if(argv[7]==NULL)return 1; if(argv[8]==NULL)return 1;
		int r = (int)wcstol(argv[6], nullptr, 0);
		int g = (int)wcstol(argv[7], nullptr, 0);
		int b = (int)wcstol(argv[8], nullptr, 0);
		
		if(argv[10]==NULL)return 1;
        int size = (int)wcstol(argv[10], nullptr, 0);

		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), size);
		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
	    gf.DrawEllipse(&pen, cx-rad, cy-rad, rad+rad,rad+rad);

		// fill up
		if(!_wcsicmp(argv[11], L"/fill") && !_wcsicmp(argv[12], L"/rgb"))
		{
			if(argv[13]==NULL)return 1; if(argv[14]==NULL)return 1; if(argv[15]==NULL)return 1;
			int r = (int)wcstol(argv[13], nullptr, 0);
		    int g = (int)wcstol(argv[14], nullptr, 0);
		    int b = (int)wcstol(argv[15], nullptr, 0);

			Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
			gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
			gf.FillEllipse(&brush, cx-rad, cy-rad, rad+rad, rad+rad);
		}else{
			return 0;
		}
	}
	/* draw pie */
	else if(!_wcsicmp(argv[1], L"/dpie") && !_wcsicmp(argv[8], L"/rgb") && !_wcsicmp(argv[12], L"/pw"))
	{
		if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[5]==NULL)return 1; if(argv[6]==NULL)return 1; if(argv[7]==NULL)return 1;

		float x1 = (float)wcstol(argv[2], nullptr, 0);
		float x2 = (float)wcstol(argv[3], nullptr, 0);
		float x3 = (float)wcstol(argv[4], nullptr, 0);
		float x4 = (float)wcstol(argv[5], nullptr, 0);
		float x5 = (float)wcstol(argv[6], nullptr, 0);
		float x6 = (float)wcstol(argv[7], nullptr, 0);

		Gdiplus::Rect ellipRect(x1, x2, x3, x4);

		if(argv[9]==NULL)return 1; if(argv[10]==NULL)return 1; if(argv[11]==NULL)return 1; if(argv[13]==NULL)return 1;

		int r = (int)wcstol(argv[9], nullptr, 0);
		int g = (int)wcstol(argv[10], nullptr, 0);
		int b = (int)wcstol(argv[11], nullptr, 0);
		int size = (int)wcstol(argv[13], nullptr, 0);

		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), size);
		Gdiplus::REAL angel = x5;
		Gdiplus::REAL swip = x6;
		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		gf.DrawPie(&pen, ellipRect, angel, swip);

		// fill up
		if(!_wcsicmp(argv[14], L"/fill") && !_wcsicmp(argv[15], L"/rgb"))
		{
			int r = (int)wcstol(argv[16], nullptr, 0);
		    int g = (int)wcstol(argv[17], nullptr, 0);
		    int b = (int)wcstol(argv[18], nullptr, 0);
			Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
			gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
			gf.FillPie(&brush, ellipRect, angel, swip);
		}else{
			return 0;
		}
	}
	/* draw polygon */
	else if(!_wcsicmp(argv[1], L"/dpol") && !_wcsicmp(argv[12], L"/rgb") && !_wcsicmp(argv[16], L"/pw"))
	{
		if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[5]==NULL)return 1; if(argv[6]==NULL)return 1; if(argv[7]==NULL)return 1; if(argv[8]==NULL)return 1; if(argv[9]==NULL)return 1; if(argv[10]==NULL)return 1; if(argv[11]==NULL)return 1;
		
		float x1 = (float)wcstol(argv[2], nullptr, 0);
		float x2 = (float)wcstol(argv[3], nullptr, 0);
		float x3 = (float)wcstol(argv[4], nullptr, 0);
		float x4 = (float)wcstol(argv[5], nullptr, 0);
		float x5 = (float)wcstol(argv[6], nullptr, 0);
		float x6 = (float)wcstol(argv[7], nullptr, 0);
		float x7 = (float)wcstol(argv[8], nullptr, 0);
		float x8 = (float)wcstol(argv[9], nullptr, 0);
		float x9 = (float)wcstol(argv[10], nullptr, 0);
		float x10 = (float)wcstol(argv[11], nullptr, 0);

		if(argv[13]==NULL)return 1; if(argv[14]==NULL)return 1; if(argv[15]==NULL)return 1; if(argv[17]==NULL)return 1;

		int r = (int)wcstol(argv[13], nullptr, 0);
		int g = (int)wcstol(argv[14], nullptr, 0);
		int b = (int)wcstol(argv[15], nullptr, 0);
		int size = (int)wcstol(argv[17], nullptr, 0);

		Gdiplus::Pen pen(Gdiplus::Color(r, g, b), size);
		Gdiplus::Point point1(x1, x2);
		Gdiplus::Point point2(x3, x4);
		Gdiplus::Point point3(x5, x6);
		Gdiplus::Point point4(x7, x8);
		Gdiplus::Point point5(x9, x10);

		Gdiplus::Point points[5] = {point1, point2, point3, point4, point5};
		gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
		gf.DrawPolygon(&pen, points, 5);

		// fill up
		if(!_wcsicmp(argv[18], L"/fill") && !_wcsicmp(argv[19], L"/rgb"))
		{
			if(argv[20]==NULL)return 1; if(argv[21]==NULL)return 1; if(argv[22]==NULL)return 1;

			int r = (int)wcstol(argv[20], nullptr, 0);
			int g = (int)wcstol(argv[21], nullptr, 0);
			int b = (int)wcstol(argv[22], nullptr, 0);

			Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
			gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
			gf.FillPolygon(&brush, points, 5);
		}else{
			return 0;
		}}
		
	    /* draw star */
		else if(!_wcsicmp(argv[1], L"/dstar") && !_wcsicmp(argv[24], L"/rgb") && !_wcsicmp(argv[28], L"/pw"))
		{
			if(argv[2]==NULL)return 1; if(argv[3]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[5]==NULL)return 1; if(argv[6]==NULL)return 1; if(argv[7]==NULL)return 1; if(argv[8]==NULL)return 1; if(argv[9]==NULL)return 1; if(argv[10]==NULL)return 1; if(argv[11]==NULL)return 1; if(argv[12]==NULL)return 1; if(argv[13]==NULL)return 1; if(argv[14]==NULL)return 1; if(argv[15]==NULL)return 1; if(argv[16]==NULL)return 1; if(argv[17]==NULL)return 1; if(argv[18]==NULL)return 1; if(argv[19]==NULL)return 1; if(argv[20]==NULL)return 1; if(argv[21]==NULL)return 1; if(argv[22]==NULL)return 1; if(argv[23]==NULL)return 1;

			float x1 = (float)wcstol(argv[2], nullptr, 0);
			float x2 = (float)wcstol(argv[3], nullptr, 0);
			float x3 = (float)wcstol(argv[4], nullptr, 0);
			float x4 = (float)wcstol(argv[5], nullptr, 0);
			float x5 = (float)wcstol(argv[6], nullptr, 0);
			float x6 = (float)wcstol(argv[7], nullptr, 0);
			float x7 = (float)wcstol(argv[8], nullptr, 0);
			float x8 = (float)wcstol(argv[9], nullptr, 0);
			float x9 = (float)wcstol(argv[10], nullptr, 0);
			float x10 = (float)wcstol(argv[11], nullptr, 0);
			float x11 = (float)wcstol(argv[12], nullptr, 0);
			float x12 = (float)wcstol(argv[13], nullptr, 0);
			float x13 = (float)wcstol(argv[14], nullptr, 0);
			float x14 = (float)wcstol(argv[15], nullptr, 0);
			float x15 = (float)wcstol(argv[16], nullptr, 0);
			float x16 = (float)wcstol(argv[17], nullptr, 0);
			float x17 = (float)wcstol(argv[18], nullptr, 0);
			float x18 = (float)wcstol(argv[19], nullptr, 0);
			float x19 = (float)wcstol(argv[20], nullptr, 0);
			float x20 = (float)wcstol(argv[21], nullptr, 0);
			float x21 = (float)wcstol(argv[22], nullptr, 0);
			float x22 = (float)wcstol(argv[23], nullptr, 0);

			if(argv[25]==NULL)return 1; if(argv[26]==NULL)return 1; if(argv[27]==NULL)return 1; if(argv[29]==NULL)return 1;

			int r = (int)wcstol(argv[25], nullptr, 0);
			int g = (int)wcstol(argv[26], nullptr, 0);
			int b = (int)wcstol(argv[27], nullptr, 0);
			int size = (int)wcstol(argv[29], nullptr, 0);

			Gdiplus::Pen pen(Gdiplus::Color(r, g, b), size);
			Gdiplus::Point point1(x1, x2);
			Gdiplus::Point point2(x3, x4);
			Gdiplus::Point point3(x5, x6);
			Gdiplus::Point point4(x7, x8);
			Gdiplus::Point point5(x9, x10);
			Gdiplus::Point point6(x11, x12);
			Gdiplus::Point point7(x13, x14);
			Gdiplus::Point point8(x15, x16);
			Gdiplus::Point point9(x17, x18);
			Gdiplus::Point point10(x19, x20);
			Gdiplus::Point point11(x21, x22);

			Gdiplus::Point points[11] = {point1, point2, point3, point4, point5, point6, point7, point8, point9, point10, point11};

			gf.SetSmoothingMode(Gdiplus::SmoothingModeHighQuality);
			gf.DrawPolygon(&pen, points, 11);
			
			/* fill up */
			if(!_wcsicmp(argv[30], L"/fill") && !_wcsicmp(argv[31], L"/rgb"))
			{
				if(argv[31]==NULL)return 1; if(argv[32]==NULL)return 1; if(argv[33]==NULL)return 1; if(argv[34]==NULL)return 1;

				int r = (int)wcstol(argv[32], nullptr, 0);
				int g = (int)wcstol(argv[33], nullptr, 0);
				int b = (int)wcstol(argv[34], nullptr, 0);
				Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
				gf.FillPolygon(&brush, points, 11);

			}else{
				return 0;
			}
		}
		
		/* draw text */
		else if(!_wcsicmp(argv[1], L"/dtext") && !_wcsicmp(argv[3], L"/x") && !_wcsicmp(argv[5], L"/y") && !_wcsicmp(argv[7], L"/ff") && !_wcsicmp(argv[9], L"/fs") && !_wcsicmp(argv[11], L"/rgb") && !_wcsicmp(argv[15], L"/pw"))
		{
			if(argv[2]==NULL)return 1; if(argv[4]==NULL)return 1; if(argv[6]==NULL)return 1; if(argv[8]==NULL)return 1; if(argv[10]==NULL)return 1; if(argv[12]==NULL)return 1; if(argv[13]==NULL)return 1; if(argv[14]==NULL)return 1; if(argv[15]==NULL)return 1; if(argv[16]==NULL)return 1;
			if(_wtoi(argv[10]) > 100 || _wtoi(argv[10]) < 1) return 1;
			
			float x1 = (float)wcstol(argv[4], nullptr, 0);
			float x2 = (float)wcstol(argv[6], nullptr, 0);

			int r = (int)wcstol(argv[12], nullptr, 0);
			int g = (int)wcstol(argv[13], nullptr, 0);
			int b = (int)wcstol(argv[14], nullptr, 0);
			int size = (int)wcstol(argv[16], nullptr, 0);

			Gdiplus::SolidBrush brush(Gdiplus::Color(r, g, b));
			
			/* Arial */
			if(!_wcsicmp(argv[8], L"ari"))
			{
				Gdiplus::FontFamily ff(L"Arial", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* arial black */
			else if(!_wcsicmp(argv[8], L"arib"))
			{
				Gdiplus::FontFamily ff(L"Arial Black", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* Calibri */
			else if(!_wcsicmp(argv[8], L"calb"))
			{
				Gdiplus::FontFamily ff(L"Calibri", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* Calibri Light */
			else if(!_wcsicmp(argv[8], L"calbl"))
			{
				Gdiplus::FontFamily ff(L"Calibri Light", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* Cambria */
			else if(!_wcsicmp(argv[8], L"cambr"))
			{
				Gdiplus::FontFamily ff(L"Cambria", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* Cambria Math */
			else if(!_wcsicmp(argv[8], L"cambrm"))
			{
				Gdiplus::FontFamily ff(L"Cambria Math", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* Candara */
			else if(!_wcsicmp(argv[8], L"candr"))
			{
				Gdiplus::FontFamily ff(L"Candara", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* comic sans ms */
			else if(!_wcsicmp(argv[8], L"csms"))
			{
				Gdiplus::FontFamily ff(L"Comic Sans MS", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* consolas */
			else if(!_wcsicmp(argv[8], L"cslas"))
			{
				Gdiplus::FontFamily ff(L"Consolas", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* constatia */
			else if(!_wcsicmp(argv[8], L"cstia"))
			{
				Gdiplus::FontFamily ff(L"Constantia", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* cobel */
			else if(!_wcsicmp(argv[8], L"cbel"))
			{
				Gdiplus::FontFamily ff(L"Corbel", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* courier new */
			else if(!_wcsicmp(argv[8], L"courn"))
			{
				Gdiplus::FontFamily ff(L"Courier New", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* gabriola */
			else if(!_wcsicmp(argv[8], L"grola"))
			{
				Gdiplus::FontFamily ff(L"Gabriola", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* geogia */
			else if(!_wcsicmp(argv[8], L"geogia"))
			{
				Gdiplus::FontFamily ff(L"Georgia", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* impact */
			else if(!_wcsicmp(argv[8], L"impct"))
			{
				Gdiplus::FontFamily ff(L"Impact", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* lucida console */
			else if(!_wcsicmp(argv[8], L"luic"))
			{
				Gdiplus::FontFamily ff(L"Lucida Console", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* lucida sans unicode */
			else if(!_wcsicmp(argv[8], L"lusu"))
			{
				Gdiplus::FontFamily ff(L"Lucida Sans Unicode", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* microsoft sans serif */
			else if(!_wcsicmp(argv[8], L"mssf"))
			{
				Gdiplus::FontFamily ff(L"Microsoft Sans Serif", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* palatino linotype */
			else if(!_wcsicmp(argv[8], L"plin"))
			{
				Gdiplus::FontFamily ff(L"Palatino Linotype", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* segoe print */
			else if(!_wcsicmp(argv[8], L"sepri"))
			{
				Gdiplus::FontFamily ff(L"Segoe Print", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* segoe script */
			else if(!_wcsicmp(argv[8], L"segsr"))
			{
				Gdiplus::FontFamily ff(L"Segoe Script", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* seogoe ui */
			else if(!_wcsicmp(argv[8], L"segui"))
			{
				Gdiplus::FontFamily ff(L"Segoe UI", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* segoe ui light */
			else if(!_wcsicmp(argv[8], L"segul"))
			{
				Gdiplus::FontFamily ff(L"Segoe UI Light", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			/* Segoe UI Semibold */
			else if(!_wcsicmp(argv[8], L"segus"))
			{
				Gdiplus::FontFamily ff(L"Segoe UI Semibold", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* Tahoma */
			else if(!_wcsicmp(argv[8], L"toma"))
			{
				Gdiplus::FontFamily ff(L"Tahoma", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* Times new roman */
			else if(!_wcsicmp(argv[8], L"timnr"))
			{
				Gdiplus::FontFamily ff(L"Times New Roman", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* Trebuchet MS */
			else if(!_wcsicmp(argv[8], L"trems"))
			{
				Gdiplus::FontFamily ff(L"Trebuchet MS", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else{
					return 1;
				}
			}
			
			/* Verdana */
			else if(!_wcsicmp(argv[8], L"verdna"))
			{
				Gdiplus::FontFamily ff(L"Verdana", nullptr);

				if(!_wcsicmp(argv[10], L"regular"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"italic"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleItalic, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"bold"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleBold, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"undrlne"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleUnderline, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}
				else if(!_wcsicmp(argv[10], L"strkout"))
				{
					Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleStrikeout, Gdiplus::UnitPixel);
					gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
				}

				else{
					return 1;
				}
			}
			
			/* own selected font */
			else{
				Gdiplus::FontFamily ff(argv[8], nullptr);
				Gdiplus::Font getf(&ff, size, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
			    gf.DrawString(argv[2], -1, &getf, Gdiplus::PointF(x1, x2), &brush);
		}}
	
	/* change color */
	else if(!_wcsicmp(argv[1], L"/color"))
	{
		if(argv[2]==NULL)return 1;

		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		uint8_t color = (uint8_t)wcstol(argv[2], nullptr, 0);
		SetConsoleTextAttribute(hOut, color);
	}
	/* transparent a window or cmd */
	else if(!_wcsicmp(argv[1], L"/trans"))
	{
		if(argv[2]==NULL)return 1;
		
		long percentage = (long)wcstol(argv[3], nullptr, 0);
		
		if(!_wcsicmp(argv[2], L"/con"))
		{
			HWND hWnd = GetConsoleWindow();
			BYTE bAlpha = 0;
	        LONG lNewLong = 0;
		    if (hWnd && percentage > -1 && percentage < 101)
 	       {
		      bAlpha = (BYTE)(2.55 * (100 - percentage) + 0.5);
		      lNewLong = GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED;
	 	      if (!SetWindowLong(hWnd, GWL_EXSTYLE, lNewLong)) return FALSE;
		      return SetLayeredWindowAttributes(hWnd, 0, bAlpha, LWA_ALPHA);
	       }
		}else{
	    HWND hWnd = FindWindow(NULL, argv[2]);
	    BYTE bAlpha = 0;
	    LONG lNewLong = 0;
	    if (hWnd && percentage > -1 && percentage < 101)
 	    {
		      bAlpha = (BYTE)(2.55 * (100 - percentage) + 0.5);
		      lNewLong = GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_LAYERED;
	 	      if (!SetWindowLong(hWnd, GWL_EXSTYLE, lNewLong)) return FALSE;
		      return SetLayeredWindowAttributes(hWnd, 0, bAlpha, LWA_ALPHA);
	    }}
	return FALSE;
	}
	/* some help */
	else if(!_wcsicmp(argv[1], L"/?") || !_wcsicmp(argv[1], L"-h") || !_wcsicmp(argv[1], L"--h"))
	{
		system("mode 200, 100");
		std::wcout << "CmdDraw Version-";
		std::wcout << "1.0" << std::endl;
		std::wcout << "Copyright (C) 2018-2020 MathInDOS" << std::endl;
		std::wcout << "Build Date: 31 December 2020" << std::endl << std::endl;
		std::wcout << "----- Usage -----" << std::endl << std::endl;
		std::wcout << "cmddraw /dimg [image path] /x [x position] /y [y position]" << std::endl;
		std::wcout << "cmddraw /dline [ax position] [ay position] [bx position] [by position] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /drec [ax start position] [ay end position] [bx start position] [by end position] /rgb [red green blue] /pw [size]" << std::endl;
	    std::wcout << "cmddraw /delip [ax start position] [ay end position] [bx start position] [by end position] /rgb [red green blue]" << std::endl;
		std::wcout << "cmddraw /dcurv [p1 p2 p3 p4 p5 p6 p7 p8 points] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /dccurv [p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14 points] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /dbezr [p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14 points] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /darc [p1 p2 p3 p4 points] /ag [angle] /sp [sweepangle] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /dtran [p1 p2 p3 p4 p5 p6] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /dcir [x y radius] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /dpie [p1 p2 p3 p4 p5 p6 points and angle and sweepPoint] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /dpol [p1 p2 p3 p4 p5 p6 p7 p8 p9 p10] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /dstar [p1 p2 p3...p22] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /dtext [text] /x [x position] /y [y position] /ff [font name] /fs [font style] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /color [color code]" << std::endl;
		std::wcout << "cmddraw /trans /con [percentage]" << std::endl << std::endl;
		std::wcout << "If you need more help type [command]--h for more info about a command." << std::endl;
		std::wcout << "Join Our Discord Server at: https://discord.gg/E5qYx7WYef" << std::endl;
		std::wcout << "Happy New Year! Stay Awesome! :3" << std::endl;
		return 0;

	}
	else if(!_wcsicmp(argv[1], L"/dimg--h"))
	{
		std::wcout << "Shows a image on cmd" << std::endl;
		std::wcout << "cmddraw /dimg [image file]" << std::endl;
		std::wcout << "Ex. cmddraw /dimg mypc.png" << std::endl;
		std::wcout << "Supported formats: *.bmp, *.png, *.jpg, *.gif (non-animated), *.tiff" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/dline--h"))
	{
		std::wcout << "Draw a line" << std::endl;
		std::wcout << "cmddraw /dline [ax position] [ay position] [bx position] [by position] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "Ex. cmddraw /dline 10 300 10 10 /rgb 0 255 0 /pw 5" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/drec--h"))
	{
		std::wcout << "Draw a rectangle" << std::endl;
		std::wcout << "cmddraw /drec [ax start position] [ay end position] [bx start position] [by end position] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "Ex. cmddraw /drec 10 30 30 50 /rgb 0 255 0 /pw 5" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/delip--h"))
	{
		std::wcout << "Draw ellipse" << std::endl;
		std::wcout << "cmddraw /delip [ax start position] [ay end position] [bx start position] [by end position] /rgb [red green blue]" <<std::endl;
		std::wcout << "Ex. cmddraw /delip 10 30 30 100 /rgb 0 255 0" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/dcurv--h"))
	{
		std::wcout << "Draw curve" << std::endl;
		std::wcout << "cmddraw /dcurv [p1 p2 p3 p4 p5 p6 p7 p8 points] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "Ex. cmddraw /dcurv 100 100 200 50 400 10 500 100 /rgb 0 255 0 /pw 5" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/dccurv--h"))
	{
		std::wcout << "Draw closed curve" << std::endl;
		std::wcout << "cmddraw /dccurv [p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14 points] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "Ex. cmddraw /dccurv 100.0f 100.0f 200.0f 50.0f 400.0f 10.0f 500.0f 100.0f 600.0f 200.0f 700.0f 400.0f 500.0f 500.0f /rgb 0 255 0 /pw 5" << std::endl;
		std::wcout << "Note: You can give only numbers without .0f" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/dbezr--h"))
	{
		std::wcout << "Draw beziers" << std::endl;
		std::wcout << "cmddraw /dbezr [p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14 points] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "Ex. cmddraw /dbezr 100.0f 100.0f 200.0f 50.0f 400.0f 10.0f 500.0f 100.0f 600.0f 200.0f 700.0f 400.0f 500.0f 500.0f /rgb 0 255 0 /pw 5" << std::endl;
		std::wcout << "Note: You can give only numbers without .0f" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/darc--h"))
	{
		std::wcout << "Draw arc" << std::endl;
		std::wcout << "cmddraw /darc [p1 p2 p3 p4 points] /ag [angle] /sp [sweepangle] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "Ex. cmddraw /darc 100 100 100 100 /ag 360 /sp 180 /rgb 0 255 0 /pw 5" << std::endl;
		std::wcout << "Note: You can give .0f to point it more effective." << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/dtran--h"))
	{
		std::wcout << "Draw traingle" << std::endl;
		std::wcout << "cmddraw /dtran [p1 p2 p3 p4 p5 p6] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "Ex. cmddraw /dtran 90 90 200 200 100 205 /rgb 0 255 0 /pw 5" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/dcir--h"))
	{
		std::wcout << "Draw circle" << std::endl;
		std::wcout << "cmddraw /dcir [x y radius] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "Ex. cmddraw /dcir 100 100 50 /rgb 0 255 0 /pw 5" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/dpie--h"))
	{
		std::wcout << "Draw pie" << std::endl;
		std::wcout << "cmddraw /dpie [p1 p2 p3 p4 p5 p6 points and angle and sweepPoint] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "Ex. cmddraw /dpie 100 100 100 100 100 100 /rgb 0 255 0 /pw 5" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/dpol--h"))
	{
		std::wcout << "Draw polygon" << std::endl;
		std::wcout << "cmddraw /dpol [p1 p2 p3 p4 p5 p6 p7 p8 p9 p10] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "Ex. cmddraw /dpol 100 100 200 130 150 200 50 200 0 130 /rgb 0 255 0 /pw 5" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/dtext--h"))
	{
		std::wcout << "Draw text" << std::endl;
		std::wcout << "cmddraw /dtext [text] /x [x position] /y [y position] /ff [font name] /fs [font style] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "Ex. cmddraw /dtext hello /x 30 /y 30 /ff webdings /fs italic /rgb 0 255 0 /pw 40" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/dstar--h"))
	{
		std::wcout << "Draw star" << std::endl;
		std::wcout << "cmddraw /dstar [p1 p2 p3...p22] /rgb [red green blue] /pw [size]" << std::endl;
		std::wcout << "cmddraw /dstar 10 85 85 75 110 10 135 75 210 85 160 125 170 190 110 150 50 190 60 125 10 85 /rgb 0 255 0 /pw 5" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/color--h"))
	{
		std::wcout << "Change color" << std::endl;
		std::wcout << "cmddraw /color [color code]" << std::endl;
		std::wcout << "Ex. cmddraw /color 0x0a" << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/trans--h"))
	{
		std::wcout << "Transparent a window or cmd" << std::endl;
		std::wcout << "cmddraw /trans /con [percentage]" << std::endl;
		std::wcout << "cmddraw /trans [window title] [percentage" << std::endl;
		std::wcout << "Ex. cmddraw /trans /con 50" << std::endl;
		std::wcout << "Ex. cmddraw /trans Calculator 50" << std::endl;
		std::wcout << "Note: Before transparent a window make sure the window is open." << std::endl;
		return 0;
	}
	else if(!_wcsicmp(argv[1], L"/license") || !_wcsicmp(argv[1], L"/l"))
	{
		std::wcout << "This software under GNU GPLv3 License. To know more about license and GPL terms and conditions please visit https://choosealicense.com" << std::endl;
		return 0;
	}
	// else do nothing
	else{
		return 0;
	}
	return 0;
}
