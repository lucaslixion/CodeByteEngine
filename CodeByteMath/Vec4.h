#pragma once



namespace CodeByte::Vector
{
	class Vec4
	{
	public:
		Vec4(float x, float y, float z, float w);
		Vec4(float s);
		//Get Item From Vec 0 to 3
		float operator[](int i) const;
		float X;
		float Y;
		float Z;
		float W;
	};
}

