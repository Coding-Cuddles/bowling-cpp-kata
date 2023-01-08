#include <gmock/gmock.h>

#include "bowling.h"

TEST(Bowling, MaximumScore)
{
    Game game;
    for (int i = 0; i < 12; ++i) {
         game.roll(10);
    }

    EXPECT_EQ(game.score(), 300);
}
