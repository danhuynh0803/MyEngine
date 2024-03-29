#include <gtest\gtest.h>
#include <Timing\Clock.h>
#include <Qt\qtest.h>

using Timing::Clock;

TEST(Clock, Initialize)
{
	Clock clock;
	EXPECT_TRUE(clock.initialize());	
	EXPECT_TRUE(clock.shutdown());
}

TEST(Clock, FrameTimeMeasuring)
{
	Clock clock;
	EXPECT_TRUE(clock.initialize());
	// Expect time of next frame to pass in 1000ms
	QTest::qSleep(1000);
	clock.newFrame();
	float timedTime = clock.timeElapsedLastFrame();
	EXPECT_TRUE(0.9f < timedTime && timedTime < 1.1f);    // Test value of timedTime by using a range from 0.9 to 1.1.
	clock.timeElapsedLastFrame();
	EXPECT_TRUE(clock.shutdown());
	clock.newFrame();
	QTest::qSleep(500);
	clock.newFrame();
	timedTime = clock.timeElapsedLastFrame();
	EXPECT_TRUE(0.4f < timedTime);
	EXPECT_TRUE(timedTime < 0.6f);

	const int NUM_TESTS = 10 + rand() % 100;
	const float THRESHOLD = 0.1f;
	// Perform multiple tests using random numbers by checking if the elapsedSeconds is in between our threshold
	for (int i = 0; i < NUM_TESTS; ++i)
	{
		int thisTestTimeMiliseconds = rand() % 10000;
		float thisTestTimeSeconds = thisTestTimeMiliseconds / 1000.0f;
		clock.newFrame();
		QTest::qSleep(thisTestTimeMiliseconds);
		clock.newFrame();
		float elapsedSeconds = clock.timeElapsedLastFrame();

		// Here we check if the time elapsed is within our threshold bounds
		EXPECT_TRUE((thisTestTimeSeconds - THRESHOLD) < elapsedSeconds);
		EXPECT_TRUE(elapsedSeconds < (thisTestTimeSeconds + THRESHOLD));
	}

	clock.newFrame();
	clock.timeElapsedLastFrame();
}
