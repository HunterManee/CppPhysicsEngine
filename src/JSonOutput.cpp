#include "JSonOutput.h"

json JSonOutput::serializePoint(const Point2& point) {
    json j;
    j = {
        {"x", point.X},
        {"y", point.Y}
    };
    return j;
}