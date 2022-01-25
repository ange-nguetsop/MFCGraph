#pragma once
#include "CData.h"
class CGraph
{
protected:
	double Xmin;
	double Xmax;
	double Ymin;
	double Ymax;
	const int leftMargin = 30;
	const int upperMargin = 30;
	int height;
	int width;
	int orgX;
	int orgY;
	COLORREF Farbe;
	UINT LinienArt;
	int LinieStaerke;
	CData Werte ;
public:

	CGraph(void);
	CGraph(double _Xmin, double _Xmax, double _Ymin, double _Ymax, int _height, int _width);
	void setFarbe(COLORREF _farbe);
	
	void setXmin(double _Xmin);
	void setYmin(double _Ymin);
	void setXmax(double _Xmax);
	void setYmax(double _Ymax);
	void setHeight(int _Height);
	void setWidth(int _width);
	void setWerte(CData _Werte);
	void setLinienStaerke(int ls);
	void setLinienArt(UINT la);
	CData getWerte(void)const;
	COLORREF getFarbe();
	int getLinienStaerke(void)const;

	UINT getLinienArt(void)const;
	
	double getXmin(void) const;
	double getYmin(void)const;
	double getXmax(void)const;
	double getYmax(void)const;
	int getHeight(void)const;
	int getWidth(void)const;


	void draw(CDC* pDc);
	int math2GrafikX(double _xWert);
	int math2GrafikY(double _yWert);
};
