#include "pch.h"
#include "StdAfx.h"
#include "CGraph.h"

CGraph::CGraph(void)
	:height(300)
	,width(600)
	,Xmin(0)
	,Xmax(0)
	,Ymin(0)
	,Ymax(0)
{}

CGraph::CGraph(double _Xmin, double _Xmax, double _Ymin, double _Ymax, double _height, double _width)
{
	Xmin   = _Xmin;
	Xmax   = _Xmax;
	Ymin   = _Ymin;
	Ymax   = _Ymax;
	height = _height;
	width  = _width;
	orgX   = leftMargin;
	orgY   = upperMargin;

}

void CGraph::setXmin(double _Xmin)
{
	Xmin = _Xmin;
}

void CGraph::setYmin(double _Ymin)
{
	Ymin = _Ymin;
}

void CGraph::setXmax(double _Xmax)
{ 
	Xmax = _Xmax;
}

void CGraph::setYmax(double _Ymax)
{
	Ymax = _Ymax;
}

void CGraph::setHeight(double _Height)
{
	height = _Height;
}

void CGraph::setWidth(double _width)
{
	width = _width;
}

void CGraph::setWerte(CData _Werte)
{
	Werte = _Werte;
}

CData CGraph::getWerte(void)const
{
	return Werte;
}

double CGraph::getXmin(void) const
{
	return Xmin;
}

double CGraph::getYmin(void) const
{
	return Ymin;
}

double CGraph::getXmax(void) const
{
	return Xmax;
}

double CGraph::getYmax(void) const
{
	return Ymax;
}

double CGraph::getHeight(void) const
{
	return height;
}

double CGraph::getWidth(void) const
{
	return width;
}

void CGraph::draw(CDC* pDc)
{
	// weiﬂes Rechteck als Hintergrund zeichnen

	CBrush backGrnd(RGB(255, 255, 255));
	pDc->SelectObject(&backGrnd);
	pDc->Rectangle(20, 20, 550, 400);
	// Koordinatenachsen x und y zeichnen
	const CString cs("Xmin");
	const CString cs1("Xmax");
	const CString cs2("Ymin");
	const CString cs3("Ymax");
	pDc->MoveTo(20 + leftMargin, 400 / 2);
	pDc->TextOutW(20 + leftMargin, 400 / 2, cs);
	pDc->TextOutW(520 - leftMargin, 400 / 2, cs1);
	pDc->LineTo(550 - leftMargin, 400 / 2);
	pDc->MoveTo(20 + leftMargin, 20 + upperMargin);
	pDc->TextOutW(20 + leftMargin, 20 + upperMargin, cs3);
	pDc->LineTo(20 + leftMargin, 400 - upperMargin);
	pDc->TextOutW(20 + leftMargin, 400 - upperMargin, cs2);

	// WerteVerlauf
	//aufoassen, ob die Werte im Rechteck sind oder auﬂerhalb


}

int CGraph::math2GrafikX(double _xWert) 
{
	return orgX + (int)((_xWert - Xmin) * width / (Xmax - Xmin));
}

int CGraph::math2GrafikY(double _yWert)
{
	return orgY + height - (int)((_yWert - Ymin) * height / (Ymax - Ymin));
}
