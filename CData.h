#pragma once
class CData
{
protected:
	double* Xwerte;
	double* Ywerte;
	int len;
public:
	CData(void);
	CData(int _len);
	CData operator=(CData& data);
	void setlen(int _len);
	int getLen(void)const;
	void setDataWerte(int i, double _x, double _y);
	double* getXWerte();
	double* getYWerte();
};