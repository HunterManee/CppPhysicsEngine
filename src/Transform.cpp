#include "Transform.h"


Transform::Transform():
Position{Point2{}}, Rotation{0}, Scale{1,1} {} 

Transform::Transform(Point2 position):
Position{position}, Rotation{0}, Scale{1,1} {} 

Transform::Transform(Point2 position, double rotation):
Position{position}, Rotation{rotation}, Scale{1,1} {} 

Transform::Transform(Point2 position, double rotation, Point2 scale):
Position{position}, Rotation{rotation}, Scale{scale} {} 