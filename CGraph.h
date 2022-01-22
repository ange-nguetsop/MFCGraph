#pragma once
#include "CData.h"
class CGraph
{
protected:
	double orgX;
	double orgY;
	double Xmin;
	double Xmax;
	double Ymin;
	double Ymax;
	const int leftMargin = 30;
	const int upperMargin = 30;
	double height = Ymax - Ymin;
	double width = Xmax - Xmin;
	CData Werte ;
public:

	CGraph(void);
	CGraph(double _Xmin, double _Xmax, double _Ymin, double _Ymax, double _height, double _width);
	void setXmin(double _Xmin);
	void setYmin(double _Ymin);
	void setXmax(double _Xmax);
	void setYmax(double _Ymax);
	void setHeight(double _Height);
	void setWidth(double _width);
	void setWerte(CData _Werte);
	CData getWerte(void)const;
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
