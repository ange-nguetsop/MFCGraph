#include "pch.h"
#include "StdAfx.h"
#include "CData.h"


CData::CData(void)
{
	Xwerte = NULL;
	Ywerte = NULL;
	len = 0;
}

CData::CData(int _len)
{
	len = _len;
	Xwerte = new double[len];
	Ywerte = new double[len];
	for (int i = 0; i < len; i++)
	{
		*(Xwerte + i) = 0;
		*(Ywerte + i) = 0;
	}
}

void CData::setlen(int _len)
{
	len = _len;
}


int CData::getLen(void) const
{
	return len;
}


void CData::setDataWerte(int i, double _x, double _y)
{
	*(Xwerte + i) = _x;
	*(Ywerte + i) = _y;
}


double* CData::getYWerte()
{
	return this->Ywerte;
}

double* CData::getXWerte()
{
	return this->Xwerte;
}

CData CData:: operator=(CData& data)
{
	delete this->Xwerte;
	delete this->Ywerte;
	this->setlen(data.getLen());
	this->Xwerte = new double[this->getLen()];
	this->Ywerte = new double[this->getLen()];
	for (int i = 0; i < this->getLen(); i++)
	{
		*(Xwerte + i) = *(data.Xwerte + i);
		*(Ywerte + i) = *(data.Ywerte + i);
	}

	return *this;
}

