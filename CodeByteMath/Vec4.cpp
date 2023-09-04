#include "Vec4.h"

namespace CodeByte::Vector
{
	Vec4::Vec4(float x, float y, float z, float w)
	{
		X = x;
		Y = y;
		Z = z;
		W = w;
	}
	Vec4::Vec4(float s)
	{
		X = s;
		Y = s;
		Z = s;
		W = s;
	}
	float Vec4::operator[](int i) const
	{
		switch (i)
		{
		case 0:
			return X;
			break;
		case 1:
			return Y;
			break;
		case 2:
			return Z;
			break;
		case 3:
			return W;
			break;
		}
	}
}
