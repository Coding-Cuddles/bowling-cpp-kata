#include <gmock/gmock.h>

#include "bowling.h"

TEST(BowlingTest, GutterGame)
{
    BowlingGame game;
    for (int i = 0; i < 20; ++i)
        game.roll(0);

    EXPECT_EQ(game.score(), 0);
}
