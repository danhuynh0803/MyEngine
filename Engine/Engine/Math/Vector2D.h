#ifndef ENGINE_VECTOR_2D_H
#define ENGINE_VECTOR_2D_H

namespace Math
{
	struct Vector2D
	{
		float x;
		float y;

		// Converting floats to Vector2D requires an explicit cast
		explicit Vector2D(float x = 0.0f, float y = 0.0f) : x(x), y(y) {}
	};

	inline Vector2D operator+(const Vector2D& left, const Vector2D& right);
	inline Vector2D operator*(float scalar, const Vector2D& vector);
	inline Vector2D operator*(const Vector2D& vector, float scalar);
    #include "vector2D.inl"
	 
}
#endif