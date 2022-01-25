#include "pch.h"
#include "StdAfx.h"
#include "CGraph.h"
#include "CLSLADialog.h"
#define DATA_LEN 600

CGraph::CGraph(void)
	:height(300)
	,width(600)
	,Xmin(0)
	,Xmax(0)
	,Ymin(0)
	,Ymax(0)
	,orgX(20 + leftMargin)
	,orgY(0)
	,Farbe(RGB(0,255,255))
	,LinieStaerke(2)
	,LinienArt(PS_SOLID)
{}

CGraph::CGraph(double _Xmin, double _Xmax, double _Ymin, double _Ymax, double _height, double _width)
{
	Xmin   = _Xmin;
	Xmax   = _Xmax;
	Ymin   = _Ymin;
	Ymax   = _Ymax;
	height = _height;
	width  = _width;
	orgX   =  20 + leftMargin;
	orgY   =  0;
	Farbe = RGB(0, 255, 255);
	LinieStaerke = 2;
	LinienArt = PS_SOLID;
	Werte = CData(0);
}

void CGraph::setFarbe(COLORREF _farbe)
{
	Farbe = _farbe;
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

void CGraph::setLinienStaerke(double ls)
{
	LinieStaerke = ls;
}

void CGraph::setLinienArt(UINT la)
{
	LinienArt = la;
}

CData CGraph::getWerte(void)const
{
	return Werte;
}

COLORREF CGraph::getFarbe()
{
	return Farbe;
}

double CGraph::getLinienStaerke(void) const
{
	return LinieStaerke;
}

UINT CGraph::getLinienArt(void) const
{
	return LinienArt;
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
	// weißes Rechteck als Hintergrund zeichnent

	CBrush backGrnd(RGB(255, 255, 255));
	pDc->SelectObject(&backGrnd);
	pDc->Rectangle(20, 20, width, height);
	// Koordinatenachsen x und y zeichnen
	pDc->MoveTo(20 + leftMargin, 20 + upperMargin);
	pDc->LineTo(20 + leftMargin, height - upperMargin);
	pDc->MoveTo(20 + leftMargin, height/2);
	pDc->LineTo(width -leftMargin , height/ 2);
	
	

	// WerteVerlauf
	//aufpassen, ob die Werte im Rechteck sind oder außerhalb
	CPen pen(LinienArt, LinieStaerke, Farbe);
	pDc->SelectObject(&pen);

		for (int i = 1; i < DATA_LEN; i++)
		{
			if ((Xmin < *(Werte.getXWerte() + i) && (Xmax > *(Werte.getXWerte() + i))) && ((Ymin < *(Werte.getYWerte() + i) && (Ymax > *(Werte.getYWerte() + i)))))
			{
				int Xs = math2GrafikX(*(Werte.getXWerte() + i));
				int Ys = math2GrafikY(*(Werte.getYWerte() + i));
				int Xa = math2GrafikX(*(Werte.getXWerte() + i - 1));
				int Ya = math2GrafikY(*(Werte.getYWerte() + i - 1));
				if ((Ya >= 50 && Ya <= 270) && Xa< (width-leftMargin))
				{
					if ((Ys >= 50 && Ys <= 270) && Xs < (width - leftMargin))
					{
						pDc->MoveTo(Xa, Ya);
						//pDc->ArcTo(X - 0.1, Y - 0.1, X + 0.1, Y + 0.1, X,Y,X,Y);
						pDc->LineTo(Xs, Ys);
					}
				}
			}
		}
	


}

int CGraph::math2GrafikX(double _xWert) 
{
	return orgX + (int)((_xWert - Xmin) * width / (Xmax - Xmin));
}

int CGraph::math2GrafikY(double _yWert)
{
	return orgY + height - (int)((_yWert - Ymin) * height / (Ymax - Ymin));
}
