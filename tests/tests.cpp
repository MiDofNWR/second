#include <gtest/gtest.h>

#include "../include/Color.h"
#include "../include/Line.h"
#include "../include/LineStyle.h"
#include "../include/Point.h"

#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <string>

TEST(ColorTest, ConstructorValid)
{
    Color color(10, 20, 30);

    ASSERT_EQ(color.getRed(), 10);
    ASSERT_EQ(color.getGreen(), 20);
    ASSERT_EQ(color.getBlue(), 30);
}

TEST(ColorTest, ConstructorInvalid)
{
    ASSERT_THROW(Color(-1, 0, 0), out_of_range);
    ASSERT_THROW(Color(0, 256, 0), out_of_range);
    ASSERT_THROW(Color(0, 0, 300), out_of_range);
}

TEST(ColorTest, IOOperators)
{
    stringstream input("255 128 0");
    Color color;
    input >> color;

    ASSERT_FALSE(input.fail());
    ASSERT_EQ(color.getRed(), 255);
    ASSERT_EQ(color.getGreen(), 128);
    ASSERT_EQ(color.getBlue(), 0);

    stringstream output;
    output << color;

    ASSERT_EQ(output.str(), "255 128 0");
}

TEST(ColorTest, IncorrectInput)
{
    stringstream input("256 0 0");
    Color color;
    input >> color;

    ASSERT_TRUE(input.fail());
}

TEST(PointTest, ConstructorAndEquality)
{
    Point first(1.5, 2.5);
    Point second(1.5, 2.5);
    Point third(2.0, 2.5);

    ASSERT_TRUE(first == second);
    ASSERT_FALSE(first == third);
}

TEST(PointTest, IOOperators)
{
    stringstream input("3.5 4.5");
    Point point;
    input >> point;

    ASSERT_FALSE(input.fail());
    ASSERT_DOUBLE_EQ(point.x, 3.5);
    ASSERT_DOUBLE_EQ(point.y, 4.5);

    stringstream output;
    output << point;

    ASSERT_EQ(output.str(), "(3.5; 4.5)");
}

TEST(LineStyleTest, DefaultStyle)
{
    LineStyle style;

    ASSERT_EQ(style.getType(), LineType::solid);
    ASSERT_EQ(style.getThickness(), 1);
}

TEST(LineStyleTest, ConstructorValid)
{
    LineStyle style(LineType::dash, 3);

    ASSERT_EQ(style.getType(), LineType::dash);
    ASSERT_EQ(style.getThickness(), 3);
}

TEST(LineStyleTest, InvalidThickness)
{
    ASSERT_THROW(LineStyle(LineType::solid, 0), invalid_argument);
    ASSERT_THROW(LineStyle(LineType::dot, -1), invalid_argument);
}

TEST(LineStyleTest, Setters)
{
    LineStyle style;

    style.setType(LineType::dashdotdot);
    style.setThickness(5);

    ASSERT_EQ(style.getType(), LineType::dashdotdot);
    ASSERT_EQ(style.getThickness(), 5);
}

TEST(LineStyleTest, IOOperators)
{
    stringstream input("dash-dot 4");
    LineStyle style;
    input >> style;

    ASSERT_FALSE(input.fail());
    ASSERT_EQ(style.getType(), LineType::dash_dot);
    ASSERT_EQ(style.getThickness(), 4);

    stringstream output;
    output << style;

    ASSERT_EQ(output.str(), "dash-dot 4");
}

TEST(LineStyleTest, IncorrectInput)
{
    stringstream input("unknown 2");
    LineStyle style;
    input >> style;

    ASSERT_TRUE(input.fail());
}

TEST(LineTest, Constructor)
{
    Point first(0.0, 0.0);
    Point second(10.0, 20.0);
    LineStyle style(LineType::dot, 2);
    Color color(100, 150, 200);

    Line line(first, second, style, color);

    ASSERT_TRUE(line.getFirstPoint() == first);
    ASSERT_TRUE(line.getSecondPoint() == second);
    ASSERT_EQ(line.getStyle().getType(), LineType::dot);
    ASSERT_EQ(line.getStyle().getThickness(), 2);
    ASSERT_EQ(line.getColor().getRed(), 100);
    ASSERT_EQ(line.getColor().getGreen(), 150);
    ASSERT_EQ(line.getColor().getBlue(), 200);
}

TEST(LineTest, DefaultConstructor)
{
    Line line;

    ASSERT_TRUE(line.getFirstPoint() == Point(0.0, 0.0));
    ASSERT_TRUE(line.getSecondPoint() == Point(0.0, 0.0));
    ASSERT_EQ(line.getStyle().getType(), LineType::solid);
    ASSERT_EQ(line.getStyle().getThickness(), 1);
    ASSERT_EQ(line.getColor().getRed(), 0);
    ASSERT_EQ(line.getColor().getGreen(), 0);
    ASSERT_EQ(line.getColor().getBlue(), 0);
}

TEST(LineTest, ChangeStyleAndColor)
{
    Line line;

    line.setStyle(LineStyle(LineType::dash, 6));
    line.setColor(Color(255, 0, 0));

    ASSERT_EQ(line.getStyle().getType(), LineType::dash);
    ASSERT_EQ(line.getStyle().getThickness(), 6);
    ASSERT_EQ(line.getColor().getRed(), 255);
    ASSERT_EQ(line.getColor().getGreen(), 0);
    ASSERT_EQ(line.getColor().getBlue(), 0);
}

TEST(LineTest, ToString)
{
    Line line(Point(1.0, 2.0), Point(3.0, 4.0), LineStyle(LineType::dash, 2), Color(255, 0, 0));
    stringstream output;
    line.ToString(output);

    string result = output.str();

    ASSERT_NE(result.find("Информация о линии"), string::npos);
    ASSERT_NE(result.find("Первая точка"), string::npos);
    ASSERT_NE(result.find("Вторая точка"), string::npos);
    ASSERT_NE(result.find("Стиль линии"), string::npos);
    ASSERT_NE(result.find("Цвет линии"), string::npos);
}

TEST(LineTest, OutputOperator)
{
    Line line(Point(1.0, 2.0), Point(3.0, 4.0), LineStyle(LineType::dash, 2), Color(255, 0, 0));
    stringstream output;
    output << line;

    string result = output.str();

    ASSERT_NE(result.find("Информация о линии"), string::npos);
    ASSERT_NE(result.find("Стиль линии: dash 2"), string::npos);
    ASSERT_NE(result.find("Цвет линии: 255 0 0"), string::npos);
}

TEST(LineTest, Read)
{
    stringstream input("1 2 3 4 dashdotdot 5 10 20 30");
    Line line = Line::Read(input);

    ASSERT_TRUE(line.getFirstPoint() == Point(1.0, 2.0));
    ASSERT_TRUE(line.getSecondPoint() == Point(3.0, 4.0));
    ASSERT_EQ(line.getStyle().getType(), LineType::dashdotdot);
    ASSERT_EQ(line.getStyle().getThickness(), 5);
    ASSERT_EQ(line.getColor().getRed(), 10);
    ASSERT_EQ(line.getColor().getGreen(), 20);
    ASSERT_EQ(line.getColor().getBlue(), 30);
}

TEST(LineTest, IncorrectRead)
{
    stringstream input("1 2 3 4 solid 0 10 20 30");

    ASSERT_THROW(Line::Read(input), invalid_argument);
}

int main(int argc, char** argv)
{
#ifdef _WIN32
    system("chcp 65001 > nul");
#endif

    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
