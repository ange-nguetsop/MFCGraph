#pragma once
#include "CData.h"
class CGraph
{
protected:
	double Xmin;
	double Xmax;
	double Ymin;
	double Ymax;
	const double leftMargin = 30;
	const double upperMargin = 30;
	double height;
	double width;
	double orgX;
	double orgY;
	double startX;
	double startY;
	double Amplitude;
	COLORREF Farbe;
	UINT LinienArt;
	double LinieStaerke;
	CData Werte ;
	double Offset;
public:

	CGraph(void);
	CGraph(double _Xmin, double _Xmax, double _Ymin, double _Ymax, double _height, double _width);
	void setFarbe(COLORREF _farbe);
	void setOffset(double o);
	void setXmin(double _Xmin);
	void setYmin(double _Ymin);
	void setXmax(double _Xmax);
	void setAmplitude(double _a);
	void setYmax(double _Ymax);
	void setHeight(double _Height);
	void setWidth(double _width);
	void setWerte(CData _Werte);
	void setLinienStaerke(double ls);
	void setLinienArt(UINT la);
	CData getWerte(void)const;
	COLORREF getFarbe();
	double getLinienStaerke(void)const;
	double getOffset(void)const;
	UINT getLinienArt(void)const;
	double getAmplitude(void)const;
	double getXmin(void) const;
	double getYmin(void)const;
	double getXmax(void)const;
	double getYmax(void)const;
	double getHeight(void)const;
	double getWidth(void)const;


	void draw(CDC* pDc);
	int math2GrafikX(double _xWert);
	int math2GrafikY(double _yWert);
};
