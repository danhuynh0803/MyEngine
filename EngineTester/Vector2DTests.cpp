#include <gtest\gtest.h>
#include <Math\Vector2D.h>

using Math::Vector2D;

TEST(Vector2D, Constructor)
{
	Vector2D first(1, 2); 
	EXPECT_EQ(1, first.x);
	EXPECT_EQ(2, first.y);
}

TEST(Vector2D, VectorAddition)
{
	Vector2D first(1, 2);
	Vector2D second(3, 4);
	Vector2D result1 = first + second; 
	Vector2D result2 = second + first;
	EXPECT_FLOAT_EQ(4, result1.x);
	EXPECT_FLOAT_EQ(6, result1.y);
	EXPECT_FLOAT_EQ(result2.x, result1.x);
	EXPECT_FLOAT_EQ(result2.y, result1.y);
}

TEST(Vector2D, ScalarMultiplication)
{
	Vector2D vec(1, 2); 
	float scalar = 2; 
	Vector2D result1 = vec * scalar;
	Vector2D result2 = scalar * vec;
	EXPECT_FLOAT_EQ(result1.x, 2);
	EXPECT_FLOAT_EQ(result1.y, 4);
	EXPECT_FLOAT_EQ(result1.x, result2.x);
	EXPECT_FLOAT_EQ(result1.y, result2.y);
}