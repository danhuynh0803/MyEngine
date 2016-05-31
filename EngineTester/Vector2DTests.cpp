#include <gtest\gtest.h>
#include <Vector2D.h>

using Math::Vector2D;

TEST(Vector2D, Constructor)
{
	Vector2D first(1, 2); 
	EXPECT_EQ(1, first.x);
	EXPECT_EQ(2, first.y);
}

TEST(Vector2D, VectorAddition)
{

}

TEST(Vector2D, VectorMultiplication)
{

}