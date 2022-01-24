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
	double height = Ymax - Ymin;
	double width = Xmax - Xmin;
	double orgX= startX + leftMargin;
	double orgY= startY + upperMargin;
	double startX=0;
	double startY=0;
	COLORREF Farbe;
	UINT LinienArt;
	double LinieStaerke;
	CData Werte ;
public:

	CGraph(void);
	CGraph(double _Xmin, double _Xmax, double _Ymin, double _Ymax, double _height, double _width);
	void setFarbe(COLORREF _farbe);
	void setXmin(double _Xmin);
	void setYmin(double _Ymin);
	void setXmax(double _Xmax);
	void setYmax(double _Ymax);
	void setHeight(double _Height);
	void setWidth(double _width);
	void setWerte(CData _Werte);
	void setLinienStaerke(double ls);
	void setLinienArt(UINT la);
	CData getWerte(void)const;
	COLORREF getFarbe();
	double getLinienStaerke(void)const;
	UINT getLinienArt(void)const;
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
